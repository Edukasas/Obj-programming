#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct data {
    string name, surname;
    int n, egzamRez; //sukurti vektoriu
    vector<int> homeWorkRez; 
    double homeWorkSum = 0, finalMark;
};

double count(double homeWorkSum, int EgzamRez);
void input(data student[], int &totalNumberOfStudents);
void output(data student[], int totalNumberOfStudents); 

int main() {
    data student[200];
    int totalNumberOfStudents;
    input(student, totalNumberOfStudents);
    output(student, totalNumberOfStudents);
    return 0;
}

double count(double homeWorkSum, int egzamRez) {
    double sum = 0.4 * homeWorkSum + egzamRez * 0.6;
    return sum;
}

void input(data student[], int &totalNumberOfStudents) {
    ifstream fd("input.txt");
    int help;
    fd >> totalNumberOfStudents;
    for(int j = 0; j < totalNumberOfStudents; j++){
        fd >> student[j].name >> student[j].surname >> student[j].n;
        for (int i = 0; i < student[j].n; i++) {
            fd >> help;
            student[j].homeWorkRez.push_back(help);
            student[j].homeWorkSum += student[j].homeWorkRez[i];
        }
        student[j].homeWorkSum /= student[j].n;
        fd >> student[j].egzamRez;
        student[j].finalMark = count(student[j].homeWorkSum, student[j].egzamRez);
    }
    fd.close();
}

void output(data student[], int totalNumberOfStudents) {
    ofstream fr ("output.txt");
    fr<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Vid.)"<<endl;
    fr<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        fr<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<student[i].finalMark<<endl;
    }
   fr<<"----";
    fr.close();
}
