#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>



using namespace std;
class regSys
{
private:
    int activeId;             //! id активного пользователя
protected:
    // enum nameErrCode{   //Коды ошибок
    //     allRight=0,
    //     exitByUser=1,
    //     alreadyTaken=2,
    //     sizeErr=3,
    //     mismatchConfirm=4
    // };
    static const int PASSMINSYMB = 6;  //Минимальная длина пароля
    static const int PASSMAXSYMB = 30; //Максиимальная длина пароля
    static const int NICKMINSYMB = 6;  //Минимальная длина имени
    static const int NICKMAXSYMB = 30; //Максиимальная длина имени
    /*
    *@param id Уникальный номер пользователя
    *@param nickname Имя соответствующее номеру
    *@param password Пароль
    *@param lvl Уровень привилегий
    *@brief Структура с данными пользователя  
    */
    struct sampleUser{
        int id;
        char nickname[NICKMAXSYMB];
        char password[PASSMAXSYMB];//TODO Своя строка ??? Использовать готовый string
        int lvl; //Privilege Levels (0 - viewer, 1 - user, 5 - Admin)
    };
    vector <sampleUser> users;  //!!!! ГЛАВНЫЙ ВЕКТОР ХРАНЯЩИЙ ВСЕ ЗАПИСИ
    // vector<string> passwords; 
    int errCode=0;              //!переменная используемая для записывания кода ошибки   
    int counter=0;              //! Счетчик зарегистрированых записей 
    int maxCount=-1;            //! Максимальное количество записей (-1 = infinity)
    bool endWork = 1;           //! Флаг для окончания работы основной функции
    char* tmpNickname;         //! Временная переменная для создания ника нового пользователя
    string tmpPassword;         //! Временная переменная для создания пароля нового пользователя
    string confirmPassword;     //! Временная переменная для подтверждения пароля нового пользователя
public:
    /*
    *@brief Получение ID текущего пользователя
    *@return ID Активного пользователя 
    */
    int getActiveId();
    /*
    *@brief Назначение текущего пользователя по id
    *@param ID требуемого пользователя 
    *@return Код ошибки: 0-успех, 1-ошибка
    */
    bool setActiveId(int ID);
    /*
    *@brief получение id
    *@return порядковый id для пользователя
    */
    int getNextId();
   /*

    /*
    *@brief вывод всехимеющихся пользователей
    */
    // void showAll();
   /*
    * @brief Регистрация в системе
    */
    void signUp();
    /*
    * @brief Вход в систему
    */
    // int signIn();
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