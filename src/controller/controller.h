#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
    void cargar_estructura();
    int inicio_sesion_1(std::string, std::string);
    int inicio_sesion_2(int, std::string);
    int consulta_saldo(std::string);
    int consulta_ci(std::string);
    std::string consulta_nombre(std::string);
    std::string consulta_tipo_de_cuenta(std::string);
    int estado_de_suspension(std::string);
    int deposito_a_cuenta(std::string, int);
    int retiro_a_cuenta(std::string, int);
    int transferencia_entre_clientes(std::string, std::string, int);
    void subir_informacion();
    std::string agregar_clientes(std::string, int, std::string);
    void eliminar_cliente(std::string);
#endif