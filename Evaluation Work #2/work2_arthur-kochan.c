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

Objeto* cadastrarTarefas(Objeto **inicio, Objeto *ultima, int *idTotal);
Objeto* buscarTarefa(Objeto *inicio, char *tituloDigitado);
Objeto* removerTarefa(Objeto **inicio, Objeto *ultima);
Objeto*  digitarTitulo(Objeto *inicio);
void tarefasPendentes(Objeto *inicio);
void mostrarMenu();
void esperarEnter();
void mostrarTarefa(Objeto *tarefa);
void alterarStatus(Objeto *inicio);
void listarTarefa(Objeto *inicio);
void tarefasConcluidas(Objeto *inicio);
void tarefasPrioridade(Objeto *inicio);
int lerOpcao();


// ==============
//  FUNÇÃO MAIN
// ==============
int main(){
    SetConsoleOutputCP(65001);

    //  Inicialização da struct
    Objeto *inicio = NULL;
    Objeto *ultima = NULL;

    //  Variáveis
    int opcao;
    int listaID=1;


//  Loop do Menu
    do
    {
        system("cls");
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            ultima = cadastrarTarefas(&inicio, ultima,&listaID);
            esperarEnter();
            break;

        case 2:
            listarTarefa(inicio);
            esperarEnter();
            break;

        case 3:
        {   
            digitarTitulo(inicio);
            esperarEnter();
            break;
        }
        case 4:
            alterarStatus(inicio);
            esperarEnter();
            break;
        case 5:
            tarefasPendentes(inicio);
            esperarEnter();
            break;
        case 6:
            tarefasConcluidas(inicio);
            esperarEnter();
            break;
        case 7:
            tarefasPrioridade(inicio);
            esperarEnter();
            break;
        case 8:
            ultima = removerTarefa(&inicio, ultima);
            printf("\n =============================================");
            esperarEnter();
            break;
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
    getchar();
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
Objeto* cadastrarTarefas(Objeto **inicio, Objeto *ultima,int *idTotal){
    Objeto *novaTarefa = (Objeto *)malloc(sizeof(Objeto)); 
    if(novaTarefa == NULL){
        printf("\nErro ao alocar memória.");
        return ultima;
    }

    novaTarefa->proxima = NULL;
    
    // ADIÇÃO SEQUÊNCIAL DO ID
    novaTarefa->id = (*idTotal)++;
    

    limparTexto();
    
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
        printf("\nDigite a descrição da tarefa: ");
        fgets(novaTarefa->descricao,400,stdin);

         novaTarefa->descricao[strcspn(novaTarefa->descricao, "\n")] = '\0';

        if (strlen(novaTarefa->descricao) == 0)
        {
            printf("\nDescrição nao pode ser vazia!");
        }

    } while (strlen(novaTarefa->descricao) == 0);




    //ADICIONAR PRIORIDADE
    int numeroDigitado;
    int reset = 0;

    do
    {
        printf("\n(1) BAIXA");
        printf("\n(2) MEDIA");
        printf("\n(3) ALTA");
        printf("\nDigite a prioridade da tarefa: ");
        scanf("%d",&numeroDigitado);
        if(numeroDigitado == 1 ||numeroDigitado == 2 ||numeroDigitado == 3){
            novaTarefa->prioridade = numeroDigitado;
            reset = 1;
        }
    }while(reset == 0);

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
    
    printf("\nTarefa criada com sucesso!");
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

// =======================
//  FUNÇÃO PRINTAR TAREFA
// =======================
void mostrarTarefa(Objeto *tarefa){
    printf("\n========== TAREFA (ID %d) =========",tarefa->id);
    printf("\nTítulo:%s",tarefa->titulo);
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

// =======================
//  FUNÇÃO ALTERAR STATUS
// =======================
void alterarStatus(Objeto *inicio){

    printf("\n=========== Alterar Status ============");

    Objeto *tarefaAlvo = digitarTitulo(inicio);
    int confirmar;
    
    if(tarefaAlvo != NULL)
    {   
        if (tarefaAlvo->status == 0){
            printf("\n\nGostaria de alterar o status para CONCLUIDO? ");
            printf("\nDigite o número 0 (SIM) ou 1 (NÃO): ");
            scanf("%d",&confirmar);
            if (confirmar==0){
                tarefaAlvo->status=1;
            }
            else{
                printf("\nO Status não foi alterado.");
            }
        }
        else if (tarefaAlvo->status == 1){
            printf("\nGostaria de alterar o status para PENDENTE? ");
            printf("\nDigite o número 0 (SIM) ou 1 (NÃO): ");
            scanf("%d",&confirmar);
            if (confirmar==0){
                tarefaAlvo->status=0;
            }     
            else{
                printf("\nO Status não foi alterado.");
            }
        }
    }
    printf("\n======================================");
}

// ===============================================
//  FUNÇÃO DIGITAR TITULO (COMPLEMENTO DO BUSCAR)
// ===============================================
Objeto* digitarTitulo(Objeto *inicio){
    char nome[100] = "vazio";
            limparTexto();

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
                return tarefaAlvo;
            }
            else
            {
                printf("\nTarefa não encontrada, procure por um titulo válido.");
                return NULL;
            }

}

// =======================
//  FUNÇÃO REMOVER TAREFA
// =======================
Objeto* removerTarefa(Objeto **inicio, Objeto *ultima){
    printf("\n ============== REMOVER TAREFA ===============");
    char nome[100];

    limparTexto();

    do
    { 
        printf("\nDigite o titulo da tarefa que deseja remover: ");
        fgets(nome,100,stdin);

         nome[strcspn(nome, "\n")] = '\0';

        if (strlen(nome) == 0)
        {
            printf("\nTitulo nao pode ser vazio!");
        }

    } while (strlen(nome) == 0);



    Objeto *atual = *inicio;
    Objeto *anterior = NULL;

    while(atual != NULL){

        if(strcmp(atual->titulo,nome) == 0){
            mostrarTarefa(atual);

            int confirmar;

            printf("\n\nDeseja realmente remover?");
            printf("\nDigite 0 (SIM) ou 1 (NÃO): ");
            scanf("%d",&confirmar);

            if(confirmar == 0){

                if(anterior == NULL){
                    *inicio = atual->proxima;
                }
                else{
                    anterior->proxima = atual->proxima;
                }

                if(atual == ultima){
                    ultima = anterior;
                }

                free(atual);

                printf("\nTarefa removida com sucesso do sistema.");

                return ultima;
            }
        }
        anterior = atual;
        atual = atual->proxima;
    }

    printf("\nTarefa não encontrada.");

    return ultima;
}

// ================
//  LISTAR TAREFAS
// ================
void listarTarefa(Objeto *inicio){
    Objeto *pos = inicio;

    printf("\n========== LISTA DE TAREFAS =========");

    while(pos != NULL){
        mostrarTarefa(pos);
        pos=pos->proxima;
    }
    printf("\n=====================================");
}

// =============================
//  MOSTRAR  TAREFAS CONCLUIDAS
// =============================
void tarefasConcluidas(Objeto *inicio){
    Objeto *pos = inicio;

    printf("\n========== LISTA DE TAREFAS CONCLUIDAS =========");

    while(pos != NULL){
        if(pos->status ==1){
            mostrarTarefa(pos);
        }
        pos=pos->proxima;
    }
    printf("\n=====================================");
}

// ============================
//  MOSTRAR  TAREFAS PENDENTES
// ============================
void tarefasPendentes(Objeto *inicio){
    Objeto *pos = inicio;

    printf("\n========== LISTA DE TAREFAS PENDENTES =========");

    while(pos != NULL){
        if(pos->status ==0){
            mostrarTarefa(pos);
        }
        pos=pos->proxima;
    }
    printf("\n=====================================");
}

// ======================================
//  MOSTRAR  TAREFA PRIORIDADE MAIS ALTA
// ======================================
void tarefasPrioridade(Objeto *inicio){
    Objeto *pos = inicio;
    int maior=0;

    printf("\n========== LISTA DE TAREFAS CONCLUIDAS =========");
    
    while(pos != NULL){
        if(pos->prioridade > maior){
            maior = pos->prioridade;
        }
        pos=pos->proxima;
    }
    
    pos = inicio;

    while(pos != NULL){
        if(pos->prioridade ==maior){
            mostrarTarefa(pos);
        }
        pos=pos->proxima;
    }
    printf("\n=====================================");
}

