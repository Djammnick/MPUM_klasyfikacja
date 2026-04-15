#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main() {

    vector<DataPoint> data = inputData("../rp.data", 693);

    std::mt19937 g(42);

    std::shuffle(data.begin(), data.end(), g);

    vector<DataPoint> data2, data4;
    for(int i = 0; i < data.size(); i++) {
        if(data[i].Y == 2) data2.push_back(data[i]);
        else data4.push_back(data[i]);
    }

    cout << "Rozmiar benign: " << data2.size() << " malignant " << data4.size() << '\n';

    ofstream fout;
    fout.open("data/benign.data");
    for(int j = 0; j < data2.size(); j++) {
        fout << 1 << '\t';
        for(int k = 0; k < data2[j].X.size(); k++) {
            fout << data2[j].X[k] << '\t';
        }
        fout << data2[j].Y << '\n';
    }
    fout.close();
    
    fout.open("data/malignant.data");
    for(int j = 0; j < data4.size(); j++) {
        fout << 1 << '\t';
        for(int k = 0; k < data4[j].X.size(); k++) {
            fout << data4[j].X[k] << '\t';
        }
        fout << data4[j].Y << '\n';
    }
    fout.close();

    fout.open("data/benign_size.data");
    fout << data2.size(); cout << data2.size() << " probek danych benign.\n";
    fout.close();

    fout.open("data/malignant_size.data");
    fout << data4.size(); cout << data4.size() << " probek danych malignant.\n";
}