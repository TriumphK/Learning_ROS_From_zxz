#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"

// ros::NodeHandle
// ros::param

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param_c");
    ros::NodeHandle nh;

    nh.setParam("type", "GL");
    nh.setParam("radius", 0.15);

    ros::param::set("type_param", "xiaoBai");
    ros::param::set("radius_param", 0.25);

    nh.setParam("radius", 0.55);
    
    return 0;
}
