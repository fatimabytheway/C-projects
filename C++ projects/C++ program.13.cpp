//program.13: Write a program to store a retrieve list of items in file using serialization, class items should have 1-name , 2-price , 3-quality//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;
    
    Item(const string& n = "", double p = 0, int q = 0) 
        : name(n), price(p), quantity(q) {}
    
    void display() const {
        cout << left << setw(20) << name 
             << setw(10) << price 
             << setw(10) << quantity << endl;
    }
};

class ItemManager {
private:
    vector<Item> items;
    
public:
    void addItem(const string& name, double price, int quantity) {
        items.push_back(Item(name, price, quantity));
    }
    
    void displayAll() const {
        cout << "\nItem List:" << endl;
        
        cout << left << setw(20) << "Name" 
             << setw(10) << "Price" 
             << setw(10) << "Quantity" << endl;
      
        for (const auto& item : items) {
            item.display();
        }
 
        cout << "Total items: " << items.size() << endl;
    }
    
    void saveToTextFile(const string& filename) {
        ofstream out(filename);
        if (!out) {
            cout << "Error opening file!" << endl;
            return;
        }
        
        out << items.size() << endl;
        for (const auto& item : items) {
            out << item.name << endl;
            out << item.price << endl;
            out << item.quantity << endl;
        }
        out.close();
        cout << "\nSaved to " << filename << endl;
    }
    
    void loadFromTextFile(const string& filename) {
        ifstream in(filename);
        if (!in) {
            cout << "Error opening file!" << endl;
            return;
        }
        
        items.clear();
        int count;
        in >> count;
        in.ignore();
        
        for (int i = 0; i < count; i++) {
            string name;
            double price;
            int quantity;
            getline(in, name);
            in >> price;
            in.ignore();
            in >> quantity;
            in.ignore();
            items.push_back(Item(name, price, quantity));
        }
        in.close();
        cout << "\nLoaded from " << filename << endl;
    }
};

int main() {
    ItemManager manager;
    int choice;
    
    do {
        cout << "\n1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Save to File" << endl;
        cout << "4. Load from File" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                string name;
                double price;
                int qty;
                cout << "Name: ";
                getline(cin, name);
                cout << "Price: ";
                cin >> price;
                cout << "Quantity: ";
                cin >> qty;
                cin.ignore();
                manager.addItem(name, price, qty);
                break;
            }
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.saveToTextFile("items.txt");
                break;
            case 4:
                manager.loadFromTextFile("items.txt");
                manager.displayAll();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    
    return 0;
}


//program.14:
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;
    
    // Constructor
    Item(string n = "", double p = 0.0, int q = 0) 
    {
        name = n;
        price = p;
        quantity = q;
    }
    
    // Display item details
    void display() 
    {
        cout << left << setw(20) << name 
             << setw(10) << price 
             << setw(10) << quantity << endl;
    }
};

class Inventory 
    {
private:
    vector<Item> items;
    string filename;
    
public:
    Inventory(string fname = "inventory.txt") {
        filename = fname;
        loadFromFile();
    }
    
    // Add item to inventory
    void addItem() 
    {
        string name;
        double price;
        int quantity;
        
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
        
        items.push_back(Item(name, price, quantity));
        cout << "Item added successfully!\n";
    }
    
    // Display all items
    void displayAll() {
        if (items.empty()) {
            cout << "No items in inventory.\n";
            return;
        }
        
        cout << "\n=== INVENTORY LIST ===\n";
        cout << left << setw(20) << "NAME" 
             << setw(10) << "PRICE" 
             << setw(10) << "QUANTITY" << endl;
        
        for (Item &item : items) 
        {
            item.display();
        }
        cout << endl;
    }
    
    // Save to file
    void saveToFile() {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing!\n";
            return;
        }
        
        for (Item &item : items) {
            file << item.name << "\n";
            file << item.price << "\n";
            file << item.quantity << "\n";
        }
        
        file.close();
        cout << "Data saved successfully!\n";
    }
    
    // Load from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file) {
            // File doesn't exist, start with empty inventory
            return;
        }
        
        string name;
        double price;
        int quantity;
        
        while (getline(file, name)) {
            if (file >> price) {
                file.ignore(); // Ignore newline
                if (file >> quantity) {
                    file.ignore(); // Ignore newline
                    items.push_back(Item(name, price, quantity));
                }
            }
        }
        
        file.close();
    }
    
    // Clear all items
    void clearAll() {
        items.clear();
        cout << "All items cleared!\n";
    }
};

