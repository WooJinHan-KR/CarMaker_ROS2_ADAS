#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/path.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std::chrono_literals;

class GlobalPathPublisher : public rclcpp::Node {
public:
    GlobalPathPublisher() : Node("global_path_publisher")
    {
        readPathFromCSV("/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/src/planning/include/planning/global_path.csv");

        RCLCPP_INFO(this->get_logger(), "Start spinning(Global_Path)...");

        path_publisher_ = this->create_publisher<nav_msgs::msg::Path>("/planning/global_path", 10);

        publish_timer_ = this-> create_wall_timer(100ms, [this]() {
            publishPath();
        });
    }

private:
    std::vector<geometry_msgs::msg::PoseStamped> global_path_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_publisher_;
    rclcpp::TimerBase::SharedPtr publish_timer_;

    void readPathFromCSV(const std::string &file_path)
    {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open CSV file");
            return;
        }

        std::string header; //skip first line
        std::getline(file, header);

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            double x, y, z;
            char comma;
            if (!(iss >> x >> comma >> y >> comma >> z)) {
                RCLCPP_ERROR(this->get_logger(), "Error parsing line in CSV file");
                continue;
            }
            geometry_msgs::msg::PoseStamped pose;
            pose.pose.position.x = x;
            pose.pose.position.y = y;
            pose.pose.position.z = z;
            global_path_.push_back(pose);
        }

        // Create nav_msgs::msg::Path message and fill poses
        path_msg_.header.frame_id = "map";
        path_msg_.header.stamp = this->now();
        path_msg_.poses = global_path_;
    }

    void publishPath()
    {
        path_publisher_->publish(path_msg_);
    }

    nav_msgs::msg::Path path_msg_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GlobalPathPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
