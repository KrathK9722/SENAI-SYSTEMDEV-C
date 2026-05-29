/*
Struct -> variavel

O simbolo "->" aponta para a variável dentro da struct


Objeto *pos serve para percorrer as outras structs sem alterar elas e pegar a posição do armazenamento
Objeto *inicio é a posição da primeira tarefa da lista
Objeto *ultima é a posição da ultima tarefa na lista

IMPLEMENTAR AGORA:

Cadastro de pessoas 
- Email - validar: deve conter @ e .com ou .br
- Nivel: deve conter junior, pleno ou senior
- Nome: Validar se permite
- Id: sequêncial e único

No cadastro da tarefa:
Dificuldade: 1,2,3
Responsavel: Pessoa

Relcionar tarefa com pessoas ex:
Senior: Até nivel 3
Pleno: Até nivel 2
Junior: Até nivel 1


Adicionar as novas variaveis da tarefa
Criar struct pessoa e permitir criação do cadastro
Permitir alterar responsavel da tarefa
Novo menu de gerenciamento da tarefa
Menu de gerenciamento dos cadastros
Menu de login do cadastro
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Structs
typedef struct Tarefa{
    int id;
    char titulo[100];
    char descricao[400];
    int prioridade;
    int status;
    struct Tarefa *proxima;
}Tarefa;


// Protótipo de funções

Tarefa* cadastrarTarefas(Tarefa **inicio, Tarefa *ultima, int *idTotal);
Tarefa* buscarTarefa(Tarefa *inicio, char *tituloDigitado);
Tarefa* removerTarefa(Tarefa **inicio, Tarefa *ultima);
Tarefa*  digitarTitulo(Tarefa *inicio);
void tarefasPendentes(Tarefa *inicio);
void mostrarMenu();
void esperarEnter();
void mostrarTarefa(Tarefa *tarefa);
void alterarStatus(Tarefa *inicio);
void listarTarefa(Tarefa *inicio);
void tarefasConcluidas(Tarefa *inicio);
void tarefasPrioridade(Tarefa *inicio);
void opcaoTarefas(int opcao, Tarefa **inicio, Tarefa **ultima, int *listaID);
void opcaoUsuarios(int opcao);
void menuTarefas();
void menuUsuario();
int lerOpcao();


// ==============
//  FUNÇÃO MAIN
// ==============
int main(){
    SetConsoleOutputCP(65001);

    //  Inicialização da struct
    Tarefa *inicio = NULL;
    Tarefa *ultima = NULL;

    //  Variáveis
    int opcao;
    int listaID=1;


//  Loop do Menu gerenciar tarefas
    do
    {
        system("cls");
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1: // Gerenciar usuários
            opcaoUsuarios(opcao);
            break;

        case 2: // Gerenciar tarefas
            opcaoTarefas(opcao, &inicio, &ultima, &listaID);;
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

// ===============
//  OPÇÃO TAREFAS
// ===============
void opcaoTarefas(int opcao, Tarefa **inicio, Tarefa **ultima, int *listaID){
    //  Loop do Menu gerenciar tarefas
    do
    {
        system("cls");
        menuTarefas();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            *ultima = cadastrarTarefas(inicio, *ultima, listaID);;
            esperarEnter();
            break;

        case 2:
            listarTarefa(*inicio);
            esperarEnter();
            break;

        case 3:
        {   
            digitarTitulo(*inicio);
            esperarEnter();
            break;
        }
        case 4:
            alterarStatus(*inicio);
            esperarEnter();
            break;
        case 5:
            tarefasPendentes(*inicio);
            esperarEnter();
            break;
        case 6:
            tarefasConcluidas(*inicio);
            esperarEnter();
            break;
        case 7:
            tarefasPrioridade(*inicio);
            esperarEnter();
            break;
        case 8:
            *ultima = removerTarefa(inicio, *ultima);
            printf("\n =============================================");
            esperarEnter();
            break;
        case 0:
            printf("\nSaindo do menu...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);
}    

// ================
//  OPÇÃO USUÁRIOS
// ================
void opcaoUsuarios(int opcao){
    //  Loop do Menu gerenciar tarefas
    do
    {
        system("cls");
        menuUsuario();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            esperarEnter();
            break;

        case 2:
            esperarEnter();
            break;

        case 3:
            esperarEnter();
            break;
        case 0:
            printf("\nSaindo do menu...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);
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

// =============================
//  FUNÇÃO VER MENU DAS TAREFAS
// =============================
void menuTarefas()
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
    printf("9 - Definir responsável\n");
    printf("10 - Alterar dificuldade\n");
    printf("0 - Sair do menu\n");
}

// =================
//  FUNÇÃO VER MENU 
// =================
void mostrarMenu()
{
    printf("\n\n==========================\n");
    printf(" SISTEMA DE GERENCIAMENTO \n");
    printf("==========================\n");
    printf("1 - Gerenciar usuários\n");
    printf("2 - Gerenciar tarefas\n");
    printf("0 - Sair do sistema\n");
}

// =============================
//  FUNÇÃO VER MENU DAS TAREFAS
// =============================
void menuUsuario()
{
    printf("\n\n=====================================\n");
    printf(" SISTEMA DE GERENCIAMENTO DE USUÁRIOS\n");
    printf("=====================================\n");
    printf("1 - Criar usuário\n");
    printf("2 - Listar usuários\n");
    printf("3 - Remover usuário\n");
    printf("0 - Sair do menu\n");
}

// =====================
//  FUNÇÃO CRIAR TAREFA
// =====================
Tarefa* cadastrarTarefas(Tarefa **inicio, Tarefa *ultima,int *idTotal){
    Tarefa *novaTarefa = (Tarefa *)malloc(sizeof(Tarefa)); 
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
Tarefa* buscarTarefa(Tarefa *inicio, char *tituloDigitado){
    Tarefa *pos = inicio;
    
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
void mostrarTarefa(Tarefa *tarefa){
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
void alterarStatus(Tarefa *inicio){

    printf("\n=========== Alterar Status ============");

    Tarefa *tarefaAlvo = digitarTitulo(inicio);
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
Tarefa* digitarTitulo(Tarefa *inicio){
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
            Tarefa *tarefaAlvo = buscarTarefa(inicio, nome);

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
Tarefa* removerTarefa(Tarefa **inicio, Tarefa *ultima){
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



    Tarefa *atual = *inicio;
    Tarefa *anterior = NULL;

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
void listarTarefa(Tarefa *inicio){
    Tarefa *pos = inicio;
    
    if(inicio == NULL){
        printf("\nNenhuma tarefa cadastrada.");
        return;
    }

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
void tarefasConcluidas(Tarefa *inicio){
    Tarefa *pos = inicio;

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
void tarefasPendentes(Tarefa *inicio){
    Tarefa *pos = inicio;

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
void tarefasPrioridade(Tarefa *inicio){
    Tarefa *pos = inicio;
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

