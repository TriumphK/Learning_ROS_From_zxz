#! /usr/bin/env python

import rospy
from plumbing_pub_sub.msg import Person

def doPerson(p):
    rospy.loginfo("Recevied: %s,%d,%.2f", p.name,p.age,p.height)

if __name__ == "__main__":
    rospy.init_node("daYe")
    sub = rospy.Subscriber("tan",Person,doPerson,queue_size=10)
    rospy.spin()
