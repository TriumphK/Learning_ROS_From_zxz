#include "ros/ros.h"
#include "pluginlib/class_loader.h"
#include "plugin_test/dbx_base.h"

int main(int argc, char *argv[])
{
    pluginlib::ClassLoader<dbx_base_ns::Dbx_Base> loader("plugin_test","dbx_base_ns::Dbx_Base");
    boost::shared_ptr<dbx_base_ns::Dbx_Base> san = loader.createInstance("dbx_plugins_ns::SanBian");
    san->init(10);
    double length1 = san->getlength();
    ROS_INFO("Sanjiaoxing: %.2f",length1);

    boost::shared_ptr<dbx_base_ns::Dbx_Base> si = loader.createInstance("dbx_plugins_ns::SiBian");
    si->init(10);
    double length2 = si->getlength();
    ROS_INFO("Sanjiaoxing: %.2f",length2);
    
    return 0;
}
