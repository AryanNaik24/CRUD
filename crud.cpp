
// Including libraries
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// specifing size of array
const int maxRow = 10;

// Strings variables for coin name and value
string CoinId[maxRow] = {};
string CoinName[maxRow] = {};
string CoinValue[maxRow] = {};
string CoinYear[maxRow] = {};

// opens file in which data is stored
void openFile()
{
    string line;
    ifstream myFile("C:\\Users\\aryan\\Desktop\\projects\\CRUD c++\\database.txt");

    if (myFile.is_open())
    {
        int x = 0;
        while (getline(myFile, line))
        {
            int l = line.length();

            CoinId[x] = line.substr(0, 3);
            CoinYear[x] = line.substr(4, 4);
            CoinValue[x] = line.substr(9, 2);
            CoinName[x] = line.substr(11, l - 11);

            x++;
        }
    }
    else
    {
        cout << "enable to open file!" << endl;
    }
}

// function for adding records
void addRecord()
{
    // variables to temporarily store coin name and value
    char coinName[50];
    char coinValue[5];
    char coinYear[10];
    char coinId[15];

    cin.ignore();

    // coin name and value inputs
    cout << "Coin ID : " << endl;
    cin.getline(coinId, 15);
    cout << "Coin Name : " << endl;
    cin.getline(coinName, 50);
    cout << "Coin Value : " << endl;
    cin.getline(coinValue, 5);
    cout << "Coin Year : " << endl;
    cin.getline(coinYear, 10);

    // checks for empty array and assigns the values to array
    for (int i = 0; i < maxRow; i++)
    {
        if (CoinValue[i] == "\0")
        {
            CoinValue[i] = coinValue;
            CoinName[i] = coinName;
            CoinYear[i] = coinYear;
            CoinId[i] = coinId;

            break;
        }
    }
}

// function to update record
void updateRecord(string srch)
{
    system("CLS");

    // variables to temporarily store coin name and value
    char coinName[50];
    char coinValue[5];
    char coinYear[10];
    char coinId[15];

    // sr no. count
    int count = 0;

    // searches for id and updates values for the same
    for (int i = 0; i < maxRow; i++)
    {
        if (CoinId[i] == srch)
        {
            count++;

            cout << "Coin Name update to :" << endl;
            cin.getline(coinName, 50);
            cout << "Coin Value update to : " << endl;
            cin.getline(coinValue, 5);
            cout << "Coin Year update to : " << endl;
            cin.getline(coinYear, 10);

            CoinName[i] = coinName;
            CoinValue[i] = coinValue;
            CoinYear[i] = coinYear;

            cout << "updated successfully" << endl;

            break;
        }
    }

    if (count == 0)
    {
        cout << "no stored records" << endl;
    }
    cout << "====================================================================" << endl;
}

// function to delete record
void deleteRecord(string srch)
{
    system("CLS");
    int count = 0;
    int total = sizeof(CoinId) / sizeof(CoinId[0]);
    // searches through records and deletes desired id value
    for (int i = 0; i < maxRow; i++)
    {
        if (CoinId[i] == srch)
        {
            count++;
            for (int j = i; j < total - 1; j++)
            {
                CoinId[j] = CoinId[j + 1];
                CoinName[j] = CoinName[j + 1];
                CoinValue[j] = CoinValue[j + 1];
                CoinYear[j] = CoinValue[j + 1];
            }
            i--;
            total--;

            cout << "Deleted successfully" << endl;
            break;
        }
    }

    // if no records are present
    if (count == 0)
    {
        cout << "no ID found" << endl;
    }
    cout << "=======================================================================================" << endl;
}

// function for searching through records
void searchRecord(string srch)
{
    system("CLS");
    int count = 0;

    cout << "Filtered Record(s)" << endl;
    cout << "=======================================================================================" << endl;

    cout << "   Sr.No.   |     ID     |   Value   |     Name     |   Year   " << endl;
    cout << "---------------------------------------------------------------------------------------\n";

    // searches records having id and prints it
    for (int i = 0; i < maxRow; i++)
    {
        if (CoinId[i] == srch)
        {
            count++;
            cout << "      " << count << "          " << CoinId[i] << "          " << CoinValue[i] << "          " << CoinName[i] << "         " << CoinYear[i] << "         " << endl;
        }
    }

    // if no records are present
    if (count == 0)
    {
        cout << "no stored records" << endl;
    }
    cout << "=======================================================================================" << endl;
}

// function for displaying the list
void listRecord()
{
    // system("CLS");

    cout << "Current Record(s)" << endl;
    cout << "=======================================================================================" << endl;

    // count for the Sr no. value
    int count = 0;

    cout << "   Sr.No.   |     ID     |   Value   |     Name     |   Year   " << endl;
    cout << "---------------------------------------------------------------------------------------\n";

    for (int i = 0; i < maxRow; i++)
    {
        if (CoinId[i] != "\0")
        {
            count++;
            cout << "      " << count << "          " << CoinId[i] << "          " << CoinValue[i] << "          " << CoinName[i] << "         " << CoinYear[i] << "         " << endl;
        }
    }
    if (count == 0)
    {
        cout << "no stored records" << endl;
    }
    cout << "====================================================================" << endl;
}

// function to save and exit file
void saveToFile()
{
    ofstream myfile;
    myfile.open("C:\\Users\\aryan\\Desktop\\projects\\CRUD c++\\database.txt");
    int count = 0;
    for (int i = 0; i < maxRow; i++)
    {
        if (CoinId[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << CoinId[i] + "," + CoinYear[i] + "," + CoinValue[i] + "," + CoinName[i] << endl;
        }
    }
    if (count == 0)
    {
        cout << "no stored records" << endl;
    }
    cout << "====================================================================" << endl;
    myfile.close();
}

// main function
int main()
{
    std::cout << "Menu\n";

    // variable for the available options
    int options;

    // variable for year value for search
    string idValue;
    // clears the console
    system("CLS");

    // opens file
    openFile();

    do
    {
        // available options
        cout << "==================================" << endl;
        cout << "1 - Create Record" << endl;
        cout << "2 - Update Record" << endl;
        cout << "3 - Delete Record" << endl;
        cout << "4 - Search Record" << endl;
        cout << "5 - Display All Records" << endl;
        cout << "6 - Exit and Save to Textfile" << endl;
        cout << "==================================" << endl;

        cout << "Select Option" << endl;
        cin >> options;

        // switch case for each number
        switch (options)
        {
        case 1:
            addRecord();
            system("CLS");

            break;
        case 2:
            // system("CLS");
            cin.ignore();
            cout << "Search coin by Id >> " << endl;
            getline(cin, idValue);
            updateRecord(idValue);

            break;
        case 3:
            cin.ignore();
            cout << "delete coin by Id >> " << endl;
            getline(cin, idValue);
            deleteRecord(idValue);
            // system("CLS");

            break;
        case 4:
            cin.ignore();
            cout << "Search coin by Id >> " << endl;
            getline(cin, idValue);
            searchRecord(idValue);
            cin.ignore();
            // system("CLS");
            break;
        case 5:
            system("CLS");
            listRecord();

            break;

        default:
            break;
        }

    } while (options != 6);

    saveToFile();
    cout << "exit...saving to file";

    return 0;
}
