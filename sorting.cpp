#include "functions.h"
void sortAndWriteChunk(vector<data> &student, int fileIndex, bool option, int nameLength)
{
    stringstream filename;
    filename << "run_" << fileIndex - 1 << ".txt";
    ofstream outfile(filename.str());

    for (const auto &s : student)
    {
        outfile << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
    }

    outfile.close();
}

void mergeRuns(vector<ifstream> &infiles, bool option, int nameLength)
{
    ofstream outfile("output.txt"), outfile2("kietakai"), outfile3("vargsiukai");
    outfile << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    outfile << "---------------------------------------------------------------------" << endl;
    outfile2 << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    outfile2 << "---------------------------------------------------------------------" << endl;
    outfile3 << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    outfile3 << "---------------------------------------------------------------------" << endl;
    vector<data> currentValues;
    vector<bool> active(infiles.size(), true);
    int minIndex;
    double finalMarkAverage;
    string name, surname, minSurname, minName;
    for (int i = 0; i < infiles.size(); ++i)
    {
        infiles[i] >> name >> surname >> finalMarkAverage;
        currentValues.push_back(data{name, surname, finalMarkAverage});
    }
    while (any_of(active.begin(), active.end(), [](bool b)
                  { return b; }))
    {
        double minValue = numeric_limits<double>::max();
        for (int i = 0; i < infiles.size(); ++i)
        {
            if (active[i] && currentValues[i].finalMarkAverage < minValue)
            {
                minIndex = i;
                minValue = currentValues[i].finalMarkAverage;
                minName = currentValues[i].name;
                minSurname = currentValues[i].surname;
            }
        }

        if (minIndex > -1)
        {
            outfile << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            if (minValue < 5)
                outfile2 << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            else
                outfile3 << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            if (!(infiles[minIndex] >> currentValues[minIndex].name))
            {
                active[minIndex] = false;
            }
            else
            {
                infiles[minIndex] >> currentValues[minIndex].surname >> currentValues[minIndex].finalMarkAverage;
            }
        }
    }
    outfile << "----";
    outfile2 << "----";
    outfile3 << "----";
    outfile.close();
    outfile2.close();
    outfile3.close();
}
void mergeRuns2(vector<ifstream> &infiles, bool option, int nameLength)
{
    ofstream outfile2("kietakai"), outfile3("vargsiukai");
    outfile2 << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    outfile2 << "---------------------------------------------------------------------" << endl;
    outfile3 << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas" << setw(nameLength) << left << (option ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    outfile3 << "---------------------------------------------------------------------" << endl;
    vector<data> currentValues;
    vector<bool> active(infiles.size(), true);
    int minIndex;
    double finalMarkAverage;
    string name, surname, minSurname, minName;
    for (int i = 0; i < infiles.size(); ++i)
    {
        infiles[i] >> name >> surname >> finalMarkAverage;
        currentValues.push_back(data{name, surname, finalMarkAverage});
    }
    while (any_of(active.begin(), active.end(), [](bool b)
                  { return b; }))
    {
        double minValue = numeric_limits<double>::max();
        for (int i = 0; i < infiles.size(); ++i)
        {
            if (active[i] && currentValues[i].finalMarkAverage < minValue)
            {
                minIndex = i;
                minValue = currentValues[i].finalMarkAverage;
                minName = currentValues[i].name;
                minSurname = currentValues[i].surname;
            }
        }

        if (minIndex > -1)
        {
            cout << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            if (minValue < 5)
                outfile2 << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            else
                outfile3 << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            if (!(infiles[minIndex] >> currentValues[minIndex].name))
            {
                active[minIndex] = false;
            }
            else
            {
                infiles[minIndex] >> currentValues[minIndex].surname >> currentValues[minIndex].finalMarkAverage;
            }
        }
    }
    outfile2 << "----";
    outfile3 << "----";
    outfile2.close();
    outfile3.close();
}
void bigMerge(int fileIndex, bool option, int nameLength, bool outputChoice)
{
    vector<ifstream> infiles(fileIndex / STUDENT_SIZE + 1);
    for (int i = 0; i <= fileIndex / STUDENT_SIZE; i++)
    {
        stringstream filename;
        filename << "run_" << i << ".txt";
        infiles[i].open(filename.str());
    }

    outputChoice ? mergeRuns(infiles, option, nameLength) : mergeRuns2(infiles, option, nameLength);

    for (size_t i = 0; i < infiles.size(); i++)
    {
        infiles[i].close();
    }
}
int parameterForSorting()
{
    int n;
    while (true)
    {
        try
        {
            string n_str;
            cout << "1 - rikiuoti pagal varda, 2 - rikiuoti pagal pavarde, 3 - rikiuoti pagal pazymi" << endl;
            cin >> n_str;

            if (!isNumeric(n_str))
            {
                throw invalid_argument("Netinkama ivestis");
            }

            n = stoi(n_str);
            if (n < 1 || n > 3)
            {
                throw invalid_argument("Netinkamas ivestis");
            }
            break;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
}
void sorting(vector<data> &student, bool option, int a)
{
    switch (a)
    {
    case 1:
        sort(student.begin(), student.end(), [option](const data &a, const data &b)
             { return compareByName(a, b, option); });
    case 2:
        sort(student.begin(), student.end(), [option](const data &a, const data &b)
             { return compareBySurname(a, b, option); });
    case 3:
        sort(student.begin(), student.end(), option ? compareByFinalMarkAverage : compareByFinalMarkMedian);
    }
}