int main() {
    Inventory inventory;
    int choice;
    
    do {
        cout << "\n=== INVENTORY MANAGEMENT ===\n";
        cout << "1. Add Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Save to File\n";
        cout << "4. Load from File\n";
        cout << "5. Clear All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.displayAll();
                break;
            case 3:
                inventory.saveToFile();
                break;
            case 4:
                inventory.loadFromFile();
                cout << "Data loaded from file!\n";
                break;
            case 5:
                inventory.clearAll();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}


//Program.15:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Account {
private:
    int accountNumber;
    string firstName;
    string lastName;
    double balance;

public:
    Account() : accountNumber(0), firstName(""), lastName(""), balance(0.0) {}
    
    Account(int accNo, string fName, string lName, double bal) 
        : accountNumber(accNo), firstName(fName), lastName(lName), balance(bal) {}

    // Getter methods
    int getAccountNumber() const { return accountNumber; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    double getBalance() const { return balance; }

    // Setter methods
    void setBalance(double bal) { balance = bal; }

    // Display account details
    void displayAccount() const {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nFirst Name: " << firstName;
        cout << "\nLast Name: " << lastName;
        cout << "\nBalance: $" << fixed << setprecision(2) << balance;
    }

    // Save account to file
    void saveToFile(ofstream& outFile) const {
        outFile << accountNumber << "\n";
        outFile << firstName << "\n";
        outFile << lastName << "\n";
        outFile << balance << "\n";
    }

    // Load account from file
    static Account loadFromFile(ifstream& inFile) {
        int accNo;
        string fName, lName;
        double bal;
        
        inFile >> accNo;
        inFile.ignore();
        getline(inFile, fName);
        getline(inFile, lName);
        inFile >> bal;
        
        return Account(accNo, fName, lName, bal);
    }
};

class BankingSystem {
private:
    vector<Account> accounts;
    int nextAccountNumber;

    void loadAccountsFromFile() {
        ifstream inFile("accounts.txt");
        if (!inFile) {
            nextAccountNumber = 1;
            return;
        }

        accounts.clear();
        while (inFile.peek() != EOF) {
            Account acc = Account::loadFromFile(inFile);
            accounts.push_back(acc);
        }
        inFile.close();

        // Set next account number
        if (!accounts.empty()) {
            nextAccountNumber = accounts.back().getAccountNumber() + 1;
        } else {
            nextAccountNumber = 1;
        }
    }

    void saveAllAccountsToFile() {
        ofstream outFile("accounts.txt");
        if (!outFile) {
            cout << "Error: Unable to save to file!\n";
            return;
        }

        for (const auto& acc : accounts) {
            acc.saveToFile(outFile);
        }
        outFile.close();
    }

    int findAccountIndex(int accountNumber) {
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return i;
            }
        }
        return -1;
    }

