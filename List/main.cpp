#include<iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    for (int i = 0; i < l.getSize(); i++)
    {
        cout << l[i] << "\n";
    }
    cout << "-------------------------------\n";
    l.pop_front();
    l.pop_back();
    for (int i = 0; i < l.getSize(); i++)
    {
        cout << l[i] << "\n";
    }
}