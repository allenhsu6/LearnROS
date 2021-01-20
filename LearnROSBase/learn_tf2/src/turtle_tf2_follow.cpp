//
// Created by xu on 2021/1/15.
//

#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <geometry_msgs/Twist.h>
int main(int argc, char** argv){

    ros::init(argc, argv, "follower");
    // client
    ros::NodeHandle nh("~");
    ros::service::waitForService("/spawn");
    ros::ServiceClient turtle_client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn spawn;
    spawn.request.name = "turtle2";
    spawn.request.x = 2;
    spawn.request.y = 2;
    turtle_client.call(spawn);

    ros::Publisher turtle2_pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    double scale_linear, scale_angular;
    nh.param("scale_linear", scale_linear, 2.0);
    nh.param("scale_angular", scale_angular, 2.0);

    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate rate(10);
    while (ros::ok()){
        geometry_msgs::Twist cmd_vel;
        // tf2 listener: turtle2 to turtle1
        geometry_msgs::TransformStamped transformStamped, transformStamped1;
        try{
            // T_turtle2_turtle1
            ros::Time now = ros::Time::now();
            ros::Time past = ros::Time::now() - ros::Duration(5.0);
//            transformStamped = tfBuffer.lookupTransform("turtle2", "turtle1", past, ros::Duration(1.0));
//            std::cout << "time(0): " << ros::Time(0) << "\ntime::now() " << ros::Time::now() << std::endl;
            transformStamped = tfBuffer.lookupTransform("turtle2",ros::Time(0),"turtle1",past,"world", ros::Duration(5.0));
        }catch (tf2::TransformException &exception){
            ROS_WARN("wait tf tree:  %s",exception.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        // std::cout << transformStamped1.transform.translation.x << std::endl;
        cmd_vel.angular.z = 4 * atan2(transformStamped.transform.translation.y,
                                        transformStamped.transform.translation.x);
        cmd_vel.linear.x = 0.5 * sqrt(pow(transformStamped.transform.translation.x, 2) +
                                      pow(transformStamped.transform.translation.y, 2));
        turtle2_pub.publish(cmd_vel);

        rate.sleep();
    }
    return 0;
}