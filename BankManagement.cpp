#include <bits/stdc++.h>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

class Account {
public:
    string name; 
    string accNum;
    string accType;

private:
    string password;
    int balance;

public:
    void setPassword(string p) {
        // Future feature: use minimum length validation or only 4 digit password
        password = p;
    }
    string getPassword() const {
        return password;
    }

    void setBalance(int b) {
        balance = b;
    }
    int getBalance() const {
        return balance;
    }

    Account(string name, string accNum, string password, int balance, string accType) {
        this->name = name;
        this->accNum = accNum;
        this->password = password;
        this->balance = balance;
        this->accType = accType;
    }

    json toJson() const {
        json j;
        j["name"] = name;
        j["accNum"] = accNum;
        j["password"] = password; 
        j["balance"] = balance;
        j["accType"] = accType;
        return j;
    }
};

// Function to generate a random account number
string generateNumber() {
    string x = "";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < 10; i++) {
        x += to_string(rand() % 10); // Generate a random digit between 0 and 9
    }

    return x;
}

// Function to read accounts from a JSON file and populate the vector
vector<Account> readAccountsFromFile(const string& filename) {
    vector<Account> accounts; //declaring it to return it when the func is called.
    ifstream file(filename);
    if (file.is_open()) {
        try {
            json j;
            file >> j; // Read the JSON data
            for (const auto& item : j) {
                string name = item.at("name").get<string>();
                string accNum = item.at("accNum").get<string>();
                string password = item.at("password").get<string>();
                int balance = item.at("balance").get<int>();
                string accType = item.at("accType").get<string>();

                Account newAccount(name, accNum, password, balance, accType); // Create a new Account object (temporary for the loop)
                accounts.push_back(newAccount);
            }
        } catch (const exception& e) {
            cout << "Error reading JSON data: " << e.what() << endl;
        }
        file.close();
    } else {
        cout << "File not found or unable to open. Starting with an empty account list." << endl;
    }
    return accounts;
}

// Function to save accounts to a JSON file
void saveAccountsToFile(const vector<Account>& accounts, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        json j = json::array(); // Create a JSON array

        // for statement condition loops throught the entire json data. 
        for (const auto& account : accounts) {
            j.push_back(account.toJson()); // Convert each account to JSON and add to the array
        }
        file << j.dump(4) << endl; // Write the entire accounts as a JSON array with indentation
        file.close();
        cout << "Accounts saved to " << filename << endl;
    }
    
     else {
        cout << "Unable to open file for writing." << endl;
    }
}

