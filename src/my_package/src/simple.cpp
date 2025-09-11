#include "rclcpp/rclcpp.hpp"



/*
##from Standard CPP to ROSCPP
std::shared_ptr<rclcpp::Node> node = std::shared_ptr<rclcpp::Node>
(new rclcpp::Node("simple_node"));

std::shared_ptr<rclcpp::Node> node = std::maked_shared<rclcpp::node>("simple_node");
auto node = std::maked_shared<rclcpp::Node>("simple_code");
auto node = rclcpp::Node::make_shared("simple_node");

*/
    


int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);
    
    auto node = rclcpp::Node::make_shared("simple_node"); //explained above!!!

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}