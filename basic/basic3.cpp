//
//  basic3.cpp
//  basic
//
//  Created by KENAN YANG on 21/6/18.
//  Copyright © 2018 KENAN YANG. All rights reserved.
//

//revision of c++ object part

#include "basic3.hpp"
/*
 class basic
    public, private, protected
 */

class Box {
public://Can be accessed from anywhere
    double length;
    double breadth;
    double height;
    double getVolume(void){//functions defined in the class are all inline functions
        return length*breadth*height;
    }
    double getHalfVolume(void);
    void setWidth(double wid);
    double getWidth(void);
    
private: //default case, can only be accessed by class itself and friend functions
    double width;
    
protected: // can be accessed from child class as well, access(private)+child class
    double protectedMember1;
};


class smallBox:Box{
public:
    void setProtectedValueinBox(double p);
    double getProtectedValueinBox(void);
};

void smallBox::setProtectedValueinBox(double p){
    protectedMember1 = p;
}
double smallBox::getProtectedValueinBox(){
    return protectedMember1;
}

double Box::getHalfVolume(){
    return 1.0/2*length*breadth*height;
}

void Box::setWidth(double wid){
    width = wid;
}
double Box::getWidth(){
    return width;
}

/*
    contruct function and destruct function of class
 */
class Line{
public:
    void setLength(double len);
    double getLength(void);
    double getWidth(void);
    Line(); //contruct function **contructor cannot have a return type**
    Line(double len);
    Line(double len, double wid);
    ~Line();//destructor, which cannot have a return type, as well as cannot have any parameters.
private:
    double length;
    double width;
};

Line::Line(void){
    cout<<"Object has been created"<<endl;
}

Line::Line(double len){
    cout<<"Object has been created"<<endl;
    length = len;
}
//Use the initialize words to construct:
Line::Line(double len, double wid): length(len),width(wid){
    cout<<"Object has been created"<<endl;
}
Line::~Line(){
    cout<<"Object has been delete"<<endl;
}

void Line::setLength(double len){
    length = len;
}
double Line::getLength(){
    return length;
}
double Line::getWidth(){
    return width;
}

int Basic3::basic(){
    
    Box Box1;
    double volume = 0.0;
    
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;
    
    volume = Box1.breadth*Box1.height*Box1.length;
    cout<<"the volume of Box1 is: "<<volume<<endl;
    
    cout<< Box1.getHalfVolume()<<endl;
    //Box1.width = 10; ==>Error, because width is a private member
    Box1.setWidth(10);
    cout<<Box1.getWidth()<<endl;
    
    smallBox boxsmall;
    boxsmall.setProtectedValueinBox(6);
    cout<<"the protected member in Box has been set to: "<<boxsmall.getProtectedValueinBox()<<endl;
    
    
    Line line;
    line.setLength(5.0);
    cout<<"Length of the line is: "<<line.getLength()<<endl;
    Line line2(4.5);
    cout<<"Length of the line2 is: "<<line2.getLength()<<endl;
    Line line3(5.5, 6);
    cout<<"Length of the line3 is: "<<line3.getLength()<< " Width of the line3 is: "<< line3.getWidth()<<endl;
    
    return 0;
}

