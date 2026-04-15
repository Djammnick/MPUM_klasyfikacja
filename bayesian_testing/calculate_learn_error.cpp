#include <bits/stdc++.h>
#include "../input.hpp"
#include "../bayesian_error.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    int size = atoi(argv[1]);
    int seed = atoi(argv[2]);

    int testSize;
    ifstream fin; fin.open("data/learn_size_" + to_string(size) + "_" + to_string(seed) +".data");
    fin >> testSize;
    fin.close();

    ofstream fout;

    vector<DataPoint> data = inputData("data/learn_" + to_string(size) + "_" + to_string(seed) +".data", testSize);

    array<double, 2> sizes;
    vector<vector<vector<double>>> bayesCounter(2, vector<vector<double>>(9, vector<double>(10, 1.0)));
    fin.open("output/bayes_" + to_string(size) + "_" + to_string(seed) +".data");
    for(int d = 0; d < 2; d++) {
        fin >> sizes[d];
        for(int j = 0; j < 9; j++) {
            for(int c = 0; c < 10; c++) {
                fin >> bayesCounter[d][j][c];
            }
        }
    }
    fin.close();
    sizes[0] -= 9; sizes[1] -= 9;

    double acc = calculateError(data, bayesCounter, sizes);
    fout.open("output/learn_errors_" + to_string(size) + "_" + to_string(seed) +".data");
    fout << acc;
    fout.close();

}