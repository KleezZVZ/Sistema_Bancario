#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
struct Clientes{
    int ci, saldo, numero_de_penalizaciones;
    string nombre, tipo_de_cuenta, suspension, numero_de_cuenta;
};
int flag=0, search_ci, deposito=0, search_numero_de_cuenta_2; 
string search_numero_de_cuenta;
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
                case 0: cliente[nline].ci=stoi(word);
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
    do{
        cout<<"Bienvenido a la plataforma online de nuestro banco, a continuacion se le dara las siguientes opciones:\n1)Consulta de cliente.\n2)Busqueda de cliente.\n3)Operaciones bancarias.\n4)Estado de penalizaciones de su cuenta.\n5)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
                cout<<"Bienvenido a la consulta de su estado de cuenta.\nNecesita ingresar su numero de cedula de identidad para poder visualizar su estado de cuenta.\nIngrese su cedula: "; cin>>search_ci;
                system("cls");
                for(int i=0; i<1000; i++){ //Razonamiento para usar linear search: Ya que solo se usara para buscar un cliente y no para filtrar en un cierto orden, no vi necesidad de implementar un sistema de ordenamiento para utilizar los otros metodos de busquedas, ya que se usaran en la seccion 2 de este programa.
                    if(search_ci==cliente[i].ci){
                        cout<<"El cliente es: "<<cliente[i].nombre<<endl;
                        cout<<"El numero de cuenta es: "<<cliente[i].numero_de_cuenta<<endl;
                        cout<<"El tipo de cuenta es: "<<cliente[i].tipo_de_cuenta<<endl;
                        cout<<"El saldo de la cuenta es: "<<cliente[i].saldo<<endl;
                        system("pause");
                        system("cls");
                        break;
                    }else if(search_ci!=cliente[i].ci && i==999){
                        cout<<"La cedula que ingreso no es correcta, por favor vuelva a intentarlo"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            case 3:
            do{
                cout<<"Bienvenido al sistema de operaciones bancarias, a continuacion se le dira sus opciones:\n1)Deposito.\n2)Retiro.\n3)Transferencia entre usuarios de nuestro mismo banco.\n4)Volver al menu principal.\nElija su opcion: "; cin>>flag;
                system("cls");
                switch(flag){
                    case 1:
                    cout<<"Bienvenido a la seccion de depositos.\nPor favor ingrese el numero de su cedula de indentidad: "; cin>>search_ci;
                    system("cls");
                    rewind(stdin);
                    cout<<"Ingrese el numero de cuenta de su tarjeta: "; getline(cin, search_numero_de_cuenta);
                    system("cls");
                    rewind(stdin);
                    for(int i=0; i<1000; i++){ //Mismo razonamiento que la seccion 1
                        if(search_ci==cliente[i].ci){
                            search_ci=i;
                            break;
                        }
                    }for(int i=0; i<1000; i++){ 
                        if(search_numero_de_cuenta==cliente[i].numero_de_cuenta){
                            search_numero_de_cuenta_2=i;
                            break;
                        }
                    }if(search_numero_de_cuenta_2!=search_ci){
                        cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
                        system("pause");
                        system("cls");
                    }else if(cliente[search_ci].suspension=="true"){
                        cout<<"Lo lamentamos "<<cliente[search_ci].nombre<<" pero su cuenta esta suspendida"<<endl;
                        system("pause");
                        system("cls");
                    }else{
                        cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<"\nIngrese la cantidad a depositar: "; cin>>deposito;
                        system("cls");
                        if(deposito<=0){
                            cout<<"I am a joke to you?"<<endl;
                            cliente[search_ci].numero_de_penalizaciones++;
                            system("pause");
                            system("cls");
                        }else{
                            cliente[search_ci].saldo+=deposito;
                            cout<<"Su deposito ha sido realizado con exito!"<<endl;
                            ofstream out_file("Operaciones.csv",ios_base::app);
                            out_file<<cliente[search_ci].ci<<","<<cliente[search_ci].nombre<<","<<"deposito"<<","<<deposito<<","<<cliente[search_ci].tipo_de_cuenta<<endl;
                            out_file.close();
                            system("pause");
                            system("cls");
                        }
                    }if(cliente[search_ci].numero_de_penalizaciones>=3){
                        cout<<"Debido a la gran de error cometido durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
                        cliente[search_ci].suspension="true";
                        cliente[search_ci].numero_de_penalizaciones=0;
                        system("pause");
                        system("cls");
                        }
                    break;
                }
            }while(flag!=4);
        }
    }while(flag!=5);
    cout<<"Gracias por su confianza!, vuelva pronto!"<<endl;
    system("pause");
    return 0;
}