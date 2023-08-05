#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;


class Expense {
public:
    Expense(const string& category, double value)
    {
        this->category = category;
        this->value = value;
    }

    string getCategory() const {
        return category;
    }

    double getValue() const {
        return value;
    }

private:
    string category;
    double value;
};

class Wallet
{
private:
    string name;
    double balance;

public:
    Wallet(string& name, double balance = 0.0)
    {
        this->name = name;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw (double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const
    {
          return this->balance;
    }

    string getName() const
    {
        return this->name;
    }
};


class Card
{

public:
    Card(string& name,string& type,double balance)
    {
        this->name = name;
        this->type = type;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance() const
    {
        return this->balance;
    }

    string getName() const
    {
        return this->name;
    }

    string getType() const
    {
        return this->type;
    }


private:
    string name;
    string type;
    double balance;

};

class BankAccount{

private:
    vector<Wallet> wallets;
    vector<Card> cards;
    vector<Expense> expenses;

public:
    BankAccount() = default;

    void addWallet(string& name, double Balance = 0.0)
    {
        Wallet wallet(name, Balance);
        wallets.push_back(wallet);
    }

    void addCard(string& name, string& type, double Balance = 0.0)
    {
        Card card(name,type,Balance);
        cards.push_back(card);
    }

    void depositWallet(int Index, double value)
    {
        if (Index >= 0 && Index < wallets.size()) {
            wallets[Index].deposit(value);
        }
    }

    void depositCard(int Index, double value)
     {
        if (Index >= 0 && Index < cards.size())
        {
            cards[Index].deposit(value);
        }
    }

    bool withdrawWallet(int Index, double value)
    {
        if (Index >= 0 && Index < wallets.size())
        {
            return wallets[Index].withdraw(value);
        }
        return false;
    }

    bool withdrawCard(int cardIndex, double amount)
    {
        if (cardIndex >= 0 && cardIndex < cards.size())
        {
            return cards[cardIndex].withdraw(amount);
        }
        return false;
    }

    void showWallets() const
    {
        for (int i = 0; i < wallets.size(); ++i)
        {

            cout << "Wallet: " << wallets[i].getName() << ", Balance: " << wallets[i].getBalance() << endl;

        }
    }

    void showCards() const {
        for (int i = 0; i < cards.size(); ++i)
        {
            cout << "Card: " << cards[i].getName() << ", Type: " << cards[i].getType()<< ", Balance: " << cards[i].getBalance() << endl;
        }
    }

    void addExpense(const string& WalletOrCardName, const string& category, double value)
    {
        for (Wallet& wallet : wallets) {
            if (wallet.getName() == WalletOrCardName)
            {
                wallet.withdraw(value);
                expenses.push_back(Expense(category, value));
                return;
            }
        }
        for (Card& card : cards) {
            if (card.getName() == WalletOrCardName)
            {
                card.withdraw(value);
                expenses.push_back(Expense(category, value));
                return;
            }
        }
    }


    void ShowExpenses() const
    {
        vector<string> uniqueCategories;
        for (const Expense& expense : expenses)
        {
            bool found = false;
            for (const string& category : uniqueCategories)
            {
                if (expense.getCategory() == category)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                uniqueCategories.push_back(expense.getCategory());
            }
        }

        for (const string& category : uniqueCategories)
        {
            double totalExpense = 0.0;
            for (const Expense& expense : expenses)
            {
                if (expense.getCategory() == category)
                {
                    totalExpense += expense.getValue();
                }
            }
            cout << "Category: " << category << ", Total Expense: " << totalExpense << endl;
        }
    }

    void showTopExpenses() const
    {
        vector<Expense> sortedExpenses = expenses;

        // Сортировка расходов по убыванию суммы
        sort(sortedExpenses.begin(), sortedExpenses.end(),[](const Expense& a, const Expense& b){return a.getValue() > b.getValue();});

        cout << "Top Expenses:" << endl;

        for (int i = 0; i < min(3, static_cast<int>(sortedExpenses.size())); ++i)
        {
            cout << "Expense " << i + 1 << ": Category - " << sortedExpenses[i].getCategory()<< ", Value - " << sortedExpenses[i].getValue() << endl;
        }
    }

    void saveExpenses(const string& filename) const
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "Error opening file " << filename << " for writing." << endl;
            return;
        }

        for (const Expense& expense : expenses)
        {
            outFile << expense.getCategory() << "," << expense.getValue() << endl;
        }

        outFile.close();
    }

    void saveTopExpenses(const string& filename) const
    {
        vector<Expense> sortedExpenses = expenses;
        sort(sortedExpenses.begin(), sortedExpenses.end(),[](const Expense& a, const Expense& b){return a.getValue() > b.getValue();});

        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "Error opening file " << filename << " for writing." << endl;
            return;
        }

        for (int i = 0; i < min(3, static_cast<int>(sortedExpenses.size())); ++i)
        {
            outFile << "Category: " << sortedExpenses[i].getCategory() << ", Value: " << sortedExpenses[i].getValue() << endl;
        }

        outFile.close();
    }
};


int main()
{
    BankAccount* bill = new BankAccount();

    bill->addWallet((string &) "Cash Wallet", 100.0);
    bill->addCard((string &) "Debit Card", (string &) "Debit", 500.0);
    bill->addCard((string &) "Credit Card", (string &) "Credit", 1000.0);


    bill->showWallets();
    bill->showCards();

    bill->depositWallet(0, 50.0);
    bill->depositCard(1, 200.0);

    bill->showWallets();
    bill->showCards();

    bill->withdrawWallet(0, 30.0);
    bill->withdrawCard(2, 100.0);

    bill->addExpense("Cash Wallet", "Groceries", 30.0);
    bill->addExpense("Debit Card", "Entertainment", 50.0);
    bill->addExpense("Credit Card", "Dining Out", 25.0);

     
    bill->ShowExpenses();

    bill->showWallets();
    bill->showCards();

    bill->showTopExpenses();

    bill->saveExpenses("expenses.txt");
    bill->saveTopExpenses("top_expenses.txt");


    return 0;
}


