#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
    string name, surname;
    int n, egzamRez;
    vector<int> homeWorkRez; 
    double homeWorkSum = 0, finalMark;
};

double countMedian(vector<int> homeWorkRez, int egzamRez);
double countAverage(double homeWorkSum, int EgzamRez);
void input(auto &student, int &totalNumberOfStudents, bool &option);
void output(auto &student, int totalNumberOfStudents, bool option);
int main() {
    vector<data> student;
    int totalNumberOfStudents;
    bool option;
    cout<<"Moksleiviu skaicius"<<endl;
    cin>>totalNumberOfStudents;
    input(student, totalNumberOfStudents, option);
    output(student, totalNumberOfStudents, option);
    return 0;
}

double countAverage(double homeWorkSum, int egzamRez) {
    return 0.4 * homeWorkSum + egzamRez * 0.6;
}
double countMedian(vector<int> homeWorkRez, int egzamRez) {
    sort(homeWorkRez.begin(), homeWorkRez.end());
    int n = homeWorkRez.size();
    if (n % 2 == 0) {
        return 0.4 * (homeWorkRez[n / 2 - 1] + homeWorkRez[n / 2]) / 2.0  + egzamRez * 0.6;
    } else {
        return 0.4 * homeWorkRez[n / 2] + egzamRez * 0.6;
    }
}
void input(auto &student, int &totalNumberOfStudents, bool &option) {
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
        cout<< "jei norit pamatyti mediana, spauskit 0, priesingu atveju pamatysit vidurki"<<endl;
        cin >> option;
       if(option) newStudent.finalMark = countAverage(newStudent.homeWorkSum, newStudent.egzamRez);
         else newStudent.finalMark = countMedian(newStudent.homeWorkRez, newStudent.egzamRez);
        student.push_back(newStudent);
    }
}

void output(auto &student, int totalNumberOfStudents, bool option) {
    if(option){
    cout<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        cout<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<student[i].finalMark<<endl;
    }
   cout<<"----";
    }
    else{
            cout<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        cout<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<student[i].finalMark<<endl;
    }
   cout<<"----";
    }

}
