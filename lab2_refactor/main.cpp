#include <iostream>
#include <string>
#include "Containers.hpp"

using namespace std;

int main(){
    
    Container <int> number, number2;

    Container <char> character('a');

    number.set_data(3);
    number2.set_data(6);
    number2.copy(number);
    number2.show_data();
    number.show_data();
    number.set_data();
    number.show_data();
    character.show_data();
    character.set_data();
    character.show_data();
    character.get_data_type();
    number.get_data_type();
    Container <float> f(1.98);
    Container <double> d(1.1);
    Container <bool> b(1);
    b.show_data();
    b.get_data_type();
    f.show_data();
    d.show_data();
    f.get_data_type();
    d.get_data_type();

    int inp_d[] = {1, 2, 3, 4, 5};
    ArrayContainer <int> int_arr(5, inp_d);
    int_arr.at(3).show_data();
    int_arr.show_data();
    ArrayContainer <char> char_arr(5, 'a', 'n', 'a', 'e', 'c');
    char char_inp_d[] = {'a', 'n', 'a', 'e', 'c'};
    ArrayContainer <char> char_arr2(5, char_inp_d);
    char_arr2.show_data(); 
    char_arr.check_size(); 
    char_arr.show_data(); 
    ArrayContainer <int> int_arr2(5, 1, 2, 3, 4, 5);
    char_arr.at(3).show_data(); 
    int_arr.at(2).show_data();
    int_arr.check_size();
    int_arr.show_data();
    
    int_arr2.show_data();
    ArrayContainer <bool> bool_arr(3, true, false, true);
    bool_arr.show_data();

    int_arr.resize(10);

    ArrayContainer <bool> arr(5, true);
    arr.show_data();

    arr.get_data_type();
    ArrayContainer <bool> bool_arr2(2, false, true);
    arr.copy(bool_arr2);
    arr.show_data();

    return 1;
}
// c-char i-int b-bool f-float d-double 