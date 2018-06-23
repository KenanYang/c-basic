//
//  basic4.cpp
//  basic
//
//  Created by KENAN YANG on 23/6/18.
//  Copyright © 2018 KENAN YANG. All rights reserved.
//

#include "basic4.hpp"
// general programming
// template

// template functions
//template <template parameters>
//return_types function_name(function parameters) {
//    statements
//}

template <typename T>
inline T Max(T const& a, T const& b){
    return a < b? b:a;
}
// template class
//template <template parameters>
//class class_name {
//    instance_member
//
//public:
//    member_function
//};

template <class T> //class and typename are kind of same
class Stack{
private:
    vector<T> elems;
public:
    void push(T const&);
    void pop();
    bool empty();
    T top();
};

template <class T>
void Stack<T>::push(T const& elem){
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if (elems.empty()){
        throw out_of_range("empty stack");
    }
    elems.pop_back();
}

template <class T>
bool Stack<T>::empty(){
    return elems.empty();
}

template <class T>
T Stack<T>::top(){
    if (elems.empty()){
        throw out_of_range("empty stack");
    }
    return elems.back();
}

int Basic4::basic(){
    int i = 10, j = 20;
    double x = 1.1, y = 2.2;
    
    cout<< Max(i,j)<<endl;
    cout<< Max(x,y)<<endl;
    
    try{
        Stack<int>  intStack;
        intStack.push(2);
        cout << intStack.top() <<endl;
        intStack.pop();
        cout << intStack.top() <<endl;
        
    }
    catch(exception const& ex){
        cerr<<"Exception: "<<ex.what()<<endl;
        return -1;
    }
    
    return 0;
}
