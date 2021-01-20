//
// Created by xu on 2021/1/15.
//


#include <ros/ros.h>
#include <ros/param.h>

int main(int argc, char **argv) {
    std::string global_name, local_name("default_local_name"), private_name("default_private_name");

    ros::init(argc, argv, "node_name");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");

    nh.setParam("local_nh_set", "local_name");
    if(nh.hasParam("local_nh_set")){
        std::cout << "local_nh_set is ok! " <<std::endl;
    }
    nh.setParam("/global_nh_set", "global_name");

   private_nh.setParam("local_pri_nh_set", "pri_local_name");
    if(nh.hasParam("/namespace/node_name/local_pri_nh_set")){
        std::cout << "local_pri_nh_set is ok! " <<std::endl;
    }
    if (nh.hasParam("local_pri_nh_set")){
        std::cout << "local_pri_nh_set: also can get by nh" <<std::endl;
    }else{
        std::cout << "local_pri_nh_set: can not get by nh" <<std::endl;
    }

    private_nh.setParam("/global_pri_nh_set", "pri_global_name");


    nh.getParam("/a_string", global_name);
    if (nh.hasParam("/namespace/node_name/a_string")){
        std::cout << "global_nh can get private param by global_parse" <<std::endl;
        nh.getParam("/namespace/node_name/a_string", local_name);
    }


    private_nh.param("a_string", private_name, private_name);

    std::cout << "global_name: " << global_name << std::endl;
    std::cout << "local_name: " << local_name << std::endl;
    std::cout << "private_name: " << private_name << std::endl;


    ros::spin();
    return 0;
}