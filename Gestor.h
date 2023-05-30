#include <stdio.h>

// ----- Estruta de dados dinamicos -> GESTOR
typedef struct Gestor {
    int id; // ID do gestor
    char nome[100]; //Nome do gestor
    char email[100]; //email do gestor
    char senha[20]; //senha gestor
    struct Gestor* prox; //apontador para o poximo elemento da lista ligada
} Gestor;

// ----- Inserção de um novo gestor
Gestor* novoGestor(Gestor* inicio,int id_, char nome_[], char email_[],char senha_[]);
Gestor* alterarGestor(Gestor* inicio, int id_,char nome_[], char email_[],char senha_[]);
// ----- Listar na consola o conteudo da lista ligada de Gestores
void listarGestores(Gestor* inicio); 
// ----- Determinar existência do 'id' na lista ligada 'inicio'
int existeGestor(Gestor* inicio, int id_); 
// ----- Remover um gestor a partir do seu código
Gestor* removerGestor(Gestor* inicio, int id_); 
// ----- Guardar gestores em formato texto
int guardarGestores(Gestor* inicio);
// ----- Ler lista de gestores
Gestor* lerGestores();

// ----- Autenticação de gestor com nome e senha
int autenticar_gestor(Gestor* inicio, char *nome_, char *senha_);

