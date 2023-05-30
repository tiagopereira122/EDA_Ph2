#include <stdlib.h>
#include <string.h>
#include "MeioEletrico.h"
#include "Cliente.h"
#include <time.h>
#define MAX_VERTICES 100 // Defina o valor apropriado aqui


// ----- Guardar meios em formato texto
int guardarMeios(Meio* inicio)
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%f;%f;%d;%s;%d\n", aux->codigo, aux->modelo, 
	                      aux->autonomia, aux->bateria, aux->disponivel, aux->user, aux->geocodigo);
  aux = aux->seguinte;
 }
 //printf("Dados referentes aos Meios existentes guardados com sucesso");
 fclose(fp);
 return(1);
 }
 else return(0);
}

// ----- Ler lista de Meios
Meio* lerMeios() 
{FILE* fp;
 int cod,disponivel_,geo;
 float bat, aut;
 char modelo_[50], user_[20];
 Meio* aux=NULL;
 fp = fopen("meios.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp, "%d;%[^;];%f;%f;%d;%[^;];%d\n", &cod, modelo_, &bat, &aut, &disponivel_, user_, &geo);
    aux = iMeio(aux, cod, modelo_, bat, aut,disponivel_,user_,geo);
      
  }
 }
 return(aux);
}

// ----- Inserção de um novo Meio
Meio* inserirMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo)
{
    
 if (!existeMeio(inicio, cod)) {Meio* novo = malloc(sizeof(struct registo));
  if (novo != NULL)
  {
    novo->codigo = cod;
   strcpy(novo->modelo,modelo_);
   novo->bateria = bat;
   novo->autonomia = aut;
   novo->disponivel = 1;
   novo->geocodigo = geo;
   novo->seguinte = inicio;
   strcpy(novo->user, "Nenhum");
   return(novo);
  }
 } else return(inicio);
}


Meio* iMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo)
{
   if (!existeMeio(inicio, cod)) {Meio* novo = malloc(sizeof(struct registo));
  if (novo != NULL)
  {
    novo->codigo = cod;
   strcpy(novo->modelo,modelo_);
   strcpy(novo->user, user_);
   novo->bateria = bat;
   novo->autonomia = aut;
   novo->disponivel = disponivel_;
   novo->geocodigo = geo;
   novo->seguinte = inicio;
   return(novo);
  }
 } else return(inicio); 
}



// Listar Meios e ordenar por autonomia
void listarMeios(Meio * inicio)
{
   int tamanho = 0;
    Meio *atual = inicio;
    
    while (atual != NULL) {
        tamanho++;
        atual = atual->seguinte;
    }
    
    Meio **meios = malloc(sizeof(Meio*) * tamanho);
    atual = inicio;
    for (int i = 0; i < tamanho; i++) {
        meios[i] = atual;
        atual = atual->seguinte;
    }
    
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (meios[j]->autonomia > meios[i]->autonomia) {
                Meio *temp = meios[i];
                meios[i] = meios[j];
                meios[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d | Modelo: %s | Bateria: %.2f | Autonomia: %.2f | Disponivel: %d | User: %s | Geo: %d\n", meios[i]->codigo, meios[i]->modelo, meios[i]->bateria, meios[i]->autonomia, meios[i]->disponivel, meios[i]->user, meios[i]->geocodigo);
    }
    
    free(meios);
}


// ----- Determinar existência do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codigo == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}


// ----- Remover um meio a partir do seu código
Meio* removerMeio(Meio* inicio, int cod) 
{
 Meio *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL); // lista ligada vazia
 else if (atual->codigo == cod) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=cod)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

// Função para percorrer a lista ligada de Meios Elétricos e verificar se o Meio Elétrico está disponível
int meio_eletrico_disponivel(int cod, Meio *inicio) {
    Meio *ptr = inicio;
    while (ptr != NULL) {
        if (ptr->codigo == cod) {
            return ptr->disponivel;
        }
        ptr = ptr->seguinte;
    }
    return false;
   
}

// Função para percorrer a lista ligada de Meios Elétricos e verificar se o Meio Elétrico está disponível
int meio_eletrico_indisponivel(int cod, Meio *inicio) {
    Meio *ptr = inicio;
    while (ptr != NULL) {
        if (ptr->codigo == cod) {
            return ptr->disponivel=0;
        }
        ptr = ptr->seguinte;
    }
    return false;
   
}

