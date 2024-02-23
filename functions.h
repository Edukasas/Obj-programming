#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "standart.h"
extern vector<string> names;
extern vector<string> surnames;
struct data
{
    string name;
    string surname;
    vector<string> splited;
    int egzamRez;
    vector<int> homeWorkRez;
    double homeWorkSum = 0;
    double finalMarkAverage;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
    void randomRez();
};
void input(vector<data>& student);
void readStudentsFromFile(const string filename, vector<data>& student);
void output(vector<data>& student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
void writeIntoFile(vector<data>& student, bool option, int nameLength);
bool compareByFinalMarkAverage(const data& a, const data& b);
bool compareByFinalMarkMedian(const data& a, const data& b);
bool compareByName(const data& a, const data& b);
bool compareBySurname(const data& a, const data& b);
string nameValidation();
void sorting(vector<data>& student, bool option);
#endif