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
void input(list<data>& student);
void readStudentsFromFile(string &filename, list<data> &student);
void output(list<data>& student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
void writeIntoFile(list<data>& student, bool option, int nameLength, string filename);
bool compareByFinalMarkAverage(const data& a, const data& b);
bool compareByFinalMarkMedian(const data& a, const data& b);
bool compareByName(const data& a, const data& b, bool option);
bool compareBySurname(const data& a, const data& b, bool option);
string nameValidation();
void sorting(list<data>& student, bool option);
bool isNumeric(const string &str);
void generateFile(int nameLength);
void distribution(list<data> studentai, list<data> &kietakai, list<data> &vargsiukai, bool option);
#endif