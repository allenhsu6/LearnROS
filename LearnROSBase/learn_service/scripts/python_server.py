#!/usr/bin/env python
# coding:utf-8

import rospy
from learn_service.srv import *

def callback_func(req):
    answer = req.a*req.b
    rospy.loginfo("result is %f", answer)
    return multinumResponse(answer)


def server():
    rospy.init_node("python_server")
    s = rospy.Service("multi_2num",multinum,callback_func)
    
    rospy.loginfo("Waiting 2 numbers...")
    rospy.spin()

if __name__=="__main__":
    server()