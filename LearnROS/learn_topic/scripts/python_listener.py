#!/usr/bin/env python
#coding=utf-8
import rospy
#倒入自定义的数据类型
from learn_topic.msg import person

def callback(person):
    rospy.loginfo('Listener: %s''s age is %d', person.name, person.age)

def listener():
    rospy.init_node('pylistener', anonymous=True)
    rospy.Subscriber('person_topic', person, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()

