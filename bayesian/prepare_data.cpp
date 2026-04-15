#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main() {

    // Transform the previous data file into a new one, which contains higher degree parameters.

    vector<DataPoint> data = inputData("../rp.data", 693);

    vector<DataPoint> benignData, malignantData;
    for(int i = 0; i < data.size(); i++) {
        if(data[i].Y == 2) benignData.push_back(data[i]);
        else malignantData.push_back(data[i]);
    }

    cout << "Rozmiar benign: " << benignData.size() << " malignant " << malignantData.size() << " calosc: " << 693 << '\n';

    ofstream fout;
    fout.open("data/benign.data");
    for(int j = 0; j < benignData.size(); j++) {
        for(int k = 0; k < benignData[j].X.size(); k++) {
            fout << benignData[j].X[k] << '\t';
        }
        fout << benignData[j].Y << '\n';
    }
    fout.close();
    
    fout.open("data/malignant.data");
    for(int j = 0; j < malignantData.size(); j++) {
        for(int k = 0; k < malignantData[j].X.size(); k++) {
            fout << malignantData[j].X[k] << '\t';
        }
        fout << malignantData[j].Y << '\n';
    }
    fout.close();

    fout.open("data/benign_size.data");
    fout << benignData.size(); cout << benignData.size() << " probek danych benign.\n";
    fout.close();

    fout.open("data/malignant_size.data");
    fout << malignantData.size(); cout << malignantData.size() << " probek danych malignant.\n";
    fout.close();

    int benign_learn_size = 0.66 * benignData.size(), benign_test_size = benignData.size() - benign_learn_size;
    int malignant_learn_size = 0.66 * malignantData.size(), malignant_test_size = malignantData.size() - malignant_learn_size;

    std::mt19937 g(42);

    std::shuffle(benignData.begin(), benignData.end(), g);
    std::shuffle(malignantData.begin(), malignantData.end(), g);

    vector<DataPoint> learnData, testData;

    for(int j = 0; j < benign_learn_size; j++) learnData.push_back(benignData[j]);
    for(int j = 0; j < malignant_learn_size; j++) learnData.push_back(malignantData[j]);

    for(int j = benign_learn_size; j < benignData.size(); j++) testData.push_back(benignData[j]);
    for(int j = malignant_learn_size; j < malignantData.size(); j++) testData.push_back(malignantData[j]);

    std::shuffle(learnData.begin(), learnData.end(), g);
    std::shuffle(testData.begin(), testData.end(), g);
    
    fout.open("data/learn.data");
    if(!fout.good()) throw runtime_error("Could not open learn file");
    for(int j = 0; j < learnData.size(); j++) {
        for(int i = 0; i < learnData[j].X.size(); i++) {
            fout << learnData[j].X[i] << '\t';
        }
        fout << (learnData[j].Y == 2 ? 0 : 1) << '\n';
    }
    fout.close();
    
    fout.open("data/test.data");
    if(!fout.good()) throw runtime_error("Could not open test file");
    for(int j = 0; j < testData.size(); j++) {
        for(int i = 0; i < testData[j].X.size(); i++) {
            fout << testData[j].X[i] << '\t';
        }
        fout << (testData[j].Y == 2 ? 0 : 1) << '\n';
    }
    fout.close();

    fout.open("data/learn_size.data");
    fout << learnData.size(); cout << learnData.size() << " probek danych treningowych.\n";
    fout.close();

    fout.open("data/test_size.data");
    fout << testData.size(); cout << testData.size() << " probek danych testowych.\n";
    fout.close();
}