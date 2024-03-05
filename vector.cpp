#include "functions.h"

int main()
{
    srand(time(nullptr));
    int a;
    vector<data> student, goodStudent, badStudent;
    string filename;
    int nameLength = 21;
    
    topSection(student, nameLength, filename);
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
    bool option = getBinaryInput();
    sorting(student, goodStudent, badStudent, option);
    writeIntoFile(goodStudent, option, nameLength, "kietakai");
    writeIntoFile(badStudent, option, nameLength, "vargsiukai");
    outputChoice ? writeIntoFile(student, option, nameLength, "output") : output(student, option, nameLength);
    return 0;
}