#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;
class regSys
{
protected:
    enum nameErrCode{
        allRight=0,
        exitByUser=1,
        alreadyTaken=2,
        sizeErr=3
    };
    // static const int PASSMINSYMB = 6;
    // static const int PASSMAXSYMB = 30;
    static const int NICKMINSYMB = 6;
    static const int NICKMAXSYMB = 30;
    /*
    *@param id Уникальный номер пользователя
    *@param id Имя соответствующее номеру
    *@brief Вектор пар <id - username> 
    */
   
    // vector<pair<int,char[NICKMAXSYMB+1]>> names; 
    vector<string> users; 
    vector<string> passwords; 
    int errCode=0;       //!переменная используемая для записывания кода ошибки   
    int counter=0;      //! Счетчик зарегистрированых записей 
    int maxCount=-1;    //! Максимальное количество записей (-1 = infinity)
    bool endWork = 1;   //! Флаг для окончания работы основной функции
    string newNickname; //! Временная переменная для создания ника нового пользователя
    string newPassword; //! Временная переменная для создания пароля нового пользователя
    
public:
    /*
    *@brief вывод всехимеющихся пользователей
    */
    void showAll();
   /*
    * @brief Регистрация в системе
    */
    void signUp();
    /*
    * @brief Вход в систему
    */
    void signIn();
    /*
    *@brief Основная функция 
    */
    void regSysMain();
    /*
    * @brief меню выбора действия
    * @return введённое число
    */
    int firstMenu();

    /*
    *@brief Первый "вход, welcome word"
    */
    void firstEnter();

    /*  
    *   @brief Конструктор
    *   @param maxCount максимально количство записей
    */
    regSys (int maxCount); //конструктор
    // virtual ~ regSys();
};