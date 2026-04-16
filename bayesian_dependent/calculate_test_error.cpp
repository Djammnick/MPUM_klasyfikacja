#include <bits/stdc++.h>
#include "../input.hpp"
#include "../bayesian_error.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int testSize;
    ifstream fin; fin.open("data/test_size.data");
    fin >> testSize;
    fin.close();

    ofstream fout;

    vector<DataPoint> data = inputData("data/test.data", testSize, 12);

    array<double, 2> sizes;
    vector<vector<vector<double>>> bayesCounter(2, vector<vector<double>>(12, vector<double>(10, 1.0)));
    fin.open("output/bayes.data");
    for(int d = 0; d < 2; d++) {
        fin >> sizes[d];
        for(int j = 0; j < 12; j++) {
            for(int c = 0; c < 10; c++) {
                fin >> bayesCounter[d][j][c];
            }
        }
    }
    fin.close();
    sizes[0] -= 12; sizes[1] -= 12;

    for(int d = 0; d < 2; d++) {
        cout << sizes[d] << '\n';
        for(int j = 0; j < 12; j++) {
            for(int c = 0; c < 10; c++) {
                cout << "P(x_" << j << " = " << c << " | y = " << d << ") = " << bayesCounter[d][j][c] << '\n';
            }
        }
    }

    double acc = calculateError(data, bayesCounter, sizes, 12);
    fout.open("output/test_errors.data");
    fout << acc;
    fout.close();

}