#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
struct data
{
    string name;
    string surname;
    int egzamRez;
    int *homeWorkRez;
    int homeWorkCount = 0;
    double homeWorkSum = 0;
    double finalMarkAverage;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
    void randomRez();
};
const int size = 10;
string* names =  new string [size]{"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
string* surnames = new string [size]{"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
string generateRandomSurname();
string generateRandomName();
void input(data *&student, int &totalNumberOfStudents);
void output(data *student, int totalNumberOfStudents, bool option);
int getBinaryInput();
int getIntegerInput();
int main()
{
    srand(time(nullptr));
    int totalNumberOfStudents = 0;
    data *student = nullptr;
    input(student, totalNumberOfStudents);
    cout << "Spauspkit 1, kad skaiciuotu galutini bala pagal vidurki, spauskite 0, kad skaiciuotu galutini bala pagal mediana" << endl;
    bool option = getBinaryInput();
    output(student, totalNumberOfStudents, option);
    for (int i = 0; i < totalNumberOfStudents; ++i)
    {
        delete[] student[i].homeWorkRez;
    }
    delete[] student;
    delete[] names;
    delete[] surnames;
    return 0;
}
string generateRandomName()
{
    return names[rand() % size];
}
string generateRandomSurname()
{
    return surnames[rand() % size];
}
void data::randomRez()
{
    homeWorkCount = rand() % 100 + 1;
    int help = rand() % 10 + 1;
    egzamRez = help;
    for (int i = 0; i < homeWorkCount; i++)
    {
        help = rand() % 10 + 1;
        int *temp = new int[i + 1];
        for (int j = 0; j < i; j++)
        {
            temp[j] = homeWorkRez[j];
        }
        temp[i] = help;
        delete[] homeWorkRez;
        homeWorkRez = temp;
        homeWorkSum += help;
    }
    homeWorkSum = homeWorkSum / homeWorkCount;
}
double data::countAverage()
{
    return 0.4 * homeWorkSum + egzamRez * 0.6;
}
double data::countMedian()
{
    for (int i = 0; i < homeWorkCount - 1; i++)
    {
        for (int j = i + 1; j < homeWorkCount; j++)
        {
            if (homeWorkRez[i] > homeWorkRez[j])
                swap(homeWorkRez[i], homeWorkRez[j]);
        }
    }
    int n = homeWorkCount;
    if (n > 0)
    {
        if (n % 2 == 0)
        {
            return 0.4 * (homeWorkRez[n / 2 - 1] + homeWorkRez[n / 2]) / 2.0 + egzamRez * 0.6;
        }
        else
        {
            return 0.4 * homeWorkRez[n / 2] + egzamRez * 0.6;
        }
    }
    else
        return egzamRez * 0.6;
}
void input(data *&student, int &totalNumberOfStudents)
{
    student = new data[1];
    while (true)
    {
        data newStudent;
        cout<< "Spauspkit 1, kad ranka suvesti varda ir pavarde, spauskite 0, kad sugeneruoti varda, pavarde ir rezultatus"<<endl;
        bool option = getBinaryInput();
        if(option){
            cin.ignore();
        cout << "Studento vardas (max 20) (Iveskite 'b' norint pabaigti)" << endl;
        getline(cin, newStudent.name);
        cout<<"Bam: "<<newStudent.name<<endl;
        while (!all_of(newStudent.name.begin(), newStudent.name.end(), [](unsigned char c)
                        { return isalpha(c) || (c == ' ' && !isspace(*(std::next(&c))) && !isspace(*(std::prev(&c)))); }) 
       || newStudent.name.length() > 20
       || (newStudent.name.length() > 0 && newStudent.name.front() == ' ')
       || (newStudent.name.length() > 0 && newStudent.name.back() == ' '))
        {
            cout << "Neteisinga ivestis, iveskite tik raides (max 20): ";
            cin.ignore();
            getline(cin, newStudent.name);
        }
        if (newStudent.name == "b")
        {
            break;
        }
        
        cout << "Studento pavarde (max 20)" << endl;
        getline(cin, newStudent.surname);
        while (!all_of(newStudent.surname.begin(), newStudent.surname.end(), [](unsigned char c)
                        { return isalpha(c) || (c == ' ' && !isspace(*(std::next(&c))) && !isspace(*(std::prev(&c)))); }) 
       || newStudent.name.length() > 20
       || (newStudent.name.length() > 0 && newStudent.name.front() == ' ')
       || (newStudent.name.length() > 0 && newStudent.name.back() == ' '))
        {
            cout << "Neteisinga ivestis, iveskite tik raides (max 20): ";
            cin.ignore();
            getline(cin, newStudent.surname);
        }
        newStudent.homeWorkRez = new int[1];
        cout << "Spauspkit 1, kad ranka suvesti namu darbu bei egzamino pazymius, spauskite 0, kad atsitiktinai generuotu rezultata" << endl;
        option = getBinaryInput();
        if (option)
        {
            while (true)
            {
                cout << "Namu darbu ivertinimas (Iveskite '-1' norint pabaigti)" << endl;
                int help = getIntegerInput();
                if (help == -1)
                {
                    break;
                }
                int *temp = new int[newStudent.homeWorkCount + 1];
                for (int i = 0; i < newStudent.homeWorkCount; ++i)
                {
                    temp[i] = newStudent.homeWorkRez[i];
                }
                temp[newStudent.homeWorkCount++] = help;
                delete[] newStudent.homeWorkRez;
                newStudent.homeWorkRez = temp;
                newStudent.homeWorkSum += help;
            }
            if (newStudent.homeWorkCount != 0)
                newStudent.homeWorkSum /= newStudent.homeWorkCount;
            else
                newStudent.homeWorkSum = 0;

                cout << "Egzamino ivertinimas" << endl;
                newStudent.egzamRez = getIntegerInput();
        }
        else
            newStudent.randomRez();
        }
        else{
            newStudent.name = generateRandomName();
            newStudent.surname = generateRandomSurname();
            newStudent.randomRez();
        }
        newStudent.finalMarkAverage = newStudent.countAverage();
        newStudent.finalMarkMedian = newStudent.countMedian();
        data *temp = new data[totalNumberOfStudents + 1];
        for (int i = 0; i < totalNumberOfStudents; ++i)
        {
            temp[i] = student[i];
        }
        temp[totalNumberOfStudents++] = newStudent;
        delete[] student;
        student = temp;
    }
}

void output(data *student, int totalNumberOfStudents, bool option)
{
    if (option)
    {
        cout << setw(20) << left << "Pavardė" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < totalNumberOfStudents; i++)
        {
            cout << setw(20) << left << student[i].surname << setw(20) << left << student[i].name << setw(20) << left << fixed << setprecision(2) << student[i].finalMarkAverage << endl;
        }
        cout << "----";
    }
    else
    {
        cout << setw(20) << left << "Pavardė" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < totalNumberOfStudents; i++)
        {
            cout << setw(20) << left << student[i].surname << setw(20) << left << student[i].name << setw(20) << left << fixed << setprecision(2) << student[i].finalMarkMedian << endl;
        }
        cout << "----";
    }
}
int getIntegerInput()
{
    int number;
    string input;
    while (true)
    {
        cin >> input;
        if (input == "-1")
        {
            return -1;
        }
        bool isValid = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            stringstream ss(input);
            if (ss >> number && ss.eof())
            {
                // Input is a valid integer
                if (number > 0 && number <= 10)
                {
                    // Number is greater than 0
                    break;
                }
                else
                {
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
int getBinaryInput()
{
    int number;
    string input;
    while (true)
    {
        cin >> input;
        stringstream ss(input);
        if (ss >> number && ss.eof())
        {
            // Input is a valid integer
            if (number == 0 || number == 1)
            {
                // Number is either 0 or 1
                break;
            }
            else
            {
                cout << "Iveskiti arba 0, arba 1" << endl;
            }
        }
        else
        {
            cout << "Iveskiti arba 0, arba 1" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
