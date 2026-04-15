#ifndef _LOGISTIC_ERROR_HPP_
#define _LOGISTIC_ERROR_HPP_

#include <bits/stdc++.h>
#include "input.hpp"

double prediction(DataPoint& row, vector<double>& weights) {
    double result = 0.0;
    for (int j = 0; j < weights.size(); j++) {
        result += row.X[j] * weights[j];
    }
    return result;
}

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double get_probability(DataPoint& row, vector<double>& weights) {
    double z = 0.0;
    for (int j = 0; j < weights.size(); j++) {
        z += row.X[j] * weights[j];
    }
    return sigmoid(z);
}

double calculateError(vector<DataPoint>& data, vector<double>& weights) {
    int truePositives = 0, falsePositives = 0, trueNegatives = 0, falseNegatives = 0;

    for (int i = 0; i < data.size(); ++i) {
        double prob = get_probability(data[i], weights);
        
        int prediction = (prob >= 0.5) ? 1 : 0;
        int actual = (int)data[i].Y;

        if(prediction == 0 && actual == 1) falseNegatives++;
        else if(prediction == 0 && actual == 0) trueNegatives++;
        else if(prediction == 1 && actual == 1) truePositives++;
        else falsePositives++;
    }
    
    double error_rate = double(truePositives+trueNegatives) / data.size();
    cout << "Percent of correct guesses: " << error_rate * 100 << "%\n";

    return error_rate;
}

#endif