#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main() {
    int learnSize;
    ifstream fin; fin.open("data/learn_size.data");
    fin >> learnSize;
    fin.close();

    vector<DataPoint> data = inputData("data/learn.data", learnSize, 12);

    vector<set<int>> values(12);
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < 12; j++) {
            values[j].insert(data[i].X[j]);
        }
    }

    vector<vector<vector<double>>> bayesCounter(2, vector<vector<double>>(12, vector<double>(10, 1.0)));
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].X.size(); j++) {
            bayesCounter[data[i].Y][j][data[i].X[j]-1] += 1;
        }
    }

    array<double, 2> sizes = {12, 12};
    for(int i = 0; i < data.size(); i++) {
        sizes[data[i].Y] += 1;
    }

    ofstream fout;
    fout.open("output/bayes.data");
    for(int d = 0; d < 2; d++) {
        fout << sizes[d]-12 << '\n';
        for(int j = 0; j < 12; j++) {
            for(int c = 0; c < 10; c++) {
                cout << "P(x_" << j << " = " << c << " | y = " << d << ") = " << bayesCounter[d][j][c]/sizes[d] << '\n';
                fout << bayesCounter[d][j][c] / sizes[d] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';
    }
    fout.close();
}