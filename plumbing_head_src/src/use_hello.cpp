#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_head_src/hello.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"use_hello_head");

    hello_ns::MyHello myHello;
    myHello.run();

    return 0;
}
