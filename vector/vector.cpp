#include "functions.h"
#include "timer.h"
int main()
{
    srand(time(nullptr));
    Timer t;
    int a;
    vector<data> student, vargsiukai, kietakai;
    string filename;
    int nameLength = 21;
    while (true)
    {
        try
        {
            // cout << "0 - Ivestis per ekrana, 1 - Ivestis per faila, 2 - Generuoti faila" << endl;
            string a_str = "1";
            // cin >> a_str;
            if (!isNumeric(a_str))
            {
                throw invalid_argument("Netinkama ivestis");
            }
            int a = stoi(a_str);
            if (a == 0)
            {
                input(student);
                break;
            }
            else if (a == 1)
            {
                t.reset();
                readStudentsFromFile(filename, student);
                cout<<"Nuskaitymas failo uztruko: "<<t.elapsed()<<endl;
                break;
            }
            else if (a == 2)
                generateFile(nameLength);
            else
                throw invalid_argument("Netinkama ivestis");
        }
        catch (const invalid_argument &ex)
        {
            cerr << "Error: " << ex.what() << endl;
        }
    }
    // cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    // bool outputChoice = getBinaryInput();
    // cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
    // bool option = getBinaryInput();
    bool outputChoice = 1;
    bool option = 1;
    t.reset();
    sorting(student, option);
    cout<<"Rikiavimas uztruko: "<<t.elapsed()<<endl;
    t.reset();
    distribution(student, kietakai, vargsiukai, option);
    cout<<"Skirstymas i dvi grupes uztruko: "<<t.elapsed()<<endl;
    outputChoice ? (   writeIntoFile(kietakai, option, nameLength, "kietakai.txt"),
    writeIntoFile(vargsiukai, option, nameLength, "vargsiukai.txt")) : output(student, option, nameLength);
    return 0;
}