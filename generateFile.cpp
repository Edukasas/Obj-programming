#include "functions.h"
bool isNumeric(const string &str)
{
    return all_of(str.begin(), str.end(), [](char c)
                  { return isdigit(c); });
}
void generateFile(int nameLength)
{
    while (true)
    {
        try
        {
            int randomNumberOfHomeWork = rand() % 20 + 1;
            string filename;
            cout << "Generuojamo failo pavadinimas" << endl;
            cin >> filename;

            cout << "Generuojamo failo dydis" << endl;
            string n_str;
            cin >> n_str;

            if (!isNumeric(n_str))
            {
                throw invalid_argument("Invalid input for 'n'");
            }

            int n = stoi(n_str);
            if (filename.length() == 0 || filename.length() > 20)
            {
                throw invalid_argument("Netinkamas failo ilgis (1-20)");
            }
            if (n < 1 || n > 10000000)
            {
                throw invalid_argument("Netinkamas dydyis (1-10,000,000)");
            }
            ofstream out_f(filename);
            out_f << setw(nameLength) << left << "Pavardė" << setw(nameLength) << left << "Vardas";
            for (int i = 1; i < randomNumberOfHomeWork; i++)
            {
                string mark = "ND" + to_string(i);
                out_f << setw(6) << left << mark;
            }
            out_f << setw(6) << left << "Egz\n";

            for (int i = 1; i < n; i++)
            {
                int help;

                string lastName = "Pavarde" + to_string(i);

                string firstName = "Vardas" + to_string(i);
                out_f << setw(nameLength) << left << lastName << setw(nameLength) << left << firstName;
                for (int i = 1; i < randomNumberOfHomeWork; i++)
                {
                    help = rand() % 10 + 1;
                    out_f << setw(6) << left << help;
                }
                help = rand() % 10 + 1;
                out_f << setw(6) << left << help << "\n";
            }

            out_f.close();
            break;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}