#!/usr/bin/env python
#coding=utf-8
import rospy
import rosparam
import os
def param_get():
    global_name = rospy.get_param("a_string")
    private_param = rospy.get_param('~private_int')
    default_param = rospy.get_param('list_of_floats', '[1., 2., 3.]')
    # fetch a group (dictionary) of parameters
    gains = rospy.get_param('gains')
    p, i, d = gains['p'], gains['i'], gains['d']

    return 0

def param_set_by_rospy():
    # Using rospy and raw python objects
    rospy.set_param('a_string', 'by_rospy')
    rospy.set_param('~private_int', 2)
    rospy.set_param('list_of_floats', [1., 2., 3., 4.])
    rospy.set_param('bool_True', True)
    rospy.set_param('gains', {'p': 1, 'i': 2, 'd': 3})


def param_set_by_rosparam():
    # Using rosparam and yaml strings
    rosparam.set_param('a_string', 'by_rosparam')
    rosparam.set_param('~private_int', '100')
    rosparam.set_param('list_of_floats', "[1., 2., 3., 4.]")
    rosparam.set_param('bool_True', "true")
    rosparam.set_param('gains', "{'p': 1, 'i': 2, 'd': 3}")

def param_existence_by_rospy(param_name):
    if (rospy.has_param(param_name)):
        rospy.delete_param(param_name)


def param_existence_by_rosparam(param_name):
    try:
        rospy.delete_param(param_name)
    except KeyError:
        print ("value not set")


if __name__ == '__main__':
    rospy.init_node("rosparam_python_node")
    param_set_by_rospy()
    param_get()