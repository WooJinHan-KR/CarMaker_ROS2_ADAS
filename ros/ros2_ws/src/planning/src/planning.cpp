/*!
 ******************************************************************************
 **  External ROS Node for simple communication with CarMaker
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 */

#include <chrono>
#include <memory>

#include "hellocm_msgs/msg/radar_data.hpp"
#include "hellocm_msgs/srv/init.hpp"
#include "hellocm_msgs/msg/aeb_system.hpp"
#include "rclcpp/create_timer.hpp"
#include "rclcpp/rclcpp.hpp"

// ROS Package header
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/transform_broadcaster.h"              /* Publish TF2 transforms */
#include "tf2_ros/static_transform_broadcaster.h"
#include "sensor_msgs/point_cloud_conversion.hpp"
#include <angles/angles.h>
#include <cstring>

using namespace std::chrono_literals;
using namespace std::placeholders;

class Planning : public rclcpp::Node {
 public:
  Planning() : Node("Planning"), cycle_no_(0), delay_(0) {
    RCLCPP_INFO(this->get_logger(), "Start spinning(Planning)...");
    init();
  }

  ~Planning() { RCLCPP_INFO(this->get_logger(), "Shutdown"); }

 private:
  /*! Cyclic log dependent on wall time (system time) */
  void on_wall_timer() { RCLCPP_INFO(this->get_logger(), "Still spinning..."); }

  /*! Callback function for timer dependent on simulation time */
  void on_timer();

  /*! Subscription callback function */
  void topic_callback_Lidar(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
  void topic_callback_Radar(const hellocm_msgs::msg::RadarData::SharedPtr msg);
  /*! Service callback function */
  void handle_service(
      const std::shared_ptr<rmw_request_id_t> request_header,
      const std::shared_ptr<hellocm_msgs::srv::Init::Request> request,
      const std::shared_ptr<hellocm_msgs::srv::Init::Response> response);

  /*! Set up subscriber, publisher and timers */
  void init();

  /*!< Current cycle number of this node */
  size_t cycle_no_;

  /*!< Expected cycle time in milliseconds of external ROS Node.
   *    - Might be used for synchronization (under development)
   *    - e.g. usage in combination of published message
   */
  int cycle_time_;

  /*!< Delay in seconds to demonstrate synchronization mechanism */
  double delay_;

  rclcpp::Publisher<hellocm_msgs::msg::AEBSystem>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscriptionL_;
  rclcpp::Subscription<hellocm_msgs::msg::RadarData>::SharedPtr subscriptionR_;


  /*!< Service for resetting this node e.g. when simulation starts */
  rclcpp::Service<hellocm_msgs::srv::Init>::SharedPtr service_;

  /*!< Timer independent from simulation time */
  rclcpp::TimerBase::SharedPtr wall_timer_;

  /*!< Timer dependent on simulation time ("/clock" topic) */
  rclcpp::TimerBase::SharedPtr timer_;
};

void Planning::init() {
  publisher_ = this->create_publisher<hellocm_msgs::msg::AEBSystem>("AEB_System", 10);
  subscriptionL_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      "carmaker/perception/LidarRSI", 10, std::bind(&Planning::topic_callback_Lidar, this, _1));
  subscriptionR_ = this->create_subscription<hellocm_msgs::msg::RadarData>(
      "carmaker/perception/RadarRSI", 10, std::bind(&Planning::topic_callback_Radar, this, _1));
  service_ = this->create_service<hellocm_msgs::srv::Init>(
      "init", std::bind(&Planning::handle_service, this, _1, _2, _3));

  bool use_sim_time;
  this->get_parameter("use_sim_time", use_sim_time);

  if (use_sim_time) {
    RCLCPP_INFO(this->get_logger(), "  -> Use time provided by Clock Server!");
  } else {
    RCLCPP_INFO(this->get_logger(), "  -> Use system time!");
  }

  const char param[] = "cycletime";
  this->declare_parameter<int>(param, 10000);
  this->get_parameter(param, cycle_time_);
  RCLCPP_INFO(this->get_logger(), "  -> Cycle time = %dms", cycle_time_);

