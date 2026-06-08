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

ARRUMAR MOSTRAR TAREFA PARANDO FUNCIONAMENTO AO MOSTRAR USUARIO NÃO CADASTRADO
*/

//Bibliotecas
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Structs
typedef struct Pessoa{
    int id;
    char nome[100];
    char email[100];
    int nivel;
    struct Pessoa *proxima;
}Pessoa;

typedef struct Tarefa{
    int id;
    char titulo[100];
    char descricao[400];
    int prioridade;
    int dificuldade;
    int status;
    struct Pessoa *responsavel;
    struct Tarefa *proxima;
}Tarefa;

// Protótipos das funções
Tarefa* cadastrarTarefas(Tarefa **inicio, Tarefa *ultima, int *idTotal, Pessoa **inicioUsuario);
Tarefa* buscarTarefa(Tarefa *inicio, char *tituloDigitado);
Tarefa* removerTarefa(Tarefa **inicio, Tarefa *ultima);
Tarefa* digitarTitulo(Tarefa *inicio);
Tarefa* definirResponsavel(Tarefa **inicio, Pessoa **inicioUsuario);
Pessoa* cadastrarPessoa(Pessoa **inicio, Pessoa *ultima, int *idTotal);
Pessoa* removerPessoa(Pessoa **inicio, Pessoa *ultima);
Pessoa* buscarUsuarioPorDificuldade(Pessoa *inicio, int dificuldade);
Pessoa* mostrarUsuario(Pessoa *usuario);
Pessoa* buscarIdUser(Pessoa *inicio, int id);
void listarPessoa(Pessoa *inicio);
void tarefasPendentes(Tarefa *inicio);
void mostrarMenu();
void esperarEnter();
void mostrarTarefa(Tarefa *tarefa);
void alterarStatus(Tarefa *inicio);
void listarTarefa(Tarefa *inicio);
void tarefasConcluidas(Tarefa *inicio);
void tarefasPrioridade(Tarefa *inicio);
void opcaoTarefas(int opcao, Tarefa **inicio, Tarefa **ultima, int *listaID, Pessoa **inicioUsuario);
void opcaoUsuarios(int opcao, Pessoa **inicio, Pessoa **ultima, int *listaID);
void menuTarefas();
void menuUsuario();
int lerOpcao();


