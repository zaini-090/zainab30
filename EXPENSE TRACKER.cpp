#include <iostream>
#include <string>
using namespace std;

struct Expense {
    int itemNo;
    string name;
    float amount;
    string date;
    Expense* next;
};

Expense* head = NULL;
int countItems = 0;

void addExpense() {
    Expense* newExpense = new Expense();
    countItems++;
    newExpense->itemNo = countItems;

    cout << "Enter item name: ";
    cin >> newExpense->name;

    cout << "Enter expense amount: ";
    cin >> newExpense->amount;

    cout << "Enter date: ";
    cin >> newExpense->date;

    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        Expense* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newExpense;
    }

    cout << "Expense added successfully!\n";
}

void displayAll() {
    Expense* temp = head;
    float total = 0;
    int items = 0;
    cout << "\n... ALL EXPENSES ...\n";
    while (temp != NULL) {
        cout << "Item No: " << temp->itemNo
             << " | Name: " << temp->name
             << " | Amount: Rs: " << temp->amount
             << " | Date: " << temp->date << endl;
        total += temp->amount;
        items++;
        temp = temp->next;
    }
    cout << "TOTAL BILL: Rs: " << total << endl;
    cout << "Total Items: " << items << endl;
}

void displayItem() {
    int num;
    cout << "Enter item number to display: ";
    cin >> num;
    Expense* temp = head;
    while (temp != NULL) {
        if (temp->itemNo == num) {
            cout << "\n=== ITEM DETAILS ===\n";
            cout << "Item No: " << temp->itemNo << endl;
            cout << "Item Name: " << temp->name << endl;
            cout << "Item Expense: Rs " << temp->amount << endl;
            cout << "Date: " << temp->date << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Item not found.\n";
}

void deleteExpense() {
    int num;
    cout << "Enter item number to delete: ";
    cin >> num;

    Expense *temp = head, *prev = NULL;

    while (temp != NULL && temp->itemNo != num) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Expense deleted successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\n... EXPENSE TRACKER ...\n";
        cout << "1. Add Expense.\n";
        cout << "2. Display All Expenses.\n";
        cout << "3. Display Specific Item.\n";
        cout << "4. Delete Expense.\n";
        cout << "5. Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: displayAll(); break;
            case 3: displayItem(); break;
            case 4: deleteExpense(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}