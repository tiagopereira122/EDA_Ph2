#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

// ----- Guardar clientes em formato texto
int guardarClientes(Cliente* inicio)
{FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
 {
 Cliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%d;%s;%s;%s;%s\n", aux->id, aux->contribuinte, 
	                      aux->nome, aux->morada, aux->email,aux->senha);
  aux = aux->prox;
 }
 //printf("-----------Bem vindo ao mundo elétrico! A sua conta foi criada com sucesso-----------\n");
 fclose(fp);
 return(1);
 }
 else return(0);
}

// ----- Ler lista de clientes
Cliente* lerClientes()
{FILE* fp;
 int id_, contribuinte_;
 char nome_[50], morada_[100], email_[100], senha_[20];
 Cliente* aux=NULL;
 fp = fopen("clientes.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%d;%[^;];%[^;];%[^;];%s\n", &id_, &contribuinte_, nome_, morada_, email_,senha_);
    aux = novoCliente(aux, id_, contribuinte_, nome_, morada_, email_,senha_);
  }
  fclose(fp);
 }
 return(aux);
}

// ----- Inserção de um novo cliente
Cliente* novoCliente(Cliente* inicio, int id_, int contribuinte_, char nome_[], char morada_[], char email_[],char senha_[]){
if(!existeCliente(inicio,id_)){
    Cliente* novo = malloc(sizeof(Cliente));
    if(novo != NULL)
{
    novo->id = id_;
    novo->contribuinte = contribuinte_;
    strcpy(novo->nome, nome_);
    strcpy(novo->morada, morada_);
    strcpy(novo->email, email_);
    strcpy(novo->senha,senha_);
    novo->prox = inicio;
    return (novo);
}
} else return (inicio);
}

Cliente* alterarCliente(Cliente* inicio, int id_, int contribuinte_, char nome_[], char morada_[], char email_[],char senha_[])
{

    while (inicio != NULL) {
        if (inicio->id == id_) {
			inicio->contribuinte = contribuinte_;
            strcpy(inicio->nome , nome_);
			strcpy(inicio->morada , morada_);
			strcpy(inicio->email , email_);
			strcpy(inicio->senha , senha_);

            return(inicio);
        }
        inicio = inicio->prox;
    }
    
    if (inicio == NULL) {
        printf("Cliente %d não encontrado.\n", id_);
    } else {
        printf("Cliente %d alterados com sucesso.\n", id_);
    }
}

// ----- Listar na consola o conteudo da lista ligada de Clientes
void listarClientes(Cliente* inicio) {
    Cliente* clienteAtual = inicio;
       printf("!!!!!!!!!!!!!!!!!!! CLIENTES !!!!!!!!!!!!!!!!!!!\n");
    while (clienteAtual != NULL) {
        printf("Cliente ID:%d | ;Contribuinte:  %d | ; Nome: %s | ;Morada:  %s |; Email:  %s |\n", clienteAtual->id, clienteAtual->contribuinte, clienteAtual->nome, clienteAtual->morada, clienteAtual->email,clienteAtual->senha);
        clienteAtual = clienteAtual->prox;
    }
}

// ----- Determinar existência do 'codigo' na lista ligada 'inicio'
int existeCliente(Cliente* inicio, int id_)
{while(inicio!=NULL)
  {if (inicio->id == id_) return(1);
    //printf("Cliente já existe - Verifique por favor");
   inicio = inicio->prox;
  } 
 return(0);
}

// ----- Remover um meio a partir do seu código
Cliente* removerCliente(Cliente* inicio, int id_) 
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL); // lista ligada vazia
 else if (atual->id == id_) // remoção do 1º registo
 {aux = atual->prox;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->id!=id_)) 
  {anterior = atual;
   atual = atual->prox;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->prox= atual->prox;
   free(atual);
   return(inicio);
  }
 }
}

// Função para percorrer a lista ligada de Clientes e verificar se o Cliente existe
int cliente_existe(char nome_[], Cliente *inicio) {
    int existe = 0;
    Cliente *clientes = inicio;
    while (clientes != NULL) {
        if (clientes->nome, nome_) {
            existe = 1; // alteração aqui
            break;
        }
        clientes = clientes->prox;
    }
    return existe;
}

// Função para buscar um Cliente na lista ligada pelo ID
Cliente *buscar_cliente(char nome_[], Cliente *inicio) {
    Cliente *clientes = inicio;
    while (clientes != NULL) {
        if (clientes->nome == nome_) {
            printf("Cliente encontrado\n");
            break;
        }
        clientes = clientes->prox;
    }
    return clientes;
}


// ----- Autenticação de cliente com nome e senha
int autenticar_cliente(Cliente* inicio, char *nome_, char *senha_) {
    FILE *fp = fopen("clientes.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char linha[100];
    char usuario_arq[20];
    char senha_arq[20];
    int autenticado = 0;

    while (fgets(linha, 100, fp) != NULL) {
        sscanf(linha, "%*d;%*d;%[^;];%*[^;];%*[^;];%s", usuario_arq, senha_arq);
        if (strcmp(usuario_arq,nome_ ) == 0 && strcmp(senha_arq, senha_) == 0) {
            printf("----------------------\n");
            printf("| Login bem sucedido!|\n");
            printf("----------------------\n");
            autenticado = 1;
            fclose(fp);
            return 1;
        }
    }
    printf("-------------------------------------------------------------------------------------\n");
    printf("| Login sem sucesso! Verifique se está a inserir o seu login e password corretamente|\n");
    printf("-------------------------------------------------------------------------------------\n");
    fclose(fp);
    return 0;
}

