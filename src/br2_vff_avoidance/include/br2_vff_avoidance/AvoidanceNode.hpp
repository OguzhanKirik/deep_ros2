#ifndef _BR2_VFF_AVOIDANCE_AVOIDANCE_NODE_
#define _BR2_VFF_AVOIDANCE_AVOIDANCE_NODE_

#include "rclcpp/rclcpp.hpp"
#include <vector>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "visualization_msgs/msg/marker_array.hpp"


namespace br2_vff_avoidance{
    
    struct VFFVectors{
        std::vector<float> attractive;
        std::vector<float> repulsive;
        std::vector<float> result;
    };
    
    typedef enum {RED, GREEN, BLUE, NUM_COLORS} VFFColor;

    class AvoidanceNode : public rclcpp::Node {
        public:
            AvoidanceNode();

            void scan_callback(sensor_msgs::msg::LaserScan::UniquePtr msg);
            void control_cycle();
        protected:
            VFFVectors get_vff(const sensor_msgs::msg::LaserScan & scan);
            visualization_msgs::msg::MarkerArray get_debug_vff(const VFFVectors & vff_vectors);
            visualization_msgs::msg::Marker make_marker(const std::vector<float> & vector, VFFColor vff_color);
            
            
        private:
            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub_;
            rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr vff_debug_pub_;
            rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub_;
            rclcpp::TimerBase::SharedPtr timer_;
            
            sensor_msgs::msg::LaserScan::UniquePtr last_scan_;

    };

} // namespace br2_vff_avoidance
 
#endif //_BR2_VFF_AVOIDANCE_AVOIDANCE_NODE_