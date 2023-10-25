#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
struct Clientes{
    string ci, nombre, numero_de_cuenta, tipo_de_cuenta, suspension;
};

int main(){
    Clientes cliente[2000]; 
    string line, word;
    int count=0, nline=0;
    ifstream in_file("clients.csv", ifstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado";
        return 0;
    }
    while(getline(in_file, line)){
        stringstream str(line);
        while(getline(str, word, ',')){
            switch(count){
                case 0: cliente[nline].ci=word;
                case 1: cliente[nline].nombre=word;
                case 2: cliente[nline].numero_de_cuenta=word;
                case 3: cliente[nline].tipo_de_cuenta=word;
                case 4: cliente[nline].suspension=word;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    for(int i=0; i<1000; i++){
        cout<<cliente[i].ci<<endl;
        cout<<cliente[i].nombre<<endl;
        cout<<cliente[i].numero_de_cuenta<<endl;
        cout<<cliente[i].tipo_de_cuenta<<endl;
        cout<<cliente[i].suspension<<endl;
    }
    system("pause");
    return 0;
}