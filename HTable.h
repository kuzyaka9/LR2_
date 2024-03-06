/*!
    \file
    \brief Заголовочный файл с описанием класса хэш таблицы
*/

#ifndef HTABLE_H
#define HTABLE_H

#include "flatsData.h"

/*!
    \brief Класс описывающий лист дерева
    \param data Данные о квартие
    \param key ключ
*/
class HNode{
public:
    flatsData data;
    string key;
/*!
    \brief Конструктор
*/
    HNode(flatsData data);

/*!
    \brief Деструктор
*/
    ~HNode(){};
};


class HTable{
private:
    vector<vector<HNode *>> table;
    int size;

/*!
    \brief Функция подсчета хеша

    Хэш вычисляется по алгоритму ly
    \return Хэш ключа
*/
    unsigned int hash(string &key);

public:

/*!
    \brief Конструктор
    \param size Размер таблицы
*/
    HTable(int size);

/*!
    \brief Метод добавления элемента в хэш таблицу
    \param data Данные о квартире
*/
    void insertData(flatsData data);

/*!
    \brief Функция поиска элемента в хэш таблице
    \param key Ключ по которому искать
    \return True or False
*/    
     bool findData(string key);

/*!
    \brief Подсчет колизий
    \return Число колизий
*/
    int countCollisions();

};

#endif