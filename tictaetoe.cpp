#include <bits/stdc++.h>
using namespace std;

// user 1 win condition and place allotment

int user1(char n[9], int a, int &f)
{
    if (n[a - 1] != 'O' && n[a - 1] != 'X')
    {
        n[a - 1] = 'X';
        if ((n[0] == n[1] && n[1] == n[2]) ||
            (n[3] == n[4] && n[4] == n[5]) ||
            (n[6] == n[7] && n[7] == n[8]) ||
            (n[0] == n[3] && n[3] == n[6]) ||
            (n[1] == n[4] && n[4] == n[7]) ||
            (n[2] == n[5] && n[5] == n[8]) ||
            (n[0] == n[4] && n[4] == n[8]) ||
            (n[2] == n[4] && n[4] == n[6]))
        {
            f = 1;
        }
    }

    else
    {
        cout << "Not vacant. Can't you see it's already taken ????" << endl;
    }
}

// user 2 win condition and place allotment

void user2(char n[9], int a, int &f)
{
    if (n[a - 1] != 'O' && n[a - 1] != 'X')
    {
        n[a - 1] = 'O';
        if ((n[0] == n[1] && n[1] == n[2]) ||
            (n[3] == n[4] && n[4] == n[5]) ||
            (n[6] == n[7] && n[7] == n[8]) ||
            (n[0] == n[3] && n[3] == n[6]) ||
            (n[1] == n[4] && n[4] == n[7]) ||
            (n[2] == n[5] && n[5] == n[8]) ||
            (n[0] == n[4] && n[4] == n[8]) ||
            (n[2] == n[4] && n[4] == n[6]))
        {
            f = 1;
        }
    }

    else
    {
        cout << "Not vacant. Can't you see it's already taken ????" << endl;
    }
}

// function to draw a board
void board(char n[9])
{
    cout << n[0] << " | " << n[1] << " | " << n[2] << endl;
    cout << "--|---|--" << endl;
    cout << n[3] << " | " << n[4] << " | " << n[5] << endl;
    cout << "--|---|--" << endl;
    cout << n[6] << " | " << n[7] << " | " << n[8] << endl;
}

// function to check tie
// it checks if any white space is available and then passes false  to the main func.. and it continues the loop but if  no white space is available it returns true and loop breaks and says tie



bool tie(char n[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (n[i] != 'X' && n[i] != 'O')
        {
            return false;
        }
    }
}

// HERE COMES THE MAIN BOYYYYY
int main()
{
    char a11 = '1', a12 = '2', a13 = '3', a21 = '4', a22 = '5', a23 = '6', a31 = '7', a32 = '8', a33 = '9';
    char n[9] = {a11, a12, a13, a21, a22, a23, a31, a32, a33};

    for (int i = 0;; i++)
    { //----------Loop condition not necessary ig-----------

        cout << endl;
        board(n);

        int choice1, choice2, f = 0;

        cout << endl
             << "Enter 1st choice : ";
        cin >> choice1;
        cout << endl;

        user1(n, choice1, f);

        board(n);

        if (f == 1)
        {
            cout << "1 wins";
            break;
        }

        if (tie(n))
        {
            cout << endl
                 << "tie" << endl;
            break;
        }

        cout << endl
             << "Enter 2nd choice : ";
        cin >> choice2;
        cout << endl;

        user2(n, choice2, f);

        cout << endl;

        if (f == 1)
        {
            board(n);
            cout << endl
                 << "2 wins";
            break;
        }
        if (tie(n))
        {
            cout << endl
                 << "tie" << endl;
            break;
        }
    }
}