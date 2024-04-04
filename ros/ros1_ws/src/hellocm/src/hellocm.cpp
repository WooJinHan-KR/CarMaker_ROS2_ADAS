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

#include "hellocm_msgs/CM2Ext.h"
#include "hellocm_msgs/Ext2CM.h"
#include "hellocm_msgs/Init.h"
#include "ros/ros.h"

class HelloCM {
 public:
  HelloCM(const ros::NodeHandle& nodehandle)
      : cycle_no_(0), delay_(0), nh_(nodehandle) {
    ROS_INFO("%s -> Start spinning...", ros::this_node::getName().c_str());
    init();
  }

  ~HelloCM() { ROS_INFO("%s -> Shutdown", ros::this_node::getName().c_str()); }

 private:
  /*! Cyclic log dependent on wall time (system time) */
  void wallTimerCallback(const ros::WallTimerEvent& event) {
    (void)event;
    ROS_INFO("%s: Still spinning...", ros::this_node::getName().c_str());
  }

  /*! Callback function for timer dependent on simulation time */
  void timerCallback(const ros::TimerEvent& event);

  /*! Subscriber callback function */
  void subcriberCallback(const hellocm_msgs::CM2Ext::ConstPtr& msg);

  /*! Service callback function */
  bool serviceCallback(hellocm_msgs::Init::Request& request,
                       hellocm_msgs::Init::Response& response);

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

  ros::NodeHandle nh_;
  ros::Publisher publisher_;
  ros::Subscriber subscriber_;

  /*!< Service for resetting this node e.g. when simulation starts */
  ros::ServiceServer service_;

  /*!< Timer independent from simulation time */
  ros::WallTimer wall_timer_;

  /*!< Timer dependent on simulation time ("/clock" topic) */
  ros::Timer timer_;
};

void HelloCM::init() {
  publisher_ = nh_.advertise<hellocm_msgs::Ext2CM>("ext2cm", 10);
  subscriber_ = nh_.subscribe<hellocm_msgs::CM2Ext>(
      "cm2ext", 10, &HelloCM::subcriberCallback, this);
  service_ = nh_.advertiseService("init", &HelloCM::serviceCallback, this);

  bool use_sim_time;
  nh_.param("/use_sim_time", use_sim_time, false);

  if (use_sim_time) {
    ROS_INFO("  -> Use time provided by clock server!");
  } else {
    ROS_INFO("  -> Use system time!");
  }

  const char param_name[] = "cycletime";
  bool param_found = nh_.param(param_name, cycle_time_, 10000);
  if (!param_found) {
    nh_.setParam(param_name, cycle_time_);
    ROS_INFO("  -> No param '%s' was set! Use default cycle time!", param_name);
  }
  ROS_INFO("  -> Cycle time = %dms", cycle_time_);

  wall_timer_ = nh_.createWallTimer(ros::WallDuration(10.0),
                                    &HelloCM::wallTimerCallback, this);
  timer_ = nh_.createTimer(ros::Duration(cycle_time_ * 1e-3),
                           &HelloCM::timerCallback, this);

  // Print general information after everything is done
  ROS_INFO("%s", "Initialization of ROS Node finished!");
  ROS_INFO("  -> Node name = '%s'", ros::this_node::getName().c_str());
  ROS_INFO("  -> Namespace = '%s'", ros::this_node::getNamespace().c_str());

  // Advertised Topics
  ros::V_string topics;
  ros::this_node::getAdvertisedTopics(topics);
  ROS_INFO("  -> Advertised Topics (%lu)", topics.size());
  for (const auto& topic : topics) {
    ROS_INFO("   -> %s", topic.c_str());
  }

  // Subscribed Topics
  topics.clear();
  ros::this_node::getSubscribedTopics(topics);
  ROS_INFO("  -> Subscribed Topics (%lu)", topics.size());
  for (const auto& topic : topics) {
    ROS_INFO("   -> %s", topic.c_str());
  }
}

void HelloCM::timerCallback(const ros::TimerEvent& event) {
  (void)event;
  hellocm_msgs::Ext2CM msg;
  msg.cycleno = static_cast<long>(++cycle_no_);
  msg.time = ros::Time::now();

  // delay node to demonstrate the effect of synchronization
  if (delay_ > 1e-9) {
    ros::WallDuration(delay_).sleep();
  }

  // set time stamp in header just before publishing
  msg.header.stamp = ros::Time(ros::WallTime::now().toSec());

  // publish the message
  publisher_.publish(msg);

  ROS_INFO("%s: Pub Msg: Time %.3fs, Cycle %lu",
           ros::this_node::getName().c_str(), msg.time.toSec(), msg.cycleno);
}

void HelloCM::subcriberCallback(const hellocm_msgs::CM2Ext::ConstPtr& msg) {
  // Update variables
  delay_ = msg->synthdelay;
  ROS_INFO("%s: Sub Msg: Time %.3fs, Cycle %lu",
           ros::this_node::getName().c_str(), msg->time.toSec(), msg->cycleno);
}

bool HelloCM::serviceCallback(hellocm_msgs::Init::Request& request,
                              hellocm_msgs::Init::Response& response) {
  (void)request;

  ROS_INFO("%s: Service 'Init' was triggered",
           ros::this_node::getName().c_str());

  // reset variables
  cycle_no_ = 0;
  delay_ = 0.0;

  // Check if parameter has changed
  const char* param_name = "cycletime";
  auto value = nh_.param(param_name, cycle_time_);
  if (value != cycle_time_) {
    cycle_time_ = value;
    timer_.setPeriod(ros::Duration(cycle_time_ * 1e-3), true);
    ROS_INFO("  -> Update param '%s' to '%d'", param_name, cycle_time_);
  }

  response.success = 1;
  response.cycletime = cycle_time_;
  return true;
}

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "hellocm");
  ros::NodeHandle nh;
  HelloCM hellocm(nh);
  ros::spin();
  ros::shutdown();
  return 0;
}
