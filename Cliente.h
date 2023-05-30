#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>


// ----- Estruta de dados dinamicos -> CLIENTE
typedef struct Cliente {
    int id; // ID_Cliente
    int contribuinte; // Contribuinte_cliente
    //int saldo; // Saldo do cliente
    char nome[20]; // Nome_cliente
    char morada[50]; //Morada do cliente
    char email[100]; //Email_cliente
    char senha[20]; //Senha para autenticação 
    struct Cliente* prox; //apontador para o poximo elemento da lista ligada
} Cliente;

// ----- Inserção de um novo cliente
Cliente* novoCliente(Cliente* inicio,int id_, int contribuinte_, char nome_[], char morada_[], char email_[],char senha_[]);
Cliente* alterarCliente(Cliente* inicio, int id_, int contribuinte_, char nome_[], char morada_[], char email_[],char senha_[]);
// ----- Listar na consola o conteudo da lista ligada de Clientes
void listarClientes(Cliente* inicio); 
// ----- Determinar existência do 'id_' na lista ligada 'inicio'
int existeCliente(Cliente* inicio, int id_); 
// ----- Remover um meio a partir do seu código
Cliente* removerCliente(Cliente* inicio, int id_); 
// ----- Guardar clientes em formato texto
int guardarCliente(Cliente* inicio);
// ----- Ler lista de clientes
Cliente* lerClientes();

// ----- Autenticação de cliente com nome e senha
int autenticar_cliente(Cliente* inicio, char *nome_, char *senha_);

// ----- Funções que permitem o aluguer de um meio
// ----- Verifica a existencia do id e busca o mesmo na lista ligada
int cliente_existe(char nome_[], Cliente *inicio);
Cliente *buscar_cliente(char nome_[], Cliente *inicio);
Cliente* alterarDadosCliente(Cliente* inicio, int novoID, int novoContribuinte, char novoNome[], char novaMorada[], char novoEmail[], char novaSenha[]);
#endif /* MEIOELETRICO_H_INCLUDED */