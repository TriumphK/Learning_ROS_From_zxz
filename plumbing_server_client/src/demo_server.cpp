#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNums(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("The request data: num1=%d, num2=%d.", num1, num2);

    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("The result: sum=%d.", sum);

    return true;
}

int main(int argc, char *argv[])
{
    
    ros::init(argc, argv, "heishui");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts", doNums);
    ROS_INFO("Server Starting...");
    
    ros::spin();
    
    return 0;
}
