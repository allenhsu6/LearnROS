//
// Created by xu on 2021/1/9.
//

#include <ros/ros.h>
#include <learn_service/multinum.h>
#include<cstdlib>
#include <time.h>
int main(int argc, char **argv){
    srand(int(time(0)));
    double a = rand()/(double(RAND_MAX)/100);
    double b = rand()/(double(RAND_MAX)/100);
    ros::init(argc, argv, "multi_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<learn_service::multinum>("multi_two_num");

    learn_service::multinum srv;
    srv.request.a = a;
    srv.request.b = b;

    if (client.call(srv)){
        ROS_INFO("%f * %f = %f", a, b, srv.response.c);
    }else{
        ROS_ERROR("Failed to call service");
    }
    return 0;
}