// Função para atualizar o estado de disponibilidade de um Meio Elétrico na lista ligada
int atualizar_meio_eletrico(int cod, Meio *inicio,char user_[]) {
    Meio *ptr = inicio;
    int disp = 0;
    
    while (ptr != NULL) {
        
        if (ptr->codigo == cod) 
        {

                if(strcmp(ptr->user, "Nenhum")==0 )
                {
           ptr->disponivel = disp;
           strcpy(ptr->user, user_);
           printf("Alugado\n");
        } 
        else {
        //printf("Nao disponivel!!!\n");
        return 0;
        }
        
    }
    else {
        ptr = ptr->seguinte;
        }
    
}
printf("Meio nao encontrado.\n");
  return 0;
}

// Desalugar meio eletrico
int desalugar_meio_eletrico(int cod, Meio *inicio, char user_[]) {
    Meio *ptr = inicio;
    
    while (ptr != NULL) {
        if (ptr->codigo == cod) {
            if (strcmp(ptr->user, user_) == 0) {
                ptr->disponivel = 1;
                strcpy(ptr->user, "Nenhum");
                printf("Meio desalugado com sucesso.\n");
                return 1;
            } else {
                printf("Esse meio eletrônico não está alugado para esse usuário.\n");
                return 0;
            }
        } else {
            ptr = ptr->seguinte;
        }
    }
    
    printf("Meio não encontrado.\n");
    return 0;
}

// Listar meios localizaçao geo
void listar_meios_localizacao(int geo, Meio* inicio) {
    Meio* meios = inicio;
    while (meios != NULL) {
        if (meios->geocodigo <= geo) {
            printf("Modelo: %s | Bateria: %.2f | Autonomia: %.2f | Disponivel: %d | Geo: %d\n", meios->modelo, meios->bateria, meios->autonomia, meios->disponivel, meios->geocodigo);
        }
        meios = meios->seguinte;
    }
}

//Função para alterar algum dado referente a um meio

Meio* alterarMeio(Meio* inicio, int cod, char modelo_[], float bat, float aut,int disponivel_,char user_[],int geo)
{

    while (inicio != NULL) {
        if (inicio->codigo == cod) {
            strcpy(inicio->modelo, modelo_);
            inicio->bateria = bat;
            inicio->autonomia = aut;
            inicio->disponivel = disponivel_;
            inicio->geocodigo = geo;
            return(inicio);
        }
        inicio = inicio->seguinte;
    }
    
    if (inicio == NULL) {
        printf("Meio %d não encontrado.\n", cod);
    } else {
        printf("Meio %d alterados com sucesso.\n", cod);
    }
}


// ------ GRAFO --------

//-- Função para criar Grafo
Grafo* criarGrafo(char nome[]) {
    Grafo* novoGrafo = malloc(sizeof(Grafo));
    if (novoGrafo != NULL) {
        strcpy(novoGrafo->nome, nome);
        novoGrafo->primeiroVertice = NULL;
    }
    return novoGrafo;
}


//-- Função para verificar exitencia de vertice
int existeVertice(Grafo* grafo, int codigo) {
    Vertice* verticeAtual = grafo->primeiroVertice;
    while (verticeAtual != NULL) {
        if (verticeAtual->codigo == codigo) {
            return 1;  // O vértice existe
        }
        verticeAtual = verticeAtual->proximo;
    }
    return 0;  // O vértice não existe
}

// -- Função que insere um vertice
void inserirVertice(Grafo* grafo, Vertice* novoVertice) {
    if (grafo->primeiroVertice == NULL) {
        grafo->primeiroVertice = novoVertice;
    } else {
        Vertice* verticeAtual = grafo->primeiroVertice;
        while (verticeAtual->proximo != NULL) {
            verticeAtual = verticeAtual->proximo;
        }
        verticeAtual->proximo = novoVertice;
    }
}


Vertice* obterVerticePorCodigo(Grafo* grafo, int codigo) {
    Vertice* verticeAtual = grafo->primeiroVertice;
    while (verticeAtual != NULL) {
        if (verticeAtual->codigo == codigo) {
            return verticeAtual;
        }
        verticeAtual = verticeAtual->proximo;
    }
    return NULL;
}

