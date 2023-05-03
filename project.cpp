
#include "project.h"

regSys::regSys(int a_base){
        a=a_base;
        printf("base has been created\n");
    };
void regSys::getA(){
        printf("a=%d\n",a); 
    }
void regSys::setA(){
        printf("'a' set to:");
        scanf("%d", a);
    }
int main(){
    regSys abc{100};
    abc.getA();
    
    while (1);
    
    return 0;
}


