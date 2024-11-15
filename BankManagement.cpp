#include <bits/stdc++.h>
#include <cstdlib>  
using namespace std;
#include <string>


class Account {


  
public :
    string name;
    string accNum;

private :

    string password;
    int balance;

    public:

    void setPassword(string p) {
        // if (p.length() < 4) { }  <----- feature to be added
        password = p;
    }
    string getPassword()  {
        return password;
    }

    void setBalance(int b) {
        // if (p.length() < 4) { }  <----- feature to be added
        balance = b;
    }
    int getBalance()  {
        return balance;
    }

 Account(string name, string accNum, string password, int balance) {
    this->name = name;
    this->accNum = accNum;
    this->password = password;
    this->balance = balance;
  }

};


string generateNumber() {

    string x = "";
  // Seed the random number generator
  srand(time(0));

  for (int i = 0; i < 10; i++) {
    x += to_string(rand() % 10); // %10 will print a random digit between 0 and 9
  }
  
    return x;
}

int checkPassword(string p, vector<Account> accounts, int f) {
    for (int i=0; i<accounts.size(); i++) {
        if (accounts[i].getPassword() == p) {f=1;}
        }

        return f;
}


int main() {

vector<Account> accounts;
int choice;

do {
        cout << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Check Balance" << endl;
        cout << "3. Debit/Credit amount" << endl;
        cout << "4. Change password" << endl;
        cout << "5. Delete account" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cin.ignore();

        switch(choice) {

            case 1: {
                string name, accNum, password;
                int balance;

                cout << "Enter Account Holder name : ";
                getline(cin, name);
                cout << "Set Account password : ";
                getline(cin, password);  //----here the password is set without using setter because it pushes it into the setpassword function
                balance =0;
                cout << endl;

                accNum = generateNumber();
                cout << "Account created, you may add some funds" << endl; 
                cout << "Your account number is: " << accNum;


                Account person(name, accNum, password, balance);
                accounts.push_back(person);

                cout << endl;
                break;
            }

            case 2: {

                string checkAccountNum, checkPassword;
                cout << "Enter the account number : ";
                cin >> checkAccountNum;
                

                for (int i=0; i<accounts.size(); i++) {

                if (checkAccountNum == accounts[i].accNum)

                {cout << "Enter password : ";
                // cin >> ;
                cout << "Current balance is " << accounts[i].getBalance() << endl;}

                }

                break;

            }





        }
    } while (choice!=6);
}