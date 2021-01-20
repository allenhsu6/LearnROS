//
// Created by xu on 2021/1/9.
//

#include <ros/ros.h>
#include <learn_service/multinum.h>


bool multi_callback(learn_service::multinum::Request &req, learn_service::multinum::Response &res){
    res.c = req.a * req.b;
    ROS_INFO("computing result is %f", res.c);
    return true;
}


int main(int argc, char **argv){


    ros::init(argc, argv, "multi_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("multi_two_num",multi_callback);
    ROS_INFO("waiting two numbers...");
    ros::spin();
    return 0;
}




