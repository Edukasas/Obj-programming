#include "functions.h"
#include "timer.h"
int main()
{
    vector<double> times;
    while(times.size()!=5){
    Timer t;
    srand(time(nullptr));
    vector<data> student;
    string filename;
    int nameLength = 21, fileIndex, choice;
    bool option = true, screenInput;
    Timer h;
    topSection(student, nameLength, filename, option, fileIndex, choice, screenInput);
    cout<<"Nuskaitymas uztruko: "<<h.elapsed()<<endl;
    // cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    // bool outputChoice = getBinaryInput();
    bool outputChoice = 1;
    if(screenInput && outputChoice == 0){
        sorting(student, option, choice);
        output(student, option, nameLength);
    }
    else if(screenInput && outputChoice == 1){
        sorting(student, option, choice);
        writeIntoFile(student, option, nameLength, "output.txt");
    }
    else{
        h.reset();
        bigMerge(fileIndex, option, nameLength, outputChoice);
        cout<<"Rusiavimas ir irasymas uztruko"<<h.elapsed()<<endl;
    }
    times.push_back(t.elapsed());           
    cout<<"Visos programos veikimo laikas: "<<times[times.size()-1]<<endl;
    }
    double average=0;
    for(double i : times)average+=i;
    cout << "Average time: "<< average<<endl;

    return 0;
}