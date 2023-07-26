// Created by Dayu Wang (dwang@stchas.edu) on 2021-04-02

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-04-04


#include "Complex_Number.h"

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // Open the input file.
    ifstream fin("complex_numbers.txt");

    // Test whether the input file was successfully opened.
    if (!fin) {
        cout << "[Error] Nonexistent input file" << endl;
        system("pause");
        return -1;
    }

    // Open the output file.
    ofstream fout("results.txt");

    // Read the input file, add the complex numbers, and write the addition results to the output file.
    Complex_Number c_num_1, c_num_2;
    while (fin >> c_num_1 >> c_num_2) { fout << c_num_1 + c_num_2 << endl; }

    // Close the input and output file.
    fin.close();
    fout.close();

    return 0;
}