
#ifndef SRC_POLYGON_BASE_H
#define SRC_POLYGON_BASE_H

namespace polygon_base{

class RegularPolygon{

public:

    virtual void initialize(double side_length) = 0;

    virtual double area() = 0;
    virtual ~RegularPolygon(){}

protected:
    RegularPolygon(){}

};

}

#endif //SRC_POLYGON_BASE_H