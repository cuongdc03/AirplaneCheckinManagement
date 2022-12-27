#include"Account.h"
#include"Chuyenbay.h"
#include<iostream>
#include<fstream>
using namespace std;
void Account::setAccount(string acc)
{
    this->account = acc;
}
void Account::setPassword(string pass)
{
    this->password = pass;
}
string Account::getAccount()
{
    return account;
}
string Account::getPassword()
{
    return password;
}
Account::Account()
{
    next = NULL;
}
Account::~Account() {}
void DanhSachAccount::InpByFile(string name)
{
    Account *hientai;
    std::ifstream input(name);

    string line;
    int rows, cols, i;
    cols = 2;
    for (rows = 0; getline(input, line); ++rows)
    {
        if (dau == NULL)
        {
            dau = new Account;
            hientai = dau;
        }
        else
        {
            hientai->next = new Account;
            hientai = hientai->next;
        }
        i = 1;
        string element = "";
        if (line.length() == 0)
            continue;
        for(int t = 0; t < line.length(); ++t)
        {
            int tmp;
            if (line[t] != ' ')
            {
                element += line[t];
            }
            else if (line[t] == ' ')
            {
                if (i == 1)
                {
                    hientai->setAccount(element);
                    i++;
                    element = "";
                }
                else if (i == 2)
                {
                    hientai->setPassword(element);
                    i++;
                    element = "";
                }
            }
        }
    }
}
void DanhSachAccount::AddNew()
{
    Account *hientai;
    if (dau == NULL)
    {
        dau = new Account;
        hientai = dau;
    }
    else
    {
        hientai = dau;
        while (hientai->next != NULL)
        {
            hientai = hientai->next;
        }
        hientai->next = new Account;
        hientai = hientai->next;
    }
    string acc, pass;
    cout<<"Nhap ten tai khoan: ";
    cin>>acc;
    cout<<"Nhap mat khau: ";
    cin>>pass;
    hientai->setAccount(acc);
    hientai->setPassword(pass);
}
bool DanhSachAccount::Search_account(string acc)
{
    Account *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getAccount() == acc)
        {
            return hientai;
        }
        hientai = hientai->next;
    }
    return NULL;
}
bool DanhSachAccount::login(string acc,string pass)
{
    Account *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getAccount() == acc && hientai->getPassword() == pass)
        {
            return true;
        }
        hientai = hientai->next;
    }
    return false;
}
void DanhSachAccount::xuat()
{
    Account *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        cout<<hientai->getAccount()<<" "<<hientai->getPassword()<<endl;
        hientai = hientai->next;
    }
}