public:
    BankingSystem() {
        loadAccountsFromFile();
    }

    ~BankingSystem() {
        saveAllAccountsToFile();
    }

    void openAccount() {
        string firstName, lastName;
        double balance;

        cout << "\n--- OPEN ACCOUNT ---\n";
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        
        cout << "Enter Initial Deposit Amount: $";
        cin >> balance;

        while (balance < 0) {
            cout << "Invalid amount! Please enter a positive amount: $";
            cin >> balance;
        }

        Account newAccount(nextAccountNumber, firstName, lastName, balance);
        accounts.push_back(newAccount);
        nextAccountNumber++;

        saveAllAccountsToFile();

        cout << "\n🎉 Congratulations! Account is created! 🎉\n";
        newAccount.displayAccount();
    }

    void accountEnquiry() {
        if (accounts.empty()) {
            cout << "\nNo accounts exist in the system!\n";
            return;
        }

        int accountNumber;
        cout << "\nACCOUNT ENQUIRY\n";
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        int index = findAccountIndex(accountNumber);
        if (index != -1) {
            accounts[index].displayAccount();
        } else {
            cout << "\n Account Number " << accountNumber << " does not exist!\n";
        }
    }

    void deposit() {
        if (accounts.empty()) {
            cout << "\nNo accounts exist in the system!\n";
            return;
        }

        int accountNumber;
        double amount;

        cout << "\nDEPOSIT\n";
        
        while (true) {
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            int index = findAccountIndex(accountNumber);
            if (index != -1) {
                cout << "Enter amount to deposit: $";
                cin >> amount;

                while (amount <= 0) {
                    cout << "Invalid amount! Please enter a positive amount: $";
                    cin >> amount;
                }

                double newBalance = accounts[index].getBalance() + amount;
                accounts[index].setBalance(newBalance);
                saveAllAccountsToFile();

                cout << "\nDeposit successful!\n";
                cout << "New Balance: $" << fixed << setprecision(2) << newBalance << "\n";
                break;
            } else {
                cout << " Account Number " << accountNumber << " does not exist!\n";
                cout << "Please enter a valid account number.\n";
            }
        }
    }

    void withdrawal() {
        if (accounts.empty()) {
            cout << "\nNo accounts exist in the system!\n";
            return;
        }

        int accountNumber;
        double amount;

        cout << "\nWITHDRAWAL\n";
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        int index = findAccountIndex(accountNumber);
        if (index != -1) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;

            while (amount <= 0) {
                cout << "Invalid amount! Please enter a positive amount: $";
                cin >> amount;
            }

            if (amount > accounts[index].getBalance()) {
                cout << " Insufficient balance! Your current balance is: $" 
                     << fixed << setprecision(2) << accounts[index].getBalance() << "\n";
            } else {
                double newBalance = accounts[index].getBalance() - amount;
                accounts[index].setBalance(newBalance);
                saveAllAccountsToFile();

                cout << "\n Money withdrawn successfully! Thank you.\n";
                cout << "New Balance: $" << fixed << setprecision(2) << newBalance << "\n";
            }
        } else {
            cout << "\n Account Number " << accountNumber << " does not exist!\n";
        }
    }

    void closeAccount() {
        if (accounts.empty()) {
            cout << "\nNo accounts exist in the system!\n";
            return;
        }

        int accountNumber;
        char confirm;

        cout << "\nCLOSE ACCOUNT\n";
        cout << "Enter Account Number to close: ";
        cin >> accountNumber;

        int index = findAccountIndex(accountNumber);
        if (index != -1) {
            cout << "\nAccount to be closed:\n";
            accounts[index].displayAccount();
            
            cout << "\nAre you sure you want to close this account? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                accounts.erase(accounts.begin() + index);
                saveAllAccountsToFile();
                cout << "\n Account " << accountNumber << " has been closed successfully!\n";
            } else {
                cout << "\nOperation cancelled. Returning to main menu.\n";
            }
        } else {
            cout << "\n Account Number " << accountNumber << " does not exist!\n";
        }
    }

    void showAllAccounts() {
        if (accounts.empty()) {
            cout << "\nNo accounts exist in the system!\n";
            return;
        }

        cout << "\n--- ALL ACCOUNTS ---\n";
        cout << "Total Accounts: " << accounts.size() << "\n";
        
        for (const auto& acc : accounts) {
            acc.displayAccount();
        }
    }

    void displayMenu() {
        cout << "        BANKING MANAGEMENT SYSTEM\n";
        cout << "1. Open an Account\n";
        cout << "2. Account Enquiry\n";
        cout << "3. Deposit\n";
        cout << "4. Withdrawal\n";
        cout << "5. Close an Account\n";
        cout << "6. Show All Accounts\n";
        cout << "7. Quit\n";
        cout << "Enter your choice (1-7): ";
    }

    void run() {
        int choice;

        do {
            displayMenu();
            cin >> choice;

            // Clear input buffer in case of invalid input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n Invalid input! Please enter a number between 1-7.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    openAccount();
                    break;
                case 2:
                    accountEnquiry();
                    break;
                case 3:
                    deposit();
                    break;
                case 4:
                    withdrawal();
                    break;
                case 5:
                    closeAccount();
                    break;
                case 6:
                    showAllAccounts();
                    break;
                case 7:
                    cout << "\nThank you for using the Banking System!\n";
                    cout << "Goodbye! 👋\n";
                    break;
                default:
                    cout << "\n Invalid choice! Please enter a number between 1-7.\n";
            }

        } while (choice != 7);
    }
};

int main() {
    BankingSystem bank;
    bank.run();
    return 0;
}
