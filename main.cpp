/*!
    \file
    \brief Тело программы для бинарного дерева, хэш-таблицы, красно черного дерева
*/

#include <bits/stdc++.h>
#include "flatsData.h"
#include "BITree.h"
#include "HTable.h"
#include "RBTree.h"

using namespace std;
/*!
    \brief Функция для генерации строки определенной длины
    \param len Длина генерируемой строки
*/



int dims[10] = {10, 100, 500, 1000, 2000, 10000, 15000, 30000, 50000, 100000};
vector<vector<flatsData>> data (10, vector<flatsData> (0));

/*!
    \brief Генерация имени владельца квартир`
*/
string generateString(const int len){


    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string tmp = "";
    for (int i = 0; i < len; i++)
        tmp += alphabet[rand() % (sizeof(alphabet) - 1)];
    
    return tmp;

}


/*!
    \brief Функция для генерации данных о пассажирах
    \param dim Количество данных, которое надо сгенерировать
*/
void generateData(int dim){

    ofstream fout("data.txt");
    for (int i = 0; i < dim; i++){
        int nameLen = rand() % 50 + 20;
        string ownerName = generateString(nameLen);
        int houseNum = rand() % 200;
        int flatNum = rand() % 1000;
        int roomCount = rand() % 4 + 1;
        int flatSquare = rand() % 500; 
        int countResidents = rand() % 5;
        fout << houseNum << " " << flatNum << " " << roomCount << " " << flatSquare << " " << ownerName << " " << countResidents << "\n";
    }

    fout.close();
}

/*!
    \brief Функция чтения данных из файла о квартираъ 
    \param data Массив данных о квартирах 
*/
void readFromFile(vector<flatsData> & data){

    ifstream finp("data.txt");
    string tmp;
    data.clear();
    while(getline(finp, tmp)){
        stringstream ss(tmp);
        int houseNum, flatNum, roomCount, flatSquare, countResidents;
        string ownerName;
        ss >> houseNum >> flatNum >> roomCount >> flatSquare >> ownerName >> countResidents;
        flatsData tmpFlat(houseNum, flatNum, roomCount, flatSquare, ownerName, countResidents);
        data.push_back(tmpFlat);
    }
    finp.close();
}

/*!
    \brief Выводит данные на консоль
*/
void writeDataToConsole(vector<flatsData> &a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i].getData() << endl; 
    }
}

/*!
    \brief Записывает в файл время в наносекундах поиска бинарного дерева поиска
*/
void countTimestampsForBITree(){
    BITree tree;

    ofstream times("timestamps_BITree.txt");

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < data[i].size(); j++){
            tree.insertData(data[i][j]);
        }
        
        chrono::steady_clock::time_point time_start; 
        chrono::steady_clock::time_point time_end;
        time_start = chrono::steady_clock::now();
        tree.findData(data[i][data[i].size()/2].getName());
        time_end = chrono::steady_clock::now();
        times <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << endl; 
    }
    times.close();
}

/*!
    \brief Записывает в файл время в наносекундах поиска Хэш таблицы
*/
void countTimestampsForHashTable(){
    ofstream times("timestamps_HTable.txt");

    for (int i = 0; i < 10; i++){
        HTable table(dims[i]);
        for (int j = 0; j < data[i].size(); j++){
            table.insertData(data[i][j]);
        }
        
        chrono::steady_clock::time_point time_start; 
        chrono::steady_clock::time_point time_end;
        time_start = chrono::steady_clock::now();
        table.findData(data[i][data[i].size()/2].getName());
        time_end = chrono::steady_clock::now();
        times <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << endl;
    }

    times.close();
}


/*!
    \brief Записывает в файл время в наносекундах поиска Красночерного дерева
*/
void countTimestampsForRBTree(){
    RBTree tree;

    ofstream times("timestamps_RBTree.txt");

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < data[i].size(); j++){
            tree.insertData(data[i][j]);
        }
        
        chrono::steady_clock::time_point time_start; 
        chrono::steady_clock::time_point time_end;
        time_start = chrono::steady_clock::now();
        tree.findData(data[i][data[i].size()/2].getName());
        time_end = chrono::steady_clock::now();
        times <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << endl; 
    }
    times.close();
}


/*!
    \brief Записывает в файл время в наносекундах поиска Multiap
*/
void countTimestampsForMultiMap(){

    multimap <string, flatsData> m;

    ofstream times("timestamps_MultiMap.txt");

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < data[i].size(); j++){
            m.insert({data[i][j].getName(), data[i][j]});
        }
        
        chrono::steady_clock::time_point time_start; 
        chrono::steady_clock::time_point time_end;
        time_start = chrono::steady_clock::now();
        m.find(data[i][data[i].size()/2].getName());
        time_end = chrono::steady_clock::now();
        times <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << endl; 
    }
    times.close();
}

/*!
    \brief Генерирует данные
*/
void generateDataArray(){
    for (int i = 0; i < 10; i++){
        generateData(dims[i]);
        vector<flatsData> a;
        readFromFile(a);
        data[i] = a;
    }
}

/*!
    \brief Записывает в файл число колизий для разных размеров массива
*/
void countCollisions(){
    ofstream collisions("collision.txt");

    for (int i = 0; i < 10; i++){
        HTable table(dims[i]);
        for (int j = 0; j < data[i].size(); j++){
            table.insertData(data[i][j]);
        }
        collisions << table.countCollisions() << endl;
    }
    collisions.close();
}

int main(){

    generateDataArray();
    countTimestampsForBITree();
    countTimestampsForHashTable();
    countTimestampsForRBTree();
    countTimestampsForMultiMap();
    countCollisions();
}