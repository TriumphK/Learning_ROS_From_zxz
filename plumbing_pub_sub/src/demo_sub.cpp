#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("The received text is: %s", msg->data.c_str());
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "cuihua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("fang", 10, doMsg);

    ros::spin();

    return 0;
}