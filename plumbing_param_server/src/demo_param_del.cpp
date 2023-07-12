#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"del_param_c");
    ros::NodeHandle nh;

    bool flag = nh.deleteParam("type_param");
    if (flag)
    {
        ROS_INFO("Success!");
    }
    else
    {
        ROS_INFO("None...");
    }
    
    return 0;
}
