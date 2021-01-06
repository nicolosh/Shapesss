//
// Created by nicol on 05/01/2021.
//

#ifndef POLYMORPHICSHAPES_SHAPESSS_H
#define POLYMORPHICSHAPES_SHAPESSS_H


#include <string>
#include <iostream>

class Shapesss {
protected:
    double width_, height_;
    //std::string name_;

public:
    explicit Shapesss(double width = 0, double height = 0) : width_(width), height_(height) {}

    virtual double computeArea() const = 0;

    virtual void tellMeWhoIam() const{
        std::cout << "Shape: ";
    };

    virtual ~Shapesss() = default; // virtual  ~Shapesss() {}

    void setWidth(double w) { width_ = w; }

    void setHeight(double h) { height_ = h; }
};

class Rectangle : public Shapesss {
public:
    Rectangle(double width, double height) : Shapesss(width, height) {}

    virtual double computeArea() const override {
        return width_ * height_;
    };

    virtual void tellMeWhoIam() const override {
        Shapesss::tellMeWhoIam();
        std::cout << "Rectangle";
    }

};


class Triangle : public Shapesss {
public:
    Triangle(double width, double height) : Shapesss(width, height) {}

    virtual double computeArea() const override {
        return height_ * width_ * 0.5;
    }

    virtual void tellMeWhoIam() const override {
        Shapesss::tellMeWhoIam();
        std::cout << "Triangle";
    };
};


class Circle : public Shapesss {
private:
    double radius_;
public:
    Circle(double radius) : radius_(radius), Shapesss(0.0,0.0) {}

    virtual double computeArea() const override {
        return radius_ * radius_ * 3.1415f;
    }

    virtual void tellMeWhoIam() const override {
        Shapesss::tellMeWhoIam();
        std::cout << "Circle";
    };

    //double getRadius() const { return radius_; }
};


#endif //POLYMORPHICSHAPES_SHAPESSS_H
