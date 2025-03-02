#include "rclcpp/rclcpp.hpp"
#include "driver_msgs/msg/target.hpp"
#include <chrono>
#include <cmath>

class DriverNode : public rclcpp::Node
{
public:
    DriverNode() : Node("driver_node"), start_time_(std::chrono::steady_clock::now())
    {
        // Declare and get the count parameter
        this->declare_parameter("count", 0);
        this->get_parameter("count", count);

        // Check if the count is within the valid range
        if (count < 0 || count > 100)
        {
            RCLCPP_WARN(this->get_logger(), "Count parameter out of range (0-100). Initialized to 0.");
            count = 0;
        }

        // Initialize the publisher with Target message type
        publisher_ = this->create_publisher<driver_msgs::msg::Target>("target", 10);

        // Create a timer that triggers the timer_callback function at 500Hz
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(2),  // 500Hz = 2ms
            std::bind(&DriverNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        // Increment the count variable
        count++;

        // Calculate the time since the node started in seconds
        auto current_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = current_time - start_time_;
        double time_since_start = elapsed_seconds.count();

        // Create a Target message
        auto message = driver_msgs::msg::Target();
        message.name = "targ";  // 设置 name 字段
        message.count = count;  // 设置 count 字段
        message.time = time_since_start;  // 设置 time 字段

        // Calculate target values using sin and cos
        double t = time_since_start;
        message.target.x = std::sin(t);  // x = sin(t)
        message.target.y = std::cos(t);  // y = cos(t)
        message.target.z = std::sin(2 * t);  // z = sin(2*t)

        // Publish the message
        publisher_->publish(message);

        // Log the info message
        RCLCPP_INFO(this->get_logger(), "Message %d published at %.2f seconds", count, time_since_start);
    }

    int count;
    rclcpp::Publisher<driver_msgs::msg::Target>::SharedPtr publisher_;  // 使用 Target 消息类型
    rclcpp::TimerBase::SharedPtr timer_;
    std::chrono::steady_clock::time_point start_time_;  // 记录节点启动时间
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DriverNode>());
    rclcpp::shutdown();
    return 0;
}