#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;


class LoggerNode : public rclcpp::Node{
    public:
        LoggerNode() : Node("logger_node"){
        
            counter_ = 0 ;
            timer_ = create_wall_timer(
                500ms, std::bind(&LoggerNode::timer_callback,this));
            }

        void timer_callback(){
                RCLCPP_INFO(get_logger(), "Hello %d", counter_++);
            }
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;

};

int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node_logger = std::make_shared<LoggerNode>();

    rclcpp::spin(node_logger);

    rclcpp::shutdown();
    return 0;

}