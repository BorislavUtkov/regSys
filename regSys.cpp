
#include "regSys.h"

regSys::regSys(int a_base){
    printf("base has been created\n");
};
void regSys::showAll(){
    int iteration=0; 
    for (int i = 0; i < counter; i++)
    {
        printf("\n%d) ", i);
        cout << users.at(i) <<" "<< passwords.at(i);
    }
   
//    for (auto &&i : users){
//         cout<< iteration <<") "<< i <<endl;
//         iteration++;
//     }

//     iteration=0; 
//     for (auto &&i : passwords){
//         cout<< iteration <<") "<< i <<endl;
//         iteration++;
//     }
}

int regSys::firstMenu()
{ 
    int sM;//? todo func CreateTemp-ScanfTemp-Return temp
    // cout << "Active user " << activeUser;
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
        if (counter < maxCount || maxCount == -1)
            signUp();
        else
            printf("We can't to add you in our society \n");
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
        //todo Проверка доступности символов (через коды таблицы ASCII)
        switch (errCode)
        {
        case nameErrCode::alreadyTaken:
            cout<<newNickname;
            printf("\n Nickname already used by other user. ");
            printf("\nUse some more your creativity, try again. ");
            break;
        case nameErrCode::sizeErr:
            printf("\nSize error, try again. ");
            break;
        default:
            break;
        }
        errCode =nameErrCode::allRight;
        printf("\n0 - Exit: ");
        printf("\nThe number of characters must be in the range [%d:%d]",NICKMINSYMB, NICKMAXSYMB);
        printf("\nEnter new username: ");
        cin >> newNickname ;
        if (newNickname=="0"){      
            errCode=nameErrCode::exitByUser;    //! пользователь решил выйти
        } else if (newNickname.size()> NICKMAXSYMB || newNickname.size()< NICKMINSYMB){
            errCode = nameErrCode::sizeErr;     //! ошибка размера имени
        } else{
            for (int i = 0; i < counter; i++){  
                if(newNickname == users[i])     //! имя уже занято  
                    errCode = nameErrCode::alreadyTaken; 
            }
        }
        system( "cls" );

       if(errCode == nameErrCode::allRight){  //проверка флага ошибки
            printf("\n Hello, ");
            cout << newNickname;
        }
    } while (errCode != nameErrCode::allRight && errCode != nameErrCode::exitByUser);
   
    //! создание пароля
    if(errCode==nameErrCode::allRight){
        do{
            newPassword="";
            printf("\n Now let's create password");
            printf("\nThe number of characters must be in the range [%d:%d]", PASSMINSYMB, PASSMAXSYMB);
            printf("\n0 - Exit: ");
            printf("\nEnter a password: ");
            cin>>newPassword;
            if (newPassword.size()<PASSMINSYMB || newPassword.size()>PASSMAXSYMB){
                system( "cls" );
                printf("\n Size error ");
                errCode=nameErrCode::sizeErr;
            }
            else
            {
                printf("\nConfirm a password: ");
                cin>>confirmPassword;
                if (confirmPassword != newPassword)
                {
                    errCode = nameErrCode::mismatchConfirm;
                    system( "cls" );
                    printf("\nPassword mismatch, try again");
                }
                else 
                    errCode=nameErrCode::allRight;
            }
        }while(errCode != nameErrCode::allRight && errCode != nameErrCode::exitByUser);
    }

    if(errCode == nameErrCode::allRight){   //выход из функции по требованию пользователя
            counter++;
            passwords.push_back(newPassword);
            users.push_back(newNickname);
            system( "cls" );
            printf("\n Welcome here "); 
            cout<<newNickname;
 
    }  else if(errCode == nameErrCode::exitByUser){
            newNickname="";
            printf("\n Return to menu"); 
    }
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