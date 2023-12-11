#include "controller.h"
#include "../model/model.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int nline=0;
void cargar_estructura(){
    string line, word, *saldo=nullptr;
    saldo=new string[2000];
    int count=0;
    ifstream in_file("../data/clients.csv", ifstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado"<<endl;
    }
    while(getline(in_file, line)){
        stringstream str(line);
        while(getline(str, word, ',')){
            switch(count){
                case 0: cliente[nline].ci=stoi(word);
                case 1: cliente[nline].nombre=word;
                case 2: cliente[nline].numero_de_cuenta=word;
                case 3: cliente[nline].tipo_de_cuenta=word;
                case 4: *(saldo+nline)=word;
                case 5: cliente[nline].suspension=word;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    for(int i=0; i<nline; i++){
        cliente[i].saldo=stoi(*(saldo+i));
    }
    delete[] saldo;
    saldo=nullptr;
    for(int i=0; i<nline; i++){
        cout<<i+1<<"-"<<cliente[i].ci<<endl;
        cout<<i+1<<"-"<<cliente[i].nombre<<endl;
        cout<<i+1<<"-"<<cliente[i].numero_de_cuenta<<endl;
        cout<<i+1<<"-"<<cliente[i].tipo_de_cuenta<<endl;
        cout<<i+1<<"-"<<cliente[i].saldo<<endl;
        cout<<i+1<<"-"<<cliente[i].suspension<<endl;
    }
}