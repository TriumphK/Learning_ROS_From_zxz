#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "ergouzi");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10);

    std_msgs::String msg;
    int count = 0;
    ros::Rate rate(1);
    while (ros::ok())
    {
        count++;
        // msg.data = "hello";
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str();

        pub.publish(msg);
        ROS_INFO("The text is: %s", ss.str().c_str());

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}