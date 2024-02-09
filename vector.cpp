#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
    string name;
    string surname;
    int egzamRez;
    vector<int> homeWorkRez; 
    double homeWorkSum = 0;
    double finalMarkAverage;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
};
void input(auto &student, int &totalNumberOfStudents);
void output(auto &student, int totalNumberOfStudents, bool option);


int getIntegerInput() {
    int number;
    string input;
    while (true) {
        cin >> input;
         if (input == "-1") {
            return -1;
        }
        bool isValid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            stringstream ss(input);
            if (ss >> number && ss.eof()) {
                // Input is a valid integer
                if (number > 0 && number <= 10) {
                    // Number is greater than 0
                    break;
                } else {
                    cout << "Skaicius turi buti didesnis uz 0, bet nedidesnis 10" << endl;
                }
            }
        }
        cout << "Ivestas duomuo turi buti skaicius" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
int getBinaryInput() {
    int number;
    string input;
    while (true) {
        cout<< "Spauspkit 1, kad skaiciuotu galutini bala pagal vidurki, spauskite 0, kad skaiciuotu galutini bala pagal mediana"<<endl;
        cin >> input;
        stringstream ss(input);
        if (ss >> number && ss.eof()) {
            // Input is a valid integer
            if (number == 0 || number == 1) {
                // Number is either 0 or 1
                break;
            } else {
                cout << "Iveskiti arba 0, arba 1" << endl;
            }
        } else {
            cout << "Iveskiti arba 0, arba 1" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
int main() {
    vector<data> student;
    int totalNumberOfStudents = 0;
    
    input(student, totalNumberOfStudents);
    
    bool option = getBinaryInput();
    output(student, totalNumberOfStudents, option);
    return 0;
}

double data::countAverage() {
    return 0.4 * homeWorkSum + egzamRez * 0.6;
}
double data::countMedian() {
    sort(homeWorkRez.begin(), homeWorkRez.end());
    int n = homeWorkRez.size();
    if (n % 2 == 0) {
        return 0.4 * (homeWorkRez[n / 2 - 1] + homeWorkRez[n / 2]) / 2.0  + egzamRez * 0.6;
    } else {
        return 0.4 * homeWorkRez[n / 2] + egzamRez * 0.6;
    }
}
void input(auto &student, int &totalNumberOfStudents) {
        while(true){
        data newStudent;
        cout << "Studento vardas (Iveskite 'baigti' norint pabaigti)" << endl;
        cin >> newStudent.name;
            if (newStudent.name == "baigti") {
                break;
            }
        while (!all_of(newStudent.name.begin(), newStudent.name.end(), [](unsigned char c) { return isalpha(c); })) {
            cout << "Neteisinga ivestis, iveskite tik raides: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> newStudent.name;
        }
        cout << "Studento pavarde" << endl;
        cin >> newStudent.surname;
        while (!all_of(newStudent.surname.begin(), newStudent.surname.end(), [](unsigned char c) { return isalpha(c); })) {
            cout << "Neteisinga ivestis, iveskite tik raides: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> newStudent.surname;
        }

        while(true){
            cout<<"Namu darbu ivertinimas (Iveskite '-1' norint pabaigti)"<<endl;
            int help = getIntegerInput();
                if (help == -1) {
                    break;
                }
            newStudent.homeWorkRez.push_back(help);
            newStudent.homeWorkSum += help;
        }
        newStudent.homeWorkSum /= newStudent.homeWorkRez.size();
        cout<<"Egzamino ivertinimas"<<endl;
        newStudent.egzamRez = getIntegerInput();
        newStudent.finalMarkAverage = newStudent.countAverage();
        newStudent.finalMarkMedian = newStudent.countMedian();
        student.push_back(newStudent);
        totalNumberOfStudents++;
    }
}

void output(auto &student, int totalNumberOfStudents, bool option) {
    if(option){
    cout<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        cout<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<fixed<<setprecision(2)<<student[i].finalMarkAverage<<endl;
    }
   cout<<"----";
    }
    else{
            cout<<setw(15)<<left<<"Pavardė"<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < totalNumberOfStudents; i++){
        cout<<setw(15)<<left<<student[i].surname<<setw(15)<<left<<student[i].name<<setw(15)<<left<<fixed<<setprecision(2)<<student[i].finalMarkMedian<<endl;
    }
   cout<<"----";
    }

}