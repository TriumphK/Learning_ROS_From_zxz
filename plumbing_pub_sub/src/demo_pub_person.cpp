#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "banzhuren");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaotian", 10);

    plumbing_pub_sub::Person person;
    person.name = "zhang";
    person.age = 18;
    person.height = 1.73;
    ros::Rate rate(1);

    while(ros::ok())
    {
        person.age += 1;
        pub.publish(person);
        ROS_INFO("Name %s, Age %d, Height %.2f", person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
