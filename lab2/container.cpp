#include "container.h"
#include "stdarg.h"
using namespace std;

Container::Container(){}

Container::~Container(){}

ArrayContainer::ArrayContainer(){}
ArrayContainer::~ArrayContainer(){}

// for bool objects

BoolContainer::BoolContainer(){}

BoolContainer::BoolContainer(bool value): data(value){}

BoolContainer::~BoolContainer(){}

void BoolContainer::setValue(){
    bool input;
    scanf("%d", &input);
    data = input;
}

void BoolContainer::showValue(){
    if (data) cout << "Stored data: true" << endl;
    else cout << "Stored data: false" << endl;
}

void BoolContainer::showType(){
    cout << "Type: bool" << endl;
}

void BoolContainer::setValue(bool value){
    data = value;
}

void BoolContainer::copyValue(const BoolContainer obj){
    data = obj.data;
}

// for int objects

IntContainer::IntContainer(){}

IntContainer::IntContainer(int value): data(value){}

IntContainer::~IntContainer(){}

void IntContainer::showValue(){
    cout << "Stored data: " << data << endl;
}

void IntContainer::setValue(){
    int input;
    scanf("%d", &input);
    data = input;
}

void IntContainer::setValue(int value){
    data = value;
}

void IntContainer::showType(){
    cout << "Type: int" << endl;
}

void IntContainer::copyValue(const IntContainer obj){
    data = obj.data;
}

// for char objects

CharContainer::CharContainer(){}

CharContainer::CharContainer(char value): data(value){}
CharContainer::~CharContainer(){}

void CharContainer::showValue() {
    cout << "Stored data: " << data << endl;
}

void CharContainer::setValue(){
    char input;
    scanf("%c", &input);
    data = input;
}

void CharContainer::setValue(char value){
    data = value;
}

void CharContainer::showType(){
    cout << "Type: char" << endl;
}

void CharContainer::copyValue(const CharContainer obj){
    data = obj.data;
}

// for float objects

FloatContainer::FloatContainer(){}

FloatContainer::FloatContainer(float value){
    data = value;
}

FloatContainer::~FloatContainer(){}

void FloatContainer::showValue(){
    cout << "Stored data: " << data << endl;
}

void FloatContainer::setValue(){
    float input;
    scanf("%f", &input);
    data = input;
}

void FloatContainer::setValue(float value){
    data = value;
}

void FloatContainer::showType(){
    cout << "Type: float" << endl;
}

void FloatContainer::copyValue(const FloatContainer obj){
    data = obj.data;
}

// for double objects

DoubleContainer::DoubleContainer(){}

DoubleContainer::DoubleContainer(double value): data(value){}
DoubleContainer::~DoubleContainer(){}

void DoubleContainer::showValue(){
    cout << "Stored data: " << data << endl;
}

void DoubleContainer::setValue(){
    double input;
    scanf("%lf", &input);
    data = input;
}

void DoubleContainer::setValue(double value){
    data = value;
}

void DoubleContainer::showType(){
    cout << "Type: double" << endl;
}

void DoubleContainer::copyValue(const DoubleContainer obj){
    data = obj.data;
}

// for int array objects

IntArrayContainer::IntArrayContainer(){}

IntArrayContainer::IntArrayContainer(int count, ...){
    data = (int*) malloc(count * sizeof(int));
    size = count;
    va_list arguments;
    va_start(arguments, count);
   
    int a = va_arg(arguments, int);
    for (int i = 0; i <= count; i++){
        data[i] = a;
        a = va_arg(arguments, int);
    }
    va_end(arguments);
}

IntArrayContainer::~IntArrayContainer(){}

void IntArrayContainer::showValue(){
    cout << "Stored elements: ";
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void IntArrayContainer::setValue() {
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++){
        scanf("%d", &data[i]);
    }
}

void IntArrayContainer::showType() {
    cout << "Type: int["<< size << "]" << endl;
} 

void IntArrayContainer::setSize(int value) {
    int* arr = (int*) malloc(value * sizeof(int));
    
    if (value > size) {
        for (int i = 0; i < value; i++){
            if (i < size){
                arr[i] = data[i];
            }
            else{
                arr[i] = 0;
            }
        }
        data = arr;
    }
    else{
        for (int i = 0; i < value; i++){
            arr[i] = data[i];
        }
        data = arr;
    }
    size = value;
    }
   
