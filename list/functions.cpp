#include "functions.h"
vector<string> names = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
vector<string> surnames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
void data::randomRez()
{
    homeWorkSum = 0;
    homeWorkRez.clear();
    int randomNumberOfHomeWork = rand() % 100 + 1;
    int help = rand() % 10 + 1;
    egzamRez = help;
    for (int i = 0; i < randomNumberOfHomeWork; i++)
    {
        help = rand() % 10 + 1;
        homeWorkRez.push_back(help);
        homeWorkSum += help;
    }
    homeWorkSum = homeWorkSum / randomNumberOfHomeWork;
}
double data::countAverage()
{
    int n = homeWorkRez.size();
    if(n>0) return 0.4 * homeWorkSum + egzamRez * 0.6;
    else return egzamRez * 0.6;
}
double data::countMedian()
{
    sort(homeWorkRez.begin(), homeWorkRez.end());
    int n = homeWorkRez.size();
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
void sorting(list<data>& student, bool option) {
    int a;
    bool end = false;
    while (!end) {
        // cout << "1 - sort by name, 2 - sort by surname, 3 - sort by final mark" << endl;
        // cin >> a;
        a = 3;
        switch (a) {
            case 1:
                student.sort([option](const data& a, const data& b) { return compareByName(a, b, option); });
                end = true;
                break;
            case 2:
                student.sort([option](const data& a, const data& b) { return compareBySurname(a, b, option); });
                end = true;
                break;
            case 3:
                student.sort(option ? compareByFinalMarkAverage : compareByFinalMarkMedian);
                end = true;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}
void distribution(list<data> studentai, list<data> &kietakai, list<data> &vargsiukai, bool option){
    for(auto it = studentai.begin(); it != studentai.end(); ++it) {
        int rez = option ? it->finalMarkAverage : it->finalMarkMedian;
        if(rez < 5)
            vargsiukai.push_back(*it);
        else
            kietakai.push_back(*it);
    }
}
int options()
{
    int number;
    string input;
    while (true)
    {
        cin >> input;
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
                if (number > 0 && number < 5)
                {
                    break;
                }
                else
                {
                    cout << "Pasirinkimai 1 - random vardas/pavarde ir pazymiai, 2 - random pazymiai, 3 - ranka ivesti duomenys, 4 - atvaizduoti" << endl;
                }
            }
        }
        cout << "Ivestas duomuo turi buti skaicius" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
bool compareByName(const data& a, const data& b, bool option) {
        if (a.name != b.name) {
            return a.name < b.name;
        } else if(a.surname != b.surname) {
            return a.surname < b.surname;
        } else {
            return option ?  a.finalMarkAverage < b.finalMarkAverage :  a.finalMarkMedian < b.finalMarkMedian;
        }
}
bool compareBySurname(const data& a, const data& b, bool option) {
        if (a.surname != b.surname) {
            return a.surname < b.surname; 
        } else if(a.name != b.name) {
            return a.name < b.name;
        } else {
            return option ?  a.finalMarkAverage < b.finalMarkAverage :  a.finalMarkMedian < b.finalMarkMedian;
        }
}
bool compareByFinalMarkMedian(const data& a, const data& b) {
        if (a.finalMarkMedian != b.finalMarkMedian) {
            return a.finalMarkMedian < b.finalMarkMedian;
        } else if (a.surname != b.surname) {
            return a.surname < b.surname;
        }
        else if (a.name != b.name) {
            return a.name < b.name;
        }
}
bool compareByFinalMarkAverage(const data& a, const data& b) {
        if (a.finalMarkAverage != b.finalMarkAverage) {
            return a.finalMarkAverage < b.finalMarkAverage; 
        } else if (a.surname != b.surname) {
            return a.surname < b.surname;
        }
        else if (a.name != b.name) {
            return a.name < b.name;
        }
}
int studentNumber()
{
    int number;
    string input;
    while (true)
    {
        cin >> input;
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
                if (number > 0 && number < 1000)
                {
                    // Number is greater than 0
                    break;
                }
                else
                {
                    cout << "Studentu skaicius turi buti daugiau nei 0, bet maziau uz 1000" << endl;
                }
            }
        }
        cout << "Ivestas duomuo turi buti skaicius" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
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
                if (number > 0 && number <= 10)
                {
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
            if (number == 0 || number == 1)
            {
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
string nameValidation()
{
    string name;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nameValidation();
    }
    getline(cin, name);

    while (!all_of(name.begin(), name.end(), [](unsigned char c)
                   { return isalpha(c) || (c == ' ' && !isspace(*(next(&c))) && !isspace(*(prev(&c)))); }) ||
           name.length() > 20 || name.length() == 0 || (name.length() > 0 && name.front() == ' ') || (name.length() > 0 && name.back() == ' '))
    {
        cout << "Netinkama ivestis" << endl;
        getline(cin, name);
    };
    return name;
}