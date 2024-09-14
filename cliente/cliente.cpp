#include <iostream>
#include <string>
#include <orbsvcs/CosNamingC.h>
#include "CEtcdC.h"

using namespace std;
using namespace CORBA;
using namespace CosNaming;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "USO: " << argv[0] << " <nome_do_servidor>\n";
        return 1;
    }

    // 1. Inicializa ORB
    ORB_var orb;
    try
    {
        orb = ORB_init(argc, argv);
    }
    catch (CORBA::Exception& e)
    {
        cerr << "Erro passo 1" << e._name() << endl;
        return 1;
    }

    // 2. Obtém referência ao serviço de nomes
    Object_var obj;
    NamingContext_var nc;
    try
    {
        obj = orb->resolve_initial_references("NameService");
        nc = NamingContext::_narrow(obj);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro passo 2" << e.what() << endl;
        return 2;
    }

    // 3. Resolução do nome do objeto no servidor
    Object_var etcdObj;
    try
    {
        Name name;
        name.length(1);
        name[0].id = string_dup(argv[1]); // Nome publicado pelo servidor
        etcdObj = nc->resolve(name);
    }
    catch(const std::exception& e)
    {
        cerr << "Erro passo 3 " << e.what() << '\n';
        return 3;
    }

    // 4. Obtém referência do objeto distribuído
    CEtcd_var cetcd = CEtcd::_narrow(etcdObj);

    if (is_nil(cetcd)) {
        cerr << "Erro passo 4" << endl;
        return 1;
    }

    int option = 0;
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - ID do objeto CEtcd" << endl;
    cout << "2 - PUT" << endl;
    cout << "3 - GET" << endl;
    cout << "4 - DEL" << endl;
    cin >> option;

    cout << endl << endl;

    switch (option)
    {
        case 1:
        {
            string idFound;

            idFound = cetcd->id();
            cout << "ID do objeto CEtcd: " << idFound << endl;

            break;
        }
        case 2:
        {
            string keyToAdd, valueToAdd;

            cout << "Chave: ";
            cin >> keyToAdd;
            cout << endl;

            cout << endl << "Valor: ";
            cin >> valueToAdd;
            cout << endl;

            bool valueAdded = cetcd->put(keyToAdd, valueToAdd);

            if (valueAdded)
            {
                cout << "Valor " << valueToAdd << " adicionado a chave " << keyToAdd << endl; 
            }
            else
            {
                cout << "Chave " << keyToAdd << " atualizada com o valor " << valueToAdd << endl;
            }

            break;
        }
        case 3:
        {
            string keyToSearch, valueFound;

            cout << "Digite a chave: ";
            cin >> keyToSearch;
            cout << endl;

            try
            {
                valueFound = cetcd->get(keyToSearch);
                cout << "Foi encontrado o valor " << valueFound << " para a chave " << keyToSearch << endl;
            }
            catch (InvalidKey& e)
            {
                cerr << "Chave " << keyToSearch << " nao encontrada" << endl;
            }

            break;
        }
        case 4:
        {
            string keyToDelete;

            cout << "Digite a chave: ";
            cin >> keyToDelete;
            cout << endl;

            try
            {
                cetcd->del(keyToDelete);
                cout << "Chave " << keyToDelete << " removida com sucesso" << endl;
            }
            catch (const InvalidKey& e)
            {
                cerr << "Chave " << keyToDelete << " nao encontrada" << endl;
            }

            break;
        }
        default:
        {
            cout << "Opcao inexistente :(" << endl;
            break;
        }
    }

    return 0;
}