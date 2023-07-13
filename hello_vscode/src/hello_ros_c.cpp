#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello_c");

    ROS_INFO("hello");

    return 0;
}
