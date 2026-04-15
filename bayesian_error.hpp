#ifndef _LOGISTIC_ERROR_HPP_
#define _LOGISTIC_ERROR_HPP_

#include <bits/stdc++.h>
#include "input.hpp"

double calculateError(vector<DataPoint>& data, vector<vector<vector<double>>>& bayesCounter, array<double, 2>& sizes) {
    int truePositives = 0, falsePositives = 0, trueNegatives = 0, falseNegatives = 0;
    double x_benign = 1, x_malign = 1;
    cout << "Calculating the estimations.\n";
    for(int i = 0; i < data.size(); i++) {
        x_benign = sizes[0];
        for(int j = 0; j < 8; j++) {
            x_benign *= bayesCounter[0][j][data[i].X[j]-1];
        }
        
        x_malign = sizes[1];
        for(int j = 0; j < 8; j++) {
            x_malign *= bayesCounter[1][j][data[i].X[j]-1];
        }

        if(x_benign > x_malign && data[i].Y == 0) trueNegatives++;
        else if(x_benign > x_malign && data[i].Y == 1) falseNegatives++;
        else if(x_benign <= x_malign && data[i].Y == 0) falsePositives++;
        else truePositives++;
    }
    
    double correct_rate = double(truePositives+trueNegatives) / data.size();
    cout << "Percent of correct guesses: " << correct_rate * 100 << "%\n";

    return correct_rate;
}

#endif