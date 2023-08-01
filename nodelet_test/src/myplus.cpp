#include "ros/ros.h"
#include "nodelet/nodelet.h"
#include "pluginlib/class_list_macros.h"
#include "std_msgs/Float64.h"

namespace my_nodelet
{
    class MyPlus: public nodelet::Nodelet
    {
        private:
            ros::Publisher pub;
            ros::Subscriber sub;
            double value;

        public:
            MyPlus()
            {
                value = 0.0;
            }
            void onInit()
            {
                ROS_INFO("hello nodelet --------");
                ros::NodeHandle nh = getPrivateNodeHandle();
                nh.getParam("value",value);
                pub = nh.advertise<std_msgs::Float64>("out",100);
                sub = nh.subscribe<std_msgs::Float64>("in",100,&MyPlus::cb,this);
            }
            void cb(const std_msgs::Float64::ConstPtr& p)
            {
                double in = p->data;
                double out = in + value;
                std_msgs::Float64 out_msg;
                out_msg.data = out;
                pub.publish(out_msg);
            }
    };
};

PLUGINLIB_EXPORT_CLASS(my_nodelet::MyPlus,nodelet::Nodelet)