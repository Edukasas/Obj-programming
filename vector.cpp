#include "functions.h"

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
    sorting(student, option);
    outputChoice ? writeIntoFile(student, option, nameLength) : output(student, option, nameLength);
    return 0;
}