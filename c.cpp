#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct data {
    string name;
    string surname;
    int egzamRez;
    int *homeWorkRez; // Pointer to int array
    int homeWorkCount = 0;
    double homeWorkSum = 0;
    double finalMarkAverage;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
    void randomHomeWorkRez();
};
void input(data *&student, int &totalNumberOfStudents);
void output(data *student, int totalNumberOfStudents, bool option);
int getBinaryInput();
int getIntegerInput();
int main() {
    int totalNumberOfStudents = 0;
    data *student = nullptr;
    input(student, totalNumberOfStudents);
    cout<< "Spauspkit 1, kad skaiciuotu galutini bala pagal vidurki, spauskite 0, kad skaiciuotu galutini bala pagal mediana"<<endl;
    bool option = getBinaryInput();
    output(student, totalNumberOfStudents, option);
        for (int i = 0; i < totalNumberOfStudents; ++i) {
        delete[] student[i].homeWorkRez;
    }
    delete[] student;
    return 0;
}
void data::randomHomeWorkRez(){
    srand(time(nullptr));
    int randomNumberOfHomeWork = rand() % 100 + 1;
    for(int i = 0; i < randomNumberOfHomeWork; i++){
        int help = rand() % 10 + 1;
        int *temp = new int[homeWorkCount + 1];
        for (int i = 0; i < homeWorkCount; ++i) {
                temp[i] = homeWorkRez[i];
            }
            temp[homeWorkCount++] = help;
            delete[] homeWorkRez;
            homeWorkRez = temp;
            homeWorkSum += help;
    }
    // for(int i = 0; i < homeWorkCount; i++){
    //     cout<<homeWorkRez[i]<<endl;
    // }
    homeWorkSum = homeWorkSum / randomNumberOfHomeWork;
}
double data::countAverage() {
    return 0.4 * homeWorkSum + egzamRez * 0.6;
}
double data::countMedian() {
    for(int i = 0; i < homeWorkCount - 1; i++){
        for(int j = i + 1; j < homeWorkCount; j++){
            if(homeWorkRez[i]>homeWorkRez[j])swap(homeWorkRez[i],homeWorkRez[j]);
        }
    }
    int n = homeWorkCount;
    if (n > 0){
        if (n % 2 == 0) {
            return 0.4 * (homeWorkRez[n / 2 - 1] + homeWorkRez[n / 2]) / 2.0  + egzamRez * 0.6;
        } else {
            return 0.4 * homeWorkRez[n / 2] + egzamRez * 0.6;
        }
    }
    else return egzamRez * 0.6;

}
void input(data *&student, int &totalNumberOfStudents) {
    student = new data[1];
        while(true){
        data newStudent;
        cout << "Studento vardas (Iveskite 'b' norint pabaigti)" << endl;
        cin >> newStudent.name;
        while (!all_of(newStudent.name.begin(), newStudent.name.end(), [](unsigned char c) { return isalpha(c); })) {
            cout << "Neteisinga ivestis, iveskite tik raides: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> newStudent.name;
        }
        if (newStudent.name == "b") {
            break;
        }        
        cout << "Studento pavarde" << endl;
        cin >> newStudent.surname;
        while (!all_of(newStudent.surname.begin(), newStudent.surname.end(), [](unsigned char c) { return isalpha(c); })) {
            cout << "Neteisinga ivestis, iveskite tik raides: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> newStudent.surname;
        }
            newStudent.homeWorkRez = new int[1];
        cout<< "Spauspkit 1, kad ranka suvesti namu darbu pazymius, spauskite 0, kad atsitiktinai generuotu rezultata"<<endl;
        bool option = getBinaryInput();
        if(option){
        while(true){
            cout<<"Namu darbu ivertinimas (Iveskite '-1' norint pabaigti)"<<endl;
            int help = getIntegerInput();
                if (help == -1) {
                    break;
                }
            int *temp = new int[newStudent.homeWorkCount + 1];
            for (int i = 0; i < newStudent.homeWorkCount; ++i) {
                temp[i] = newStudent.homeWorkRez[i];
            }
            temp[newStudent.homeWorkCount++] = help;
            delete[] newStudent.homeWorkRez;
            newStudent.homeWorkRez = temp;
            newStudent.homeWorkSum += help;
        }
        if(newStudent.homeWorkCount != 0)newStudent.homeWorkSum /= newStudent.homeWorkCount;
        else newStudent.homeWorkSum = 0;
        }
        else newStudent.randomHomeWorkRez();
        cout<<"Egzamino ivertinimas"<<endl;
        newStudent.egzamRez = getIntegerInput();
        newStudent.finalMarkAverage = newStudent.countAverage();
        newStudent.finalMarkMedian = newStudent.countMedian();
        data *temp = new data[totalNumberOfStudents + 1];
        for (int i = 0; i < totalNumberOfStudents; ++i) {
            temp[i] = student[i];
        }
        temp[totalNumberOfStudents++] = newStudent;
        delete[] student;
        student = temp;
    }
}

void output(data *student, int totalNumberOfStudents, bool option) {
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