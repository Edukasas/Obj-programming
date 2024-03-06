#include "functions.h"
#include "timer.h"
int main()
{
    srand(time(nullptr));
    vector<data> student;
    string filename;
    int nameLength = 21;
    bool option = true;
    bigMerge(9999999, option, nameLength);
    //topSection(student, nameLength, filename, option, fileIndex);
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    Timer t;
    //sorting(student, option);
    cout<<"Uztruko sortingas "<<t.elapsed()<<endl;
    outputChoice ? writeIntoFile(student, option, nameLength, "output") : output(student, option, nameLength);
    //student.clear();
    t;
    readAndWrite(option, nameLength);
    cout<<"Uztruko irasymas "<<t.elapsed()<<endl;
    return 0;
}