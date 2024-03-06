#include "functions.h"
#include "timer.h"
int main()
{
    srand(time(nullptr));
    int a;
    vector<data> student;
    string filename;
    int nameLength = 21;
    
    topSection(student, nameLength, filename);
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
    bool option = getBinaryInput();
    Timer t;
    sorting(student, option);
    cout<<"Uztruko sortingas "<<t.elapsed()<<endl;
    outputChoice ? writeIntoFile(student, option, nameLength, "output") : output(student, option, nameLength);
    student.clear();
    t;
    readAndWrite(option, nameLength);
    cout<<"Uztruko irasymas "<<t.elapsed()<<endl;
    return 0;
}