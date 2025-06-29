#include <bits/stdc++.h>

using namespace std; 


void iptbuffclean() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class Account {
public:
    int accountnumber;
    string name;
    float balance; 

    Account(int acnum = 0, string acname = "", float bal = 0.0f) 
        : accountnumber(acnum), name(std::move(acname)), balance(bal) {}


    void display() const {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }


    string tocsvstring() const {
        stringstream ss;
        ss << accountnumber << "," << name << "," << balance;
        return ss.str();
    }

    static Account fromcsvstring(const string& csvline) {
        stringstream ss(csvline);
        string segment;
        vector<string> seglist;

        while(getline(ss, segment, ',')) {
            seglist.push_back(segment);
        }

        if (seglist.size() == 3) {
            try {
                int accNum = stoi(seglist[0]);
                string accName = seglist[1];
                float bal = stof(seglist[2]); 
                return Account(accNum, accName, bal);
            } catch (const exception& e) {
                cerr << "Error parsing CSV line: " << csvline << " - " << e.what() << endl;
                return Account(); 
            }
        }
        return Account(); 
    }
};

class Bankdb {
private:
    vector<Account> accounts;
    const string filename = "accounts.csv";
    int nxtaccnum;

    void loadaccounts() {
        ifstream file(filename);

        string line;
     
        getline(file, line); 

        int maxaccnum = 1000;
        while (getline(file, line)) {
            Account acc = Account::fromcsvstring(line);
            if (acc.accountnumber) { 
                accounts.push_back(acc);
                if (acc.accountnumber > maxaccnum) {
                    maxaccnum = acc.accountnumber;
                }
            }
        }
        nxtaccnum = maxaccnum + 1;
        file.close();
    }

    void saveaccounts() const {
        ofstream file(filename);
       
        file << "AccountNumber,Name,Balance\n"; 
        for (const auto& acc : accounts) {
            file << acc.tocsvstring() << "\n";
        }
        file.close();
    }

    Account* findaccount(int tempnum) {
        for (auto& acc : accounts) {
            if (acc.accountnumber == tempnum) {
                return &acc;
            }
        }
        return nullptr; 
    }

public:
    Bankdb() {
        loadaccounts();
    }

    void createaccount() {
        string name;
        float initialdeposit; 

        cout << "Enter account holder name: ";
        getline(cin, name);

        while (true) {
            cout << "Enter initial deposit amount: ";
            cin >> initialdeposit;
            if (cin.fail() || initialdeposit < 0) {
                cout << "Invalid amount. Please enter a non-negative number." << endl;
                cin.clear();
                iptbuffclean();
            } else {
                break;
            }
        }
        iptbuffclean();

        Account newaccount(nxtaccnum++, name, initialdeposit);
        accounts.push_back(newaccount);
        saveaccounts();
        cout << "Account created successfully! Your account number is: " << newaccount.accountnumber << endl;
    }


    void deposit() {
        int tempnum;
        float amount;

        cout << "Enter account number: ";
        cin >> tempnum;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            iptbuffclean();
            return;
        }
        iptbuffclean();

        Account* acc = findaccount(tempnum);
        if (acc) {
            while (true) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (cin.fail() || amount <= 0) {
                    cout << "Invalid amount. Please enter a positive number." << endl;
                    cin.clear();
                    iptbuffclean();
                } else {
                    break;
                }
            }
            iptbuffclean();

            acc->balance += amount;
            saveaccounts();
            cout << "Deposit successful. New balance: " << acc->balance << endl;
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdraw() {
        int tempnum;
        float amount;

        cout << "Enter account number: ";
        cin >> tempnum;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            iptbuffclean();
            return;
        }
        iptbuffclean();

        Account* acc = findaccount(tempnum);
        if (acc) {
            while (true) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (cin.fail() || amount <= 0) {
                    cout << "Invalid amount. Please enter a positive number." << endl;
                    cin.clear();
                    iptbuffclean();
                } else if (amount > acc->balance) {
                    cout << "Insufficient balance. Current balance: " << acc->balance << endl;
                    cin.clear();
                    iptbuffclean();
                } else {
                    break;
                }
            }
            iptbuffclean();

            acc->balance -= amount;
            saveaccounts();
            cout << "Withdrawal successful. New balance: " << acc->balance << endl;
        } else {
            cout << "Account not found." << endl;
        }
    }

    void viewaccount() {
        int tempnum;
        cout << "Enter account number: ";
        cin >> tempnum;
        if (cin.fail()) {
            cout << "Invalid input. Enter a number." << endl;
            cin.clear();
            iptbuffclean();
            return;
        }
        iptbuffclean();

        Account* acc = findaccount(tempnum);
        if (acc) {
            acc->display();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void listallaccounts() const {
        if (accounts.empty()) {
            cout << "No accounts registered yet." << endl;
            return;
        }
        cout << "\n--- All Accounts ---" << endl;
        for (const auto& acc : accounts) {
            acc.display();
            cout << "--------------------" << endl;
        }
    }

    void deleteaccount() {
        int tempnum;
        cout << "Enter account number to delete: ";
        cin >> tempnum;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            iptbuffclean();
            return;
        }
        iptbuffclean();

        bool found = false;
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->accountnumber == tempnum) {
                accounts.erase(it);
                found = true;
                saveaccounts();
                cout << "Account " << tempnum << " deleted successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found." << endl;
        }
    }
};

int main() {
    Bankdb bank;
    int choice;

    do {
        cout << "\n--- Bank Management System ---" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. View Account Details" << endl;
        cout << "5. List All Accounts" << endl;
        cout << "6. Delete Account" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            cin.clear();
            iptbuffclean();
            continue;
        }
        iptbuffclean();

        switch (choice) {
            case 1:
                bank.createaccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.viewaccount();
                break;
            case 5:
                bank.listallaccounts();
                break;
            case 6:
                bank.deleteaccount();
                break;
            case 7:
                cout << "Exiting Bank Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}