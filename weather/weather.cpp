//
//  main.cpp
//  weather
//
//  Created by Jamie Yadoff on 11/3/19.
//  Copyright © 2019 Jamie Yadoff. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <vector>
#include <map>
#include "xcode_redirect.hpp"

using namespace std;


class WeatherData {
private:
    vector<vector<int>> filedata;
    vector<string> headers;
    vector<int> precipitation;
    vector<int> january;
    vector<int> february;
    vector<int> march;
    vector<int> april;
    vector<int> may;
    vector<int> june;
    vector<int> july;
    vector<int> august;
    vector<int> september;
    vector<int> october;
    vector<int> november;
    vector<int> december;
    vector<int> winter;
    vector<int> spring;
    vector<int> summer;
    vector<int> fall;
    vector<int> avgmonth;
    vector<int> avgseason;
    vector<int> allhightemps;
    double avgprec = 0;
    double avghigh = 0;
    
public:
    //constructor, initializes the 2D vector from the modified file
    WeatherData() {
        string junk;
        int inputdata;
        for (int i = 0; i < 4; i++) {
            cin >> junk;
            headers.push_back(junk);
        }
        for (int i = 0; i < 365; i++) {
            vector<int> data;
            for (int i = 0; i < 4; i++) {
                cin >> inputdata;
                data.push_back(inputdata);
            }
            filedata.push_back(data);
        }
        
    }
    
