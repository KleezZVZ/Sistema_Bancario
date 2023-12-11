#include "test.h"
#include "../src/controller/controller.h"
#include <cassert>
void pruebas_unitarias_controlador(){
    assert(inicio_sesion_1("0","0")!=0);
    assert(inicio_sesion_1("0","0")==-1);
    assert(inicio_sesion_2(0,"0")!=0);
    assert(inicio_sesion_2(0,"0")==-1);
    assert(consulta_saldo("0")!=0);
    assert(consulta_saldo("0")==-1);
    assert(consulta_ci("0")!=0);
    assert(consulta_ci("0")==-1);
    assert(consulta_nombre("0")!="0");
    assert(consulta_nombre("0")=="-1");
    assert(consulta_tipo_de_cuenta("0")!="0");
    assert(consulta_tipo_de_cuenta("0")=="-1");
    assert(estado_de_suspension("0")!=0);
    assert(estado_de_suspension("0")==-1);
    assert(deposito_a_cuenta("0",0)!=0);
    assert(deposito_a_cuenta("0",0)==-2);
    assert(retiro_a_cuenta("0",0)!=0);
    assert(retiro_a_cuenta("0",0)==-3);
    assert(transferencia_entre_clientes("0","0", 0)!=0);
    assert(transferencia_entre_clientes("0","0", 0)==-3);
}