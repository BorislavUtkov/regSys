
#include "regSys.h"

regSys::regSys(int a_base){
    printf("base has been created\n");
};
void regSys::showAll(){
   int iteration=0; 
   for (auto &&i : users)
    {
        cout<< iteration <<") "<< i <<endl;
        iteration++;
    }
}

int regSys::firstMenu()
{
    int sM;//? todo func CreateTemp-ScanfTemp-Return temp 
    printf ("\n________________________\n");
    printf("|1 - Sign in             |\n");
    printf("|2 - Sign Up             |\n");
    printf("|3 - Show all users      |\n");
    printf("|0 - exit                |\n");
    printf("_________________________\n");
    printf("|Enter a number: ");
    scanf("%i",&sM);
    system( "cls" );
    switch (sM){
    case 1:
        signIn();
        break;
    case 2:
        signUp();
        break;
    case 3:
        showAll();
        break;
    case 0:
        return(0);
        break;
    default:
        printf("\n Unknown number, please repeat\n");
        break;
    }
    return(1);
}
void regSys::signUp(){
    errCode =nameErrCode::allRight;
    system( "cls" );
    do{   
        //todo Проверка доступности символов
        switch (errCode)
        {
        case nameErrCode::alreadyTaken:
            printf("\nNickname already used by other user. ");
            printf("\nUse some more your creativity, try again. ");
            break;
        case nameErrCode::sizeErr:
            printf("\nSize error, try again. ");
            break;
        default:
            break;
        }
        printf("\n0 - Exit: ");
        printf("\nThe number of characters must be in the range [%d:%d]",NICKMINSYMB, NICKMAXSYMB);
        printf("\nEnter new username: ");
        cin >> newNickname ;
        if (newNickname=="0"){      
            errCode=nameErrCode::exitByUser;    // пользователь решил выйти
        } else if (newNickname.size()> NICKMAXSYMB || newNickname.size()< NICKMINSYMB){
            errCode = nameErrCode::sizeErr;     // ошибка размера имени
            newNickname="-1";       //флаг ошибки     
        } else{
            for (int i = 0; i < counter; i++){  
                if(newNickname == users[i])     // имя уже занято  
                    errCode = nameErrCode::alreadyTaken; 
                newNickname="-1";   //флаг ошибки 
            }
        }
        system( "cls" );
        if (errCode==nameErrCode::exitByUser){
            newNickname="";
            printf("\n Return to menu");   
        }else if(newNickname != "-1"){  //проверка флага ошибки
            printf("\n Hello, ");
            cout << newNickname;
            printf("\n Registation succeful");
            printf("\n Welcome here <3\n");
            counter++;
            users.push_back(newNickname);
        }
    } while (errCode != nameErrCode::allRight && errCode != nameErrCode::exitByUser);
 }
void regSys::signIn(){
        printf("\n\n todo\n\n");    
 }
//todo UserMenu
//todo Copy user's information in file.txt 
//todo SignIn
//todo password 
void regSys::regSysMain(){
    while (endWork)
    {
        endWork =firstMenu();    
    }
}


int main(){
    regSys alpha{10};
    alpha.regSysMain();
    return 0;
}