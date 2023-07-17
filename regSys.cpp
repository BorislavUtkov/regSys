
#include "regSys.h"

regSys::regSys(int a_base){
    printf("  ______________________\n");
    printf(" |                      |\n");
    printf(" |base has been created |\n");
    printf(" |______________________|\n");
    
    //создание гостевого/начального пользователя
    sampleUser guest;// как конвертировать строку в идентификатор
    users.push_back(guest);           
    users.at(0).id=getNextId();
    strcpy(users.at(0).nickname,"Guest"); //сделать отдельной функцией ?
    users.at(0).lvl=0;
    setActiveId(0);
};
bool regSys::setActiveId(int ID){
    if (ID<=counter && ID>=0){
        activeId=ID;
        return 0; //успех
    }
    else
        return 1; //ошибка
}
int regSys::getNextId() {
    counter++;
    return(--counter);

    //? проблема, что требуется считать с 0
    //? но после return'а счетик не изменить
    //? решение чтобы не делать костыль в .h
    //? начиная счетчик с -1
}
int regSys::getActiveId()
{
    return activeId;
}
/*void regSys::showAll(){
    int iteration=0; 
    for (int i = 0; i < counter; i++){
        printf("\n%d) ", i);
        cout << users.at(i) <<" "<< passwords.at(i);
    }


   for (auto &&i : users){
        cout<< iteration <<") "<< i <<endl;
        iteration++;
    }

    iteration=0; 
    for (auto &&i : passwords){
        cout<< iteration <<") "<< i <<endl;
        iteration++;
    }
}*/

int regSys::firstMenu()
{ 
    
    int sM;//? todo func CreateTemp-ScanfTemp-Return temp
    printf("\n");
    printf(" Hello, %s \n", users.at(getActiveId()).nickname);
    printf(" _________________________\n");
    printf("| 1 - Sign in             |\n");
    printf("| 2 - Sign Up             |\n");
    //printf("| 3 - Show all users      |\n");
    printf("| 0 - exit                |\n");
    printf("|_________________________|\n");
    printf("|Enter a number: ");
    scanf("%i",&sM);
    system( "cls" );
    switch (sM){ //FIXME getchar()-48 (вычет кода ASCII) ? 
    case 1:
        //signIn();
        break;
    case 2:
        if (counter < maxCount || maxCount == -1)           
            signUp();
        // else
            printf("We can't to add you in our society \n");
        break;
    case 3:
        // showAll();
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
    system( "cls" );
    do{   
        // TODO Проверка доступности символов (через коды таблицы ASCII)
        tmpNickname= "0";
        printf("\n");
        printf("  _________________________________\n");
        printf(" | The number of characters         |\n");
        printf(" |  should be in the range [%d:%d]   |\n",NICKMINSYMB, NICKMAXSYMB);
        printf(" |                                  |\n");
        printf(" |  0 - Exit:                       |\n");
        printf(" |__________________________________|\n");
        printf("\nEnter new username: ");
        scanf ("%s", tmpNickname) ;

        printf("\n - %s", tmpNickname);
        if (tmpNickname != "0"){//! пользователь решил выйти      
            if (tmpNickname[NICKMAXSYMB+1] != 0 || tmpNickname[NICKMINSYMB] == 0 ){  //! ошибка размера имени
                printf("\nSize error, try again. ");
            } else if (counter > 1){
                for (int i = 0; i < counter; i++)  
                    if(tmpNickname == users[i].nickname) {    //! имя уже занято  
                        printf("\n Nickname already used by other user. ");
                        printf("\n Please, try again. ");
                    }
            } else                                          //проверка флага ошибки
                printf("Hello, %s", tmpNickname);
        }
    } while (tmpNickname != "0");
// //! ************************************************************************************************
// //! ************************************************************************************************
// //! ************************************************************************************************
//     //! Если нет ошибок на этом этапе,
//     //! то переходим к созданию пароля
//     if(errCode==nameErrCode::allRight){
//         do{
//             tmpPassword="";


//             printf("  _________________________________\n");
//             printf(" | Now let's create password        |\n");
//             printf(" |  should be in the range [%d:%d]   |\n",PASSMINSYMB, PASSMAXSYMB);
//             printf(" |                                  |\n");
//             printf(" |  0 - Exit:                       |\n");
//             printf(" |__________________________________|\n");
//             printf("\nEnter a password: ");
//             cin>>tmpPassword;
//             if (tmpNickname=="0"){      
//                     errCode=nameErrCode::exitByUser;    //! пользователь решил выйти
//             } else if (tmpPassword.size()<PASSMINSYMB || tmpPassword.size()>PASSMAXSYMB){
//                 system( "cls" );
//                 printf(" Size error \n");
//                 errCode=nameErrCode::sizeErr;
//             }
//             else{
//                 printf("\nConfirm a password: ");
//                 cin>>confirmPassword;
//                 if (confirmPassword != tmpPassword){    //! пароль не совпадает с введенным ранее
//                     errCode = nameErrCode::mismatchConfirm; 
//                     system( "cls" );
//                     printf("\nPassword mismatch, try again\n");
//                 }else 
//                     errCode=nameErrCode::allRight;
//             }
//         }while(errCode != nameErrCode::allRight && errCode != nameErrCode::exitByUser);
//     }


//     if(errCode == nameErrCode::allRight){   //выход из функции по требованию пользователя
//             counter++;
//             // passwords.push_back(tmpPassword);
//             // users.push_back(tmpNickname);
//             system( "cls" );
//             printf("\n Welcome here, ");
//             cout<<tmpNickname<<endl;
 
//     }  else if(errCode == nameErrCode::exitByUser){
//             tmpNickname="";
//             printf("\n Return to menu"); 
//     }
 }


// int regSys::signIn(){
//     if (counter>0){
//         printf("\n Login: "); 
//         cin >> tmpNickname;
//         int i=0;
//         while (i != counter+1) //TODO сделать без +1
//         {
            
//         }
        
//             if (users[i] == tmpNickname){

//             }
        
//     }
//     else{
//         printf("\n Return to menu"); 
//         return -1;
//     }

//  }
//todo UserMenu
//todo Copy user's information in file.txt 
//todo SignIn
// password 
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