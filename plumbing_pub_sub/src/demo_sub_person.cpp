#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

void doPerson(const plumbing_pub_sub::Person::ConstPtr& person)
{
    ROS_INFO("Name %s, Age %d, Height %.2f", person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "jiazhang");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("liaotian", 10, doPerson);

    ros::spin();
    return 0;
}
