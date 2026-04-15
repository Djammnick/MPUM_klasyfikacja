#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main() {
    int learnSize;
    ifstream fin; fin.open("data/learn_size.data");
    fin >> learnSize;
    fin.close();

    vector<DataPoint> data = inputData("data/learn.data", learnSize);

    vector<set<int>> values(9);
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < 9; j++) {
            values[j].insert(data[i].X[j]);
        }
    }

    for(int i = 0; i < 9; i++) {
        cout << "Wartosci dla parametru " << i << " to byly: ";
        for(auto &x : values[i]) {
            cout << x << ' ';
        } cout << '\n';
    }

    vector<vector<vector<double>>> bayesCounter(2, vector<vector<double>>(9, vector<double>(10, 1.0)));
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].X.size(); j++) {
            bayesCounter[data[i].Y][j][data[i].X[j]-1] += 1;
        }
    }

    array<double, 2> sizes = {9, 9};
    for(int i = 0; i < data.size(); i++) {
        sizes[data[i].Y] += 1;
    }

    ofstream fout;
    fout.open("output/bayes.data");
    for(int d = 0; d < 2; d++) {
        fout << sizes[d]-9 << '\n';
        for(int j = 0; j < 9; j++) {
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