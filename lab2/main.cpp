#include "container.cpp"
#include "stdarg.h"

int main(){
    
    BoolContainer bool_val(true);
    bool_val.showValue();
    bool_val.showType();
    bool_val.setValue(false);
    bool_val.showValue();

    BoolContainer bool_val2(false);
    bool_val2.showValue();
    bool_val2.showType();
    bool_val2.copyValue(bool_val);
    bool_val2.showValue();

    IntContainer int_val(51);
    int_val.showType();
    int_val.showValue();
    int_val.setValue(14);
    int_val.showValue();

    CharContainer char_val('a');
    char_val.showType();
    char_val.showValue();
    char_val.setValue('$');
    char_val.showValue();

    FloatContainer float_val(5.924);
    float_val.showType();
    float_val.showValue();
    float_val.setValue(3.14);
    float_val.showValue();

    DoubleContainer double_val(2.314);
    double_val.showType();
    double_val.showValue();
    double_val.setValue(30.10004);
    double_val.showValue();

    // ----------- ARRAYS -------------

    IntArrayContainer int_arr(5, 1, 2, 3, 4, 5);
    int_arr.showValue();
    int_arr.setSize(10);
    int_arr.showValue();
    int_arr.setValue();
    int_arr.showValue();
    int_arr.showType();

    CharArrayContainer char_arr(5, 'a', 'b', 'c', 'd', 'e');
    char_arr.showValue();
    char_arr.setSize(10);
    char_arr.showValue();
    char_arr.setValue();
    char_arr.showValue();
    char_arr.showType();


    return 1;
}