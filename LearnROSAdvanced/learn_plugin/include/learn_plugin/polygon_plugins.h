//
// Created by xu on 2021/1/11.
//

#ifndef SRC_POLYGON_PLUGINS_H
#define SRC_POLYGON_PLUGINS_H

#include <learn_plugin/polygon_base.h>
#include <cmath>

namespace polygon_plugins{

class Triangle: public polygon_base::RegularPolygon
{
public:
    // cnstructor
    Triangle(): side_length_() {}


    void initialize(double side_length){
        side_length_ = side_length;
    }

    double area(){
        return 0.5 * side_length_ * getHight();
    }

    double getHight(){
        return sqrt((side_length_ * side_length_) - ((side_length_/2) * (side_length_/2)));
    }

private:
    double side_length_;
};


class Square : public polygon_base::RegularPolygon
{
public:

    Square():side_length_(){}

    void initialize(double side_length){
        side_length_ = side_length;
    }

    double area(){
        return side_length_ * side_length_;
    }

private:
    double side_length_;
};

}

#endif //SRC_POLYGON_PLUGINS_H
