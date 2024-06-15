#ifndef Containers_hpp
#define Containers_hpp
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

// class BaseContainer{
// public:
//     BaseContainer(){}
//     ~BaseContainer(){}
//     virtual void show_data();
//     virtual void get_data_type();
//     virtual void set_data();
// };

// class BaseArrayContainer: public BaseContainer{
// public:
//     BaseArrayContainer(){}
//     ~BaseArrayContainer(){}
//     virtual void resize(int newSize);
// };

template <typename TYPE>

class Container{

private:
    TYPE data;
public:
    Container(){}
    Container(TYPE input) {
        data = input;
    }
    void set_data(TYPE input) {
        data = input;
    }
    void set_data(){
        cout << "Input data: ";
        cin >> data;
    }
    void show_data()  {
        cout << "Stored data: " << data << endl;
    }
    TYPE get_data() {
        return data;
    }
    void copy(const Container <TYPE> Container){
        data = Container.data;
    }
    void get_data_type()  {
        char type = typeid(data).name()[0];
        string type_name;
        switch (type) {
        case 'i':
            type_name = "int";
            break;
        case 'd':
            type_name = "double";
            break;
        case 'c':
            type_name = "char";
            break;
        case 'b':
            type_name = "bool";
            break;
        case 'f':
            type_name = "float";
            break;
        default:
            type_name = "undefined";
            break;
        };
        cout << "Type: " << type_name << endl;
    }
};

template <typename TYPE>

class ArrayContainer{
private:
    TYPE * data;
    int size;
public:
    ArrayContainer(){}
    ArrayContainer(int input_size, TYPE * input_data) : size(input_size), data(input_data){}
    ArrayContainer(int input_size, TYPE input_data) : size(input_size){
        data = new TYPE[size];
        for (int index = 0; index < size; index++){
            data[index] = input_data;
        }
    }
    ArrayContainer(int input_size, ...) {
        size = input_size;
        data = new TYPE[size];
        va_list arguments;
        va_start(arguments, input_size);

        for (size_t index = 0; index < size; index++) {
            if (typeid(TYPE) == typeid(char)) {
                data[index] = static_cast <TYPE> (va_arg(arguments, int));
            } else if (typeid(TYPE) == typeid(bool)) {
                data[index] = static_cast <TYPE> (va_arg(arguments, int));
            }
            else{
                data[index] = va_arg(arguments, TYPE);
            }   
        }
        va_end(arguments);
    }

    ~ArrayContainer(){
        delete[] data;
    }

    Container <TYPE> at(int index){
        Container <TYPE> returned(data[index]);
        return returned;
    }

    void check_size(){
        cout << "Array size: " << size << endl;
    }

    void show_data() {    
        for (int i = 0; i < size; i++) {
            if (typeid(TYPE) == typeid(bool)){
                if (data[i] == 1) cout << "true ";
                else cout << "false ";
                continue;
            }
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void get_data_type(){
        Container <TYPE> returned(data[0]);
        returned.get_data_type();
    }

    void copy(const ArrayContainer <TYPE> Array){
        size = Array.size;
        data = Array.data;
    }

    void resize(int newSize) {
    TYPE *newData = new TYPE[newSize];

    for (int index = 0; index < newSize; index++) {
        if (index >= size) {
            if (typeid(TYPE) == typeid(char)) {
                newData[index] = '\0';
            } else {
                newData[index] = 0;
            }
        } else {
            newData[index] = data[index];
        }
    }
    data = newData;
    size = newSize;
    }
};

#endif