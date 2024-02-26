#include "functions.h"
string generateRandomName()
{
    return names[rand() % names.size()];
}
string generateRandomSurname()
{
    return surnames[rand() % surnames.size()];
}
void input(vector<data> &student)
{
    data newStudent;
    int workMethods = 0, studentCount;
    string name;
    try
    {
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
    catch (const std::exception &e)
    {
        cerr << "Error: Netiketa problema ivestyje" << endl;
    }
}
void readStudentsFromFile(const string filename, vector<data> &student)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Neisejo atidaryti failo " << filename << endl;
        return;
    }
    try
    {
        string line;
        getline(file, line);

        while (getline(file, line))
        {
            data newStudent;
            istringstream iss(line);
            if (!(iss >> newStudent.name >> newStudent.surname) || newStudent.name.length() < 2 || newStudent.surname.length() < 2)
            {
                cerr << "Error: Nepavyko nuskaityti studento vardo ir pavardes " << filename << endl;
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
                cerr << "Error: Namu darbu rezultato nera " << filename << endl;
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
    catch (const std::exception &ex)
    {
        cerr << "Error: Atsitiko nenumatyta klaida nuskaitant faila " << filename << endl;
    }
}
void output(vector<data> &student, bool option, int nameLength)
{

    cout << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (const auto &s : student)
    {
        cout << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
    }
    cout << "----";
}

void writeIntoFile(vector<data> &student, bool option, int nameLength)
{
    try
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
    catch (const std::exception &e)
    {
        cerr << "Error: Netiketa problema irasant faila" << endl;
    }
}