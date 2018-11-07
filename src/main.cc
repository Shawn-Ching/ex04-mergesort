//
// Created by Shawn Ching on 9/26/18.
//
#include <iostream>
#include "mergesort.h"

using edu::vcccd::vc::csv15::mergesort;
using std::cout;
using std::endl;

int main (int argc, char *argv[]) {
    //int array[] = {2,3,5,7,1,4,6,8,9};
    int array [] = { 2, 4, 1, 6, 8, 5, 3, 7};

    cout << "ORIG : | ";
    for(int i = 0; i <= 7; i++)
    {
        cout << array[i] << " | ";
    }
    cout << endl;

    mergesort(array, 8);

    cout << "SORT : | ";
    for(int i = 0; i <= 7; i++)
    {
        cout << array[i] << " | ";
    }
};
