#!/usr/bin/env python
# coding:utf-8

import rospy
from learn_service.srv import *
import random

def client():
    rospy.init_node("python_client")
    #rospy.wait_for_service("multi_2num")
    try:
        c = rospy.ServiceProxy("multi_2num",multinum)
        a = random.random() * 100
        b = random.random() * 100
        response = c.call(multinumRequest(a,b))

        rospy.loginfo("%f * %f = %f", a, b, response.c)
    except rospy.ServiceException, e:
        rospy.logerr("service call failed: %s", e)

if __name__=="__main__":
    client()