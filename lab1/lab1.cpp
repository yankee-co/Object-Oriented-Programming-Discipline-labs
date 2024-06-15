#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

// Variant 5 Zemlyanskyi Eduard KV-22

int InstanceCounter = 0;
int AllTimeInstanceCounter = 0;
bool showLogs = false;

class Ratio{

    public:

        int numerator;
        int denominator;

        Ratio();
        Ratio(int numerator, int denominator = 1);
        void SetRatio(int numerator, int denominator);
        void GetRatio() const;
        float GetRatioAsFloat();
        void CopyRatio(const Ratio & refRatio);
        void Simplify();
        void Compare(const Ratio & refRatio);
        void CompareToInt(int ref_numerator);
        void operator=(const Ratio & refRatio);
        void operator=(int integer);
        void CheckIfInt();
        int GetIntegerPart();
        Ratio GetRatioPart();
        Ratio Power(int integer);
        Ratio operator+(const Ratio & refRatio);
        Ratio operator+(int integer);
        Ratio operator-(const Ratio & refRatio);
        Ratio operator-(int integer);
        Ratio operator*(const Ratio & refRatio);
        Ratio operator*(int integer);
        Ratio operator/(const Ratio & refRatio);
        Ratio operator/(int integer);
        ~Ratio();
};

Ratio::Ratio(){
    if (showLogs){
        cout << "Constructor without parameters called for " << this << endl;
    }
    InstanceCounter++;
    AllTimeInstanceCounter++;
}

Ratio::Ratio(int numerator, int default_denominator) : denominator(default_denominator){
    if (showLogs){
        cout << "Constructor with parameters called for " << this << endl;
    }
    SetRatio(numerator, denominator);
    InstanceCounter++;
    AllTimeInstanceCounter++;
}

void Ratio::SetRatio(int passed_numerator, int passed_denominator){
    if (showLogs){
        cout << "Setter called for " << this << endl;
    }
    numerator = passed_numerator;
    denominator = passed_denominator;
}

void Ratio::GetRatio() const {
    if (showLogs){
        cout << "Getter called for " << this << endl;
    }
    cout << "Ratio: " << numerator << "/" << denominator << endl;
}

float Ratio::GetRatioAsFloat(){
    if (showLogs){
        cout << "Float getter called for " << this << endl;
    }
    // cout << "Float: " << float(numerator)/float(denominator) << endl;

    return float(numerator)/float(denominator);
}

void Ratio::CopyRatio(const Ratio & refRatio){
    if (showLogs){
        cout << "Copying called for " << this << endl;
    }
    numerator = refRatio.numerator;
    denominator = refRatio.denominator; 
}

void Ratio::Simplify(){

    if (showLogs){
        cout << "Simplifying called for " << this << endl;
    }

    if(numerator % denominator == 0){
        numerator /= denominator;
        denominator = 1;
    }
    else if (denominator % numerator == 0){
        denominator /= numerator;
        numerator = 1;
    }
    else {
        while(numerator % 2 == 0 && denominator % 2 == 0){
            numerator /= 2;
            denominator /= 2;
        }
    }
}

int Ratio::GetIntegerPart(){
    if (showLogs){
        cout << "Getting integer part called for " << this << endl;
    }

    int integer;

    if(numerator > denominator){
        // cout << "Integer part: " << integer << " Ratio part: " << numerator - integer * denominator << "/" << denominator << endl;
        return int(numerator/denominator);
    }
    else if (numerator < denominator){
        cout << "No integer part can be taken." << endl;
    }
    return 0;
}

Ratio Ratio::GetRatioPart(){
    if (showLogs){
        cout << "Getting ratio part called for " << this << endl;
    }

    int new_numerator, integer;

    if(numerator > denominator){
        int integer = GetIntegerPart();
        new_numerator = numerator - integer * denominator;
    }
    else if (numerator < denominator){
        cout << "No integer part can be taken." << endl;
    }

    Ratio newRatio(new_numerator, denominator);

    return newRatio;
}


