#include <stdlib.h>
#include "view/view.h"
using namespace std;
int main(){
    menu_principal();
    system("pause");
    /*
    do{
        cout<<"Bienvenido a la plataforma online de nuestro banco, a continuacion se le dara las siguientes opciones:\n1)Consulta de cliente.\n2)Operaciones bancarias.\n3)Estado de suspension de su cuenta.\n4)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 2:
                do{
                    cout<<"Bienvenido al sistema de operaciones bancarias, a continuacion se le dira sus opciones:\n1)Deposito.\n2)Retiro.\n3)Transferencia entre usuarios de nuestro mismo banco.\n4)Volver al menu principal.\nElija su opcion: "; cin>>flag_2;
                    system("cls");
                    switch(flag_2){
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
    write_file.close();*/
    return 0;
}