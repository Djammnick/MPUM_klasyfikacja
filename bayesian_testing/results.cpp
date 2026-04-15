#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> sizes = {5, 10, 15, 20, 25, 35, 50, 75, 100, 125, 150, 175, 200, 225, 250, 286, 300, 325, 350, 375, 400, 425, 457};
    vector<int> seeds = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    ifstream fin;
    ofstream fout;
    double inp;
    double sum;

    vector<double> results(sizes.size());
    
    for(int i = 0; i < sizes.size(); i++) {
        sum = 0;
        for(auto &seed : seeds) {
            fin.open("output/test_errors_" + to_string(sizes[i]) + "_" + to_string(seed) + ".data");
            fin >> inp; sum += inp;
            fin.close();
        }
        sum /= seeds.size();
        results[i] = sum;
    }

    for(int i = 0; i < sizes.size(); i++) {
        cout << sizes[i] << ' ' << results[i] << '\n';
    }

    fout.open("results.data");
    for(int i = 0; i < sizes.size(); i++) {
        fout << sizes[i] << ", ";
    } fout << '\n';
    for(int i = 0; i < sizes.size(); i++) {
        fout << 1-results[i] << ", ";
    } fout << '\n';
    fout.close();
}