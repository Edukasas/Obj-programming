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
    catch (const std::exception &ex)
    {
        cerr << "Error: " << ex.what() << endl;
    }
}
void readStudentsFromFile(string &filename, vector<data> &student, bool option, int nameLength, int &fileIndex, int &choice)
{
    student.reserve(1000);
    ifstream file(filename);
    while (true)
    {
        try
        {
           cout << "Iveskite failo pavadinima: ";
           cin >> filename;
            if (filename.length() == 0 || filename.length() > 20)
            {
                throw invalid_argument("Netinkamas failo ilgis (1-20)");
            }
            file.open(filename);
            if (!file)
            {
                throw runtime_error("Nepavyko atidaryti failo " + filename);
            }
            break;
        }
        catch (const invalid_argument &ex)
        {
            cerr << "Error: " << ex.what() << endl;
        }
        catch (const runtime_error &ex)
        {
            cerr << "Error:  " << ex.what() << endl;
        }
        catch (const bad_alloc &ex) {
            cerr << "Error: atmintis uzsilenke" << endl;
        }
    }
    string line;
    fileIndex = 0;
    getline(file, line);
    while (getline(file, line))
    {
        fileIndex++;
        data newStudent;
        istringstream iss(line);
        if (!(iss >> newStudent.name >> newStudent.surname) || newStudent.name.length() < 2 || newStudent.surname.length() < 2)
        {
            cerr << "Error: Nepavyko nuskaityti studento vardo ir pavardes " << student.size() << " eilute" << endl;
            continue;
        }
        int grade;
        while (iss >> grade)
        {
            newStudent.homeWorkRez.push_back(grade);
            newStudent.homeWorkSum += grade;
        }
        newStudent.egzamRez = newStudent.homeWorkRez.back();
        newStudent.homeWorkRez.pop_back();
        newStudent.homeWorkSum -= newStudent.egzamRez;
        newStudent.homeWorkSum /= newStudent.homeWorkRez.size();
        if (newStudent.homeWorkRez.empty() && (newStudent.egzamRez < 0 || newStudent.egzamRez > 10))
        {
            cerr << "Error: Namu darbu rezultato nera " << student.size() << endl;
            continue;
        }
        double rez = option ? newStudent.finalMarkAverage = newStudent.countAverage() : newStudent.finalMarkMedian = newStudent.countMedian();
        student.push_back(newStudent);
        if (student.size() == STUDENT_SIZE) {
            sorting(student, option, choice);
            sortAndWriteChunk(student, fileIndex / STUDENT_SIZE, option, nameLength);
            student.clear();
        }
    }
    if (!student.empty()) {
        sorting(student, option, choice);
        sortAndWriteChunk(student, fileIndex / STUDENT_SIZE + 1, option, nameLength);
        student.clear();
    }
    file.close();
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
void writeIntoFile(vector<data> &student, bool option, int nameLength, string filename)
{
    try
    {
        ofstream out_f(filename);
        out_f << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(20) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << '\n';
        out_f << "---------------------------------------------------------------------\n";

        for (const auto &s : student)
        {
            out_f << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
        }

        out_f << "----";
        out_f.close();
    }
    catch (const std::exception &ex)
    {
        cerr << "Error:" << ex.what() << endl;
    }
}