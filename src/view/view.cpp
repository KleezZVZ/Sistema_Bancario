#include "view.h"
#include "../controller/controller.h"
#include <iostream>
#include <string>
using namespace std;
void menu_principal(){
    int flag;
    cargar_estructura();
    do{
        cout<<"Bienvenido a la plataforma online de nuestro banco, a continuacion se le dara las siguientes opciones:\n1)Consulta de cliente.\n2)Operaciones bancarias.\n3)Estado de suspension de su cuenta.\n4)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_1();
            system("cls");
            break;
            case 3:
            menu_3();
            system("cls");
            break;
        }
    }while(flag!=4);
}
void menu_1(){
    int flag, verificacion, saldo, ci;
    string nombre, numero_de_cuenta, tipo_de_cuenta;
    do{
        cout<<"Bienvenido a la seccion para consultar su estado de cuenta, a continuacion se le dira sus opciones:\n1)Buscar su cuenta mediante su nombre y numero de cuenta.\n2)Buscar su cuenta mediante su cedula y numero de cuenta.\n3)Volver al menu principal.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            rewind(stdin);
            cout<<"Por favor ingrese su nombre y apellido: "; getline(cin, nombre);
            system("cls");
            rewind(stdin);
            cout<<"Ingrese su numero de cuenta: "; getline(cin, numero_de_cuenta);
            system("cls");
            rewind(stdin);
            verificacion=inicio_sesion_1(nombre, numero_de_cuenta);
            if(verificacion==1){
                saldo=consulta_saldo(numero_de_cuenta);
                ci=consulta_ci(numero_de_cuenta);
                tipo_de_cuenta=consulta_tipo_de_cuenta(numero_de_cuenta);
                cout<<"Bienvenido/a "<<nombre<<", este es su estado de cuenta: "<<endl;
                cout<<"Su saldo actual: "<<saldo<<endl;
                cout<<"Informacion adicional: "<<endl;
                cout<<"Numero de cedula: "<<ci<<endl;
                cout<<"Numero de cuenta: "<<numero_de_cuenta<<endl;
                cout<<"Tipo de cuenta: "<<tipo_de_cuenta<<endl;
                cout<<"Para mas informacion sobre el estado de suspension, por favor vaya a la seccion Estado de suspension de su cuenta, en el menu principal"<<endl;
            }else{
                cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
            }
            system("pause");
            system("cls");
            break;
            case 2:
            rewind(stdin);
            cout<<"Por favor ingrese su cedula de identidad: "; cin>>ci;
            system("cls");
            rewind(stdin);
            cout<<"Ingrese su numero de cuenta: "; getline(cin, numero_de_cuenta);
            system("cls");
            rewind(stdin);
            verificacion=inicio_sesion_2(ci, numero_de_cuenta);
            if(verificacion==1){
                saldo=consulta_saldo(numero_de_cuenta);
                nombre=consulta_nombre(numero_de_cuenta);
                tipo_de_cuenta=consulta_tipo_de_cuenta(numero_de_cuenta);
                cout<<"Bienvenido/a "<<nombre<<", este es su estado de cuenta: "<<endl;
                cout<<"Su saldo actual: "<<saldo<<endl;
                cout<<"Informacion adicional: "<<endl;
                cout<<"Numero de cedula: "<<ci<<endl;
                cout<<"Numero de cuenta: "<<numero_de_cuenta<<endl;
                cout<<"Tipo de cuenta: "<<tipo_de_cuenta<<endl;
                cout<<"Para mas informacion sobre el estado de suspension, por favor vaya a la seccion Estado de suspension de su cuenta, en el menu principal"<<endl;
            }else{
                cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
            }
            system("pause");
            system("cls");
            break;
            case 3:
            system("cls");
            break;
            default:
            cout<<"Ingrese una opcion valida."<<endl;
            system("pause");
            system("cls");
        }
    }while(flag!=3);
}
void menu_3(){
    int verificacion, suspension;
    string numero_de_cuenta, nombre;
    cout<<"Bienvenido a la seccion de penalizacion de su cuenta, a continuacion se le nombrara las politicas del banco que en caso de incumplirse sera motivo de penalizacion.\n1)Ingresar montos en las operaciones iguales a 0 o menor.\n2)Realizar retiros cuyo monto exceda los 50.000$ en una sola operacion.\n3)Realizar transferencias entre clientes del mismo banco cuyo monto exceda los 100.000$ en una sola operacion.\nEn caso de recibir 3 penalizaciones, su cuenta sera suspendida hasta nuevo aviso.\nTiene que iniciar sesio para verificar su estado de suspension de la cuenta. ";
    system("pause");
    system("cls");
    rewind(stdin);
    cout<<"Por favor ingrese su nombre y apellido: "; getline(cin, nombre);
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su numero de cuenta: "; getline(cin, numero_de_cuenta);
    system("cls");
    rewind(stdin);
    verificacion=inicio_sesion_1(nombre, numero_de_cuenta);
    if(verificacion==1){
        suspension=estado_de_suspension(numero_de_cuenta);
        if(suspension==-1){
            cout<<"Estimado cliente/a "<<nombre<<" su cuenta "<<numero_de_cuenta<<" esta en estado de suspension"<<endl;
        }else{
             cout<<"Estimado cliente/a "<<nombre<<" su cuenta "<<numero_de_cuenta<<" no se encuentra en estado de suspension.\nEstas son sus numeros de penalizaciones acumuladas: "<<suspension<<endl;
        }
    }else{
        cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
    }
    system("pause");
}