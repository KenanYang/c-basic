//
//  basic1.cpp
//  basic
//
//  Created by KENAN YANG on 21/6/18.
//  Copyright © 2018 KENAN YANG. All rights reserved.
//

#include "basic1.hpp"

typedef int inch;

#define PI 3.14



//function declaration
float func();

//variable declaration
extern inch x; //variable can be declared multiple times but can only be defined once.

int Basic1::basic() {
    //    // insert code here...
    //    std::cout << "Hello, World!\n";
    
    // enum
    enum color {red, green = 5, blue} c;//variable define
    c = blue;//varible initialization
    cout << c<<endl;
    inch x = 5;
    cout << x <<endl;
    color a,b;
    b = red;
    a = green;
    cout<<b<<endl;
    
    float fn = func();
    cout<< fn << endl;
    const int ci = 5;//#define and const are two ways to declare constant variables.
    cout<< ci <<endl;
    
    // auto, regsiter, static, extern, mutable
    /*
     'auto' is the default store type for local varibles
     'register' will put variable stored in register rather than RAM, which means it usually only a byte learge and cannot do & calculation (it has no RAM location).
     'static' can set a variable only use one reference location
     'extern' means find variables declaration in other files.
     'mutable'
     */
    
    //
    static int count = 3;
    while (count){
        cout << --count <<endl; //-> 2 1 0, but with count--, it is 3 2 1
    }
    int count1 = 0;
    while (count1){
        cout << "int = 0 also true"<<endl;
        break;
    }
    
    int cy1 = 0, cy2;
    cy2 = cy1;
    cy2 = 2;
    cout << cy1 << endl;
    
    return 0;
}

float func(){
    return PI;
}
