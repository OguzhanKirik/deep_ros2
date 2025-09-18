#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "br2_tf2_detector/ObstacleDetectorNode.hpp"
#include "br2_tf2_detector/ObstacleDetectorImprovedNode.hpp"
#include "br2_tf2_detector/ObstacleMonitorNode.hpp"


int main(int argc, char* argv[]){
    
    rclcpp::init(argc,argv);
    
    auto node_detector = std::make_shared<br2_tf2_detector::ObstacleDetectorImprovedNode>();
    auto node_monitor = std::make_shared<br2_tf2_detector::ObstacleMonitorNode>();

    rclcpp::executors::SingleThreadedExecutor executor;

    executor.add_node(node_detector->get_node_base_interface());
    executor.add_node(node_monitor->get_node_base_interface());

    executor.spin();

    rclcpp::shutdown();

    return 0;
}