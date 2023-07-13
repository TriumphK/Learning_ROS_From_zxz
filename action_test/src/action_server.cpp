#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "action_test/AddIntsAction.h"

typedef actionlib::SimpleActionServer<action_test::AddIntsAction> Server;

void cb(const action_test::AddIntsGoalConstPtr &goalPtr, Server* server)
{
    int goal_num = goalPtr->num;
    ROS_INFO("Client send the goal number is: %d",goal_num);
    ros::Rate rate(10);
    int result = 0;
    ROS_INFO("Start feedback---");
    for (int i = 1; i < goal_num; i++)
    {
        result += i;
        rate.sleep();

        action_test::AddIntsFeedback fb;
        fb.progress_bar = i / (double)goal_num;
        server->publishFeedback(fb);
    }
    ROS_INFO("Result: %d",result);
    action_test::AddIntsResult r;
    r.result = result;
    server->setSucceeded(r);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"addInts_server");
    ros::NodeHandle nh;
    Server server(nh,"addInts",boost::bind(&cb,_1,&server),false);
    server.start();
    ROS_INFO("Server Start!!!");

    ros::spin();    
    return 0;
}