IntContainer IntArrayContainer::getIndex(int value) {
    IntContainer returned(data[value]);
    return returned;
}
 
CharArrayContainer::CharArrayContainer(){}

CharArrayContainer::CharArrayContainer(int count, ...)
{
    data = (char*) malloc(count * sizeof(char));
    size = count;
    va_list arguments;
    va_start(arguments, count);

    char a = va_arg(arguments, int);
    for (int i = 0; i <= count; i++){
        data[i] = a;
        a = va_arg(arguments, int);
    }
    va_end(arguments);
}

CharArrayContainer::~CharArrayContainer(){}

void CharArrayContainer::showValue() {
    for (int i = 0; i < size; i++){
        cout << data[i] << ",";
    }
    cout << endl;
}

void CharArrayContainer::setValue() {
    for (int i = 0; i < size; i++){
        scanf("%c", &data[i]);
    }
    cout << endl;
}

void CharArrayContainer::showType() {
    cout << "Type: char[" << size << "]" << endl;
}

void CharArrayContainer::setSize(int value) {
    char* arr = (char*) malloc(value * sizeof(char));
    if (value > size) {
        for (int i = 0; i < value; i++){
            if (i < size){
                arr[i] = data[i];
            }
            else{
                arr[i] = 0;
            }
        }
        data = arr;
    }
    else
    {
        for (int i = 0; i < value; i++){
            arr[i] = data[i];
        }
        data = arr;
    }
    size = value;
}

CharContainer CharArrayContainer::getIndex(int value) {
    CharContainer returned(data[value]);
    return returned;
}

FloatArrayContainer::FloatArrayContainer(){}

FloatArrayContainer::FloatArrayContainer(int count, ...)
{
    data = (float*) malloc(count * sizeof(float));
    size = count;
    va_list arguments;
    va_start(arguments, count);
    for (int i = 0; i < count; i++)
    {
        float a = va_arg(arguments, double); // Use double as va_arg requires a type
        data[i] = a;
    }
    va_end(arguments);
}

FloatArrayContainer::~FloatArrayContainer(){}

void FloatArrayContainer::showValue() {
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ",";
    }
    cout << endl;
}

void FloatArrayContainer::setValue() {
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &data[i]);
    }
    cout << endl;
}

void FloatArrayContainer::showType() {
    cout << "Type: float[" << size << "]" << endl;
}

void FloatArrayContainer::setSize(int value) {
    float* arr = (float*) malloc(value * sizeof(float));

    if (value > size) {
        for (int i = 0; i < value; i++)
        {
            if (i < size){
                arr[i] = data[i];
            }
            else {
                arr[i] = 0;
            }
        }
        data = arr;
    }
    else{
        for (int i = 0; i < value; i++){
            arr[i] = data[i];
        }
        data = arr;
    }
    size = value;
}

FloatContainer FloatArrayContainer::getIndex(int value) {
    FloatContainer returned(data[value]);
    return returned;
}

DoubleArrayContainer::DoubleArrayContainer(){}

DoubleArrayContainer::DoubleArrayContainer(int count, ...)
{
    data = (double*) malloc(count * sizeof(double));
    size = count;
    va_list arguments;
    va_start(arguments, count);
    for (int i = 0; i < count; i++)
    {
        float a = va_arg(arguments, double); // Use double as va_arg requires a type
        data[i] = a;
    }
    va_end(arguments);
}

DoubleArrayContainer::~DoubleArrayContainer(){}

void DoubleArrayContainer::showValue() {
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ",";
    }
    cout << endl;
}

void DoubleArrayContainer::setValue() {
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }
    cout << endl;
}

void DoubleArrayContainer::showType() {
    cout << "Type: double[" << size << "]" << endl;
}

void DoubleArrayContainer::setSize(int value) {
    double* arr = (double*) malloc(value * sizeof(double));

    if (value > size) {
        for (int i = 0; i < value; i++)
        {
            if (i < size){
                arr[i] = data[i];
            }
            else {
                arr[i] = 0;
            }
        }
        data = arr;
    }
    else{
        for (int i = 0; i < value; i++){
            arr[i] = data[i];
        }
        data = arr;
    }
    size = value;
}

DoubleContainer DoubleArrayContainer::getIndex(int value) {
    DoubleContainer returned(data[value]);
    return returned;
}