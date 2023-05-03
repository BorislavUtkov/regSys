#include <stdio.h>
#include <vector>
#include <string>

class regSys
{
protected:
    std::vector<int> myVector;
    int a=0;
public:
    void getA();
    void setA();
    
    regSys (int a_base); //конструктор
};


