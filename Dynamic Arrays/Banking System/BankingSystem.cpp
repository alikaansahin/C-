//name: ali kaan sahin
//sec: 002
//id: 22002932

#include <iostream>
#include <iomanip>
#include "BankingSystem.h"

using namespace std;

BankingSystem::BankingSystem() {
    branchCount = 0;
    accountCount = 0;
    customerCount = 0;
    accountId = 0;
    branches = NULL;
    customers = NULL;
    accounts = NULL;
}

BankingSystem::~ BankingSystem() {

    if (branches != NULL) {
        delete[] branches;
        branches = NULL;
    }
    if (customers != NULL) {
        delete[] customers;
        customers = NULL;
    }
    if (accounts != NULL) {
        delete[] accounts;
        accounts = NULL;
    }

}

void BankingSystem::addBranch(const int branchId, const string branchName) {
    bool branchExist = false;

    if (branchCount == 0) {

        branches = new Branch[branchCount + 1];
        branches[0] = Branch(branchId, branchName);
        cout << "Branch " << branchId << " has been added" << endl;
        branchCount++;

        return;
    } else {
        for (int i = 0; i < branchCount; i++) {
            if (branches[i].getBranchId() == branchId) {
                branchExist = true;
            }

        }
        if (!branchExist) {

            Branch *tempBranch = new Branch[branchCount];

            for (int i = 0; i < branchCount; i++) {
                tempBranch[i] = branches[i];
            }
            delete[] branches;
            branches = new Branch[branchCount + 1];

            for (int i = 0; i < branchCount; i++) {
                branches[i] = tempBranch[i];
            }

            branches[branchCount] = Branch(branchId, branchName);

            branchCount++;
            delete[] tempBranch;

            cout << "Branch " << branchId << " has been added" << endl;
        } else {
            cout << "Branch " << branchId << " already exists" << endl;
        }
    }
}

void BankingSystem::deleteBranch(const int branchId) {

    bool isExist = false;
    int branchIndex;

    if (branchCount != 0) {
        for (int i = 0; i < branchCount; i++) {
            if (branches[i].getBranchId() == branchId) {
                isExist = true;
                branchIndex = i;
            }
        }
    }

    if (isExist) {
        if(accountCount != 0) {
            int accountIndex;
            for (int index = 0; index < accountCount;) {
                if (accounts[index].getBranchId() == branchId) {
                    accountIndex = index;

                    if (accountCount == 1) {
                        delete[] accounts;
                        accountCount--;

                    } else {
                        if (accountIndex == 0) {
                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 1; i < accountCount; i++) {
                                tempAccount[i - 1] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;
                            accountCount--;


                        } else if (accountIndex == accountCount - 1) {

                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 0; i < accountCount - 1; i++) {
                                tempAccount[i] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;
                            accountCount--;

                        } else {
                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 0; i < accountIndex; i++) {
                                tempAccount[i] = accounts[i];
                            }
                            for (int i = accountIndex + 1; i < accountCount; i++) {
                                tempAccount[i - 1] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;

                            accountCount--;
                        }
                    }
                } else {
                    index++;
                }

            }
        }
        if (branchCount == 1) {

            delete[] branches;
            branches = NULL;
            cout << "Branch " << branchId << " has been deleted" << endl;
            branchCount--;
            return;
        } else {
            if (branchIndex == 0) {

                Branch *tempBranch = new Branch[branchCount - 1];

                for (int i = 1; i < branchCount; i++) {
                    tempBranch[i - 1] = branches[i];
                }

                delete[] branches;

                branches = tempBranch;
                cout << "Branch " << branchId << " has been deleted" << endl;
                branchCount--;

                return;
            }
            if (branchIndex == branchCount - 1) {

                Branch *tempBranch = new Branch[branchCount - 1];

                for (int i = 0; i < branchCount - 1; i++) {
                    tempBranch[i] = branches[i];
                }

                delete[] branches;

                branches = tempBranch;

                cout << "Branch " << branchId << " has been deleted" << endl;
                branchCount--;
                return;
            }

            Branch *tempBranch = new Branch[branchCount - 1];

            for (int i = 0; i < branchIndex; i++) {
                tempBranch[i] = branches[i];
            }

            for (int i = branchIndex + 1; i < branchCount; i++) {
                tempBranch[i - 1] = branches[i];
            }

            delete[] branches;
            branches = tempBranch;
            cout << "Branch " << branchId << " has been deleted" << endl;
            branchCount--;
        }
    } else {
        cout << "Branch " << branchId << " does not exist" << endl;
        return;
    }
}

