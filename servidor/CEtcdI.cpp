#include "CEtcdI.h"
#include <map>
#include <iostream>
#include <stdexcept>

using namespace std;

extern CORBA::ORB_var orb;

// Implementação skeleton constructor
CEtcd_i::CEtcd_i() {}

// Implementação skeleton destructor
CEtcd_i::~CEtcd_i() {}

// Membro privado para armazenar chave-valor
std::map<std::string, std::string> kv_store;

std::string CEtcd_i::id ()
{
    cout << "retornando id\n";
    return string("1234-5");
}

// Implementação do método put
::CORBA::Boolean CEtcd_i::put(const std::string key, const std::string val) {
    std::cout << "Inserindo chave: " << key << " com valor: " << val << std::endl;
    auto result = kv_store.insert({key, val});
    if (!result.second) {
        // Se a chave já existia, atualizamos o valor e retornamos false
        kv_store[key] = val;
        std::cout << "Chave existente, valor atualizado para: " << val << std::endl;
        return false;
    }
    std::cout << "Nova chave-valor inserida" << std::endl;
    return true;  // Nova chave-valor inserida
}

// Implementação do método get
std::string CEtcd_i::get(const std::string key) {
    std::cout << "Buscando valor para a chave: " << key << std::endl;
    auto it = kv_store.find(key);
    if (it != kv_store.end()) {
        std::cout << "Valor encontrado: " << it->second << std::endl;
        return it->second;  // Retorna o valor associado à chave
    } else {
        std::cout << "Chave não encontrada, lançando exceção InvalidKey" << std::endl;
        throw InvalidKey();  // Lança exceção se a chave não for encontrada
    }
}

// Implementação do método del
void CEtcd_i::del(const std::string key) {
    std::cout << "Tentando remover a chave: " << key << std::endl;
    auto it = kv_store.find(key);
    if (it != kv_store.end()) {
        kv_store.erase(it);  // Remove chave-valor da tabela
        std::cout << "Chave removida com sucesso" << std::endl;
    } else {
        std::cout << "Chave não encontrada, lançando exceção InvalidKey" << std::endl;
        throw InvalidKey();  // Lança exceção se a chave não for encontrada
    }
}