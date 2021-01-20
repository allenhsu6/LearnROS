//
// Created by xu on 2021/1/16.
//
#include <ros/ros.h>

using namespace std;
int main(int argc, char **argv) {

    ros::init(argc, argv, "test");
    ros::NodeHandle n;
    ros::Time begin = ros::Time::now(); //获取当前时间
    ros::Time at_some_time1(5,20000000);  //5.2s
    ros::Time at_some_time2(5.2); //同上，重载了float类型和两个uint类型的构造函数
    ros::Duration one_hour(60*60,0); //1h

    double secs1 = at_some_time1.toSec();//将Time转为double型时间
    double secs2 = one_hour.toSec();//将Duration转为double型时间 s unit

    cout << secs1 << endl;
    cout << secs2 << endl;
    cout << "============ add / sub ============" << endl;

    ros::Time t1 = ros::Time::now() - ros::Duration(5.5); //t1是5.5s前的时刻，Time加减Duration返回都是Time
    ros::Time t2 = ros::Time::now() + ros::Duration(3.3);//t2是当前时刻往后推3.3s的时刻
    ros::Duration d1 = t2 - t1;//从t1到t2的时长，两个Time相减返回Duration类型
    ros::Duration d2 = d1 -ros::Duration(0,300);//两个Duration相减，还是Duration

    cout << t1 << endl; // time type can be output directly


    cout << "===========sleep=============" << endl;

    ros::Duration(0.5).sleep(); //用Duration对象的sleep方法休眠

    ros::Rate r(10); //10HZ
    while(ros::ok())
    {
        r.sleep();
        //定义好sleep的频率，Rate对象会自动让整个循环以10hz休眠，即使有任务执行占用了时间
    }

    cout << "===========timer=============" << endl;

//    ros::Timer timer1 = n.createTimer(ros::Duration(0.1), callback1);  //timer1每0.1s触发一次callback1函数
//    ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2);  //timer2每1.0s触发一次callback2函数

    ros::spin();  //千万别忘了spin，只有spin了才能真正去触发回调函数

    return 0;
}