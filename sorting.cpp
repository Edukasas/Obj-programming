#include "functions.h"
void sortAndWriteChunk(vector<data>& student, int fileIndex, bool option, int nameLength) {
    stringstream filename;
    filename << "run_" << fileIndex - 1 << ".txt";
    ofstream outfile(filename.str());

    for (const auto &s : student)
    {
        outfile << setw(nameLength) << left << s.surname << setw(nameLength) << left << s.name << setprecision(3) << left << (option ? s.finalMarkAverage : s.finalMarkMedian) << '\n';
    }

    outfile.close();
}

void mergeRuns(vector<ifstream>& infiles, bool option, int nameLength) {
    ofstream outfile("output.txt");
    vector<data> currentValues;
    vector<bool> active(infiles.size(), true);
    int minIndex;
    double finalMarkAverage;
    string name, surname, minSurname, minName;
            for (int i = 0; i < infiles.size(); ++i) {
            infiles[i] >> name >> surname >> finalMarkAverage;
            currentValues.push_back(data{name, surname, finalMarkAverage});
        }
    while (any_of(active.begin(), active.end(), [](bool b) { return b; })) {
        double minValue = numeric_limits<double>::max();
        for (int i = 0; i < infiles.size(); ++i) {
            if (active[i] && currentValues[i].finalMarkAverage < minValue) {
                minIndex = i;
                minValue = currentValues[i].finalMarkAverage;
                minName = currentValues[i].name;
                minSurname = currentValues[i].surname;
            }
        }

        if (minIndex > -1) {
            // Output the minimum value to the output file
            outfile << setw(nameLength) << left << minName << setw(nameLength) << left << minSurname << setprecision(3) << left << minValue << '\n';
            
            // Read new values from the input file and update currentValues[minIndex]
                      if (!(infiles[minIndex] >> currentValues[minIndex].name)) {
                active[minIndex] = false;
            } else {
                infiles[minIndex] >> currentValues[minIndex].surname >> currentValues[minIndex].finalMarkAverage;
            }
        }
    }
    outfile.close();
}
void bigMerge(int fileIndex, bool option, int nameLength){
    vector<ifstream> infiles(fileIndex / STUDENT_SIZE + 1);
    for (int i = 0; i <= fileIndex / STUDENT_SIZE; i++) {
        stringstream filename;
        filename << "run_" << i << ".txt";
        infiles[i].open(filename.str());
    }

    mergeRuns(infiles, option, nameLength);

    for (size_t i = 0; i < infiles.size(); i++) {
        infiles[i].close();
    }
    cout << "Sorting completed. Output written to output.txt" << endl;
}