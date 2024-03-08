#include "functions.h"
#include "timer.h"

void topSection(vector<data> &student, int nameLength, string filename, bool &option, int &fileIndex, int &choice, bool &screenInput)
{
    screenInput = false;
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
                cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
                option = getBinaryInput();
                choice = parameterForSorting();
                input(student);
                screenInput = true;
                break;
            }
            else if (a == 1)
            {
                cout << "0 - skaiciuoti pagal mediana, 1 - skaiciuoti pagal vidurki" << endl;
                option = getBinaryInput();
                choice = parameterForSorting();
                readStudentsFromFile(filename, student, option, nameLength, fileIndex, choice);
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
}