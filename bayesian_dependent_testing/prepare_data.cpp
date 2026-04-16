#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    int size = atoi(argv[1]);
    int seed = stoi(argv[2]);

    vector<DataPoint> data = inputData("../rp.data", 693);

    vector<DataPoint> benignData, malignantData;
    for(int i = 0; i < data.size(); i++) {
        data[i].X.push_back(data[i].X[7]);
        data[i].X.push_back(data[i].X[7]);
        data[i].X.push_back(data[i].X[7]);
        if(data[i].Y == 2) benignData.push_back(data[i]);
        else malignantData.push_back(data[i]);
    }

    cout << "Rozmiar benign: " << benignData.size() << " malignant " << malignantData.size() << " calosc: " << 693 << '\n';

    ofstream fout;

    int benign_learn_size = 0.66 * benignData.size(), benign_test_size = benignData.size() - benign_learn_size;
    int malignant_learn_size = 0.66 * malignantData.size(), malignant_test_size = malignantData.size() - malignant_learn_size;

    std::mt19937 g(seed);

    std::shuffle(benignData.begin(), benignData.end(), g);
    std::shuffle(malignantData.begin(), malignantData.end(), g);

    vector<DataPoint> learnData, testData;

    for(int j = 0; j < benign_learn_size; j++) learnData.push_back(benignData[j]);
    for(int j = 0; j < malignant_learn_size; j++) learnData.push_back(malignantData[j]);

    for(int j = benign_learn_size; j < benignData.size(); j++) testData.push_back(benignData[j]);
    for(int j = malignant_learn_size; j < malignantData.size(); j++) testData.push_back(malignantData[j]);

    std::shuffle(learnData.begin(), learnData.end(), g);
    std::shuffle(testData.begin(), testData.end(), g);

    while(learnData.size() > size) learnData.pop_back();
    
    fout.open("data/learn_" + to_string(size) + "_" + to_string(seed) +".data");
    if(!fout.good()) throw runtime_error("Could not open learn file");
    for(int j = 0; j < learnData.size(); j++) {
        for(int i = 0; i < learnData[j].X.size(); i++) {
            fout << learnData[j].X[i] << '\t';
        }
        fout << (learnData[j].Y == 2 ? 0 : 1) << '\n';
    }
    fout.close();
    
    fout.open("data/test_" + to_string(size) + "_" + to_string(seed) +".data");
    if(!fout.good()) throw runtime_error("Could not open test file");
    for(int j = 0; j < testData.size(); j++) {
        for(int i = 0; i < testData[j].X.size(); i++) {
            fout << testData[j].X[i] << '\t';
        }
        fout << (testData[j].Y == 2 ? 0 : 1) << '\n';
    }
    fout.close();

    fout.open("data/learn_size_" + to_string(size) + "_" + to_string(seed) +".data");
    fout << learnData.size(); cout << learnData.size() << " probek danych treningowych.\n";
    fout.close();

    fout.open("data/test_size_" + to_string(size) + "_" + to_string(seed) +".data");
    fout << testData.size(); cout << testData.size() << " probek danych testowych.\n";
    fout.close();
}