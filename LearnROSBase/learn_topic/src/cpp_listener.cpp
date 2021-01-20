//
// Created by xu on 2021/1/8.
//
#include <ros/ros.h>
#include "learn_topic/person.h"

void getAgeCallback(const learn_topic::personConstPtr &person){

    ROS_INFO("answer: %s's age is %d", person->name.data(), person->age);
}

int main(int argc, char **argv){

    ros::init(argc, argv, "cpp_listener");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/person_topic",1, getAgeCallback);
    ros::spin();
    return 0;
}