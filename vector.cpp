#include "functions.h"
int main()
{
    srand(time(nullptr));
    vector<data> student;
    string filename;
    int nameLength = 21, fileIndex, choice;
    bool option = true, screenInput;
    topSection(student, nameLength, filename, option, fileIndex, choice, screenInput);
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    if(screenInput && outputChoice == 0){
        sorting(student, option, choice);
        output(student, option, nameLength);
    }
    else if(screenInput && outputChoice == 1){
        sorting(student, option, choice);
        writeIntoFile(student, option, nameLength, "output.txt");
    }
    else{
        bigMerge(fileIndex, option, nameLength, outputChoice);
    }
                    

    return 0;
}