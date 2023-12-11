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