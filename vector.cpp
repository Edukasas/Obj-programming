#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct data
{
    string name;
    string surname;
    vector<string> splited;
    int egzamRez;
    vector<int> homeWorkRez;
    double homeWorkSum = 0;
    double finalMarkAverage;
    double finalMarkMedian;
    double countMedian();
    double countAverage();
    void randomRez();
};
vector<string> names = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
vector<string> surnames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
void input(auto &student);
void readStudentsFromFile(const string filename, auto &student);
void output(auto &student, bool option, int nameLength);
int getBinaryInput();
int options();
int getIntegerInput();
int studentNumber();
void writeIntoFile(auto &student, bool option, int nameLength);
string nameValidation();
int main()
{
    srand(time(nullptr));

    vector<data> student;
    string filename = "kursiokai.txt";
    int nameLength = 21;
    cout << "0 - Ivestis per ekrana, 1 - Ivestis per faila" << endl;
    bool inputChoice = getBinaryInput();
    inputChoice ? readStudentsFromFile(filename, student) : input(student); 
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
    bool option = getBinaryInput();
    if (outputChoice)
    {
        writeIntoFile(student, option, nameLength);
    }
    else
    {
        output(student, option, nameLength);
    }

    return 0;
}
string generateRandomName()
{
    return names[rand() % names.size()];
}
string generateRandomSurname()
{
    return surnames[rand() % surnames.size()];
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
void input(auto &student)
{
    data newStudent;
    int workMethods = 0, studentCount;
    string name;

    while (workMethods != 4)
    {
        cout << "Pasirinkimai 1 - random vardas/pavarde ir pazymiai, 2 - random pazymiai, 3 - ranka ivesti duomenys, 4 - atvaizduoti" << endl;
        workMethods = options();
        switch (workMethods)
        {
        case 1:
            cout << "Iveskite studentu skaiciu" << endl;
            studentCount = studentNumber();
            for (int i = 0; i < studentCount; i++)
            {
                newStudent.name = generateRandomName();
                newStudent.surname = generateRandomSurname();
                newStudent.randomRez();
                student.push_back(newStudent);
            }
            break;
        case 2:
            cin.ignore();
            while (true)
            {
                cout << "Studento vardas (Iveskite 'b' norint pabaigti)" << endl;
                newStudent.name = nameValidation();
                if (newStudent.name == "b")
                    break;
                cout << "Studento pavarde" << endl;
                newStudent.surname = nameValidation();
                newStudent.randomRez();
                student.push_back(newStudent);
            }
            break;
        case 3:

            while (true)
            {
                cin.ignore();

                cout << "Studento vardas (Iveskite 'b' norint pabaigti)" << endl;
                newStudent.name = nameValidation();
                if (newStudent.name == "b")
                    break;
                cout << "Studento pavarde " << endl;
                newStudent.surname = nameValidation();
                while (true)
                {
                    cout << "Namu darbu ivertinimas (Iveskite '-1' norint pabaigti)" << endl;
                    int help = getIntegerInput();
                    if (help == -1)
                    {
                        break;
                    }
                    newStudent.homeWorkRez.push_back(help);
                    newStudent.homeWorkSum += help;
                }
                if (newStudent.homeWorkRez.size() != 0)
                    newStudent.homeWorkSum /= newStudent.homeWorkRez.size();
                else
                    newStudent.homeWorkSum = 0;
                cout << "Egzamino ivertinimas" << endl;
                newStudent.egzamRez = getIntegerInput();
                student.push_back(newStudent);
            }
            break;
        }
    }

    for (auto &s : student)
    {
        s.finalMarkAverage = s.countAverage();
        s.finalMarkMedian = s.countMedian();
    }
}

void output(auto &student, bool option, int nameLength)
{

    cout << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (const auto &s : student)
    {
        cout << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
    }
    cout << "----";
}

void writeIntoFile(auto &student, bool option, int nameLength)
{
    ofstream out_f("output.txt");
    if (!out_f.is_open())
    {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }

    out_f << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(20) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << '\n';
    out_f << "---------------------------------------------------------------------\n";

    for (const auto &s : student)
    {
        out_f << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
    }

    out_f << "----";
    out_f.close();
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

void readStudentsFromFile(const string filename, auto &student)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

       while (getline(file, line))
    {
        data newStudent;
               istringstream iss(line);
        if (!(iss >> newStudent.name >> newStudent.surname))
        {
            cerr << "Error reading student name and surname from file " << filename << endl;
            continue;
        }
        int grade;
        while (iss >> grade)
        {
            newStudent.homeWorkRez.push_back(grade);
            newStudent.homeWorkSum += grade;
        }

        if (newStudent.homeWorkRez.empty())
        {
            cerr << "Error: No grades found for student in file " << filename << endl;
            continue;
        }

        newStudent.egzamRez = newStudent.homeWorkRez.back();
        newStudent.homeWorkRez.pop_back();
        newStudent.homeWorkSum -= newStudent.egzamRez;
        newStudent.homeWorkSum /= newStudent.homeWorkRez.size();

        student.push_back(newStudent);
    }
    for (auto &s : student)
    {
        s.finalMarkAverage = s.countAverage();
        s.finalMarkMedian = s.countMedian();
    }
}