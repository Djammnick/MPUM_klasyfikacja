#include <bits/stdc++.h>
#include "../input.hpp"
#include "../gradient_descent.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int learnSize;
    ifstream fin; fin.open("data/learn_size.data");
    fin >> learnSize;
    fin.close();

    vector<double> l1_values = {0.03};
    vector<double> l2_values = {0};

    vector<DataPoint> data = inputData("data/learn.data", learnSize, 10);
    ofstream fout;
    fout.open("output/models.data");
    for(auto &l1 : l1_values) {
        for(auto &l2 : l2_values) {
            cout << "Calculating with regularization: (" << l1 << ", " << l2 << ")\n";

            vector<double> weights(data[0].X.size(), 0);
            vector<double> gradient(data[0].X.size(), 0);

            weights = gradientDescent(data, weights, l1, l2, 500, 0.1);
            weights = gradientDescent(data, weights, l1, l2, 2500, 0.03);
            weights = gradientDescent(data, weights, l1, l2, 2000, 0.01);
            weights = gradientDescent(data, weights, l1, l2, 1000, 0.003);
            weights = gradientDescent(data, weights, l1, l2, 1000, 0.001);

            for(int u = 0; u < weights.size(); u++) {
                fout << weights[u] << '\t';
            } fout << '\n';
        }
    }
}