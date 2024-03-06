/*!
    \file
    \brief Заголовочный файл с описанием класса бинарного дерева поиска
*/

#ifndef BITREE_H
#define BITREE_H

#include "flatsData.h"

/*!
    \brief Класс описывающий лист дерева
    \param data Данные о квартие
    \param key ключ
    \param left указатель на левый лист
    \param right указатель на правый лист
*/
class BINode{
public:
    vector<flatsData> data;
    string key;
    BINode *left;
    BINode *right;
    BINode(const flatsData data);
    ~BINode(){};
};

/*!
    \brief Класс описывающий бинарное дерево поиска
*/
class BITree{
private:
    BINode *root;
    void del(BINode *node);
public:

/*!
    \brief Конструктор по умолчанию
*/
    BITree();

/*!
    \brief Метод поиска значений по ключу в бинарном дереве
    \return True or False
*/
    bool findData(const string &key);

/*!
    \brief Метод добавления элемента в дерево
*/
    void insertData(flatsData &data);
    
/*!
    \brief Вывод начала вывода дерева 
*/
    void print();

/*!
    \brief Вывод дерева по возрастанию
*/
    void printTree(BINode *node);

/*!
    \brief Деструктор
*/
    ~BITree();
};

#endif