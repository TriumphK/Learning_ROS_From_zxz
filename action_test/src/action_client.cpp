#include "ros/ros.h"
#include "actionlib/client/simple_action_client.h"
#include "action_test/AddIntsAction.h"

typedef actionlib::SimpleActionClient<action_test::AddIntsAction> Client;

void done_cb(const actionlib::SimpleClientGoalState &state, const action_test::AddIntsResultConstPtr &result)
{
    if (state.state_ == state.SUCCEEDED)
    {
        ROS_INFO("Success, the result is: %d",result->result);
    }
    else
    {
        ROS_INFO("Failed..");
    }
}

void active_cb()
{
    ROS_INFO("Server and Client connected!!!");
}

void feedback_cb(const action_test::AddIntsFeedbackConstPtr &feedback)
{
    ROS_INFO("Current: %.2f",feedback->progress_bar);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"addInts_client");
    ros::NodeHandle nh;
    Client client(nh,"addInts");
    ROS_INFO("Waiting For Start---");
    client.waitForServer();
    // void Client::sendGoal(const action_test::AddIntsGoal &goal, 
    //boost::function<...> done_cb = actionlib::SimpleActionClient<...>::SimpleDoneCallback(), 
    //boost::function<...> active_cb = actionlib::SimpleActionClient<...>::SimpleActiveCallback(), 
    //boost::function<...> feedback_cb = actionlib::SimpleActionClient<...>::SimpleFeedbackCallback())
    action_test::AddIntsGoal goal;
    goal.num = 100;
    client.sendGoal(goal,&done_cb,&active_cb,&feedback_cb);
    
    ros::spin();

    return 0;
}
