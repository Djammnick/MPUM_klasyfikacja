#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include <bits/stdc++.h>
using namespace std;

struct DataPoint {
    vector<double> X;
    double Y;
};

double stringToDouble(string s) {
    replace(s.begin(), s.end(), ',', '.');
    return stod(s);
}

string to_readable_string(double val) {
    std::stringstream sstream;
    sstream << val;
    return sstream.str();
}

vector<DataPoint> inputData(string fileName, int dataSize, int xLength = 9) {
    ifstream fin;
    fin.open(fileName);
    if(!fin.good()) throw runtime_error("Could not open input file " + fileName);

    vector<DataPoint> data;
    DataPoint input;
    string s;

    while(dataSize--) {
        input.X = vector<double>(xLength);
        for(auto &x : input.X) {
            fin >> s;
            x = stringToDouble(s);
        }
        fin >> s;
        input.Y = stringToDouble(s);
        data.push_back(input);
    }
    fin.close();

    return data;
}

vector<double> readWeights(string fileName, int size) {
    ifstream fin;
    fin.open(fileName);
    if(!fin.good()) throw runtime_error("Could not read weights (have you forgotten to calculate them?)");

    vector<double> weights(size);
    for(int i = 0; i < size; i++) {
        fin >> weights[i];
    }
    fin.close();

    return weights;
}

#endif