#include "functions.h"
vector<string> names = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
vector<string> surnames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
void sorting(vector<data>& student, bool option) {
    int a;
    bool end = false;
    while (!end) {
        cout << "1 - rikiuoti pagal varda, 2 - rikiuoti pagal pavarde, 3 - rikiuoti pagal pazymi" << endl;
        cin >> a;

        switch (a) {
            case 1:
                sort(student.begin(), student.end(), compareByName);
                end = true;
                break;
            case 2:
                sort(student.begin(), student.end(), compareBySurname);
                end = true;
                break;
            case 3:
                sort(student.begin(), student.end(), option ? compareByFinalMarkAverage : compareByFinalMarkMedian);
                end = true;
                break;
            default:
                cout << "Ivestas netinkamas skaicius. Bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}
void data::randomRez()
{
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
    return 0.4 * homeWorkSum + egzamRez * 0.6;
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
                // Input is a valid integer
                if (number > 0 && number < 5)
                {
                    // Number is greater than 0
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
bool compareByName(const data& a, const data& b) {
    return a.name < b.name;
}
bool compareBySurname(const data& a, const data& b) {
    return a.surname < b.surname;
}
bool compareByFinalMarkMedian(const data& a, const data& b) {
    return a.finalMarkMedian < b.finalMarkMedian;
}
bool compareByFinalMarkAverage(const data& a, const data& b) {
    return a.finalMarkAverage < b.finalMarkAverage;
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