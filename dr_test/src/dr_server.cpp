#include "ros/ros.h"
#include "dynamic_reconfigure/server.h"
#include "dr_test/drConfig.h"

void cb(dr_test::drConfig &config, uint32_t level)
{
    ROS_INFO("The new configure param: %d",config.int_param);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"dr_server");
    dynamic_reconfigure::Server<dr_test::drConfig> server;
    server.setCallback(boost::bind(&cb,_1,_2));

    ros::spin();
    return 0;
}
