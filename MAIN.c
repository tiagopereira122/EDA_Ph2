// ----- Bibliotecas
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----- Ficheiros .c com as funçoes de Meios/Clientes/Gestores
#include "MeioEletrico.c"
#include "Cliente.c"
#include "Gestor.c"

// ----- Menu principal de autenticação do programa e registo de um novo cliente
int MenuAutenticacao()
{
    int op;
    printf("1 Autenticação - Cliente\n");
    printf("2 Autenticação - Gestor\n");
    printf("3 Criar conta cliente\n");
    printf("0 Cancelar\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}


// ----- SubMenu àrea de autenticação gestorsubMenuGestores_2
int subMenuGestores_2()
{
    int op;
    printf("1 GERIR GESTORES\n");
    printf("2 GERIR MEIOS\n");
    printf("3 GERIR CLIENTES\n");
    printf("4 GERIR GRAFOS\n");
    printf("0 Cancelar\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

// ----- SubMenu àrea de autenticação cliente
int subMenuClientes()
{
    int op;
    printf("\nM E N U - Clientes\n");
    printf("1 Ler Meios\n");
    printf("2 Alugar Meio\n");
    printf("3 Desalugar Meio\n");
    printf("4 Verificar Saldo\n");
    printf("5 Ler Meios Localização\n");
    printf("0 Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

// ----- SUB-MENUS PARA A ÀREA DE GESTOR (MANIPULAR DADOS DOS GESTORES, MEIOS E CLIENTES)
// ----- SubMenu Meios (GERIR MEIOS)
int subMenuMeios()
{
    int op;
    printf("\nM E N U - Meios de Mobilidade Eletrica (Gerido por Gestor)\n");
    printf("1 Inserir Meio\n");
    printf("2 Listar Meios\n");
    printf("3 Remover Meio\n");
    printf("4 Guardar Meios\n");
    printf("5 Ler Meios\n");
    printf("6 Alterar dados dos Meios\n");
    printf("0 Voltar ao menu principal\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}
// ----- SubMenu Cliente (GERIR CLIENTES)
int subMenuCliente_Gestor()
{
    int op;
    printf("\nM E N U - Clientes (Gerido por Gestor)\n");
    printf("1 Inserir novo cliente\n");
    printf("2 Listar Clientes\n");
    printf("3 Remover Cliente\n");
    printf("4 Guardar Cliente\n");
    printf("5 Ler Clientes\n");
    printf("6 Alterar dados dos Clientes\n");
    printf("0 Voltar ao menu principal\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}
// ----- SubMenu Gestor (GERIR GESTORES)
int subMenuGestores()
{
    int op;
    printf("\nM E N U - Gestores\n");
    printf("1 Inserir Novo Gestor\n");
    printf("2 Listar Gestores\n");
    printf("3 Remover Gestor\n");
    printf("4 Guardar Gestores\n");
    printf("5 Ler Gestor\n");
    printf("6 Alugar Meio\n");
    printf("7 Mostrar Alugures\n");
    printf("9 Alterar dados dos Gestores\n");
    printf("0 Voltar ao menu principal\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

int subMenuGestores_Grafos()
{
    int op;
    printf("\nM E N U - Gestores\n");
        printf("MENU - GRAFOS:\n");
        printf("1. Criar novo grafo\n");
        printf("2. Inserir novo vértice\n");
        printf("3. Inserir nova aresta\n");
        printf("4. Associar código de meio a um vértice\n");
        printf("5. Imprimir grafo\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
    return op;
}


// ----- Inicio da função main
int main(){

    // ----- Listas ligadas vazias
    Meio* meios = NULL; 
    Cliente* clientes = NULL;
    Gestor* gestores = NULL;
    Vertice* vertices = NULL;
    Aresta* arestas = NULL;
    Grafo* grafos = NULL;
    Grafo* grafo = NULL;
    //RegistoAluguer* alugueres = NULL;

    // ----- Variaveis globais do código
    int op, cod, id_, contribuinte_, id_cliente, id_meio_eletrico,disponivel_,existe,bat,codClient,num_users = 0, num_users2 = 0,autenticado1,autenticado2,geo,codigoOrigem, codigoDestino,novoID, novoContribuinte;
    float aut,peso;
    char modelo[50], nome_[20],morada_[100],email_[100], data_inicio[20], data_fim[20], senha_[20], user_[20], vertice [50],novoNome[50],  novaMorada[50], novoEmail[50], novaSenha[50];
;    int opcao_principal, opcao_sub;
    const char* nomeArquivo;

    // ----- Mensagem interativa com o usuário
    printf("----------------------------------------------------------\n");
    printf("|Bem-vindo! Por favor, selecione autenticacao pretendida:|\n");
    printf("----------------------------------------------------------\n");

    // ----- Inicia o programa com o menu de autenticação
    do {
        opcao_principal = MenuAutenticacao();
        // ----- SubMenu de autenticação do cliente
        switch (opcao_principal) {
        case 1:
            printf("Bem-vindo! Por favor, faca login para continuar.\n");
            printf("Digite nome de utilizador: ");
            scanf("%s", nome_);

            printf("Digite sua senha: ");
            scanf("%s", senha_);
            
            autenticado1 = autenticar_cliente(clientes,nome_, senha_);

            if (autenticado1) { // ----- Em caso do cliente ser autenticado(variavel ser atribuida o valor 1 na funçao) entra no menu de Cliente
                // ----- Cases com funções associadas ao menu de Cliente
                do{
                opcao_sub = subMenuClientes();

                    switch(opcao_sub){
                    case 1: 
                        printf("-------------------> LISTA DE MEIOS  <-------------------\n");
                        meios = lerMeios();
                        listarMeios(meios);
                    break;
                    case 2:
                            nomeArquivo = "grafo.txt";
                            FILE* arquivo = fopen(nomeArquivo, "r");
                            if (arquivo == NULL) {
                            printf("Erro ao abrir o arquivo.\n");
                            return 1;
                            }

                        // Solicitar o ID do Meio Elétrico e do Cliente para realizar o aluguel
                        printf("\n--- ALUGUEL DE MEIO ELÉTRICO ---\n");
                        printf("Digite o ID do Meio Elétrico que deseja alugar: ");
                        scanf("%d", &cod);
                        // printf("Digite o ID do Cliente que deseja alugar o Meio Elétrico: ");
                        //scanf("%s", &nome_);
                        if (meio_eletrico_disponivel(cod, meios)) {
                        printf("Meio Elétrico disponível para aluguel!\n");
                        // Procurar o Cliente na lista ligada pelo ID
                        Cliente *cliente = buscar_cliente(nome_, clientes);
                        // Atualizar o estado de disponibilid1ade do Meio Elétrico na lista ligada
                        atualizar_meio_eletrico(cod, meios,nome_);
                        guardarMeios(meios);
                        meios = lerMeios(meios);
                        listarMeios(meios);
                        
                        } else {
                        printf("Meio Elétrico indisponível para aluguel!\n");
                            }

                            char linha[100];

                            char busca[10];
                            sprintf(busca, ";%d;", cod); // Altera o padrão de busca para ;<cod>;

                            int encontrado = 0;
                            printf("----- GRAFO -----\n");
                            while (fgets(linha, sizeof(linha), arquivo)) {

                                if (strstr(linha, busca) != NULL) {

                                    printf("%s", linha);
                                    encontrado = 1;
                                }
                            }

                            if (!encontrado) {
                                printf("Nenhum resultado encontrado.\n");
                            }

                            fclose(arquivo);




                        break;
                        case 3:
                        // Solicitar o ID do Meio Elétrico e do Cliente para realizar o aluguel
                        printf("\n--- DESALUGAR MEIO ELÉTRICO ---\n");
                        printf("Digite o ID do Meio Elétrico que deseja desalugar: ");
                        scanf("%d", &cod);
                        desalugar_meio_eletrico(cod, meios,nome_);
                        guardarMeios(meios);
                        meios = lerMeios(meios);
                        listarMeios(meios);
                        
                        
                            break;
                        case 4:
                            //Inserir aqui funcao de verificar saldo
                            break;
                        case 5:
                            printf("Geocodigo pretendido:\n");
                            scanf("%d", &geo);
                            listar_meios_localizacao(geo,meios);
                            break;
                        case 0:
                            printf("Saindo do programa...\n\n");
                            break;
                    }
                } while (opcao_sub != 0);
            } else {
                // Usuário nao autenticado
            }
        break;
        // ----- SubMenu de autenticação do gestor
        case 2:
            printf("Bem-vindo! Por favor, faca login para continuar.\n");
            printf("Digite nome de utilizador: ");
            scanf("%s", nome_);

            printf("Digite sua senha: ");
            scanf("%s", senha_);
            
            autenticado2 = autenticar_gestor(gestores,nome_,senha_);

            if (autenticado2) {

            printf("Bem-vindo! Por favor, faça login para continuar.\n");

             do {
                opcao_sub= subMenuGestores_2();
        
                switch (opcao_sub) {
                    // ----- SubMenu de autenticação do cliente (em caso de autenticado ser verdadeiro) -> Manipular dados Gestor
                    case 1:     
                        do{
                            opcao_sub = subMenuGestores();

                            switch(opcao_sub){
                                case 1:
                                    printf("ID de Gestor?\n");
                                    scanf("%d",&id_);
                                    printf("Nome do Gestor?\n");
                                    scanf("%s",nome_);
                                    printf("Email do Gestor?\n");
                                    scanf("%s",email_);
                                    printf("Senha:");
                                    scanf("%s",senha_);
                                    gestores = novoGestor(gestores,id_, nome_, email_,senha_);
                                break;
                                case 2:
                                    listarGestores(gestores);
                                break;
                    
                                case 3:
                                    printf("[Codigo do gestor a remover?]\n");
                                    scanf("%d",&id_);
                                    gestores = removerGestor(gestores, id_);
                                break;
                                case 4:
                                    guardarGestores(gestores);
                                break;
                                case 5:
                                    gestores = lerGestores();
                                break;
                                case 9:
									printf("ID de Gestor?\n");
                                    scanf("%d",&id_);
                                    printf("Nome do Gestor?\n");
                                    scanf("%s",nome_);
                                    printf("Email do Gestor?\n");
                                    scanf("%s",email_);
                                    printf("Senha:");
                                    scanf("%s",senha_);
									
                                    alterarGestor(gestores,id_, nome_, email_,senha_);
                                    guardarGestores(gestores);
									
                                break; 
                                case 6:
                                    printf("teste");
                                break;   
                            } 
                        } while(opcao_sub != 0);
                    break;
                    // ----- SubMenu de autenticação do cliente (em caso de autenticado ser verdadeiro) -> Manipular dados Meios
                    case 2:
                        do{
                            opcao_sub = subMenuMeios();

                            switch(opcao_sub){
                            case 1:
                                printf("Codigo?\n");
                                scanf("%d",&cod);
                                scanf("%*c"); 
                                printf("Modelo\n");
                                scanf("%s",modelo);
                                printf("Nivel da bateria?\n");
                                scanf("%d",&bat);
                                printf("Autonomia\n");
                                scanf("%f",&aut);
                                printf("Geocódigo\n");
                                scanf("%d",&geo);
                                meios = inserirMeio(meios,cod,modelo,bat,aut,disponivel_,user_,geo);
                            break;
                            case 2:
                                listarMeios(meios);
                            break;
                            case 3:
                                printf("[Codigo do meio de mobilidade a remover?]\n");
                                scanf("%d",&cod);
                                meios = removerMeio(meios, cod);
                            break;
                            case 4:
                                guardarMeios(meios);
                            break;
                            case 5:
                                meios = lerMeios();
                            break;
                            case 6:
                                printf("Codigo?\n");
                                scanf("%d",&cod);
                                scanf("%*c"); 
                                printf("Modelo\n");
                                scanf("%s",modelo);
                                printf("Nivel da bateria?\n");
                                scanf("%d",&bat);
                                printf("Autonomia\n");
                                scanf("%f",&aut);
                                printf("Geocódigo\n");
                                scanf("%d",&geo);

                                alterarMeio(meios,cod,modelo,bat,aut,disponivel_,user_,geo);
                                guardarMeios(meios);
                            break;
                            default:
                                printf("Opcao invalida.\n");
                            break;
                            }
                        }while (opcao_sub != 0);
                    break;
                    // ----- SubMenu de autenticação do cliente (em caso de autenticado ser verdadeiro) -> Manipular dados Clientes
                    case 3:
                        do{
                            opcao_sub = subMenuCliente_Gestor();

                            switch(opcao_sub){
                                case 1:
                                    printf("ID de cliente?\n");
                                    scanf("%d",&id_);
                                    scanf("%*c"); 
                                    printf("Contribuinte de cliente?\n");
                                    scanf("%d",&contribuinte_);
                                    printf("Nome do cliente?\n");
                                    scanf("%s",nome_);
                                    printf("Localidade do cliente?\n");
                                    scanf("%s",morada_);
                                    printf("Email do cliente?\n");
                                    scanf("%s",email_);
                                    printf("Senha:\n");
                                    scanf("%s",senha_);
                                    clientes = novoCliente(clientes,id_,contribuinte_,nome_,morada_,email_,senha_);
                                    break;
                                case 2:
                                    listarClientes(clientes);
                                    break;
                                case 3:
                                    printf("[Codigo do cliente a remover?]\n");
	                                scanf("%d",&id_);
	                                clientes = removerCliente(clientes, id_);
                                    break;
                                case 4:
                                    guardarClientes(clientes);
                                    break;
                                case 5:
                                    clientes = lerClientes();
                                    break;
                                case 6:
									printf("ID de cliente?\n");
                                    scanf("%d",&id_);
                                    scanf("%*c"); 
                                    printf("Contribuinte de cliente?\n");
                                    scanf("%d",&contribuinte_);
                                    printf("Nome do cliente?\n");
                                    scanf("%s",nome_);
                                    printf("Localidade do cliente?\n");
                                    scanf("%s",morada_);
                                    printf("Email do cliente?\n");
                                    scanf("%s",email_);
                                    printf("Senha:\n");
                                    scanf("%s",senha_);
									alterarCliente(clientes,id_,contribuinte_,nome_,morada_,email_,senha_);
									guardarClientes(clientes);
									
                                break;
                                case 0:
                                    break;
                                default:
                                printf("Opcao invalida.\n");
                                    break;
                            }
                        } while(opcao_sub != 0);        
                    break;
                    case 4:
                            do{
                            opcao_sub = subMenuGestores_Grafos();

                            switch(opcao_sub){
                                case 1:
                                    if (grafo != NULL) {
                                        printf("Já existe um grafo criado. Deseja substituí-lo? (S/N): ");
                                        char resposta;
                                        scanf(" %c", &resposta);
                                        if (resposta == 'N' || resposta == 'n') {
                                            break;
                                        }
                                        free(grafo);
                                    } 

                                    grafo = (Grafo*)malloc(sizeof(Grafo));
                                    printf("Digite o nome do grafo: ");
                                    scanf("%s", grafo->nome);
                                    grafo->primeiroVertice = NULL;
                                    printf("Grafo criado com sucesso!\n");
                                    break;
                                case 2:
                                    if (grafo == NULL) {
                                        printf("É necessário criar um grafo primeiro!\n");
                                    } else {
                                        int codigoVertice;
                                        printf("Digite o código do vértice: ");
                                        scanf("%d", &codigoVertice);

                                        if (!existeVertice(grafo, codigoVertice)) {
                                            Vertice* novoVertice = malloc(sizeof(Vertice));
                                            if (novoVertice != NULL) {
                                                novoVertice->codigo = codigoVertice;
                                                novoVertice->codigoMeio = -1;  // Código de meio inicialmente indefinido
                                                novoVertice->primeiraAresta = NULL;
                                                novoVertice->proximo = NULL;

                                                inserirVertice(grafo, novoVertice);
                                                printf("Vértice inserido com sucesso!\n");
                                            }
                                        } else {
                                            printf("O vértice com código %d já existe!\n", codigoVertice);
                                        }
                                    }

                                break;
                                case 3:
                                        if (grafo == NULL) {
                                            printf("É necessário criar um grafo primeiro!\n");
                                        } else {
                                            int codigoOrigem, codigoDestino, codigoMeio;
                                            float peso;
                                            meios = lerMeios();

                                            printf("Digite o código do vértice de origem: ");
                                            scanf("%d", &codigoOrigem);
                                            printf("Digite o código do vértice de destino: ");
                                            scanf("%d", &codigoDestino);
                                            printf("Digite o peso da aresta: ");
                                            scanf("%f", &peso);
                                            printf("Codigo Meio:");
                                            scanf("%d", &codigoMeio);
                                            


                                            if (existeVertice(grafo, codigoOrigem) && existeVertice(grafo, codigoDestino) && existeMeio(meios, codigoMeio)) {
                                                // Os vértices de origem, destino e o meio existem, então podemos criar a aresta
                                                criarAresta(grafo, codigoOrigem, codigoDestino, peso, codigoMeio);
                                                printf("Aresta inserida com sucesso!\n");
                                            } else {
                                                printf("Código de vértice ou meio inválido!\n");
                                            }
                                        }

                                    break;
                                    case 4:
                                        //meios = inserirMeio(meios,10,"tesla",100,500,1,"tiago",10);
                                        //meios = lerMeios();
                                        if (grafo == NULL) {
                                            printf("É necessário criar um grafo primeiro!\n");
                                        } else {
                                        int codigoVertice, codigoMeio;
                                        printf("Digite o código do vértice: ");
                                        scanf("%d", &codigoVertice);
                                        printf("Digite o código do meio: ");
                                        scanf("%d", &codigoMeio);

                                        meios = lerMeios(meios);
                                    
                                        if (existeMeio(meios, codigoMeio)) {
                                            
                                            // O meio existe, então podemos associá-lo ao vértice
                                            Vertice* verticeEncontrado = obterVerticePorCodigo(grafo, codigoVertice);
                                            verticeEncontrado->codigoMeio = codigoMeio;
                                            printf("Código de meio associado ao vértice com sucesso!\n");
                                        } else {
                                            printf("Código de meio inválido!\n");
                                        }
                                    }
                                        break;
                                    case 5:
                                        if (grafo == NULL) {
                                            printf("É necessário criar um grafo primeiro!\n");
                                        } else {
                                            imprimirGrafo(grafo,meios);
                                            salvarGrafoEmtxt(grafo,"grafo.txt");
                                        } 
                                        break;
                                    case 6:
                                        printf("Saindo...\n");
                                        break;
                                    default:
                                        printf("Opção inválida! Tente novamente.\n");
                                        break;
                                        }
                        } while(opcao_sub != 0);        
                    break;
                    case 0:
                        printf("Saindo do programa...\n");
                        return 0;
                }          
            } while (opcao_sub != 0);
        }
        break;
        // ----- Case do menu principal -> Permite ao utilizador associar-se à plataforma e fazer um registo de um novo cliente
        case 3:
            printf("ID de cliente?\n");
	        scanf("%d",&id_);
	        scanf("%*c"); 
            printf("Contribuinte de cliente?\n");
            scanf("%d",&contribuinte_);
	        printf("Nome do cliente?\n");
	        scanf("%s",nome_);
	        printf("Localidade do cliente?\n");
	        scanf("%s",morada_);
	        printf("Email do cliente?\n");
	        scanf("%s",email_);
            printf("Senha?");
            scanf("%s",senha_);
            clientes = novoCliente(clientes,id_,contribuinte_,nome_,morada_,email_,senha_);
            guardarClientes(clientes);
            printf("---> Bem vindo ao mundo elétrico <--- ---> Cliente registado com sucesso <---\n");
            break;
        } 
    } while (opcao_principal != 0);
return 0;
}

