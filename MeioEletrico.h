#ifndef MEIOELETRICO_H_INCLUDED
#define MEIOELETRICO_H_INCLUDED

#include <stdio.h>
#include "stdbool.h"

// ----- Estruta de dados dinamicos -> MEIO
typedef struct registo {
 int codigo; // código do meio de mobilidade elétrica
 int ano; // ano de fabrico do meio 
 char modelo[50]; // modelo do meio
 float bateria; //bateria do meio
 float autonomia; //autonomia do meio
 int alugado;  // Estado alugado dos meios (WIP)
 float preco; //preço do meio
 int disponivel; // estado disponivel
 char user[20];
 struct registo* seguinte; // endereço de memória para uma struct registo
 int geocodigo; // armazenar o geocodigo da localização do meio
} Meio;

// ----- Estruta de dados dinamicos -> ALUGUER
typedef struct {
    int id_cliente; // id_cliente
    int id_meio_eletrico; //id_meio_eletrico
    char data_inicio[20]; //data de aluguer
    char data_fim[20]; //data de desaluger
    struct Aluguer* prox;
} RegistoAluguer;

// ----- Inserção de um novo Meio
Meio* inserirMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo); 
void listar_meios_localizacao(int geo, Meio* inicio);

Meio* iMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo);

// ----- Listar na consola o conteudo da lista ligada de Meios
void listarMeios(Meio* inicio); 
// ----- Determinar existência do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio* inicio, int cod); 
// ----- Remover um meio a partir do seu código
Meio* removerMeio(Meio* inicio, int cod); 
// ----- Guardar meios em formato texto
int guardarMeios(Meio* inicio);
// ----- Ler lista de Meios
Meio* lerMeios();
Meio* alterarMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo);



// ----- Funções que permitem o aluguer de um meio
// ----- Verifica a existencia do id e atualiza estado
int meio_eletrico_disponivel(int cod, Meio *inicio);
int atualizar_meio_eletrico(int cod, Meio *inicio,char user[]);
int desalugar_meio_eletrico(int cod, Meio *inicio,char user_[]);

// Estruturas para criar o garfo

typedef struct Aresta {
    int codigoDestino;
    float peso;
    int codigoMeio;
    struct Aresta* proxima;
} Aresta;

typedef struct Vertice {
    int codigo;
    int codigoMeio;
    Aresta* listaArestas;
    struct Aresta* primeiraAresta;
    struct Vertice* proximo;
    int codigoVertice;
    int numArestas;
    int codigoMeioAssociado;
    Aresta arestas[100];
} Vertice;

typedef struct Grafo {
    struct Vertice* primeiroVertice;
    Aresta arestas[100];
    Vertice vertices[100];
    char nome[50];
    int numVertices;
} Grafo;


void criarAresta(Grafo* grafo, int codigoOrigem, int codigoDestino, float peso, int codigoMeio); // Função para criar Aresta
void inserirVertice(Grafo* grafo, Vertice* novoVertice);// Função para criar Vertice

int existeVertice(Grafo* grafo, int codigo); // Verifica existencia de vertice
void associarCodigoMeio(Vertice* vertice, int codigoMeio); // Associar a um meio esistente
void imprimirVertice(Vertice* vertice, Meio* meios); // Imprime valor do vertice
void imprimirGrafo(Grafo* grafo, Meio* meios); // Imprime Grafo 

Meio* obterMeioPorCodigo(Meio* listaMeios, int codigo); // Obter meio pelo id existente na listaMeios
void salvarGrafoEmtxt(Grafo* grafo, const char* nomeArquivo); // Salva grafo no txt

#endif /* MEIOELETRICO_H_INCLUDED */
