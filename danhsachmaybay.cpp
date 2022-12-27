#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include"danhsachmaybay.h"
using namespace std;
int danhsachmaybay::sl_mb = 0;

void danhsachmaybay::Tang_SlMB(){
    ++sl_mb;
}

danhsachmaybay::danhsachmaybay(){
    dau = NULL;
}

void danhsachmaybay::InpByFile(string name){
    maybay* hientai;
    std::ifstream input(name);
    string line;
    int rows, cols, i;
    cols = 4;
    for(rows = 0; getline(input, line) ; ++rows)
    {
        if(dau == NULL){
            dau = new maybay;
            hientai = dau;
        }
        else{
            hientai->next = new maybay;
            hientai = hientai->next;
        }
        i = 1;
        string element = "";
        for(int t = 0; t < line.length(); ++t){
            if(line[t] != ' '){
                element += line[t];
            }
            else if(line[t] == ' '){    
                if(i == 1)hientai->setSohieu(element);                                    
                else if(i == 2) hientai->setLoai(element);                                  
                else if(i == 3) hientai->setSoCho(element);
                else if(i == 4) hientai->setSl_mb(element);
                else break;
                element = ""; 
                while (line[t] == ' '){
                    t++;
                }
                t--;
                i++;
            }
        }
        Tang_SlMB();
    }
}



maybay *danhsachmaybay::Search(string id){
    if(dau == NULL) {
        cout << "Danh sach may bay rong!" << endl;
        return NULL;
    }
    maybay *hientai;
    hientai = dau;
    while (hientai != NULL){
        if(hientai->getSohieu() == id){
            //cout << "FOUND!" << endl;
            return hientai;
        }
        hientai = hientai->next;
    }
    return NULL;
}

