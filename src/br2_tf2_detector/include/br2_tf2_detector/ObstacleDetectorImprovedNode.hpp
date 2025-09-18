#ifndef BR2_TF2_DETECTOR_OBSTACLEDETECTORIMPROVEDNODE_HPP_
#define BR2_TF2_DETECTOR_OBSTACLEDETECTORIMPROVEDNODE_HPP_

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/static_transform_broadcaster.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "sensor_msgs/msg/laser_scan.hpp" 



namespace br2_tf2_detector{

    class ObstacleDetectorImprovedNode : public rclcpp::Node{

        public:
            ObstacleDetectorImprovedNode();

        private:
            void scan_callback(sensor_msgs::msg::LaserScan::UniquePtr msg);
            rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub_;

            std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_broadcaster_;
            tf2::BufferCore tf_buffer_;
            tf2_ros::TransformListener tf_listener_;
    };

} //namespace br2_tf2_detector



#endif // BR2_TF2_DETECTOR_OBSTACLEDETECTORIMPROVEDNODE_HPP_
