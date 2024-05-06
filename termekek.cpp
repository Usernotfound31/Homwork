#include <iostream>
#include <vector>
#include <string>
using namespace std;



void processTransactions() {
    vector<vector<string>> transactions;
    vector<string> uniqueItems;

    int transactionCount;
    cout << "Add meg a tranzakciók számát: ";
    cin >> transactionCount;
    cin.ignore(); // Törli a pufferben maradt newline karaktert

    for (int i = 0; i < transactionCount; ++i) {
        vector<string> transaction;
        string items;

        cout << "Add meg a(z) " << i + 1 << ". tranzakció termékeit (vesszővel elválasztva): ";
        getline(cin, items);

        size_t pos = 0;
        while ((pos = items.find(',')) != string::npos) {
            string item = items.substr(0, pos);
            transaction.push_back(item);
            items.erase(0, pos + 1);
        }
        transaction.push_back(items);

        transactions.push_back(transaction);

        // Egyedi termékek kigyűjtése
        for (const string& item : transaction) {
            bool exists = false;
            for (const string& unique : uniqueItems) {
                if (unique == item) {
                    exists = true;
                    break;
                }
            }
            if (!exists)
                uniqueItems.push_back(item);
        }
    }


    cout << "Tranzakciók:" << endl;
    for (size_t i = 0; i < transactions.size(); ++i) {
        cout << i + 1 << ". tranzakció: ";
        for (const string& item : transactions[i]) {
            cout << item << " ";
        }
        cout << endl;
    }


    cout << "Egyedi termékek:" << endl;
    for (const string& item : uniqueItems) {
        cout << item << endl;
    }
}

int main() {
    processTransactions();
    return 0;
}