#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
struct Clientes{
    int ci, numero_de_penalizaciones, saldo;
    string nombre, tipo_de_cuenta, suspension, numero_de_cuenta;
};
int flag=0, flag_2=0, search_ci, search_ci_2, deposito=0, retiro=0, search_numero_de_cuenta_2, search_numero_de_cuenta_3, search_nombre_2; 
string search_numero_de_cuenta, search_nombre, saldo[1000];
int main(){
    Clientes cliente[2000]; 
    string line, word;
    int count=0, nline=0;
    ifstream in_file("../data/clients.csv", ifstream::in);
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
                case 4: saldo[nline]=word;
                case 5: cliente[nline].suspension=word;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    for(int i=0; i<1000; i++){
        cliente[i].saldo=stoi(saldo[i]); //Hice muchas pruebas, y por mas que los datos se estaban guardando bien, no pude lograr guardar el saldo en la parte anterior debido a un error con el stoi
    }do{
        cout<<"Bienvenido a la plataforma online de nuestro banco, a continuacion se le dara las siguientes opciones:\n1)Consulta de cliente.\n2)Operaciones bancarias.\n3)Estado de suspension de su cuenta.\n4)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
                do{
                    cout<<"Bienvenido a la seccion para consultar su estado de cuenta, a continuacion se le dira sus opciones:\n1)Buscar su cuenta mediante su nombre y numero de cuenta.\n2)Buscar su cuenta mediante su cedula y numero de cuenta.\n3)Volver al menu principal.\nElija su opcion: "; cin>>flag_2;
                    system("cls");
                    switch(flag_2){
                        case 1:
                        rewind(stdin);
                        cout<<"Por favor ingrese su nombre y apellido: "; getline(cin, search_nombre);
                        system("cls");
                        rewind(stdin);
                        cout<<"Ingrese su numero de cuenta: "; getline(cin, search_numero_de_cuenta);
                        system("cls");
                        rewind(stdin);
                        for(int i=0; i<1000; i++){ 
                            if(search_nombre==cliente[i].nombre){
                                search_nombre_2=i;
                                break;
                            }
                        }for(int i=0; i<1000; i++){ 
                            if(search_numero_de_cuenta==cliente[i].numero_de_cuenta){
                                search_numero_de_cuenta_2=i;
                                break;
                            }
                        }if(search_numero_de_cuenta_2!=search_nombre_2){
                            cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
                            system("pause");
                            system("cls");
                        }else{
                            cout<<"Bienvenido/a "<<cliente[search_nombre_2].nombre<<", este es su estado de cuenta: "<<endl;
                            cout<<"Su saldo actual: "<<cliente[search_nombre_2].saldo<<endl;
                            cout<<"Informacion adicional: "<<endl;
                            cout<<"Numero de cedula: "<<cliente[search_nombre_2].ci<<endl;
                            cout<<"Numero de cuenta: "<<cliente[search_nombre_2].numero_de_cuenta<<endl;
                            cout<<"Tipo de cuenta: "<<cliente[search_nombre_2].tipo_de_cuenta<<endl;
                            cout<<"Para mas informacion sobre el estado de suspension, por favor vaya a la seccion Estado de suspension de su cuenta, en el menu principal"<<endl;
                            system("pause");
                            system("cls");
                        }
                        break;
                        case 2:
                        cout<<"Por favor ingrese el numero de su cedula de indentidad: "; cin>>search_ci;
                        system("cls");
                        rewind(stdin);
                        cout<<"Ingrese su numero de cuenta: "; getline(cin, search_numero_de_cuenta);
                        system("cls");
                        rewind(stdin);
                        for(int i=0; i<1000; i++){ 
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
                        }else{
                            cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<", este es su estado de cuenta: "<<endl;
                            cout<<"Su saldo actual: "<<cliente[search_ci].saldo<<endl;
                            cout<<"Informacion adicional: "<<endl;
                            cout<<"Numero de cedula: "<<cliente[search_ci].ci<<endl;
                            cout<<"Numero de cuenta: "<<cliente[search_ci].numero_de_cuenta<<endl;
                            cout<<"Tipo de cuenta: "<<cliente[search_ci].tipo_de_cuenta<<endl;
                            cout<<"Para mas informacion sobre el estado de suspension, por favor vaya a la seccion Estado de suspension de su cuenta, en el menu principal"<<endl;
                            system("pause");
                            system("cls");
                        }
                        break;
                        case 3:
                            cout<<"Esperamos que haya sido fructifera su consulta!"<<endl;
                            system("pause");
                            system("cls");
                            break;
                        default:
                        cout<<"Ingrese una opcion valida."<<endl;
                        system("pause");
                        system("cls");
                    }
                }while(flag_2!=3);
                break;
            case 2:
                do{
                    cout<<"Bienvenido al sistema de operaciones bancarias, a continuacion se le dira sus opciones:\n1)Deposito.\n2)Retiro.\n3)Transferencia entre usuarios de nuestro mismo banco.\n4)Volver al menu principal.\nElija su opcion: "; cin>>flag_2;
                    system("cls");
                    switch(flag_2){
                        case 1:
                        cout<<"Bienvenido a la seccion de depositos.\nPor favor ingrese el numero de su cedula de indentidad: "; cin>>search_ci;
                        system("cls");
                        rewind(stdin);
                        cout<<"Ingrese el numero de cuenta de su tarjeta: "; getline(cin, search_numero_de_cuenta);
                        system("cls");
                        rewind(stdin);
                        for(int i=0; i<1000; i++){ 
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
                            cout<<"Lo lamentamos "<<cliente[search_ci].nombre<<". pero su cuenta esta suspendida"<<endl;
                            system("pause");
                            system("cls");
                        }else{
                            cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<".\nIngrese la cantidad a depositar: "; cin>>deposito;
                            system("cls");
                            if(deposito<=0){
                                cout<<"I am a joke to you?"<<endl;
                                cliente[search_ci].numero_de_penalizaciones++;
                                system("pause");
                                system("cls");
                            }else{
                                cliente[search_ci].saldo+=deposito;
                                cout<<"Su deposito ha sido realizado con exito!"<<endl;
                                ofstream out_file("../data/Operaciones.csv",ios_base::app);
                                out_file<<cliente[search_ci].ci<<","<<cliente[search_ci].nombre<<","<<cliente[search_ci].tipo_de_cuenta<<","<<"deposito"<<","<<deposito<<endl;
                                out_file.close();
                                system("pause");
                                system("cls");
                            }
                        }if(cliente[search_ci].numero_de_penalizaciones>=3){
                            cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
                            cliente[search_ci].suspension="true";
                            cliente[search_ci].numero_de_penalizaciones=0;
                            system("pause");
                            system("cls");
                            }
                        break;
                        case 2:
                        cout<<"Bienvenido a la seccion de retiro.\nPor favor ingrese el numero de su cedula de indentidad: "; cin>>search_ci;
                        system("cls");
                        rewind(stdin);
                        cout<<"Ingrese el numero de cuenta de su tarjeta: "; getline(cin, search_numero_de_cuenta);
                        system("cls");
                        rewind(stdin);
                        for(int i=0; i<1000; i++){ 
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
                            cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<".\nIngrese la cantidad a retirar: "; cin>>retiro;
                            system("cls");
                            if(retiro<=0){
                                cout<<"I am a joke to you?"<<endl;
                                cliente[search_ci].numero_de_penalizaciones++;
                                system("pause");
                                system("cls");
                            }else if(retiro>cliente[search_ci].saldo){
                                cout<<"No puede retirar una cantidad superior a su saldo. Por favor, depositele a su cuenta"<<endl;
                                system("pause");
                                system("cls");
                            }else if(retiro>50000){
                                cout<<"La politicas de nuestro banco no permite retiros mayores a 50.000$"<<endl;
                                cliente[search_ci].numero_de_penalizaciones++;
                                system("pause");
                                system("cls");
                            }else{
                                cliente[search_ci].saldo-=retiro;
                                cout<<"Su retiro ha sido realizado con exito!"<<endl;
                                ofstream out_file("../data/Operaciones.csv",ios_base::app);
                                out_file<<cliente[search_ci].ci<<","<<cliente[search_ci].nombre<<","<<cliente[search_ci].tipo_de_cuenta<<","<<"retiro"<<","<<retiro<<endl;
                                out_file.close();
                                system("pause");
                                system("cls");
                            }
                        }if(cliente[search_ci].numero_de_penalizaciones>=3){
                            cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
                            cliente[search_ci].suspension="true";
                            cliente[search_ci].numero_de_penalizaciones=0;
                            system("pause");
                            system("cls");
                            }
                        break;
                        case 3:
                        cout<<"Bienvenido a la seccion de transferencias entre clientes de nuestro banco.\nPor favor ingrese la cedula del cliente de origen:"; cin>>search_ci;
                        system("cls");
                        rewind(stdin);
                        cout<<"Ingrese el numero de cuenta de su tarjeta: "; getline(cin, search_numero_de_cuenta);
                        system("cls");
                        rewind(stdin);
                        for(int i=0; i<1000; i++){ 
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
                            cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<".\nPor favor, ingrese la cedula del cliente a transferir: "; cin>>search_ci_2;
                            system("cls");
                            rewind(stdin);
                            cout<<"Ingrese el numero de cuenta de la tarjeta a transferir: "; getline(cin, search_numero_de_cuenta);
                            system("cls");
                            rewind(stdin);
                            for(int i=0; i<1000; i++){ 
                                if(search_ci_2==cliente[i].ci){
                                    search_ci_2=i;
                                    break;
                                }
                            }for(int i=0; i<1000; i++){ 
                                if(search_numero_de_cuenta==cliente[i].numero_de_cuenta){
                                    search_numero_de_cuenta_3=i;
                                    break;
                                }
                            }if(search_numero_de_cuenta_3!=search_ci_2){
                                cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
                                system("pause");
                                system("cls");
                            }else if(cliente[search_ci_2].suspension=="true"){
                                cout<<"Lo lamentamos pero la cuenta de "<<cliente[search_ci_2].nombre<<" esta suspendida"<<endl;
                                system("pause");
                                system("cls");
                            }else{
                                cout<<"Ingrese la cantidad a transferir a "<<cliente[search_ci_2].nombre<<": "; cin>>deposito;
                                if(deposito<=0){
                                    cout<<"I am a joke to you?"<<endl;
                                    cliente[search_ci].numero_de_penalizaciones++;
                                    system("pause");
                                    system("cls");
                                }else if(deposito>100000){
                                    cout<<"Las politicas de nuestro banco no permiten transferencias mayores a 100.000$"<<endl;
                                    cliente[search_ci].numero_de_penalizaciones++;
                                    system("pause");
                                    system("cls");
                                }else if(deposito>cliente[search_ci].saldo){
                                    cout<<"No puede transferir un monto mayor a su saldo actual. Por favor, depositele a su cuenta"<<endl;
                                    system("pause");
                                    system("cls");
                                }else{
                                    cliente[search_ci].saldo-=deposito;
                                    cliente[search_ci_2].saldo+=deposito;
                                    cout<<"Su transferencia a "<<cliente[search_ci_2].nombre<<" ha sido realizado con exito"<<endl;
                                    ofstream out_file("../data/Operaciones.csv",ios_base::app);
                                    out_file<<cliente[search_ci].ci<<","<<cliente[search_ci].nombre<<","<<cliente[search_ci].tipo_de_cuenta<<","<<"transferencia"<<","<<cliente[search_ci_2].ci<<","<<cliente[search_ci_2].nombre<<","<<cliente[search_ci_2].tipo_de_cuenta<<","<<deposito<<endl;
                                    out_file.close();
                                    system("pause");
                                    system("cls");
                                }
                            }
                        }
                        if(cliente[search_ci].numero_de_penalizaciones>=3){
                            cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
                            cliente[search_ci].suspension="true";
                            cliente[search_ci].numero_de_penalizaciones=0;
                            system("pause");
                            system("cls");
                        }
                        break;
                        case 4:
                            cout<<"Esperamos que sus operaciones hayan sido fructiferas!"<<endl;
                            system("pause");
                            system("cls");
                            break;
                        default: 
                            cout<<"No ingreso una opcion valida"<<endl;
                            system("pause");
                            system("cls");
                            break;
                    }
                }while(flag_2!=4);
            break;
            case 3:
                cout<<"Bienvenido a la seccion de penalizacion de su cuenta, a continuacion se le nombrara las politicas del banco que en caso de incumplirse sera motivo de penalizacion.\n1)Ingresar montos en las operaciones iguales a 0 o menor.\n2)Realizar retiros cuyo monto exceda los 50.000$ en una sola operacion.\n3)Realizar transferencias entre clientes del mismo banco cuyo monto exceda los 100.000$ en una sola operacion.\nEn caso de recibir 3 penalizaciones, su cuenta sera suspendida hasta nuevo aviso.\nPor favor ingrese su numero de cedula para verificar el estado de suspension de su cuenta: "; cin>>search_ci;
                system("cls");
                for(int i=0; i<1000; i++){ 
                        if(search_ci==cliente[i].ci){
                            search_ci=i;
                            break;
                        }else if(search_ci!=cliente[i].ci && i==999){
                            cout<<"La cedula que ingreso no es correcta, por favor vuelva a intentarlo"<<endl;
                            search_ci=2000;
                            system("pause");
                            system("cls");
                        }
                    }if(cliente[search_ci].suspension=="true" && search_ci!=2000){
                        cout<<"Estimado cliente/a "<<cliente[search_ci].nombre<<" su cuenta "<<cliente[search_ci].numero_de_cuenta<<" "<<cliente[search_ci].tipo_de_cuenta<<" esta en estado de suspension"<<endl;
                        system("pause");
                        system("cls");
                    }else if(cliente[search_ci].suspension=="false" && search_ci!=2000){
                        cout<<"Estimado cliente/a "<<cliente[search_ci].nombre<<" su cuenta "<<cliente[search_ci].numero_de_cuenta<<" "<<cliente[search_ci].tipo_de_cuenta<<" no se encuentra en estado de suspension.\nEstas son la cantidad de penalizaciones que actual tiene: "<<cliente[search_ci].numero_de_penalizaciones<<endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                case 4:
                    cout<<"Gracias por su confianza, vuelva pronto!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout<<"No ingreso una opcion valida"<<endl;
                    system("pause");
                    system("cls");
                    break;
        }
    }while(flag!=4);
    ofstream write_file("../data/clients.csv", ofstream::out);
    for(int i=0; i<1000; i++){
        write_file<<cliente[i].ci<<","<<cliente[i].nombre<<","<<cliente[i].numero_de_cuenta<<","<<cliente[i].tipo_de_cuenta<<","<<cliente[i].saldo<<","<<cliente[i].suspension<<endl;
    }
    write_file.close();
    return 0;
}