int main() {
    vector<Account> accounts = readAccountsFromFile("accounts.json"); // Read existing accounts from JSON file
    int choice;

    do {
        cout << endl;
        cout << "1. Create Account" << endl; //done
        cout << "2. Check Balance" << endl; //done
        cout << "3. Debit/Credit amount" << endl; //done
        cout << "4. Change password" << endl; //done
        cout << "5. Delete account" << endl;
        cout << "6. Exit" << endl; //done
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cin.ignore();

        switch(choice) {

            case 1: { 
                string name, accNum, password, accType;
                int balance = 0;

                cout << "Enter Account Holder name: ";
                getline(cin, name);
                cout << "Set Account password: ";
                getline(cin, password);
                cout << "Set Account type (savings/current): ";
                getline(cin, accType);

                accNum = generateNumber();
                cout << "Account created. Your account number is: " << accNum << endl;

                Account newAccount(name, accNum, password, balance, accType);
                accounts.push_back(newAccount); 
                break;
            } //closing case 1


            case 2: { 
                string checkAccountNum;
                cout << "Enter the account number: ";
                cin >> checkAccountNum;

                bool found = 0;

                for (int i=0; i<accounts.size(); i++) {
                    if (checkAccountNum == accounts[i].accNum) {

                        found = 1;
                        cout << "Current balance is " << accounts[i].getBalance() << endl;

                    if (accounts[i].getBalance()<1000 && accounts[i].accType=="savings")
                    {cout << "Minimum balance requirement is not met, please add more funds to keep the account active" << endl;}    
                        
                        break;

                    }
                }

                if(found == 0)
                {cout << "Account not found" << endl;}

                break;
            } //closing case 2

            case 3 : {
            
            string checkAccountNum, checkPassword;
            char option;
            int amount;
            bool found = 0;

            cout << "Do you want to deposit or withdraw money? (d/w): ";
            cin >> option;

            cout << "Enter the account number: ";
            cin >> checkAccountNum;

            for (int i=0; i<accounts.size(); i++) {
                if (checkAccountNum == accounts[i].accNum) {

                    found = 1;

                   switch (option) {

                    case 'w': {

                    bool terminate=0;

                    for (int j=0; j<5 ; j++) {

                    cout << "Enter the account password: ";
                    cin >> checkPassword;

                    if (checkPassword==accounts[i].getPassword())
                    {
                        cout << endl << "Account found, you can now perform transactions" << endl;
                        break; //breaks the loop and proceeds further
                    }

                    if (j==4) {terminate=1;}

                    else {
                        cout << "Incorrect password, try again."<<endl << 4-j <<" tries left."<<endl<<endl; 
                        continue;
                        }

                    }

                    if (terminate==1) {
                        cout << "You have exceeded the maximum number of attempts." << endl;
                        break;}

                    cout << endl << "Current balance is " << accounts[i].getBalance() << endl;

                    cout << "Enter amount to withdraw : ";
                    cin >> amount;
                    cout << endl;

                    if (accounts[i].getBalance()>amount) {

                    int z = accounts[i].getBalance() - amount;
                    accounts[i].setBalance(z); 
                    cout << "Amount " << amount << " deducted from account" << endl;
                    cout << "Updated balance is : " << accounts[i].getBalance() << endl;
                    } //closing if of sufficient funds.

                    else {
                        cout << "Insufficient balance. Try again by depositing some money." << endl;}
                    
                      break;
                    } //closing w

                    case 'd': {

                    cout << endl << "Current balance is " << accounts[i].getBalance() << endl;

                    cout << "Enter amount to deposit : ";
                    cin >> amount;
                    cout << endl;

                    int z = accounts[i].getBalance() + amount;
                    accounts[i].setBalance(z); 
                    cout << "Amount " << amount << " depostied to account" << endl;
                    cout << "Updated balance is : " << accounts[i].getBalance() << endl;
                    
                      break;


                    } //closing d


                    } //closing switch
            
             
             break;
             } //closing if check acc
             } //closing for loop that runs over the vector

            if (found == 0) 
            {cout << "Account not found" << endl;}

            break;
            } //closing case 3



            case 4: {

                string checkAccountNum,checkPassword,password;
                bool found=0;

                cout << "Enter the account number: ";
                cin >> checkAccountNum;

                for (int i=0; i<accounts.size(); i++) {
                    if (checkAccountNum == accounts[i].accNum)
                    {   
                        found = 1;
                        cout << "Enter old password to confirm : ";
                        cin >> checkPassword;

                        if (checkPassword == accounts[i].getPassword())
                        {
                            cout << "Set new Passowrd : ";
                            cin >> password;
                        }
                    accounts[i].setPassword(password);
                    break;
                    }

                }

                if (found == 0) 
                {cout << "Account not found" << endl;}

                break;
            } //closing case 4

            case 5: {

                string checkAccountNum, checkPassword;
                bool found = false;

                cout << "Enter the account number : ";
                cin >> checkAccountNum;

                for (int i = 0; i < accounts.size(); i++) {
                    if (checkAccountNum == accounts[i].accNum) {
                        found = true;

                   for (int j=0; j<5 ; j++) {

                    cout << "Enter the account password: ";
                    cin >> checkPassword;

                    if (checkPassword==accounts[i].getPassword())
                    {
                        cout << endl << "Account found, you can now perform transactions" << endl;
                        break;
                    }

                    else {
                        cout << "Incorrect password, try again."<<endl << 4-j <<" tries left."<<endl<<endl; 
                        continue;}
                    }




                    accounts.erase(accounts.begin() + (i - 1));
                    cout << "Account deleted"<<endl;
                        break; 
                    }

                    
                }

                

                if (found==0) { //can also use if (!found)
                    cout << "Account not found" << endl;
                }

                break;
            } //closing case 5



            default:
                if(choice != 6){
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
        } //closing switch
    } while (choice != 6);

    

    // Save accounts back to JSON before exiting
    saveAccountsToFile(accounts, "accounts.json");
    return 0;
} //closing 