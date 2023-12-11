#include "view.h"
#include "../controller/controller.h"
#include <iostream>
#include <string>
using namespace std;
void menu_principal(){
    int flag;
    cargar_estructura();
    do{
        cout<<"Bienvenido a la plataforma online de nuestro banco, a continuacion se le dara las siguientes opciones:\n1)Consulta de cliente.\n2)Operaciones bancarias.\n3)Estado de suspension de su cuenta.\n4)Clientes.\n5)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_1();
            system("cls");
            break;
            case 2:
            menu_2();
            system("cls");
            break;
            case 3:
            menu_3();
            system("cls");
            break;
            case 4:
            menu_4();
            system("cls");
            break;
            case 5:
            cout<<"Muchas gracias por su confianza, vuelva pronto!"<<endl;
            subir_informacion();
            break;
            default:
            cout<<"Ingrese una opcion valida";
            system("pause");
            system("cls");
        }
    }while(flag!=5);
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
void menu_2(){
    int flag;
    do{
        cout<<"Bienvenido al sistema de operaciones bancarias, a continuacion se le dira sus opciones:\n1)Deposito.\n2)Retiro.\n3)Transferencia entre usuarios de nuestro mismo banco.\n4)Volver al menu principal.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_2_1();
            system("cls");
            break;
            case 2:
            menu_2_2();
            system("cls");
            break;
            case 3:
            menu_2_3();
            system("cls");
            break;
            case 4:
            system("cls");
            break;
            default:
            cout<<"No ingreso una opcion valida"<<endl;
            system("pause");
        }
    }while(flag!=4);
    
}
void menu_2_1(){
    int verificacion, suspension, deposito, verificacion_deposito;
    string nombre, numero_de_cuenta;
    cout<<"Bienvenido a la seccion de depositos.\nPrimero debe de iniciar sesion para realizar el deposito."<<endl;
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
        if(suspension!=-1){
            cout<<"Bienvenido/a "<<nombre<<".\nIngrese la cantidad a depositar: "; cin>>deposito;
            system("cls");
            verificacion_deposito=deposito_a_cuenta(numero_de_cuenta, deposito);
            if(verificacion_deposito==-2){
                cout<<"Am i a joke to you?"<<endl;
            }else if(verificacion_deposito==-1){
                cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
            }else{
                cout<<"Su deposito ha sido realizado con exito!"<<endl;
            }
        }else{
            cout<<"Estimado cliente, no puede realizar operaciones bancarias debido a que su cuenta esta suspendida."<<endl;
        }
    }else{
        cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
    }
    system("pause");
}
void menu_2_2(){
    int verificacion, suspension, retiro, verificacion_retiro;
    string nombre, numero_de_cuenta;
    cout<<"Bienvenido a la seccion de retiros.\nPrimero debe de iniciar sesion para realizar el retiro."<<endl;
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
        if(suspension!=-1){
            cout<<"Bienvenido/a "<<nombre<<".\nIngrese la cantidad a retirar: "; cin>>retiro;
            system("cls");
            verificacion_retiro=retiro_a_cuenta(numero_de_cuenta, retiro);
            if(verificacion_retiro==-3){
                cout<<"Am i a joke to you?"<<endl;
            }else if(verificacion_retiro==-2){
                cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
            }else if(verificacion_retiro==-1){
                cout<<"No puede retirar una cantidad que exceda su saldo."<<endl;
            }else{
                cout<<"Su retiro ha sido realizado con exito!"<<endl;
            }
        }else{
            cout<<"Estimado cliente, no puede realizar operaciones bancarias debido a que su cuenta esta suspendida."<<endl;
        }
    }else{
         cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
    }
    system("pause");
}
void menu_2_3(){
    int verificacion, verificacion_2, suspension, suspension_2, transferencia, verificacion_transferencia;
    string nombre, numero_de_cuenta, nombre_2, numero_de_cuenta_2;
    cout<<"Bienvenido a la seccion de transferencias entre clientes.\nPrimero debe de iniciar sesion para realizar la transferencia."<<endl;
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
        if(suspension!=-1){
            cout<<"Bienvenido/a "<<nombre<<".\nPor favor ingrese el nombre y apellido del cliente a transferir: "; getline(cin, nombre_2);
            system("cls");
            rewind(stdin);
            cout<<"Ingrese el numero de cuenta del cliente a transferir: "; getline(cin, numero_de_cuenta_2);
            system("cls");
            rewind(stdin);
            verificacion_2=inicio_sesion_1(nombre_2, numero_de_cuenta_2);
            if(verificacion_2==1){
                suspension_2=estado_de_suspension(numero_de_cuenta_2);
                if(suspension_2!=-1){
                    cout<<"Ingrese la cantidad a transferir a "<<nombre_2<<": "; cin>>transferencia;
                    system("cls");
                    verificacion_transferencia=transferencia_entre_clientes(numero_de_cuenta,numero_de_cuenta_2,transferencia);
                    if(verificacion_transferencia==-3){
                        cout<<"Am i a joke to you?"<<endl;
                    }else if(verificacion_transferencia==-2){
                        cout<<"Debido a la gran cantidad de errores cometidos durante sus operaciones, hemos decidido suspender su cuenta."<<endl;
                    }else if(verificacion_transferencia==-1){
                        cout<<"No puede transferir una cantidad que exceda su saldo."<<endl;
                    }else{
                        cout<<"Su transferencia ha sido realizado con exito!"<<endl;
                    }
                }else{
                    cout<<"Lo lamentamos, pero la cuenta de "<<nombre_2<<" se encuentra suspendida"<<endl;
                }
            }else{
                cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
            }
        }else{
             cout<<"Estimado cliente, no puede realizar operaciones bancarias debido a que su cuenta esta suspendida."<<endl;
        }
    }else{
        cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
    }
    system("pause");
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
void menu_4(){
    int flag;
    do{
        cout<<"Bienvenido/a a la seccion enfocado a los clientes, a continuacion se le dara sus opciones:\n1)Registrarse.\n2)Eliminar su registro.\n3)Volver al menu principal.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_4_1();
            system("cls");
            break;
            case 2:
            menu_4_2();
            system("cls");
            break;
            case 3:
            system("cls");
            break;
            default:
            cout<<"Ingrese una opcion valida"<<endl;
            system("pause");
            system("cls");
        }
    }while(flag!=3);
}
void menu_4_1(){
    int ci;
    string nombre, tipo_de_cuenta, numero_de_cuenta;
    cout<<"Nos alegra que quiera ser parte de nuestro banco. A continuacion, los requisitos que tiene que rellenar:\n1)Cedula de identidad.\n2)Nombre y apellido.\n3)Tipo de cuenta."<<endl;
    system("pause");
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su nombre y apellido: "; getline(cin, nombre);
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su cedula de identidad: "; cin>>ci;
    system("cls");
    rewind(stdin);
    cout<<"Ingrese el tipo de cuenta que desea [debit][current]: "; getline(cin, tipo_de_cuenta);
    system("cls");
    numero_de_cuenta=agregar_clientes(nombre,ci,tipo_de_cuenta);
    cout<<"Su registro ha sido llevado con exito!, señor/a "<<nombre<<".\nLe invitamos a hacer su primer deposito, su numero de cuenta es: "<<numero_de_cuenta<<endl;
    system("pause");
}
void menu_4_2(){
    int verificacion, suspension;
    string numero_de_cuenta, nombre;
    cout<<"Lamentamos que haya decidido abandonar nuestro banco. Le pedimos que inicie sesion para poder eliminar su informacion de nuestro sistema"<<endl;
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
        eliminar_cliente(numero_de_cuenta);
        cout<<nombre<<", usted ha sido eliminado satisfactoriamente de nuestro sistema"<<endl;
    }else{
        cout<<"Los datos ingresados no coinciden, por favor vuelva a intentar"<<endl;
    }
    system("pause");
}