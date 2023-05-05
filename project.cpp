
#include "project.h"

regSys::regSys(int a_base){
    printf("base has been created\n");
};
int regSys::firstMenu()
{
    int sM;
    printf ("___________________________\n");
    printf("|1 - Sign in             |\n");
    printf("|2 - Sign Up             |\n");
    printf("___________________________\n");
    printf("|Enter a number: ");
    scanf("%d",&sM);
    switch (sM){
    case 1:
        signIn();
        break;
    case 2:
        signUp();
        break;
    default:
        printf("\n Unknown number, please repeat\n");
        break;
    }
    
}

 
 int signUp(){


 }
 int signIn(){

    
 }

int regSys::regSysMain(){
    while (endWork)
    {
        firstMenu();
        
    }
}


int main(){
    regSys alpha{10};
    alpha.regSysMain();
    return 0;
}


