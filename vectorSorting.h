#ifndef VECTOR_SORTING_H
#define VECTOR_SORTING_H

#include <iostream>
using namespace std;

class vectorSorting
{
private:
    vector <int> lista;
    int size;
public:
    vectorSorting(int n);
    ~vectorSorting();
    void input();
    void sort();
    void print();
    void swap(int &a, int &b);
};

#endif