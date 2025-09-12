#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;

void callback(const std_msgs::msg::Int32::SharedPtr msg){
    RCLCPP_INFO(rclcpp::get_logger("subscriber_node"), "Hello %d",msg->data);
}


int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node_sub = rclcpp::Node::make_shared("subscriber_node");

    auto subscriber = node_sub->create_subscription<std_msgs::msg::Int32>(
        "int_topic",10, std::bind(&callback , _1));

    rclcpp::spin(node_sub);

    rclcpp::shutdown();
    return 0;

}
