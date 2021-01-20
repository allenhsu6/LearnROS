//
// Created by xu on 2021/1/8.
//

#include <ros/ros.h>
#include <learn_topic/person.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "cpp_talker");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<learn_topic::person>("person_topic", 1);

    ros::Rate loop_rate(1);

    learn_topic::person man;
    man.age = 0;
    man.name = "allen";
    ROS_INFO("pub: Here's a man named, how old is he? %s", man.name.data());
    while (ros::ok()){
        man.age++;
        pub.publish(man);
        loop_rate.sleep();
    }
    return 0;
}