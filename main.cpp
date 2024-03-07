#include <iostream>
#include <iomanip>
#define Pi 3.1415926
using namespace std;

//Номер группы 315, факультет ФДО
#if 0
Разработчик программы Логвинцов А.А.
Номер лабораторной работы 1
#endif

//Очистка буфера cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//Функция вывода меню
void printMenu(void)
{
    cout<<"Введите номер соответсвующий задаче, либо q либо для выхода"<<endl;
    cout<<"1 - Вычислить скорость прямолинейного движения (по расстоянию и времени)."<<endl;
    cout<<"2 - Вычислить ускорение (по начальной скорости, конечной скорости и времени)."<<endl;
    cout<<"3 - Вычислить радиус круга (по длине его окружности)."<<endl;
    cout<<"q - Выход из программы"<<endl;
}

//Функция подсчета и вывода скорости
void speed(void)
{
     //Очистка буфера ввода если остался какой шлак
     BUFF_CLEAR;

     float distanceMeters;
     float timeSec;
     cout<<"Введите расстояние в метрах и время в секундах"<<endl;
     cin>>distanceMeters>>timeSec;

     //Верификация ввода если ввел ерунду
     while (cin.fail())
     {
         cin.clear();
         BUFF_CLEAR;
         cout<<"Вводите числовые значения"<<endl;
         cin>>distanceMeters>>timeSec;
     }

     //Подсчет и вывод скорости
     cout<<"V = "<<distanceMeters/timeSec << "м/с"<<endl;
}

//Функция подсчета и вывода ускорения
void acceleration(void)
{
    //Очистка буфера ввода если остался какой шлак
    BUFF_CLEAR;

    float startingSpeedMS, finalSpeedMS;
    float timeSec;
    cout<<"Введите начальную и конечную скорость в м/с и время в секундах"<<endl;
    cin>>startingSpeedMS>>finalSpeedMS>>timeSec;

    //Верификация ввода если ввел ерунду
    while (cin.fail())
    {
        cin.clear();
        BUFF_CLEAR;
        cout<<"Вводите числовые значения"<<endl;
        cin>>startingSpeedMS>>finalSpeedMS>>timeSec;
    }

    //Подсчет и вывод ускорения
    cout<<"a = "<<(finalSpeedMS - startingSpeedMS)/timeSec<<" м/с"<<endl;
}

//Функция подсчета и вывода радиуса
void radius(void)
{
   //Очистка буфера ввода если остался какой шлак
   BUFF_CLEAR;

   float circleMm;
   cout<<"Введите длинну окружности"<<endl;
   cin>>circleMm;

   //Верификация ввода если ввел ерунду
   while (cin.fail())
   {
       cin.clear();
       BUFF_CLEAR;
       cout<<"Вводите числовые значения"<<std::endl;
       cin>>circleMm;
   }

   cout<<"r = "<<circleMm/Pi<<" м"<<std::endl;
}


int main()
{
    //Задание 2
    cout<<setw(10)<<std::right<<"*****"<<setw(30)<<right<<"ТУСУР"<<setw(30)<<right<<"*****"<<endl<<endl<<endl;
    cout<<setw(42)<<right<<" "<<"Факультет: Доп. Образование"<<endl;
    cout<<setw(42)<<right<<" "<<"Группа 315"<<endl;
    cout<<setw(42)<<right<<" "<<"Студент: Логвинцов Алексей"<<endl<<endl;
    cout<<setw(35)<<right<<" "<<"Томск 2024"<<endl<<endl;

   //Задание 3
   //Печатаем меню
   printMenu();

   //Переменная нашего выбора
   char taskSelection;
   cin>>taskSelection;

   //Зациклим чтобы можно было решать разные задачи
   while(taskSelection != 'q' && taskSelection != 'Q')
   {
       //Подсчет и вывод в зависимости от нашего выбора
       switch(taskSelection)
       {
          case '1': speed(); break;
          case '2': acceleration(); break;
          case '3': radius(); break;
          default: cout<<"Выберите значение из меню"<<endl; break;
       }

       //Очистка буфера ввода если остался какой шлак
       BUFF_CLEAR;

       //Чтобы меню не вводилось второй раз если ввели ерунду
       if(taskSelection >= '1' && taskSelection <= '3')
       printMenu();
       cin>>taskSelection;
   }

   cout<<"До скорой встречи друг!!!";
   return 0;
}