void BankingSystem::addCustomer(const int customerId, const string customerName) {
    bool customerExist = false;

    if (customerCount == 0) {

        //delete[] customers;
        customers = new Customer[customerCount + 1];
        customers[0] = Customer(customerId, customerName);
        cout << "Customer " << customerId << " has been added" << endl;
        customerCount++;

        return;
    } else {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() == customerId) {
                customerExist = true;

            }
        }
        if (!customerExist) {

            Customer *tempCustomer = new Customer[customerCount];

            for (int i = 0; i < customerCount; i++) {
                tempCustomer[i] = customers[i];
            }
            delete[] customers;
            customers = new Customer[customerCount + 1];

            for (int i = 0; i < customerCount; i++) {
                customers[i] = tempCustomer[i];
            }

            customers[customerCount] = Customer(customerId, customerName);

            customerCount++;
            delete[] tempCustomer;

            cout << "Customer " << customerId << " has been added" << endl;
        } else {
            cout << "Customer " << customerId << " already exists" << endl;
        }
    }
}

void BankingSystem::deleteCustomer(const int customerId) {
    bool isExist = false;
    int customerIndex;

    if (customerCount != 0) {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() == customerId) {
                isExist = true;
                customerIndex = i;
            }
        }
    }
    if (isExist) {
        if(branchCount != 0) {
            int accountIndex;
            for (int index = 0; index < accountCount;) {
                if (accounts[index].getCustomerId() == customerId) {
                    accountIndex = index;

                    if (accountCount == 1) {
                        delete[] accounts;
                        //added
                        accounts = NULL;
                        //added
                        accountCount--;

                    } else {
                        if (accountIndex == 0) {
                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 1; i < accountCount; i++) {
                                tempAccount[i - 1] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;
                            accountCount--;


                        } else if (accountIndex == accountCount - 1) {

                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 0; i < accountCount - 1; i++) {
                                tempAccount[i] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;
                            accountCount--;

                        } else {
                            Account *tempAccount = new Account[accountCount - 1];

                            for (int i = 0; i < accountIndex; i++) {
                                tempAccount[i] = accounts[i];
                            }
                            for (int i = accountIndex + 1; i < accountCount; i++) {
                                tempAccount[i - 1] = accounts[i];
                            }

                            delete[] accounts;

                            accounts = tempAccount;

                            accountCount--;
                        }
                    }
                } else {
                    index++;
                }
            }
        }
        if (customerCount == 1) {

            delete[] customers;
            customers = NULL;
            cout << "Customer " << customerId << " has been deleted" << endl;
            customerCount--;
            return;
        } else {
            if (customerIndex == 0) {

                Customer *tempCustomer = new Customer[customerCount - 1];

                for (int i = 1; i < customerCount; i++) {
                    tempCustomer[i - 1] = customers[i];
                }

                delete[] customers;

                customers = tempCustomer;
                cout << "Customer " << customerId << " has been deleted" << endl;
                customerCount--;

                return;
            }
            if (customerIndex == customerCount - 1) {

                Customer *tempCustomer = new Customer[customerCount - 1];

                for (int i = 0; i < customerCount - 1; i++) {
                    tempCustomer[i] = customers[i];
                }

                delete[] customers;

                customers = new Customer[customerCount - 1];

                for (int i = 0; i < customerCount - 1; i++) {
                    customers[i] = tempCustomer[i];
                }
                cout << "Customer " << customerId << " has been deleted" << endl;
                customerCount--;
                delete[] tempCustomer;
                return;
            } else {
                Customer *tempCustomer = new Customer[customerCount - 1];

                for (int i = 0; i < customerIndex; i++) {
                    tempCustomer[i] = customers[i];
                }
                for (int i = customerIndex + 1; i < customerCount; i++) {
                    tempCustomer[i - 1] = customers[i];
                }
                delete[] customers;

                customers = new Customer[customerCount - 1];

                for (int i = 0; i < customerCount - 1; i++) {
                    customers[i] = tempCustomer[i];
                }
                cout << "Customer " << customerId << " has been deleted" << endl;

                customerCount--;
                delete[] tempCustomer;
                return;
            }
        }
    } else {
        cout << "Customer " << customerId << " does not exist" << endl;
        return;
    }
}

