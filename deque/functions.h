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
void input(deque<data>& student);
void readStudentsFromFile(string &filename, deque<data> &student);
void output(deque<data>& student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
void writeIntoFile(deque<data>& student, bool option, int nameLength, string filename);
bool compareByFinalMarkAverage(const data& a, const data& b);
bool compareByFinalMarkMedian(const data& a, const data& b);
bool compareByName(const data& a, const data& b, bool option);
bool compareBySurname(const data& a, const data& b, bool option);
string nameValidation();
void sorting(deque<data>& student, bool option);
bool isNumeric(const string &str);
void generateFile(int nameLength);
void distribution(deque<data> &studentai, deque<data> &kietakai, deque<data> &vargsiukai, bool option);
#endif