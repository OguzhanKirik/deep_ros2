#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node{

    public:
        // contstructor runs when  a Publisher node, 
        //Node("publisher_node") calls base class construtor , naming this node
        
        PublisherNode() : Node("publisher_node"){
            // create a publisher in constructor
            publisher_ = create_publisher<std_msgs::msg::Int32>("int_topic",10);
            
            // Creates a wall timer that calls function repeatedly,
            //intervall:500ms and std::bind binds the callback ofthe this node obecjt
            
            timer_ = create_wall_timer(
                500ms, std::bind(&PublisherNode::timer_callback, this));
        }
        // 
        void timer_callback(){
            message_.data += 1;
            publisher_->publish(message_);
        }
        
    private:
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_; 
        rclcpp::TimerBase::SharedPtr timer_;
        std_msgs::msg::Int32 message_;

}; 


int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node_pub = std::make_shared<PublisherNode>();

    rclcpp::spin(node_pub); // keeps the node alive, waits for callback

    rclcpp::shutdown();

}

