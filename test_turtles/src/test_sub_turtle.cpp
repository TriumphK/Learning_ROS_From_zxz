#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"sub_tf");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);

    ros::Rate rate(10);

    while (ros::ok())
    {
        try
        {
            geometry_msgs::TransformStamped tfs = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            geometry_msgs::Twist twist;
            twist.linear.x = 1 * sqrt(pow(tfs.transform.translation.x,2)+pow(tfs.transform.translation.y,2));
            twist.angular.z = 4 * atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("Error: %s",e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
