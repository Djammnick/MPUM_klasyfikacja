#include <bits/stdc++.h>
#include "../input.hpp"
#include "../logistic_error.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int size = atoi(argv[1]);
    int seed = stoi(argv[2]);

    int testSize;
    ifstream fin; fin.open("data/test_size_" + to_string(size) + "_" + to_string(seed) + ".data");
    fin >> testSize;
    fin.close();

    vector<DataPoint> data = inputData("data/test_" + to_string(size) + "_" + to_string(seed) + ".data", testSize, 10);

    vector<double> weights(data[0].X.size());

    vector<double> l1_values = {0.03};
    vector<double> l2_values = {0};

    ofstream fout;
    fin.open("output/models_" + to_string(size) + "_" + to_string(seed) +".data");
    fout.open("output/test_errors_" + to_string(size) + "_" + to_string(seed) +".data");
    for(auto &l1 : l1_values) {
        for(auto &l2 : l2_values) {
            cout << "Calculating with regularization: (" << l1 << ", " << l2 << ")\n";
            for(int j = 0; j < data[0].X.size(); j++) {
                fin >> weights[j];
            }
            fout << l1 << '\t' << l2 << '\t' << calculateError(data, weights) << '\n';
        }
    }
    fout.close();
    fin.close();
}