// ==============
//  FUNÇÃO MAIN
// ==============
int main(){
    SetConsoleOutputCP(65001);

    // Inicialização da struct
    Tarefa *inicio = NULL;
    Tarefa *ultima = NULL;
    Pessoa *inicioPessoa = NULL;
    Pessoa *ultimaPessoa = NULL;

    // Variáveis
    int opcao;
    int listaIDtarefa=1;
    int listaIDPessoa=1;


    // Loop menu geral
    do
    {
        system("cls");
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1: // Gerenciar usuários
            opcaoUsuarios(opcao, &inicioPessoa, &ultimaPessoa, &listaIDPessoa);
            break;

        case 2: // Gerenciar tarefas
            opcaoTarefas(opcao, &inicio, &ultima, &listaIDtarefa, &inicioPessoa);
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
void opcaoTarefas(int opcao, Tarefa **inicio, Tarefa **ultima, int *listaID, Pessoa **inicioUsuario){
    // Loop do Menu gerenciar tarefas
    do
    {
        system("cls");
        menuTarefas();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            *ultima = cadastrarTarefas(inicio, *ultima, listaID, inicioUsuario);
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
        case 9:
            definirResponsavel(inicio, inicioUsuario);
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
void opcaoUsuarios(int opcao, Pessoa **inicio, Pessoa **ultima, int *listaID){
    // Loop do Menu gerenciar tarefas
    do
    {
        system("cls");
        menuUsuario();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            *ultima = cadastrarPessoa(inicio, *ultima, listaID);
            esperarEnter();
            break;

        case 2:
            listarPessoa(*inicio);
            esperarEnter();
            break;

        case 3:
            *ultima = removerPessoa(inicio, *ultima);
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
Tarefa* cadastrarTarefas(Tarefa **inicio, Tarefa *ultima,int *idTotal, Pessoa **inicioUsuario){
    Tarefa *novaTarefa = (Tarefa *)malloc(sizeof(Tarefa)); 

    if(novaTarefa == NULL){
        printf("\nErro ao alocar memória.");
        return ultima;
    }

    novaTarefa->proxima = NULL;
    
    
    // Adicionar ID em forma sequencial
    novaTarefa->id = (*idTotal)++;
    

    limparTexto();
    
    // Adicionar título
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
    
    // Adicionar descrição
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




    // Adicionar prioridade
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

    // Status pendente
    novaTarefa->status = 0;
    
    // Adicionar dificuldade
    numeroDigitado = -1;
    reset = 0;

    do
    {
        printf("\n(1) BAIXA");
        printf("\n(2) MEDIA");
        printf("\n(3) ALTA");
        printf("\nDigite a dificuldade da tarefa: ");
        scanf("%d",&numeroDigitado);
        if(numeroDigitado == 1 ||numeroDigitado == 2 ||numeroDigitado == 3){
            novaTarefa->dificuldade = numeroDigitado;
            reset = 1;
        }
    }while(reset == 0);
    
    // Adicionar responsavel
    printf("Adicione o responsável pela tarefa: ");
    Pessoa *pos = buscarUsuarioPorDificuldade(*inicioUsuario, novaTarefa->dificuldade);

    if (pos != NULL){

        pos = *inicioUsuario;

        do
        {
            mostrarUsuario(buscarUsuarioPorDificuldade(pos, novaTarefa->dificuldade));
        } while (pos!= NULL);
        
        do
        {
            printf("Digite o ID do usuário responsavel: ");
            scanf("%d",&numeroDigitado);
            pos = buscarIdUser(*inicioUsuario, numeroDigitado);
            if (pos != NULL)
            {
                novaTarefa->responsavel = pos;
                printf("Usuário atribuído com sucesso!\n");
            }
            else
            {
                novaTarefa->responsavel = NULL;
                printf("Usuário não encontrado. Tente novamente.\n");
            }

        }while (pos == NULL);
    }
    else{
        novaTarefa->responsavel = NULL;
        printf("Nenhum usuário com o nivel necessário para a tarefa. Adicione o responsavel posteriormente.");

    }
    
    
    
    


    // Adicionar tarefa na lista
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
    // Mostrar prioridade
    if (tarefa->prioridade == 1){
        printf("\nPrioridade: BAIXA(1)");
    }
    else if (tarefa->prioridade == 2){
        printf("\nPrioridade: MÉDIA(2)");
    }
    else if (tarefa->prioridade == 3){
        printf("\nPrioridade: ALTA(3)");
    }
    // Mostrar Dificuldade
    if (tarefa->dificuldade == 1){
        printf("\nDificuldade: BAIXA(1)");
    }
    else if (tarefa->dificuldade == 2){
        printf("\nDificuldade: MÉDIA(2)");
    }
    else if (tarefa->dificuldade == 3){
        printf("\nDificuldade: ALTA(3)");
    }
    // Mostrar status
    if (tarefa->status == 0){
        printf("\nSTATUS: PENDENTE(0)");
    }
    else if (tarefa->status == 1){
        printf("\nSTATUS: CONCLUIDO(1)");
    }
    printf("\nUsuário responsavel: ");
    if (tarefa->responsavel == NULL){
        printf("Nenhum usuário atribuido.");
    }
    else{
        mostrarUsuario(tarefa->responsavel);
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

            // Salvar titulo
            do
            { 
                printf("\nInforme o titulo da tarefa que procura: ");
                fgets(nome, 100, stdin);

                nome[strcspn(nome, "\n")] = '\0';

                if (strlen(nome) == 0)
                {
                    printf("\nTitulo não pode ser vazio!");
                }

            } while (strlen(nome) == 0);
            
            // Buscar titulo
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

        if (strlen(nome) == 0) // 
        {
            printf("\nTitulo não pode ser vazio!");
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
    
    if(inicio == NULL){
        printf("\nNenhuma tarefa concluída.");
        return;
    }

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

    if(inicio == NULL){
        printf("\nNenhuma tarefa pendente.");
        return;
    }

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

    if(inicio == NULL){
        printf("\nNenhuma tarefa cadastrada.");
        return;
    }

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

// ==========================
//  FUNÇÃO CADASTRAR USUÁRIO
// ==========================
Pessoa* cadastrarPessoa(Pessoa **inicio, Pessoa *ultima, int *idTotal){
    Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa)); 
    if(novaPessoa == NULL){ // Verifica se deu pra alocar memoria
        printf("\nErro ao alocar memória.");
        return ultima;
    }
    
    novaPessoa->proxima = NULL;
    
    // Adicionar ID em forma sequencial
    novaPessoa->id = (*idTotal)++;
    

    limparTexto();
    
    // Adicionar nome
    do
    { 
        printf("\nDigite o nome do usuário (ID %d): ",novaPessoa->id);
        fgets(novaPessoa->nome,100,stdin);

         novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

        if (strlen(novaPessoa->nome) == 0)
        {
            printf("\nNome não pode ser vazio!");
        }

    } while (strlen(novaPessoa->nome) == 0);
    
    // Adicionar email
    do
    { 
        printf("\nDigite o email do usuário: ");
        fgets(novaPessoa->email,100,stdin);

         novaPessoa->email[strcspn(novaPessoa->email, "\n")] = '\0';

        if (strlen(novaPessoa->email) == 0)
        {
            printf("\nEmail não pode ser vazio!");
        }
        else if(strchr(novaPessoa->email,'@') == NULL || (strstr(novaPessoa->email,".com") == NULL && strstr(novaPessoa->email,".br") == NULL))
        {
            printf("\nEmail deve conter '@' e '.com' ou '.br'!");
            novaPessoa->email[0] = '\0';
        }

    } while (strlen(novaPessoa->email) == 0);

    // Adicionar nivel
    int reset = 0;

    do
    {
        printf("\n(1) JUNIOR");
        printf("\n(2) PLENO");
        printf("\n(3) SENIOR");
        printf("\nDigite o nível do usuário: ");
        int numeroDigitado;
        scanf("%d",&numeroDigitado);
        if (numeroDigitado == 1 || numeroDigitado == 2 || numeroDigitado == 3 ){
            novaPessoa->nivel=numeroDigitado;
            reset = 1;
            continue;
        }
        printf("\nDigite um valor válido");
    }while(reset == 0);

    // Adicionar usuário na lista
    if (*inicio == NULL){
        *inicio = novaPessoa;
        ultima = novaPessoa;
    }
    else{
        ultima->proxima=novaPessoa;
        ultima=novaPessoa;
    }
    
    printf("\nUsuário criado com sucesso!");
    return ultima;
}

// ========================
//  FUNÇÃO REMOVER USUÁRIO
// ========================
Pessoa* removerPessoa(Pessoa **inicio, Pessoa *ultima){
    printf("\n ============== REMOVER USUÁRIO ===============");
    char nome[100];

    limparTexto();

    do
    { 
        printf("\nDigite o nome do usuário que deseja remover: ");
        fgets(nome,100,stdin);

         nome[strcspn(nome, "\n")] = '\0';

        if (strlen(nome) == 0)
        {
            printf("\nNome não pode ser vazio!");
        }

    } while (strlen(nome) == 0);



    Pessoa *atual = *inicio;
    Pessoa *anterior = NULL;

    while(atual != NULL){

        if(strcmp(atual->nome,nome) == 0){
            mostrarUsuario(atual);

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

                printf("\nUsuário removido com sucesso do sistema.");

                return ultima;
            }
        }
        anterior = atual;
        atual = atual->proxima;
    }
    printf("\nUsuário não encontrado.");
    return ultima;
}

// ========================
//  FUNÇÃO LISTAR USUÁRIOS
// ========================
void listarPessoa(Pessoa *inicio){
    Pessoa *pos = inicio;
    
    if(inicio == NULL){
        printf("\nNenhum usuário cadastrado.");
        return;
    }

    printf("\n========== LISTA DE USUÁRIOS =========");

    while(pos != NULL){
        mostrarUsuario(pos);
        pos=pos->proxima;
    }
    printf("\n=====================================");
}

// =======================
//  FUNÇÃO MOSTRAR USUÁRIO
// =======================
Pessoa* mostrarUsuario(Pessoa *usuario){
    if (usuario != NULL){
        printf("\n========== USUÁRIO (ID %d) =========",usuario->id);
        printf("\nNome:%s",usuario->nome);
        printf("\nEmail:%s",usuario->email);
        if (usuario->nivel == 1){
            printf("\nCargo: JUNIOR(1)");
        }
        else if (usuario->nivel == 2){
            printf("\nCargo: PLENO(2)");
        }
        else if (usuario->nivel == 3){
            printf("\nCargo: SENIOR(3)");
        }
        printf("\n===================================");
        return usuario;
    }
    return NULL;
}

// ========================================
//  BUSCAR USUARIO COM NIVEL = DIFICULDADE
// ========================================
Pessoa* buscarUsuarioPorDificuldade(Pessoa *inicio, int dificuldade){
    Pessoa *pos = inicio;

    while(pos != NULL){
        if(pos->nivel== dificuldade){
            return(pos);
        }
        pos = pos->proxima;
    }
    return NULL;
}

// ====================
//  BUSCAR USER POR ID
// ====================
Pessoa* buscarIdUser(Pessoa *inicio, int id){
    Pessoa *pos = inicio;

    while(pos != NULL){
        if(pos->id == id){
            return(pos);
        }
        pos = pos->proxima;
    }
    return NULL;
}

Tarefa* definirResponsavel(Tarefa **inicio, Pessoa **inicioUsuario){
    Tarefa *pos = *inicio;
    
     printf("\n ============== DEFINIR RESPONSÁVEL ===============");
    char nome[100];

    limparTexto();

    do
    { 
        printf("\nDigite o titulo da tarefa que deseja remover: ");
        fgets(nome,100,stdin);

         nome[strcspn(nome, "\n")] = '\0'; 

        if (strlen(nome) == 0) // 
        {
            printf("\nTitulo não pode ser vazio!");
        }

    } while (strlen(nome) == 0);


}