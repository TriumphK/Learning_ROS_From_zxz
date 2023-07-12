#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;


    double radius2 = 0.0;
    // double radius = nh.param("radius",0.5);
    bool result = nh.getParamCached("radius",radius2);
    if (result)
    {
        ROS_INFO("Radius = %.2f",radius2);
    }
    else
    {
        ROS_INFO("Don't exit!");
    }

    // get param names
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("The whole elements: %s", name.c_str());
    }
    
    return 0;
}
