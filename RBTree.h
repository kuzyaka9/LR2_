/*!
    \file 
    \brief Заголовочный файл с описанием класса красно черного дерева поиска
*/

#ifndef RBTREE_H
#define RBTREE_H

#include "flatsData.h"

/*!
    \brief Класс описывающий ноду дерева
    \param data Данные о квартире
    \param key ключ
    \param color Цвет ноды
    \param left Указатель на левого потомка
    \param right Указатель на правого потомка
    \param parent Указатель на родителя
*/
class RBNode{
public:
    vector<flatsData> data;
    string key;
    int color;
    RBNode *left;
    RBNode *right;
    RBNode *parent;

/*!
    \brief Конструктор
    \param data Данные о квартире
    \param key ключ
    \param color Цвет ноды
    \param left Указатель на левого потомка
    \param right Указатель на правого потомка
    \param parent Указатель на родителя
*/
    RBNode(flatsData data, int color, RBNode *left, RBNode *right, RBNode *parent);
};


/*!
    \brief Класс описывающий красно черное дерево
    \param root Указатель на корень дерева
    \param nil Указатель на лист
*/
class RBTree{
private:
    RBNode *root;
    RBNode *nil;

/*!
    \brief Левый поворот дерева
    \param node Нода вокруг которой поворачиваем
*/
    void leftRotate(RBNode *node);
/*!
    \brief Правый поворот
    \param node Нода вокруг которой поворачиваем
*/
    void rightRotate(RBNode *node);

/*!
    \brief Вставка элемента в красно черное дерево, как в бинарное
    \param data Данные о квартире
    \return Указатель на ноду куда вставили данные
*/
    RBNode* binaryInsert(RBNode *nodefParent, RBNode *node, flatsData data);
public:

/*!
    \brief Конструктор по умолчанию
*/
    RBTree();

/*!
    \brief Вставка элемента

    Элемент вставляется как в бинарное дерево, потом производится балансировка
    \param data Данные о квартире
*/
    void insertData(flatsData Data);
/*!
    \brief Функция поиска в КЧ дереве
    \param key Ключ по которому ищем
    \return True or False
*/
    bool findData(string key);

/*!
    \brief Вывод начала вывода дерева 
*/
    void print();

/*!
    \brief Вывод дерева по возрастанию
*/
    void printTree(RBNode *node);

};
#endif