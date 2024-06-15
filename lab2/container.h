#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class Container{
public:
    Container();
    virtual ~Container();
    virtual void setValue(){};
    virtual void showValue(){};
    virtual void showType(){};
};

class CharContainer : public Container{
private:
    char data;
public:
    CharContainer();
    CharContainer(char value);
    ~CharContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setValue(char value);
};


class BoolContainer : public Container{
private:
    bool data;
public:
    BoolContainer();
    BoolContainer(bool value);
    ~BoolContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setValue(bool value);
    void copyValue(const BoolContainer obj);
};

class IntContainer : public Container{
private:
    int data;
public:
    IntContainer();
    IntContainer(int value);
    ~IntContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setValue(int value);
    void copyValue(const IntContainer obj);
};

class FloatContainer : public Container{
private:
    float data;
public:
    FloatContainer();
    FloatContainer(float value);
    ~FloatContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setValue(float value);
    void copyValue(const FloatContainer obj);
};

class DoubleContainer: public Container{
private:
    double data;
public:
    DoubleContainer();
    DoubleContainer(double value);
    ~DoubleContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setValue(double value);
    void copyValue(const DoubleContainer obj);
};

class ArrayContainer: public Container{
public:
    ArrayContainer();
    virtual ~ArrayContainer();
    virtual void setSize(int value) {};
};

class IntArrayContainer: public ArrayContainer{
private:
    int * data;
    int size;
public:
    IntArrayContainer();
    IntArrayContainer(int count, ...);
    ~IntArrayContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setSize(int value) override;
    
    IntContainer getIndex(int value);
};

class CharArrayContainer: public ArrayContainer{
private:
    char * data;
    int size;
public:
    CharArrayContainer();
    CharArrayContainer(int count, ...);
    ~CharArrayContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setSize(int value) override;
    CharContainer getIndex(int value);
};

class DoubleArrayContainer: public ArrayContainer{
private:
    double * data;
    int size;
public:
    DoubleArrayContainer();
    DoubleArrayContainer(int count, ...);
    ~DoubleArrayContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setSize(int value) override;
    DoubleContainer getIndex(int value);
};

class FloatArrayContainer: public ArrayContainer{
private:
    float * data;
    int size;
public:
    FloatArrayContainer();
    FloatArrayContainer(int count, ...);
    ~FloatArrayContainer();
    void setValue() override;
    void showValue() override;
    void showType() override;
    void setSize(int value) override;
    FloatContainer getIndex(int value);
};

#endif