  wall_timer_ =
      create_wall_timer(10s, std::bind(&Planning::on_wall_timer, this));
  timer_ = rclcpp::create_timer(this, this->get_clock(),
                                std::chrono::milliseconds(cycle_time_),
                                std::bind(&Planning::on_timer, this));

  // Print general information after everything is done
  RCLCPP_INFO(this->get_logger(), "%s", "Initialization of ROS Node finished!");
  RCLCPP_INFO(this->get_logger(), "  -> Node Name = '%s'", this->get_name());
  RCLCPP_INFO(this->get_logger(), "  -> Namespace = '%s'",
              this->get_namespace());

  // Advertised and subscribed Topics
  auto topics = this->get_topic_names_and_types();
  RCLCPP_INFO(this->get_logger(), "  -> Topics (%lu)", topics.size());
  for (const auto& topic : topics) {
    RCLCPP_INFO(this->get_logger(), "   -> %s (%s)", topic.first.c_str(),
                topic.second.data()->c_str());
  }

  auto services = this->get_service_names_and_types();
  RCLCPP_INFO(this->get_logger(), "  -> Services     (%lu)", services.size());
  for (const auto& topic : services) {
    RCLCPP_INFO(this->get_logger(), "   -> %s (%s)", topic.first.c_str(),
                topic.second.data()->c_str());
  }
}

void Planning::on_timer() {
  hellocm_msgs::msg::AEBSystem msg;
  msg.cycleno = static_cast<long>(++cycle_no_);
  msg.time = this->now();

  // delay node to demonstrate the effect of synchronization
  if (delay_ > 1e-9) {
    std::chrono::duration<double> sleep_s(delay_);
    auto sleep_ms(
        std::chrono::duration_cast<std::chrono::milliseconds>(sleep_s));
    rclcpp::sleep_for(sleep_ms);
  }

  // set time stamp in header just before publishing
  msg.header.stamp = rclcpp::Clock().now();

  // publish the message
  publisher_->publish(msg);

  RCLCPP_INFO(this->get_logger(), "[%.3f]: Pub Msg: Time %.3fs, Cycle %lu",
              this->now().seconds(), rclcpp::Time(msg.time).seconds(),
              msg.cycleno);
}

void Planning::topic_callback_Lidar(const sensor_msgs::msg::PointCloud2::SharedPtr /*msg*/) {
  // Update variables
  //printf("Lidar\n");
  //RCLCPP_INFO(this->get_logger(), "[%.3f]: Sub Msg: Time %.3fs",
  //            this->now().seconds(), rclcpp::Time(msg->time).seconds());
}

void Planning::topic_callback_Radar(const hellocm_msgs::msg::RadarData::SharedPtr msg) {
  // Update variables
  delay_ = msg->synthdelay;
  RCLCPP_INFO(this->get_logger(), "[%.3f]: Sub Msg: Time %.3fs, Cycle %lu",
              this->now().seconds(), rclcpp::Time(msg->time).seconds(),
              msg->cycleno);
}

void Planning::handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<hellocm_msgs::srv::Init::Request> request,
    const std::shared_ptr<hellocm_msgs::srv::Init::Response> response) {
  (void)request_header;
  (void)request;

  RCLCPP_INFO(this->get_logger(), "Service 'Init' was triggered");

  // reset variables
  cycle_no_ = 0;
  delay_ = 0.0;

  /*
   * Check if parameter has changed!
   *  TODO: use topic /parameter_events instead?
   */
  const char param[] = "cycletime";

  if (this->has_parameter(param)) {
    int value;
    this->get_parameter(param, value);

    if (cycle_time_ != value) {
      cycle_time_ = value;
      RCLCPP_INFO(this->get_logger(), "  -> Update param '%s' to '%d'", param,
                  cycle_time_);

      timer_ = create_timer(this, this->get_clock(),
                            std::chrono::milliseconds(cycle_time_),
                            std::bind(&Planning::on_timer, this));
    }
  }

  response->success = 1;
  response->cycletime = cycle_time_;
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Planning>());
  rclcpp::shutdown();
  return 0;
}
