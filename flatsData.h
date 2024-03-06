/*!
    \file
    \brief Заголовочный файл с описанием структуры с данными о квартире
*/

#ifndef FLATSDATA_H
#define FLATSDATA_H

#include <bits/stdc++.h>


using namespace std;

/*!
    \brief Класс для работы с данным о квартирах
    \param houseNum номер дома
    \param flatNum номер квартиры
    \param roomCount количество комнат
    \param flatSquare площадь квартиры
    \param ownerName имя владельца
    \param countResidents количество жителей
*/
class flatsData{

private:
    
    int houseNum;
    int flatNum;
    int roomCount;
    int flatSquare;
    string ownerName;
    int countResidents;
    
public:
/*!
    \brief Конструктор по умолчанию
*/
    flatsData();
/*!
    \brief Конструктор
    \param houseNum номер дома
    \param flatNum номер квартиры
    \param roomCount количество комнта
    \param flatSquare площадь квартиры
    \param ownerName ФИО владельца
    \param countResidents число проживающих
*/
    flatsData(int houseNum, int flatNum, int roomCount, int flatSquare, string ownerName, int countResidents);

/*!
    \brief Конструктор копирования
*/
    flatsData(const flatsData &other);

/*!
    \brief Деструктор
*/
    ~flatsData() {};

/*!
    \brief Функция получения ФИО владельца
    \return ФИО владельца
*/
    string getName();
    
/*!
    \brief Функция получения данных о квартире в CSV формате
    \return Строка в формате ФИО;номер дома;номер квартиры;количество комнат;общая площадь;число проживающих
*/
    string getData();
/*!
    @brief Оператор проверки на равенство двух квартир
    \param a данные о первой квартире
    \param b данные о второй квартире
    \return Совпадают ли данные о квартирах
*/
    friend bool operator == (const flatsData & a, const flatsData & b);

/*!
    @brief Оператор проверки меньше
    \param a данные о первой квартире
    \param b данные о второй квартире
    \return Меньше ли данные о первой квартире
*/
    friend bool operator < (const flatsData & a, const flatsData & b);

/*!
    @brief Оператор проверки на меньше или равно
    \param a данные о первой квартире
    \param b данные о второй квартире
    \return Меньше или равны ли данные о первой 
*/
    friend bool operator <= (const flatsData & a, const flatsData & b);

/*!
    @brief Оператор проверки на больше
    \param a данные о первой квартире
    \param b данные о второй квартире
    \return Больше ли данные о первой квартире
*/
    friend bool operator > (const flatsData & a, const flatsData & b);

/*!
    @brief Оператор проверки на больше или равно
    \param a данные о первой квартире
    \param b данные о второй квартире
    \return больше или равны ли данные о первой квартире
*/
    friend bool operator >= (const flatsData & a, const flatsData & b);

};

#endif