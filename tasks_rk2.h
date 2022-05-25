#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

//task1
struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    std::list<Node*> listChilds;
    int marker;
    int name;
    static int countNodes;
};

class Graph {
    private :
        Node* head;
        //здесь можно писать любые функции, которые могут понадобиться
    public :
        Graph();
        Graph(int countNodes);
        ~Graph();
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeBFS(int countNodes);
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeDFS(int countNodes);
        /*
            description	:	обход графа и записи вершин в файл
            input		:
            output		:
            author		:
            date		:
            version		:
        */
        void BFS();
        void DFS();
        /*
            description	:	функция поиска узла по его имени,
                            DFS - № студ билет чётный
                            BSD - № студ билет нечётный
            input 		:	nameNode -- имя узла
            output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
            description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
            author		:
            date		:
            version		:
        */
        std::pair<bool, list<int>> searchDFS(int nameNode);
        std::pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo {
    private :
        T* ar;	//массив
        int size;	//размер массива
        int countData;	//число элементов в массиве
    public :
        Filo()
        {
            ar = new T[10];
            size = 10;
            countData = 0;
        }
        Filo(int _size)
        {
            ar = new T[_size];
            size = _size;
            countData = 0;
        }
        ~Filo()
        {
            delete[] ar;
            size = -1;
            countData = 0;
        }
        /*
            input		:	элемент который надо добавить
            output		:	1 - элемент добавлен, 0 - элемент не добавлен
            description	:	добавление элемента в конец массива
        */
        int push_back(T el)
        {
            if(size - countData > 0)
            {
                ar[countData] = el;
                countData++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        /*
            input		:	элемент который надо добавить
            output		:	пара
                            значение первого аргумента пары
                                1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            значение второго аргумента пары -- это извлечённый элемент
            description	:	извлечение элемента из массива
        */
        pair<int,T> pop_back()
        {
            if(countData<=0)
            {
                pair<int, T> temp;
                temp.first = 0;
                return temp;
            }
            else
            {
                if(size>0)
                {
                    pair<int, T> temp;
                    temp.first = 1;
                    temp.second = ar[countData-1];
                    countData--;
                    return temp;
                }
            }
        }
        /*
            input		:	элемент который надо добавить
            output		:	пара
                            значение первого аргумента пары
                                1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            значение второго аргумента пары -- это извлечённый элемент
            description	:	извлечение элемента из массива
        */
        void returnAr() {}
};

//task4
template<class T>
std::ostream& operator<<(std::ostream& os, const pair<int,T> temp)
{
    os << "(" << temp.first << ", " << temp.second << ")" << std::endl;
    return os;
}

//task5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //можно объявляеть любые переменные и функции
    string vvod;
public :
    CheckBrackets() : Filo<char>() {}
      CheckBrackets(int klv) : Filo<char>(klv) {}
    ~CheckBrackets() {}
    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок
    */
    int checkBrackets(const char* strBrackets)
    {
        vvod = strBrackets;
        Filo<char> skobochki(vvod.length());
        for(int i = 0; i < vvod.length(); i++)
        {
            if(vvod[i] == '(' || vvod[i] == '[' || vvod[i] == '{')
            {
                skobochki.push_back(vvod[i]);
            }
            else
            {
                if(vvod[i] == ')')
                {
                    pair<int, char> a = skobochki.pop_back();
                    if(a.first == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        if(a.second != '(')
                        {
                            return 1;
                        }
                    }
                }
                else
                {
                    if(vvod[i] == ']')
                    {
                        pair<int, char> a = skobochki.pop_back();
                        if(a.first == 0)
                        {
                            return 1;
                        }
                        else
                        {
                            if(a.second != '[')
                            {
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        if(vvod[i] == '}')
                        {
                            pair<int, char> a = skobochki.pop_back();
                            if(a.first == 0)
                            {
                                return 1;
                            }
                            else
                            {
                                if(a.second != '{')
                                {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        pair<int, char> a = skobochki.pop_back();
        if(a.first == 0)
            return 0;
        else
            return 1;
    }
};
