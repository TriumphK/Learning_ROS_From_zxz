#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"tf_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Rate r(1);
    
    while (ros::ok())
    {
        geometry_msgs::PointStamped point_turtle;
        point_turtle.header.frame_id = "turtle1";
        point_turtle.header.stamp = ros::Time();
        point_turtle.point.x = 1;
        point_turtle.point.y = 1;
        point_turtle.point.z = 0;

        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_turtle,"world");
            ROS_INFO("%.2f,%.2f,%.2f,%s",point_base.point.x,point_base.point.y,point_base.point.z,point_base.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            ROS_INFO("ERROR: %s",e.what());
        }

        r.sleep();
        ros::spinOnce();
        
    }

    return 0;
}