int BankingSystem::addAccount(const int branchId, const int customerId, const double amount) {

    bool customerExists = false;
    bool branchExists = false;

    if (branchCount != 0) {
        for (int i = 0; i < branchCount; i++) {
            if (branches[i].getBranchId() == branchId) {
                branchExists = true;
            }
        }
    }
    if (branchExists) {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() == customerId) {
                customerExists = true;
            }
        }
        if (customerExists) {
            if (accountCount == 0) {

                accountId++;
                accountCount++;

                accounts = new Account[accountCount];
                accounts[0] = Account(branchId, customerId, amount);
                accounts[0].setAccountId(accountId);
                cout << "Account " << accountId << " added for customer " << customerId << " at branch " << branchId
                     << endl;
                return accountId;

            } else {
                Account *tempAccount = new Account[accountCount];

                for (int i = 0; i < accountCount; i++) {
                    tempAccount[i] = accounts[i];
                }

                delete[] accounts;
                accounts = new Account[accountCount + 1]; //Account*?

                for (int i = 0; i < accountCount; i++) {
                    accounts[i] = tempAccount[i];
                }

                accountId++;
                accounts[accountCount] = Account(branchId, customerId, amount);
                accounts[accountCount].setAccountId(accountId);

                accountCount++;
                delete[] tempAccount;

                cout << "Account " << accountId << " added for customer " << customerId << " at branch " << branchId
                     << endl;
                return accountId;
            }
        } else {
            cout << "Customer " << customerId << " does not exist" << endl;
            return -1;
        }
    } else {
        cout << "Branch " << branchId << " does not exist" << endl;
        return -1;
    }
}

void BankingSystem::deleteAccount(const int accountId) {
    bool accountExist = false;
    int accountIndex = 0;
    if (accountId == -1) {
        cout << "Account " << accountId << " does not exist" << endl;
        return;
    }

    if (accountCount != 0) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountId() == accountId) {
                accountExist = true;
                accountIndex = i;
            }
        }
    }

    if (accountExist) {
        if (accountCount == 1) {

            delete[] accounts;
            accounts = NULL;
            cout << "Account " << accountId << " has been deleted" << endl;
            accountCount--;
            return;
        } else {
            if (accountIndex == 0) {

                Account *tempAccount = new Account[accountCount - 1];

                for (int i = 1; i < accountCount; i++) {
                    tempAccount[i - 1] = accounts[i];
                }

                delete[] accounts;

                accounts = tempAccount;

                cout << "Account " << accountId << " has been deleted" << endl;
                accountCount--;

                return;
            }
            if (accountIndex == accountCount - 1) {

                Account *tempAccount = new Account[accountCount - 1];

                for (int i = 0; i < accountCount - 1; i++) {
                    tempAccount[i] = accounts[i];
                }

                delete[] accounts;

                accounts = tempAccount;

                cout << "Account " << accountId << " has been deleted" << endl;
                accountCount--;

                return;
            } else {
                Account *tempAccount = new Account[accountCount - 1];

                for (int i = 0; i < accountIndex; i++) {
                    tempAccount[i] = accounts[i];
                }
                for (int i = accountIndex + 1; i < accountCount; i++) {
                    tempAccount[i - 1] = accounts[i];
                }

                delete[] accounts;

                accounts = tempAccount;

                cout << "Account " << accountId << " has been deleted" << endl;
                accountCount--;
                return;
            }
        }
    } else {
        cout << "Account " << accountId << " does not exist" << endl;

    }
}

