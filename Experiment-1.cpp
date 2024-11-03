#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 0;
    int ch;
    int pos = 0;

    cout << "Please enter the number of games in your library: ";
    cin >> num;

    string games[1000];

    cout << endl << "Entering the games in the array: " << endl;
    for(int  i = 0; i < num; i++)
    {
        cout << "Enter the name of the game: ";
        cin >> games[i];
        cout << endl;
    }

    do
    {
        cout << "Displaying your library: " << endl;
        for(int  i = 0; i < num; i++)
        {
            cout << i + 1 << ". " << games[i] << " " << endl;
        }

        cout << "Please select one of the options listed below: " << endl;
        cout << "1. Insert at the start" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete at the start" << endl;
        cout << "5. Delete at the end" << endl;
        cout << "6. Delete at a specific position" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            for (int i = num; i > 0; i--)
            {
                    games[i] = games[i-1];
            }
            cout << endl << "Enter the name of the game: ";
            cin >> games[0];
            num++;
            break;

        case 2:
            cout << endl << "Enter the name of the game: ";
            cin >> games[num];
            num++;
            break;

        case 3:
            cout << endl << "Enter the position: ";
            cin >> pos;
            pos = pos - 1;
            for(int i = num; i > pos; i--)
            {
                games[i] = games[i-1];
            }
            cout << endl << "Enter the name of the game: ";
            cin >> games[pos];
            num++;
            break;

        case 4:
            cout << endl << "Deleted";
            for(int i = 0; i < num; i++)
            {
                games[i] = games[i + 1];
            }
            num--;
            break;

        case 5:
            cout << endl << "Deleted";
            num--;
            break;

        case 6:
            cout << endl << "Enter the position: ";
            cin >> pos;
            cout << endl << "Deleted";

            pos - 1;
            for(int i = pos; i < num; i++)
            {
                games[i] = games[i + 1];
            }
            num--;
            break;

        case 7:
            cout << endl << "Exiting";
            break;

        default:
            cout << "Invalid!!";
        }
    }while(ch != 7);

    return 0;
}
