//
//  basic2.cpp
//  basic
//
//  Created by KENAN YANG on 21/6/18.
//  Copyright © 2018 KENAN YANG. All rights reserved.
//

#include "basic2.hpp"



/*
 switch(expression){    //expression can only be one of following type: int, enum or an int class
 case constant-expression1 :
    statement1;
    break;
 case constant-expression2 :
    statement2;
    break;
 
//
 default:
    statement_last;
 }
 */
int add(int num1, int num2);
char * myfunction();
string * myfunction2();

double vals[] = {1.1, 3.9, 4.55};
double & setValues(int i);


int Basic2::basic(){
    cout << add(1,2) <<endl;
    int array1[2][3] = {{1,2,3},{4,5,6}};
    int* ptr_array1;
    ptr_array1 = array1[1];
    
    cout<< *ptr_array1<<endl;
    
    /*
     c++ can only return a pointer from functions but not array.
     any local variable addresses cannot be returned, unless it is declared as static
     */
    cout<<*myfunction()<<endl;
    cout<<*(myfunction()+2)<<endl;
    cout<<*(myfunction2()+1)<<endl;
    
    /*
     the name of an array is a pointer constant which points to the address of the first element in that array
     e.g. int var[2] = {1,2};
     *var = 3; ==> var = {3,2}
     *var++; ==> invalid, var is a constant
     */
    
    /*
     we can use a char pointer array to store a list of strings
     */
    char * test[2]={ "world","hello"};
    cout<< test[0]<<" and "<<test[1]<<endl;
    
    // **pptr is the pointer points to a pointer.
    int var;
    int *ptr;
    int **pptr;
    var = 100;
    ptr = &var;
    pptr = &ptr;
    cout<< var <<endl;
    cout<< *ptr <<endl;
    cout<< **pptr <<endl;
    //REFERENCE
    int i;
    double d;
    int &r = i;
    double & s = d;
    i = 17;
    s = 3.333;
    cout << "Value of i: "<<i<< " Value of i reference (r):"<<r<<endl;
    cout << "Value of d: "<<d<< " Value of d reference (s):"<<s<<endl;
    
    // c++ can return a reference through functions, but local variable cannot be returned as reference, only if it is static.
    
    setValues(0) = 666;
    cout<<*vals<<endl;
    cout<<setValues(1)<<endl;
    
    return 0;
}

int add(int num1, int num2){
    return num1+num2;
}
char * myfunction(){
    static char r[] = "red";
    return r;
}

string * myfunction2(){
    static string s1[2]= {"green","blue"};
    return &s1[0];
}
double & setValues(int i){
    return vals[i];
}



