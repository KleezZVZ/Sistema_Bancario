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
}
int inicio_sesion_1(string search_nombre, string search_numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(search_nombre==cliente[i].nombre && search_numero_de_cuenta==cliente[i].numero_de_cuenta){
            return 1;
        }
    }
    return -1;
}
int inicio_sesion_2(int search_ci, string search_numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(search_ci==cliente[i].ci && search_numero_de_cuenta==cliente[i].numero_de_cuenta){
            return 1;
        }
    }
    return -1;
}
int consulta_saldo(string numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(numero_de_cuenta==cliente[i].numero_de_cuenta){
            return cliente[i].saldo;
        }
    }
    return -1;
}
int consulta_ci(string numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(numero_de_cuenta==cliente[i].numero_de_cuenta){
            return cliente[i].ci;
        }
    }
    return -1;
}
string consulta_nombre(string numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(numero_de_cuenta==cliente[i].numero_de_cuenta){
            return cliente[i].nombre;
        }
    }
    return "-1";
}
string consulta_tipo_de_cuenta(string numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(numero_de_cuenta==cliente[i].numero_de_cuenta){
            return cliente[i].tipo_de_cuenta;
        }
    }
    return "-1";
}
int estado_de_suspension(string search_numero_de_cuenta){
    for(int i=0; i<nline; i++){
        if(search_numero_de_cuenta==cliente[i].numero_de_cuenta && cliente[i].suspension=="false"){
            return cliente[i].numero_de_penalizaciones;
        }
    }
    return -1;
}
int deposito_a_cuenta(string numero_de_cuenta, int deposito){
    try{
        if(deposito<=0){
            throw 1;
        }
        for(int i=0; i<nline; i++){
            if(numero_de_cuenta==cliente[i].numero_de_cuenta){
                cliente[i].saldo+=deposito;
                ofstream out_file("../data/Operaciones.csv",ios_base::app);
                out_file<<cliente[i].ci<<","<<cliente[i].nombre<<","<<cliente[i].tipo_de_cuenta<<","<<"deposito"<<","<<deposito<<endl;
                out_file.close();
                return 1;
            }
        }
    }catch(int n){
        for(int i=0; i<nline; i++){
            if(numero_de_cuenta==cliente[i].numero_de_cuenta){
                cliente[i].numero_de_penalizaciones+=n;
            }if(cliente[i].numero_de_penalizaciones>=3){
                cliente[i].suspension="true";
                return -1;
            }
        }
        return -2;
    }
    return -3;
}
int retiro_a_cuenta(string numero_de_cuenta, int retiro){
    try{
        if(retiro<=0){
            throw 1;
        }
        for(int i=0; i<nline; i++){
            if(numero_de_cuenta==cliente[i].numero_de_cuenta && retiro<=cliente[i].saldo){
                cliente[i].saldo-=retiro;
                ofstream out_file("../data/Operaciones.csv",ios_base::app);
                out_file<<cliente[i].ci<<","<<cliente[i].nombre<<","<<cliente[i].tipo_de_cuenta<<","<<"retiro"<<","<<retiro<<endl;
                out_file.close();
                return 1;
            }else if(numero_de_cuenta==cliente[i].numero_de_cuenta && retiro>cliente[i].saldo){
                return -1;
            }
        }
    }catch(int n){
        for(int i=0; i<nline; i++){
            if(numero_de_cuenta==cliente[i].numero_de_cuenta){
                cliente[i].numero_de_penalizaciones+=n;
            }if(cliente[i].numero_de_penalizaciones>=3){
                cliente[i].suspension="true";
                return -2;
            }
        }
        return -3;
    }
    return -4;
}
int transferencia_entre_clientes(string numero_de_cuenta, string numero_de_cuenta_2, int transferencia){
    int pos, pos_2;
    try{
        if(transferencia<=0){
            throw 1;
        }
        for(int i=0; i<nline; i++){
            if(cliente[i].numero_de_cuenta==numero_de_cuenta && transferencia<=cliente[i].saldo){
                pos=i;
            }else if(cliente[i].numero_de_cuenta==numero_de_cuenta && transferencia>cliente[i].saldo){
                return -1;
            }if(cliente[i].numero_de_cuenta==numero_de_cuenta_2){
                pos_2=i;
            }
        }
        cliente[pos].saldo-=transferencia;
        cliente[pos_2].saldo+=transferencia;
        ofstream out_file("../data/Operaciones.csv",ios_base::app);
        out_file<<cliente[pos].ci<<","<<cliente[pos].nombre<<","<<cliente[pos].tipo_de_cuenta<<","<<"transferencia"<<","<<cliente[pos_2].ci<<","<<cliente[pos_2].nombre<<","<<cliente[pos_2].tipo_de_cuenta<<","<<transferencia<<endl;
        out_file.close();
        return 1;
    }catch(int n){
        for(int i=0; i<nline; i++){
            if(numero_de_cuenta==cliente[i].numero_de_cuenta){
                cliente[i].numero_de_penalizaciones+=n;
            }if(cliente[i].numero_de_penalizaciones>=3){
                cliente[i].suspension="true";
                return -2;
            }
        }
        return -3;
    }
    return -4;
}