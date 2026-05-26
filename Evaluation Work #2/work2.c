/*
Struct -> variavel

O simbolo "->" aponta para a variável dentro da struct


Objeto *pos serve para percorrer as outras structs sem alterar elas e pegar a posição do armazenamento
Objeto *inicio é a posição da primeira tarefa da lista
Objeto *ultima é a posição da ultima tarefa na lista
*/










#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Structs
typedef struct Objeto{
    int id;
    char titulo[100];
    char descricao[400];
    int prioridade;
    int status;
    struct Objeto *proxima;
}Objeto;

// Protótipo de funções

Objeto* cadastrarTarefas(Objeto **inicio, Objeto *ultima);

Objeto* buscarTarefa(Objeto *inicio, char *tituloDigitado);

void mostrarMenu();

int lerOpcao();

void esperarEnter();

void mostrarTarefa(Objeto *tarefa);

// ==============
//  FUNÇÃO MAIN
// ==============
int main(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese");

    //  Inicialização da struct
    Objeto *inicio = NULL;
    Objeto *ultima = NULL;

    //  Variáveis
    int opcao;


//  Loop do Menu
    do
    {
        system("cls");
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            ultima = cadastrarTarefas(&inicio, ultima);
            esperarEnter();
            break;

        case 2:
            esperarEnter();
            break;

        case 3:
        {   
            char nome[100] = "vazio";
            getchar();

            //Salvar titulo
            do
            { 
                printf("\nInforme o titulo da tarefa que procura: ");
                fgets(nome, 100, stdin);

                nome[strcspn(nome, "\n")] = '\0';

                if (strlen(nome) == 0)
                {
                    printf("\nTitulo nao pode ser vazio!");
                }

            } while (strlen(nome) == 0);
            
            //Buscar titulo
            Objeto *tarefaAlvo = buscarTarefa(inicio, nome);

            if(tarefaAlvo != NULL)
            {   
                mostrarTarefa(tarefaAlvo);
            }
            else
            {
                printf("Tarefa não encontrada, procure por um titulo válido.");
            }

            esperarEnter();
            break;
        }
        case 0:
            printf("\nPrograma encerrado.\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}    

// ==================
//  FUNÇÃO LER OPÇÃO
// ==================
int lerOpcao()
{
    int opcao;
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// ====================
//  FUNÇÃO LIMPAR CHAR
// ====================
void limparTexto()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ======================
//  FUNÇÃO APERTAR ENTER
// ======================
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    limparTexto();
}

// =================
//  FUNÇÃO VER MENU
// =================
void mostrarMenu()
{
    printf("\n\n=====================================\n");
    printf(" SISTEMA DE GERENCIAMENTO DE TAREFAS\n");
    printf("=====================================\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Listar tarefas\n");
    printf("3 - Buscar tarefa\n");
    printf("4 - Alterar status da tarefa\n");
    printf("5 - Ver tarefas pendentes\n");
    printf("6 - Ver tarefas concluidas\n");
    printf("7 - Ver tarefas de maior prioridade\n");
    printf("8 - Remover tarefa\n");
    printf("0 - Sair\n");
}



// =====================
//  FUNÇÃO CRIAR TAREFA
// =====================
Objeto* cadastrarTarefas(Objeto **inicio, Objeto *ultima){
    Objeto *novaTarefa = (Objeto *)malloc(sizeof(Objeto)); 
    novaTarefa->proxima = NULL;
    
    // ADIÇÃO SEQUÊNCIAL DO ID
    if (ultima == NULL){
        novaTarefa->id = 1;
    }
    else{
        novaTarefa->id = ultima-> id +1;
    }

    getchar();
    
    // ADICIONAR TITULO
    do
    { 
        printf("\nDigite o titulo da tarefa (ID %d): ",novaTarefa->id);
        fgets(novaTarefa->titulo,100,stdin);

         novaTarefa->titulo[strcspn(novaTarefa->titulo, "\n")] = '\0';

        if (strlen(novaTarefa->titulo) == 0)
        {
            printf("\nTitulo nao pode ser vazio!");
        }

    } while (strlen(novaTarefa->titulo) == 0);
    
    // ADICIONAR DESCRIÇÃO
    do
    { 
        printf("\nDigite a descrição da tarefa: ",novaTarefa->descricao);
        fgets(novaTarefa->descricao,400,stdin);

         novaTarefa->descricao[strcspn(novaTarefa->descricao, "\n")] = '\0';

        if (strlen(novaTarefa->descricao) == 0)
        {
            printf("\nDescrição nao pode ser vazia!");
        }

    } while (strlen(novaTarefa->descricao) == 0);




    //ADICIONAR PRIORIDADE
    printf("\n(1) BAIXA");
    printf("\n(2) MEDIA");
    printf("\n(3) ALTA");
    printf("\nDigite a prioridade da tarefa: ");
    scanf("%d",&novaTarefa->prioridade);

    //STATUS PADRÃO
    novaTarefa->status = 0;


    // ADICIONAR TAREFA NA LISTA
    if (*inicio == NULL){
        *inicio = novaTarefa;
        ultima = novaTarefa;
    }
    else{
        ultima->proxima=novaTarefa;
        ultima=novaTarefa;
    }
    
    return ultima;
}

// ===============
//  FUNÇÃO BUSCAR 
// ===============
Objeto* buscarTarefa(Objeto *inicio, char *tituloDigitado){
    Objeto *pos = inicio;

    while (pos != NULL){
         if (strcmp(pos->titulo, tituloDigitado) == 0){
            return pos;
         }
         pos = pos->proxima;
    }
    return NULL;
}

// =====================
// FUNÇÃO PRINTAR TAREFA
// =====================
void mostrarTarefa(Objeto *tarefa){
    printf("\n========== TAREFA (ID %d) =========",tarefa->id);
    printf("\nTitulo:%s",tarefa->titulo);
    printf("\nDescrição:%s",tarefa->descricao);
    if (tarefa->prioridade == 1){
        printf("\nPrioridade: BAIXA(1)");
    }
    else if (tarefa->prioridade == 2){
        printf("\nPrioridade: MÉDIA(2)");
    }
    else if (tarefa->prioridade == 3){
        printf("\nPrioridade: ALTA(3)");
    }

    if (tarefa->status == 0){
        printf("\nSTATUS: PENDENTE(0)");
    }
    else if (tarefa->status == 1){
        printf("\nSTATUS: CONCLUIDO(1)");
    }
    printf("\n===================================");
}