#ifndef _GRADIENT_DESCENT_HPP_
#define _GRADIENT_DESCENT_HPP_

#include <bits/stdc++.h>
#include "input.hpp"
using namespace std;

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

vector<double> calculateGradient(vector<DataPoint>& data, vector<double> weights, double lambda1, double lambda2) {
    vector<double> gradient(data[0].X.size(), 0);
    double l1_error, l2_error;

    int cnt = 0;
    for(auto &x : data) {
        cnt++;
        double correct = x.Y;
        double prediction = 0;
        for(int j = 0; j < x.X.size(); j++) {
            prediction += weights[j] * x.X[j];
        }

        prediction = sigmoid(prediction);

        for(int j = 0; j < x.X.size(); j++) {
            gradient[j] += (prediction - correct) * x.X[j];
        }
    }
    
    gradient[0] /= data.size();
    for (int j = 1; j < data[0].X.size(); ++j) {
        gradient[j] /= data.size();

        double l1_term = lambda1 * (weights[j] == 0 ? 0 : (weights[j] > 0 ? 1 : -1));
        double l2_term = lambda2 * weights[j];
        gradient[j] += (l1_term + l2_term);
    }
    return gradient;
}

vector<double> gradientDescent(
    vector<DataPoint>& data,
    vector<double>& init,
    double lambda1 = 0,
    double lambda2 = 0,
    int iterations = 100,
    double learningRate = 0.1
) {
    vector<double> weights = init;
    vector<double> gradient;
    double learningError;

    for(int i = 1; i <= iterations; i++) {
        gradient = calculateGradient(data, weights, lambda1, lambda2);
        for(int j = 0; j < weights.size(); j++) {
            weights[j] = weights[j] - (learningRate * gradient[j]);
        }
        if(i % 100 == 0) {
            cout << i << "/" << iterations << "\n";
        }
    }

    return weights;
}

#endif