//
// SERVIDOR DE CONTA SIMPLES
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// (C) Prof. Luiz Lima Jr. (luiz.lima@pucpr.br)
//
// USANDO SERVIDOR DE NOMES
// USAR COMANDO rebind

#include <iostream>
#include <fstream>
#include <string>
#include "CEtcdS.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;
using namespace PortableServer;
using namespace CosNaming;

ORB_var orb; // global para ser usado na classe Conta_i para shutdown

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "USO: " << argv[0] << " <nome_do_servidor>\n";
        return 1;
    }

    try {
	    // 1. Inicia ORB
        orb = ORB_init(argc, argv, "ORB");
	
        // 2. Ativa RootPOA
        Object_ptr tmp = orb->resolve_initial_references("RootPOA");
        POA_var poa = POA::_narrow(tmp);
        POAManager_var ger = poa->the_POAManager();
        ger->activate();
	
        // 3. Instancia "servants"
        CEtcd ci;
	
        // 4. Registra servos no POA, criando objetos distribuídos
        CEtcd_var CEtcd = ci._this();
	
        // 5. Publica IOR NO SERVIDOR DE NOMES

        tmp = orb->resolve_initial_references("NameService");
        NamingContext_var ns = NamingContext::_narrow(tmp);   // ns  o servidor de nomes

        Name nome(1);
        nome.length(1);
        nome[0].id = string_dup(argv[1]);

        ns->rebind(nome, CEtcd.in());

        /* String_var ior = orb->object_to_string(conta.in());
        ofstream arq("conta.ior");
        arq << ior;
        arq.close();
        cout << "IOR salva: conta.ior\n"; */
	
        // 6. Aguarda requisições
        cout << "Aguardando requisicoes...\n"; 
        orb->run();
	
        // 7. Finalizações
        poa->destroy(true, true);
        orb->destroy();
    } catch (const CORBA::Exception& e) {
        cerr << "Erro CORBA: " << e << endl;
    }
    return 0;
}
