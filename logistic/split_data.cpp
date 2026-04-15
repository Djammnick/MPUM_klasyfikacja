#include <bits/stdc++.h>
#include "../input.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    int benign_size;
    ifstream fin; fin.open("data/benign_size.data");
    fin >> benign_size;
    fin.close();

    int malignant_size;
    fin.open("data/malignant_size.data");
    fin >> malignant_size;
    fin.close();

    int benign_learn_size = 0.66 * benign_size, benign_test_size = benign_size - benign_learn_size;
    int malignant_learn_size = 0.66 * malignant_size, malignant_test_size = malignant_size - malignant_learn_size;

    vector<DataPoint> benignData = inputData("data/benign.data", benign_size, 10);
    vector<DataPoint> malignantData = inputData("data/malignant.data", malignant_size, 10);

    std::mt19937 g(400);

    std::shuffle(benignData.begin(), benignData.end(), g);
    std::shuffle(malignantData.begin(), malignantData.end(), g);

    vector<DataPoint> learnData, testData;

    for(int j = 0; j < benign_learn_size; j++) learnData.push_back(benignData[j]);
    for(int j = 0; j < malignant_learn_size; j++) learnData.push_back(malignantData[j]);

    for(int j = benign_learn_size; j < benign_size; j++) testData.push_back(benignData[j]);
    for(int j = malignant_learn_size; j < malignant_size; j++) testData.push_back(malignantData[j]);

    std::shuffle(learnData.begin(), learnData.end(), g);
    std::shuffle(testData.begin(), testData.end(), g);

    ofstream fout;
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