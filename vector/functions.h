#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "standart.h"
extern vector<string> names;
extern vector<string> surnames;
struct data
{
    string name;
    string surname;
    double finalMarkAverage;
    vector<string> splited;
    int egzamRez;
    vector<int> homeWorkRez;
    double homeWorkSum = 0;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
    void randomRez();
};
void input(vector<data>& student);
void readStudentsFromFile(string &filename, vector<data> &student);
void output(vector<data>& student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
void writeIntoFile(vector<data>& student, bool option, int nameLength, string filename);
bool compareByFinalMarkAverage(const data& a, const data& b);
bool compareByFinalMarkMedian(const data& a, const data& b);
bool compareByName(const data& a, const data& b, bool option);
bool compareBySurname(const data& a, const data& b, bool option);
string nameValidation();
void sorting(vector<data>& student, bool option);
bool isNumeric(const string &str);
void generateFile(int nameLength);
void distribution(vector<data> &studentai, vector<data> &kietakai, vector<data> &vargsiukai, bool option);
#endif