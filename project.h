#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class regSys
{
protected:
    /*
    *@param id Уникальный номер пользователя
    *@brief Вектор пар <id - username> 
    */
    vector<pair<int,string>> names; 
    int counter=0;      //! Счетчик зарегистрированых записей
    int maxCount=-1;    //! Максимальное количество записей (-1 = infinity)
    bool endWork =0;    //! Флаг для окончания работы основной функции
    
public:
   /*
    * @brief Регистрация в системе
    */
    int signUp();
    /*
    * @brief Вход в систему
    */
    int signIn();
    /*
    *@brief Основная функция 
    */
    int regSysMain();
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