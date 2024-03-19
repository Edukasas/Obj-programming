#include "functions.h"

int main()
{
    srand(time(nullptr));
    int a;
    vector<data> student, vargsiukai, kietakai;
    string filename;
    int nameLength = 21;
    while (true)
    {
        try
        {
            cout << "0 - Ivestis per ekrana, 1 - Ivestis per faila, 2 - Generuoti faila" << endl;
            string a_str;
            cin >> a_str;
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
                readStudentsFromFile(filename, student);
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
    cout << "0 - atvaizdavimas ekrane, 1 - atvaizdavimas faile" << endl;
    bool outputChoice = getBinaryInput();
    cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
    bool option = getBinaryInput();
    sorting(student, option);
    distribution(student, kietakai, vargsiukai, option);
    outputChoice ? writeIntoFile(student, option, nameLength, "output.txt") : output(student, option, nameLength);
    writeIntoFile(kietakai, option, nameLength, "kietakai.txt");
    writeIntoFile(vargsiukai, option, nameLength, "vargsiukai.txt");
    return 0;
}