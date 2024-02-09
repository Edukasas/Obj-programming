#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct data {
    string name, surname;
    int n, egzamRez;
    vector<int> homeWorkRez; 
    double homeWorkSum = 0, finalMark;
};

double count(double homeWorkSum, int EgzamRez);
void input(auto &student, int &totalNumberOfStudents);
void output(auto &student, int totalNumberOfStudents);
int main() {
    vector<data> student;
    int totalNumberOfStudents;
    cout<<"Moksleiviu skaicius"<<endl;
    cin>>totalNumberOfStudents;
    input(student, totalNumberOfStudents);
    output(student, totalNumberOfStudents);
    return 0;
}

double count(double homeWorkSum, int egzamRez) {
    return 0.4 * homeWorkSum + egzamRez * 0.6;
}

void input(auto &student, int &totalNumberOfStudents) {
        for(int j = 0; j < totalNumberOfStudents; j++) {
        data newStudent;
        cout << "Studento vardas" << endl;
        cin >> newStudent.name;
        cout << "Studento pavarde" << endl;
        cin >> newStudent.surname;
        cout << "Ivertinimu skaicius" << endl;
        cin >> newStudent.n;
        int help;
        for (int i = 0; i < newStudent.n; i++) {
            cout << "Ivertinimas" << endl;
            cin >> help;
            newStudent.homeWorkRez.push_back(help);
            newStudent.homeWorkSum += help;
        }
        newStudent.homeWorkSum /= newStudent.n;
        cout << "Egzamino rezultatas" << endl;
        cin >> newStudent.egzamRez;
        newStudent.finalMark = count(newStudent.homeWorkSum, newStudent.egzamRez);
        student.push_back(newStudent);
    }
}

void output(auto &student, int totalNumberOfStudents) {
    cout<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        cout<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<student[i].finalMark<<endl;
    }
   cout<<"----";
}