void Ratio::Compare(const Ratio & refRatio){

    if (showLogs){
        cout << "Comparison called for " << this << endl;
    }

    int new_numerator1, new_numerator2;

    if (denominator == refRatio.denominator){
        if (numerator > refRatio.numerator){
            cout << numerator << "/" << denominator << " > " << refRatio.numerator << "/" << refRatio.denominator << endl; 
        }
        else{
            cout << numerator << "/" << denominator << " < " << refRatio.numerator << "/" << refRatio.denominator << endl; 
        }
    }
    else{
        new_numerator1 = numerator * refRatio.denominator;
        new_numerator2 = refRatio.numerator * denominator;

        if (new_numerator1 > new_numerator2){
            cout << numerator << "/" << denominator << " > " << refRatio.numerator << "/" << refRatio.denominator << endl; 
        }
        else{
            cout << numerator << "/" << denominator << " < " << refRatio.numerator << "/" << refRatio.denominator << endl; 
        }

    }
}

void Ratio::CompareToInt(int integer){

    if (numerator > integer * denominator){
        cout << numerator << "/" << denominator << " > " << integer << endl; 
    } else{
            cout << numerator << "/" << denominator << " < " << integer << endl; 
        }

    if (showLogs){
        cout << "Comparison called for " << this << endl;
    }
}

void Ratio::operator=(const Ratio & refRatio){
    CopyRatio(refRatio);
}

void Ratio::operator=(int integer){
    CopyRatio(Ratio(integer, 1));
}

void Ratio::CheckIfInt(){
    cout << "Ratio " << numerator << "/" << denominator;
    Simplify();
    if (denominator == 1){
        cout << " is an integer: " << numerator << endl;
    } else {
        cout << " is not an integer." << endl;
    }
}

Ratio Ratio::operator+(const Ratio & refRatio){

    int new_numerator, new_denominator;

    if (denominator == refRatio.denominator){
        new_numerator = numerator + refRatio.numerator;
        new_denominator = denominator;
    }
    else{
        new_numerator = numerator * refRatio.denominator + refRatio.numerator * denominator;
        new_denominator = denominator * refRatio.denominator;
    }

    Ratio newRatio = Ratio(new_numerator, new_denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Addition called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator+(int integer){

    Ratio newRatio = Ratio(numerator + integer * denominator, denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Addition called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator-(const Ratio & refRatio){
    int new_numerator, new_denominator;

    if (denominator == refRatio.denominator){
        new_numerator = numerator - refRatio.numerator;
        new_denominator = denominator;
    }
    else{
        new_numerator = numerator * refRatio.denominator - refRatio.numerator * denominator;
        new_denominator = denominator * refRatio.denominator;
    }

    Ratio newRatio = Ratio(new_numerator, new_denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Substraction called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator-(int integer){

    Ratio newRatio = Ratio(numerator - integer * denominator, denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Substraction called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator*(const Ratio & refRatio){
    int new_numerator, new_denominator;

    new_numerator = numerator * refRatio.numerator;
    new_denominator = denominator * refRatio.denominator;

    Ratio newRatio = Ratio(new_numerator, new_denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Multiplication called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator*(int integer){
    
    Ratio newRatio = Ratio(numerator * integer, denominator);
    newRatio.Simplify();

    if (showLogs){
        cout << "Multiplication called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator/(const Ratio & refRatio){

    Ratio newRatio = this->operator*(Ratio(refRatio.denominator, refRatio.numerator));

    if (showLogs){
        cout << "Dividing called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::operator/(int integer){

    Ratio newRatio = this->operator*(Ratio(1, integer));
    
    if (showLogs){
        cout << "Dividing called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio Ratio::Power(int integer){

    Ratio newRatio = Ratio(pow(numerator, integer), pow(denominator, integer));
    newRatio.Simplify();

    if (showLogs){
        cout << "Power elevation called for " << &newRatio << endl;
    }
    return newRatio;
}

Ratio::~Ratio(){
    if (showLogs){
        cout << "Destructor called for " << this << endl;
    }
    InstanceCounter--;
}

void AskLogs(){
    string Answer;
    cout << "Show logs ? (y/n): ";
    cin >> Answer;
    if ((Answer == "y" || Answer == "yes" || Answer != "0") && Answer != "no" && Answer != "n" && Answer != "nope"){
        showLogs = true;
    }
}

Ratio ParseRatio(string RefString){

    int numerator = stoi(RefString);
    int denominator = stoi(RefString.substr(RefString.find('/') + 1));

    return Ratio(numerator, denominator);
}

int main(){

    AskLogs();

    // test here
    
    return 0;
}