#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;


int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node_logger = rclcpp::Node::make_shared("logger_node");

    rclcpp::Rate loop_rate(500ms);
    int counter =0;
   
    while(rclcpp::ok()){
       
        RCLCPP_INFO(node_logger->get_logger(), "Hello %d", counter++);
        // if you wanna control callbacks with your loop
        // so while loop controls it. if there was spin, your loop
        //would not interate after 1
        rclcpp::spin_some(node_logger); 
        loop_rate.sleep();

    }

    rclcpp::shutdown();
    return 0;
}