    //calculates a vector for each month of just high temperatures
    //then calculates the avg high temp from each vector and puts each in one vector of all avgs
    void calculateMonth() {
        int month = 0;
        for (int i = 0; i < filedata.size(); i++) {
            month = (filedata[i][0] % 2010) / 100;
            if (month == 1) {
                january.push_back(filedata[i][2]);
            }
            else if (month == 2) {
                february.push_back(filedata[i][2]);
            }
            else if (month == 3) {
                march.push_back(filedata[i][2]);
            }
            else if (month == 4) {
                april.push_back(filedata[i][2]);
            }
            else if (month == 5) {
                may.push_back(filedata[i][2]);
            }
            else if (month == 6) {
                june.push_back(filedata[i][2]);
            }
            else if (month == 7) {
                july.push_back(filedata[i][2]);
            }
            else if (month == 8) {
                august.push_back(filedata[i][2]);
            }
            else if (month == 9) {
                september.push_back(filedata[i][2]);
            }
            else if (month == 10) {
                october.push_back(filedata[i][2]);
            }
            else if (month == 11) {
                november.push_back(filedata[i][2]);
            }
            else if (month == 12) {
                december.push_back(filedata[i][2]);
            }
        }
        int total = 0;
        for (int i = 0; i < january.size(); i++) {
            total += january[i];
        }
        total /= january.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < february.size(); i++) {
            total += february[i];
        }
        total /= february.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < march.size(); i++) {
            total += march[i];
        }
        total /= march.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < april.size(); i++) {
            total += april[i];
        }
        total /= april.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < may.size(); i++) {
            total += may[i];
        }
        total /= may.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < june.size(); i++) {
            total += june[i];
        }
        total /= june.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < july.size(); i++) {
            total += july[i];
        }
        total /= july.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < august.size(); i++) {
            total += august[i];
        }
        total /= august.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < september.size(); i++) {
            total += september[i];
        }
        total /= september.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < october.size(); i++) {
            total += october[i];
        }
        total /= october.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < november.size(); i++) {
            total += november[i];
        }
        total /= november.size();
        avgmonth.push_back(total);
        total = 0;
        for (int i = 0; i < december.size(); i++) {
            total += december[i];
        }
        total /= december.size();
        avgmonth.push_back(total);
    }
    
    //calculates a vector for each season of just low temperatures
    //then calculates the median for each season and puts each in one vector of all medians
    void calculateSeason() {
        //winter was until march 20 and after december 21
        //spring was until june 21
        //summer was until september 22
        //fall was until december 21
        for (int i = 0; i < filedata.size(); i++) {
            if (i >= 0 && i < 79) {
                winter.push_back(filedata[i][1]);
            }
            else if (i >= 79 && i < 172) {
                spring.push_back(filedata[i][1]);
            }
            else if (i >= 172 && i < 265) {
                summer.push_back(filedata[i][1]);
            }
            else if (i >= 265 && i < 355) {
                fall.push_back(filedata[i][1]);
            }
            else if (i >= 355 && i < 365) {
                winter.push_back(filedata[i][1]);
            }
        }
        sort(winter.begin(), winter.end());
        sort(summer.begin(), summer.end());
        sort(spring.begin(), spring.end());
        sort(fall.begin(), fall.end());
        
        int median = 0;
        median = winter[winter.size()/2];
        avgseason.push_back(median);
        median = spring[spring.size()/2];
        avgseason.push_back(median);
        median = summer[summer.size()/2];
        avgseason.push_back(median);
        median = (fall[winter.size()/2] + fall[winter.size()/2+1])/2;
        avgseason.push_back(median);
    }
    
    //calculates a vector of all the precipitations in the year
    void calculatePrecipitation() {
        for (int i = 0; i < filedata.size(); i++) {
            precipitation.push_back(filedata[i][3]);
        }
    }
    
    //uses linear regression algorithm to calculate slope of precipitation and high temperature graph
    double calculateSlopePrecHighlinearregression() {
        for (int i = 0; i < filedata.size(); i++) {
            allhightemps.push_back(filedata[i][2]);
        }
        for (int i = 0; i < precipitation.size(); i++) {
            avgprec+= precipitation[i];
        }
        avgprec /= precipitation.size();
        for (int i = 0; i < allhightemps.size(); i++) {
            avghigh += allhightemps[i];
        }
        avghigh /= allhightemps.size();
        
        double numerator = 0.0;
        double denominator = 0.0;
        double ratio = 0.0;
        for (int i = 0; i < precipitation.size(); i++) {
            numerator += (precipitation[i] - avgprec) * (allhightemps[i] - avghigh);
            denominator += (precipitation[i] - avgprec) * (precipitation[i] - avgprec);
        }
        ratio = numerator / denominator;
        return ratio;
    }
    
    //displays the function from the linear regression line
    void displayLinearRegression() {
        double slope = calculateSlopePrecHighlinearregression();
        cout << "This is for the information for the graph of Precipitation and High Temperature in 2010" << endl;
        cout << "(with precipitation as x and high temperature as y)" << endl;
        cout << "Slope of linear regression line: " << slope << endl;
        
        double intercept = avghigh - (slope*avgprec);
        cout << "Intercept of linear regression line: " << intercept << endl;
        cout << "Equation for relationship: (hightemp) = " << slope << "(precipitation) + " << intercept << endl;
    }
    
    //displays the data for avg high temp for each month in numbers
    void displayMonth() {
        cout << "Month Number with Corresponding Average High Temperature 2010" << endl;
        for (int i = 0; i < avgmonth.size(); i++) {
            cout << i+1 << ": " << avgmonth[i] << endl;
        }
        cout << endl;
    }
    
    //displays the data for median low temp for each season
    void displaySeason() {
        cout << "Season with Corresponding Median Low Temperature 2010" << endl;
        cout << "Winter: " << avgseason[0] << endl;
        cout << "Spring: " << avgseason[1] << endl;
        cout << "Summer: " << avgseason[2] << endl;
        cout << "Fall: " << avgseason[3] << endl;
        cout << endl;
    }
    
    //displays the data for precipitation over the year in a scatter plot type graph
    void displayPrecipitation() {
        cout << "Day with Corresponding Precipitation 2010" << endl;
        for (int i = 0; i < precipitation.size(); i++) {
            cout << i+1 << ": ";
            for (int j = 0; j < precipitation[i]; j++) {
                cout << " ";
            }
            cout << "*" << endl;
        }
        cout << endl;
    }
};

int main(int argc, char * argv[]) {
    // insert code here...
    //okay download csv into vector of vector (of strings??)
    //then make vectors for each month and season
    //to display make a vertical scatterplot w nested for and * for points
    
    xcode_redirect(argc, argv);
    WeatherData test;
    test.calculateMonth();
    test.calculateSeason();
    test.calculatePrecipitation();
    test.displayPrecipitation();
    test.displayMonth();
    test.displaySeason();
    test.displayLinearRegression();
    
    return 0;
}
