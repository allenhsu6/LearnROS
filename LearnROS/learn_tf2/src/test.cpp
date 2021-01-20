//
// Created by xu on 2021/1/16.
//
#include <ros/ros.h>
#include <tf/LinearMath/Quaternion.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <turtlesim/Pose.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "test");
    tf::StampedTransform transform;
    tf::TransformListener listener;
    listener.waitForTransform("turtle2", "turtle1", ros::Time(0), ros::Duration(30));

    ros::Rate rate(1);
    while (ros::ok()){
        // in the turtle2 frame, the coordinate of turtle1;
        listener.lookupTransform("turtle2", "turtle1", ros::Time(0), transform);
        rate.sleep();
        std::cout << transform.getOrigin().x() << std::endl;
    }

    return 0;
}