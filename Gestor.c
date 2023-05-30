#include <stdlib.h>
#include <string.h>
#include "Gestor.h"

// ----- Guardar gestores em formato texto
int guardarGestores(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%s;%s\n", aux->id,aux->nome, aux->email, aux->senha);
  aux = aux->prox;
 }
 printf("Dados referentes aos Gestores existentes guardados com sucesso");
 fclose(fp);
 return(1);
 }
 else return(0);
}

// ----- Ler lista de gestores
Gestor* lerGestores()
{FILE* fp;
 int id_;
 char nome_[100], email_[100], senha_[20];
 Gestor* aux=NULL;
 fp = fopen("gestores.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%[^;];%[^;];%s\n", &id_, nome_, email_,senha_);
    aux = novoGestor(aux, id_, nome_, email_,senha_);
  }
  fclose(fp);
 }
 return(aux);
}

// ----- Inserção de um novo gestor
Gestor* novoGestor(Gestor* inicio,int id_, char nome_[], char email_[], char senha_[]){
if(!existeGestor(inicio,id_)){
    Gestor* novo = malloc(sizeof(Gestor));
    if(novo != NULL)
{
    novo->id = id_;
    strcpy(novo->nome, nome_);
    strcpy(novo->email, email_);
    strcpy(novo->senha, senha_);
    novo->prox = inicio;
    return (novo);
}
} else return (inicio);
}


Gestor* alterarGestor(Gestor* inicio, int id_,char nome_[], char email_[],char senha_[])
{

    while (inicio != NULL) {
        if (inicio->id == id_) {
            strcpy(inicio->nome , nome_);
			strcpy(inicio->email , email_);
			strcpy(inicio->senha , senha_);

            return(inicio);
        }
        inicio = inicio->prox;
    }
    
    if (inicio == NULL) {
        printf("Gestor %d não encontrado.\n", id_);
    } else {
        printf("Gestor %d alterados com sucesso.\n", id_);
    }
}

// ----- Listar na consola o conteudo da lista ligada de Gestores
void listarGestores(Gestor* inicio)

{
printf("!!!!!!!!!!!!!!!!!!! GESTORES !!!!!!!!!!!!!!!!!!!\n");
    while (inicio != NULL)
 {
  printf("Id: %d, Nome: %s. Email: %s\n", inicio->id,inicio->nome,inicio->email);
  inicio = inicio->prox;
 }
}
// ----- Determinar existência do 'id' na lista ligada 'inicio'
int existeGestor(Gestor* inicio, int id_)
{while(inicio!=NULL)
  {if (inicio->id == id_) return(1);
   inicio = inicio->prox;
  }
 return(0);
}

// ----- Remover um gestor a partir do seu código
Gestor* removerGestor(Gestor* inicio, int id_) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

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

// ----- Autenticação de gestor com nome e senha
int autenticar_gestor(Gestor* inicio, char *nome_, char *senha_) {
    FILE *fp = fopen("gestores.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    char linha[100];
    char usuario_arq[20];
    char senha_arq[20];
    int n_autenticado2 = 1;

    while (fgets(linha, 100, fp) != NULL) {
        sscanf(linha, "%*d;%[^;];%*[^;];%s", usuario_arq, senha_arq);
        if (strcmp(usuario_arq,nome_ ) == 0 && strcmp(senha_arq, senha_) == 0) {
            printf("----------------------\n");
            printf("| Login bem sucedido!|\n");
            printf("----------------------\n");
            n_autenticado2 = 1;
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