// Função para criar aresta
void criarAresta(Grafo* grafo, int codigoOrigem, int codigoDestino, float peso, int codigoMeio) {
    Vertice* verticeOrigem = obterVerticePorCodigo(grafo, codigoOrigem);
    if (verticeOrigem != NULL) {
        Aresta* novaAresta = malloc(sizeof(Aresta));
        if (novaAresta != NULL) {
            novaAresta->codigoDestino = codigoDestino;
            novaAresta->peso = peso;
            novaAresta->codigoMeio = codigoMeio; // Adicionando o código do meio à aresta
            novaAresta->proxima = NULL;

            if (verticeOrigem->listaArestas == NULL) {
                verticeOrigem->listaArestas = novaAresta;
            } else {
                Aresta* arestaAtual = verticeOrigem->listaArestas;
                while (arestaAtual->proxima != NULL) {
                    arestaAtual = arestaAtual->proxima;
                }
                arestaAtual->proxima = novaAresta;
            }
        }
    }
}

// Associar codigo do vertice ao meio
void associarCodigoMeio(Vertice* vertice, int codigoMeio) {
    vertice->codigoMeio = codigoMeio;
}


// Imprimir dados do grafo
void imprimirGrafo(Grafo* grafo, Meio* meios) {
    printf("Nome do Grafo: %s\n", grafo->nome);
    Vertice* verticeAtual = grafo->primeiroVertice;
    while (verticeAtual != NULL) {
        imprimirVertice(verticeAtual, meios);
        verticeAtual = verticeAtual->proximo;
    }
}

// Imprimir dados referente ao vertice
void imprimirVertice(Vertice* vertice, Meio* meios) {
    if (vertice == NULL) {
        printf("Vertice nulo.\n");
        return;
    }

    printf("Código Vertice: %d\n", vertice->codigo);
    printf("Código do meio: %d\n", vertice->codigoMeio);
    printf("Arestas: ");

    Aresta* arestaAtual = vertice->listaArestas;
    while (arestaAtual != NULL) {
        printf("(%d, %.2f) ", arestaAtual->codigoDestino, arestaAtual->peso);
        arestaAtual = arestaAtual->proxima;
    }
    printf("\n");

    // Imprimir informações do meio associado
    Meio* meioAssociado = obterMeioPorCodigo(meios, vertice->codigoMeio);
    if (meioAssociado != NULL) {
        printf("Meio associado: %s\n", meioAssociado->modelo);
        // Imprimir outras informações do meio, se necessário
    } else {
        printf("Meio associado não encontrado.\n");
    }
}



void liberarGrafo(Grafo* grafo) {
    Vertice* verticeAtual = grafo->primeiroVertice;
    while (verticeAtual != NULL) {
        Aresta* arestaAtual = verticeAtual->primeiraAresta;
        while (arestaAtual != NULL) {
            Aresta* proximaAresta = arestaAtual->proxima;
            free(arestaAtual);
            arestaAtual = proximaAresta;
        }
        
        Vertice* proximoVertice = verticeAtual->proximo;
        free(verticeAtual);
        verticeAtual = proximoVertice;
    }
    
    free(grafo);
}

Meio* obterMeioPorCodigo(Meio* listaMeios, int codigo) {
    Meio* meioAtual = listaMeios;
    while (meioAtual != NULL) {
        if (meioAtual->codigo == codigo) {
            return meioAtual;
        }
        meioAtual = meioAtual->seguinte;
    }
    return NULL;
}

// Salvar grafo num txt
void salvarGrafoEmtxt(Grafo* grafo, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome do Grafo: %s\n", grafo->nome);
    fprintf(arquivo, "-----\n");

    Vertice* verticeAtual = grafo->primeiroVertice;
    
    while (verticeAtual != NULL) {
        fprintf(arquivo, "%d;%d", verticeAtual->codigo, verticeAtual->codigoMeio);

        Aresta* arestaAtual = verticeAtual->listaArestas;
        while (arestaAtual != NULL) {
            fprintf(arquivo, ";%d;%.2f", arestaAtual->codigoDestino, arestaAtual->peso);
            // Mover para a próxima aresta
            arestaAtual = arestaAtual->proxima;
        }
        
        fprintf(arquivo, "\n");
        
        // Mover para o próximo vértice
        verticeAtual = verticeAtual->proximo;
    }

    fclose(arquivo);
}
