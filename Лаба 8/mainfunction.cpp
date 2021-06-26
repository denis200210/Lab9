#include "pch.h"
#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    char input[100];
    int j = 0;
    for (j = 0; j < 100; ++j)
    {
        input[j] = 0;
    }
    cout << "¬ведите выражение : " << endl;
    cin.getline((char*)input, 100);
    cout << endl   << Obratnaipoliskai(input) << endl << endl;
}

