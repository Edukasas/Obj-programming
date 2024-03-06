#include "functions.h"
#include "timer.h"

void topSection(vector<data> &student, int nameLength, string filename, bool &option, int& fileIndex)
{
    // while (true)
    // {
    //     try
    //     {
                cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
                option = getBinaryInput();
    //         cout << "0 - Ivestis per ekrana, 1 - Ivestis per faila, 2 - Generuoti faila" << endl;
    //         string a_str;
    //         cin >> a_str;
    //         if (!isNumeric(a_str))
    //         {
    //             throw invalid_argument("Netinkama ivestis");
    //         }
    //         int a = stoi(a_str);
    //         if (a == 0){
    //         input(student);
    //         break;
    //         }
    //         else if (a == 1){
        Timer t;
            readStudentsFromFile(filename, student, option, nameLength, fileIndex);
        cout<<"Skaitymas uztruko "<<t.elapsed()<<endl;
    //         break;
    //         }
    //         else if (a == 2)
    //             generateFile(nameLenght);
    //         else
    //             throw invalid_argument("Netinkama ivestis");
    //     }
    //     catch (const invalid_argument &ex)
    //     {
    //         cerr << "Error: " << ex.what() << endl;
    //     }
    // }
}