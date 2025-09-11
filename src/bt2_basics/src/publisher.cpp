#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

int main(int argc, char* argv[]){


    // std::shared_ptr<rclcpp::Node> node= std::shared_ptr<rclcpp::Node>
    //  (new rclcpp::Node("publisher_node"));
    // std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("publisher_node");
    // auto node = rclcpp::Node::make_shared("publisher_node");


    // std::shared_ptr<rclcpp::Node> node = std::shared_ptr<rclcpp::Node> (new rclcpp::Node("pb"));
    // auto  n= std::make_shared<rclcpp::Node>("pb");
    // auto n = rclcpp::Node::make_shared("pb");
    //auto p = n->create_publisher<std_msgs::msg::Int32>("int_topic",10);


    rclcpp::init(argc,argv);

    auto node_pub = rclcpp::Node::make_shared("publisher_node");
    //auto  node_pub = std::make_shared<rclcpp::Node>("publisher_node");



    auto publisher = node_pub->create_publisher<std_msgs::msg::Int32>("int_topic",10);

    std_msgs::msg::Int32 message;
    message.data = 0;

    rclcpp::Rate loop_rate(500ms);

    while (rclcpp::ok()) {
        message.data += 1;
        publisher->publish(message);

        rclcpp::spin_some(node_pub);
        loop_rate.sleep();
    }
    
    rclcpp::shutdown();

}