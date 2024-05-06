#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void processTransactions() {
    vector<vector<string>> transactions;
    unordered_set<string> uniqueItemsSet;
    unordered_map<string, int> itemAppearances;
    unordered_map<string, unordered_map<string, int>> combinationCounts;

    int transactionCount;
    cout << "Add meg a tranzakciók számát: ";
    cin >> transactionCount;
    cin.ignore();

    for (int i = 0; i < transactionCount; ++i) {
        vector<string> transaction;
        string items;

        cout << "Add meg a(z) " << i + 1 << ". tranzakció termékeit (vesszővel elválasztva): ";
        getline(cin, items);

        istringstream iss(items);
        string item;
        while (getline(iss, item, ',')) {
            uniqueItemsSet.insert(item);
            transaction.push_back(item);
            itemAppearances[item]++;
        }

        // Kombinációk számlálása
        for (size_t i = 0; i < transaction.size(); ++i) {
            for (size_t j = i + 1; j < transaction.size(); ++j) {
                if (transaction[i] < transaction[j]) {
                    combinationCounts[transaction[i]][transaction[j]]++;
                } else {
                    combinationCounts[transaction[j]][transaction[i]]++;
                }
            }
        }

        transactions.push_back(transaction);
    }

    // Egyedi termékek kiírása
    cout << "Egyedi termékek:" << endl;
    for (const string& item : uniqueItemsSet) {
        int itemCount = itemAppearances[item];
        double percentage = static_cast<double>(itemCount) / transactionCount * 100;
        cout << item << ": " << fixed << setprecision(2) << percentage << "%" << endl;
    }

    // Kombinációk kiírása
    cout << "Kombinációk:" << endl;
    for (const auto& pair1 : combinationCounts) {
        const string& item1 = pair1.first;
        const auto& innerMap = pair1.second;
        for (const auto& pair2 : innerMap) {
            const string& item2 = pair2.first;
            int combinationCount = pair2.second;
            double combinationPercentage = static_cast<double>(combinationCount) / transactionCount * 100;
            cout << item1 << ", " << item2 << ": " << fixed << setprecision(2) << combinationPercentage << "%" << endl;
        }
    }
}

int main() {
    processTransactions();
    return 0;
}