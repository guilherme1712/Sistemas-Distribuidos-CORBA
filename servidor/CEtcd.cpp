#include "CEtcd.h"
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

// Definição da exceção InvalidKey
class InvalidKey : public exception {
public:
  const char* what() const throw() {
    return "Chave inválida";
  }
};

// Implementação da classe CEtcd_i
class CEtcd_i : public POA_CEtcd {
public:
  // Construtor
  CEtcd_i() : id_("1236-8") {}

  // Destrutor
  ~CEtcd_i() {}

  // Implementação do atributo readonly id
  std::string id() override {
    return id_;
  }

  // Implementação do método put
  bool put(const std::string& key, const std::string& val) override {
    // Insere ou modifica o par chave:valor
    auto result = tabela_.insert_or_assign(key, val);
    return result.second; // Retorna true se a chave foi nova, false se foi modificada
  }

  // Implementação do método get
  std::string get(const std::string& key) override {
    auto it = tabela_.find(key);
    if (it != tabela_.end()) {
      return it->second; // Retorna o valor associado à chave
    } else {
      throw InvalidKey(); // Lança exceção se a chave não for encontrada
    }
  }

  // Implementação do método del
  void del(const std::string& key) override {
    auto it = tabela_.find(key);
    if (it != tabela_.end()) {
      tabela_.erase(it); // Remove a chave e o valor associado
    } else {
      throw InvalidKey(); // Lança exceção se a chave não for encontrada
    }
  }

private:
  string id_;  // Identificador do objeto
  map<string, string> tabela_; // Tabela de chave-valor
};
