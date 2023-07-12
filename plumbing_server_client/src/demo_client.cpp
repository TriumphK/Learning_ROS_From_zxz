#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ROS_INFO("Need three parameters...");
        return 1;
    }
    
    ros::init(argc, argv, "yon ghu");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    client.waitForExistence();

    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("Success.");
        ROS_INFO("SUM result=%d.", ai.response.sum);
    }
    else
    {
        ROS_INFO("Failed...");
    }

    return 0;
}
