#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns
{
    void MyHello::run()
    {
        ROS_INFO("run function!");
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello_head");
    hello_ns::MyHello myHello;
    myHello.run();
    
    return 0;
}
