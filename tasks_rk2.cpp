#include <map>
#include <list>


#include "tasks_rk2.h"

//task1
Node::Node()
{

}
Node::Node(int nameNode)
{

}
Node::~Node()
{

}

Graph::Graph()
{

}
Graph::Graph(int countNodes)
{

}
Graph::~Graph()
{

}
int Graph::buildTreeBFS(int countNodes)
{

}
int Graph::buildTreeDFS(int countNodes) {}
void Graph::BFS()
{

}
void Graph::DFS() {}
std::pair<bool, list<int>> Graph::searchDFS(int nameNode)	 {}
std::pair<bool, list<int>> Graph::searchBFS(int nameNode)
{

}

//task2
pair<int/*index el*/, int /*count call*/> binSearch(int* ar, int sizeAr, int el)
{
    static int cnt = 0;
    cnt++;
    if (sizeAr <= 0)
    {
        pair<int, int> temp;
        temp.first = -1;
        temp.second = cnt;
        return temp;
    }
    if (ar[sizeAr / 2] == el)
    {
        pair<int, int> temp;
        temp.first = sizeAr / 2;
        temp.second = cnt;
        return temp;
    }

    //    Правила обработки массива:
    //        1. Если размер массива нечетное число, центральный элемент приписывается в правую часть. Левая часть меньше правой на 1 элемент.
    //           2. Если размер массива четное число, то центральный элемент приписывается в левую часть. Левая = правая часть.

    double mytemp = sizeAr / 2.0;
    int myinttemp = sizeAr / 2;
    double sr = myinttemp;

    if (mytemp == sr) //Значит делится
    {
        if (el >= ar[myinttemp]) //Значит пойдем вправо
        {
            pair<int, int> z = binSearch(&ar[sizeAr / 2], sizeAr / 2, el);
            int per = z.first + sizeAr / 2;
            pair<int, int> vozvrat;
            vozvrat.first = per;
            vozvrat.second = cnt;
            return vozvrat;
        }
        else //Значит нам надо влево
        {
            pair<int, int> z = binSearch(ar, sizeAr / 2, el);
            int per = z.first;
            pair<int, int> vozvrat;
            vozvrat.first = per;
            vozvrat.second = cnt;
            return vozvrat;
        }
    }
    else
    {
        if (el >= ar[myinttemp]) //Значит пойдем вправо
        {
            pair<int, int> z = binSearch(&ar[sizeAr / 2], myinttemp + 1, el);
            int per = z.first + sizeAr / 2;
            pair<int, int> vozvrat;
            vozvrat.first = per;
            vozvrat.second = cnt;
            return vozvrat;
        }
        else //Значит нам надо влево
        {
            pair<int, int> z = binSearch(ar, myinttemp, el);
            int per = z.first;
            pair<int, int> vozvrat;
            vozvrat.first = per;
            vozvrat.second = cnt;
            return vozvrat;
        }

    }
}


//task3

//task4
//task5
