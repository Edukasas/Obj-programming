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
int parameterForSorting();
void mergeRuns(vector<ifstream>& infiles, bool option, int nameLength);
void mergeRuns2(vector<ifstream>& infiles, bool option, int nameLength);
void sortAndWriteChunk(vector<data>& student, int fileIndex, bool option, int nameLength);
void topSection(vector<data> &student, int nameLength, string filename, bool &option, int &fileIndex, int &choice, bool &screenInput);
bool isNumeric(const string &str);
void generateFile(int nameLength);
void input(vector<data>& student);
void readStudentsFromFile(string &filename, vector<data>& student, bool option, int nameLength, int &fileIndex, int &choice);
void output(vector<data>& student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
bool compareByFinalMarkAverage(const data& a, const data& b);
bool compareByFinalMarkMedian(const data& a, const data& b);
bool compareByName(const data& a, const data& b, bool option);
bool compareBySurname(const data& a, const data& b, bool option);
string nameValidation();
void sorting(vector<data>& student, bool option, int a);
void bigMerge(int fileIndex, bool option, int nameLength, bool outputChoice);
void writeIntoFile(vector<data> &student, bool option, int nameLength, string filename);
#endif