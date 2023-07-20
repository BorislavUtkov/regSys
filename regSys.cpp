
#include "regSys.h"

#define welcomeWord true
#define debug false

regSys::regSys(int a_base){
#if welcomeWord == 1 || debug == 1
    system("color 2");
    printf( " __________________________________\n"
            "|                                  |\n"
            "|    base   has   been   created . |\n"
            "|                                  |\n"
            "|    Welcome here,                 |\n"
            "|       press any key for start.   |\n"
            "|__________________________________|\n");
#endif

    sampleUser guest;               //создание гостевого/начального пользователя
    users.push_back(guest);           
    users.at(0).id=getNextId();
    users.at(0).nickname="Guest";   // strcpy(users.at(0).nickname,"Guest"); 
    users.at(0).lvl=0;
    setActiveId(0);
    getch();

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
    for (i = 0; i < counter; i++){
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

    return(1);
}
void regSys::signUp(){
    system( "cls" );
    sampleUser tmpUser;
    do{   
        tmpNick[NICKMAXSYMB+1]=0;
        tmpNick[NICKMINSYMB-1]=0;
        printf("\n\t  __________________________________\n"
                "\t| The number of characters          |\n"
                "\t|  it must be in the range [%2d:%2d]  |\n" //сделать нормальную реакцию на пробел, мб использовать getch?
                "\t|   and use only A-Z a-z 0-9 _ -    |\n"
                "\t|                                   |\n"
                "\t|  0 - Exit                         |\n"
                "\t|___________________________________|\n",NICKMINSYMB, NICKMAXSYMB);
        printf("\n\t Enter new username: ");
        scanf ("%s", tmpNick) ;
        printf ("\n%s", tmpNick) ;
        system("cls");
        if (tmpNick[0] != '0' && tmpNick[1] != 0){                                        //!проверка корректности имени      
            if (static_cast<int>( tmpNick[NICKMAXSYMB+1]) != 0){                           
                printf("\nToo long name, please try again.");
                errCode=1;
            } else if(static_cast<int>( tmpNick[NICKMINSYMB-1]) == 0)
            { 
                printf("\nToo short name, please try again.");
                errCode=1;
            }else {
                for (int i = 0; i <= NICKMAXSYMB; i++){
                    if (tmpNick[i] == 0)
                        i=NICKMAXSYMB;
                    else if(!( tmpNick[i] == ' ' || tmpNick[i] == '-' || tmpNick[i] == '_' || (tmpNick[i]>= 'a' && tmpNick[i]<= 'z')||(tmpNick[i]>= 'A' && tmpNick[i]<= 'Z')||(tmpNick[i]>= '0' && tmpNick[i]<= '9'))){
                            printf("\n Bad symbol (%c), please try again.", tmpNick[i]);
                            errCode =1;                                 //!недоступный символ                
                        }
                }
                if(errCode==0){
                    if (counter > 1){
                        for (i = 0; i < counter; i++)  
                            if(tmpNick == users[i].nickname){                //! имя уже занято  
                                printf("\n Nickname already used by other user.\n Please, try again. ");
                                errCode=1;
                            }
                    } 
                }
            }
        }
#if debug==1  
    printf("\n*****");
    printf("\n - %s", tmpNick);
    printf("\n%d: %d\n", NICKMINSYMB, static_cast<int>( tmpNick[NICKMINSYMB-1]));
    printf("%d: %d\n",NICKMAXSYMB+1 ,static_cast<int>( tmpNick[NICKMAXSYMB+1]));
    printf("\n*****");
#endif

    if (errCode) getch();
    system("cls");
} while (errCode);

tmpUser.nickname=tmpNick;
printf("\tHello, %s\n", tmpNick);
printf("\tLet's create a Password");
getch();
//! ************************************************************************************************
//! ************************************************************************************************
//! ************************************************************************************************
//! Если нет ошибок на этом этапе,
//! то переходим к созданию пароля
   /* if(errCode==nameErrCode::allRight){
        do{
            tmpPassword="";


            printf("  _________________________________\n");
            printf(" | Now let's create password        |\n");
            printf(" | it must be in the range [%d:%d]   |\n",PASSMINSYMB, PASSMAXSYMB);
            printf(" |                                  |\n");
            printf(" |  0 - Exit:                       |\n");
            printf(" |__________________________________|\n");
            printf("\nEnter a password: ");
            cin>>tmpPassword;
            if (tmpNick=="0"){      
                    errCode=nameErrCode::exitByUser;    //! пользователь решил выйти
            } else if (tmpPassword.size()<PASSMINSYMB || tmpPassword.size()>PASSMAXSYMB){
                system( "cls" );
                printf(" Size error \n");
                errCode=nameErrCode::sizeErr;
            }
            else{
                printf("\nConfirm a password: ");
                cin>>confirmPassword;
                if (confirmPassword != tmpPassword){    //! пароль не совпадает с введенным ранее
                    errCode = nameErrCode::mismatchConfirm; 
                    system( "cls" );
                    printf("\nPassword mismatch, try again\n");
                }else 
                    errCode=nameErrCode::allRight;
            }
        }while(errCode != nameErrCode::allRight && errCode != nameErrCode::exitByUser);
    }


    if(errCode == nameErrCode::allRight){   //выход из функции по требованию пользователя
            counter++;
            // passwords.push_back(tmpPassword);
            // users.push_back(tmpNick);
            system( "cls" );
            printf("\n Welcome here, ");
            cout<<tmpNick<<endl;
 
    }  else if(errCode == nameErrCode::exitByUser){
            tmpNick="";
            printf("\n Return to menu"); 
    }*/
 }
/* int regSys::signIn(){
//     if (counter>0){
//         printf("\n Login: "); 
//         cin >> tmpNick;
//         int i=0;
//         while (i != counter+1) //TODO сделать без +1
//         {
            
//         }
        
//             if (users[i] == tmpNick){

//             }
        
//     }
//     else{
//         printf("\n Return to menu"); 
//         return -1;
//     }

//  
//todo UserMenu
//todo Copy user's information in file.txt 
//todo SignIn
// password 
*/
void regSys::regSysMain(){
    endWorkFlag=0;
    do{
        system( "cls" );
        char sM;//? todo func/lambda CreateTemp-ScanfTemp-Return temp
        printf(" \n\n\tHello, %s \n", users.at(getActiveId()).nickname);
        printf(" \t __________________________________\n"
                "\t| 1 - Sign in                       |\n"
                "\t| 2 - Sign Up                       |\n"
                "\t| 0 - exit                          |\n"
                "\t|___________________________________|\n"
                "\t Enter a number: ");
        // scanf("%c",&sM);    //todo защита от нескольких символов и пробелов
        // system( "cls" );
        switch (getch()-'0'){ 
        case 1:
            printf("\nNot now, sorry\n");
            getch();
            //signIn();
            break;
        case 2:
            if (counter < maxCount || maxCount == -1)           
                signUp();
            // else
                printf("\nWe can't add you in our society \n");
            break;
        case 3:
            // showAll();
        break;
        case 0:
            endWorkFlag=1;
        break;
        default:
            printf("\n Unknown number, please try again\n");
        break;
    }   
    }while (endWorkFlag==0);
}


int main(){
    regSys alpha{10};
    alpha.regSysMain();


    return 0;
}