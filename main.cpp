#include <QCoreApplication>
#include "tasks_rk2.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    pair<int, char> temp;
    temp.first = 1;
    temp.second = 'T';
    std:: cout << temp;
    return a.exec();
}