void BankingSystem::showAllAccounts() {
    cout << "Account id Branch id Branch name Customer id Customer name Balance" << endl;
    string branchName;
    string customerName;

    for (int i = 0; i < accountCount; i++) {

        for (int j = 0; j < branchCount; j++) {
            if (accounts[i].getBranchId() == branches[j].getBranchId()) {
                branchName = branches[j].getName();
            }
        }
        for (int j = 0; j < customerCount; j++) {
            if (accounts[i].getCustomerId() == customers[j].getCustomerId()) {
                customerName = customers[j].getName();
            }
        }
        cout << accounts[i].getAccountId() << " " << accounts[i].getBranchId() << " " << branchName << " " <<
             accounts[i].getCustomerId() << " " << customerName << " " <<
             fixed << setprecision(2) << accounts[i].getBalance() << endl;
    }
}

void BankingSystem::showBranch(const int branchId) {
    bool isExist = false;
    int branchIndex = 0;
    int accountsInBranch = 0;
    string customerName;
    for (int i = 0; i < branchCount; i++) {
        if (branches[i].getBranchId() == branchId) {
            isExist = true;
            branchIndex = i;
        }
    }
    if (isExist) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getBranchId() == branchId) {
                accountsInBranch++;
            }
        }

        cout << "Branch id: " << branches[branchIndex].getBranchId() << " Branch name: "
             << branches[branchIndex].getName() << " Number of accounts: " << accountsInBranch << endl;
        if (accountsInBranch == 0) {
            return;
        }
        cout << "Accounts at this branch:" << endl;
        cout << "Account id Customer id Customer name Balance" << endl;

        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getBranchId() == branchId) {
                for (int j = 0; j < customerCount; j++) {
                    if (accounts[i].getCustomerId() == customers[j].getCustomerId()) {
                        customerName = customers[j].getName();
                    }
                }
                cout << accounts[i].getAccountId() << " " << accounts[i].getCustomerId() << " " << customerName << " "
                     <<
                     fixed << setprecision(2) << accounts[i].getBalance() << endl;
            }
        }

    } else {
        cout << "Branch " << branchId << " does not exist" << endl;
    }
}

void BankingSystem::showBranches() {

    for (int i = 0; i < branchCount; i++) {
        cout << branches[i].getBranchId() << endl;
        cout << branches[i].getName() << endl;
    }
}

void BankingSystem::showCustomers() {

    for (int i = 0; i < customerCount; i++) {
        cout << customers[i].getCustomerId() << endl;
        cout << customers[i].getName() << endl;
    }
}

void BankingSystem::showCustomer(const int customerId) {
    bool isExist = false;
    string customerName = "";
    string branchName = "";
    int customerIndex = 0;
    int customersAccounts = 0;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == customerId) {
            isExist = true;
            customerName = customers[i].getName();
            customerIndex = i;
        }
    }
    if (isExist) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getCustomerId() == customerId) {
                customersAccounts++;
            }
        }
        cout << "Customer id: " << customers[customerIndex].getCustomerId() << " Customer name: "
             << customerName << " Number of accounts: " << customersAccounts << endl;
        if (customersAccounts == 0) {
            return;
        }
        cout << "Accounts of this customer:" << endl;
        cout << "Account id Branch id Branch name Balance" << endl;
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getCustomerId() == customerId) {
                for (int j = 0; j < branchCount; j++) {
                    if (accounts[i].getBranchId() == branches[j].getBranchId()) {
                        branchName = branches[j].getName();
                    }
                }
                cout << accounts[i].getAccountId() << " " << accounts[i].getBranchId() << " " << branchName << " " <<
                     fixed << setprecision(2) << accounts[i].getBalance() << endl;
            }
        }
    } else {
        cout << "Customer " << customerId << " does not exist" << endl;
    }
}