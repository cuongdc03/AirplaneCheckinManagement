#ifndef __Account_h__
#define __Account_h__
#include <string>
#include "Chuyenbay.h"
using namespace std;
// create class Account with 2 private variables(account,password) and 2 public functions
class Account
{
private:
    string account;
    string password;

public:
    Account *next;
    void setAccount(string acc);
    void setPassword(string pass);
    string getAccount();
    string getPassword();
    Account();
    ~Account();
};
// create class DanhSachAccount with 1 private variable(dau) and 3 public functions
class DanhSachAccount
{
private:
    Account *dau;

public:
    DanhSachAccount() { dau = NULL; }
    void InpByFile(string name);
    void AddNew();
    bool Search_account(string acc);
    void xuat();
    bool login(string acc, string pass);
    
};
#endif