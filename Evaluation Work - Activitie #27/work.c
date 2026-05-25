/*
Completar as funções restantes do código:

O que o código deve conter:
1 - Cadastrar produto
2 - Listar produtos
3 - Buscar produto
4 - Produto mais caro
5 - Valor total em estoque
0 - Sair



Funções a implementar:
2 - Listar produtos
3 - Buscar produto
4 - Produto mais caro
5 - Valor total em estoque

Start code link: https://www.programiz.com/online-compiler/3X1OJ4IKdQtq1

VALIDAÇÕES OBRIGATÓRIAS
O sistema deverá validar:
nome vazio
preço negativo
estoque negativo
limite máximo de produtos
opções inválidas do menu

DESAFIOS EXTRAS (OPCIONAL)

Permitir alterar:
preço
estoque
Permitir remover produtos
Mostrar:
produto com menor preço
Calcular:
média de preços dos produtos
Mostrar:
produtos com estoque baixo
Exemplo:
estoque menor que 5

*/



#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 10

//Variáveis Globais

//Estruturas
typedef struct {
    char nome[50]; 
    float preco;
    int estoque;
}Produto;



// ==========================
// FUNÇÃO PARA VALIDAR PREÇO
// ==========================
float lerPreco()
{
    float preco;

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco);

        if (preco < 0)
        {
            printf("Preco invalido!\n");
        }

    } while (preco < 0);

    return preco;
}


// ====================================
// Função limpa o char e valida entrada
// ====================================
void limparTexto()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ============================
// Clicar enter para continuar
// ============================
void esperarEnter()
{
    printf("\nPressione ENTER para continuar...");
    limparTexto();
    getchar();
}

// =============================
// FUNÇÃO PARA VALIDAR ESTOQUE
// =============================
int lerEstoque()
{
    int estoque;

    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque);

        if (estoque < 0)
        {
            printf("Quantidade invalida!\n");
        }

    } while (estoque < 0);

    return estoque;
}

// ==========================
// FUNÇÃO PARA CADASTRAR
// ==========================
int cadastrarProduto(Produto cadastro[],int total)
{
    int i = total;

    // Verifica limite máximo
    if (total >= MAX)
    {
        printf("\nLimite maximo de produtos atingido!\n");
        return total;
    }

    getchar();

    printf("\n\n===== CADASTRO DE PRODUTO =====\n");

    // Cadastro do nome
    do
    {
        printf("Nome do produto: ");
        fgets(cadastro[i].nome, 50, stdin);

        cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';

        if (strlen(cadastro[i].nome) == 0)
        {
            printf("Nome nao pode ser vazio!\n");
        }

    } while (strlen(cadastro[i].nome) == 0);

    // Cadastro do preço
    cadastro[i].preco = lerPreco();

    // Cadastro do estoque
    cadastro[i].estoque = lerEstoque();

    // Incrementa quantidade de produtos
    total++;

    printf("\nProduto cadastrado com sucesso!");
    printf("\n================================");

    return total;
}

// ===========================
// FUNÇÃO PARA LISTAR PRODUTOS
// ===========================
void lista(Produto cadastro[], int total)
{
    printf("\n\n=========== LISTA DE PRODUTOS ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n========================================"); 
        return;
    }

    for (int i=0;i<total;i++)
    {
        printf("\nProduto: %s  Preço do produto: R$%.2f  Quantidade em Estoque: %d",cadastro[i].nome,cadastro[i].preco,cadastro[i].estoque);
    }

    printf("\n========================================"); 
}

// ===========================
// FUNÇÃO PARA BUSCAR PRODUTO
// ===========================
int buscar(Produto cadastro[], int total)
{
    char nome[50] = "vazio";

    printf("\n\n========== BUSCA DE PRODUTOS ========\n");

    if (total == 0)
    {
        printf("Nenhum produto cadastrado.");
        return -1;
    }

    getchar();

    //Salvar nome para buscar
    do
    { 
        printf("Qual produto quer buscar? ");
        fgets(nome, 50, stdin);

        nome[strcspn(nome, "\n")] = '\0';

        if (strlen(nome) == 0)
        {
            printf("\nNome nao pode ser vazio!");
        }

    } while (strlen(nome) == 0);

    //Buscar produto
    for (int i=0;i<total;i++)
    {
        if (strcmp(cadastro[i].nome, nome) == 0)
        {
            return i;
        }
    }

    printf("Produto não encontrado!");

    return -1;
}

// ==========================
// FUNÇÃO VALOR TOTAL
// ==========================
void valorTotal(Produto cadastro[], int totalProdutos)
{
    float total = 0;

    if (totalProdutos == 0)
    {
        printf("\n\n=============================================\n");
        printf("Nenhum produto cadastrado.");
        printf("\n=============================================");
        return;
    }

    for (int i=0;i<totalProdutos;i++)
    {
        total = total + (cadastro[i].preco * cadastro[i].estoque);
    }

    printf("\n\n=============================================\n");
    printf("O valor total em estoque é R$%.2f.",total);
    printf("\n=============================================");
}

// ==========================
// FUNÇÃO PRODUTO MAIS CARO
// ==========================
void produtoMaisCaro(Produto cadastro[], int total){

    float maior=0;
    int posProduto = 0;
    int empatado = 0;
    int produtosEmpatados[MAX];

    printf("\n\n=========== Produto mais caro ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n=========================================");
        return;
    }

    //Achar o maior valor
    for (int i=0;i<total;i++)
    {              
        if (cadastro[i].preco > maior)
        {
            maior = cadastro[i].preco;
            posProduto = i;
        }
    }

    //Ver quantos produtos tem o maior valor
    for (int i=0;i<total;i++)
    {
        if (cadastro[i].preco == maior)
        {
            produtosEmpatados[empatado] = i;
            empatado++;
        }
    }

    if (empatado > 1)
    {
        printf("\nMensagem do sistema: %d produtos tem o mesmo valor e são os mais caros do estoque:",empatado);

        for (int i=0;i<empatado;i++)
        {
            printf("\n\nNOME DO PRODUTO: %s",cadastro[produtosEmpatados[i]].nome);
            printf("\nPreço: R$%.2f",cadastro[produtosEmpatados[i]].preco);
            printf("\nQuantidade: %d",cadastro[produtosEmpatados[i]].estoque);
        }
     }

     else {
        printf("\nNOME DO PRODUTO: %s",cadastro[posProduto].nome);
        printf("\nPreço: R$%.2f",cadastro[posProduto].preco);
        printf("\nQuantidade: %d",cadastro[posProduto].estoque);
     }

     printf("\n=========================================");
}

// ==========================
// FUNÇÃO PRODUTO MAIS BARATO
// ==========================
void produtoMaisBarato(Produto cadastro[], int total)
{
    float menor = cadastro[0].preco;
    int posProduto = 0;
    int empatado = 0;
    int produtosEmpatados[MAX];

    printf("\n\n=========== Produto mais barato ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n=========================================");
        return;
    }

    //Achar o menor valor
    for (int i=0;i<total;i++)
    {              
        if (cadastro[i].preco < menor)
        {
            menor = cadastro[i].preco;
            posProduto = i;
        }
    }

    //Ver quantos produtos tem o menor valor
    for (int i=0;i<total;i++)
    {
        if (cadastro[i].preco == menor)
        {
            produtosEmpatados[empatado] = i;
            empatado++;
        }
    }

    if (empatado > 1)
    {
        printf("\nMensagem do sistema: %d produtos tem o mesmo valor e são os mais baratos do estoque:",empatado);

        for (int i=0;i<empatado;i++)
        {
            printf("\n\nNOME DO PRODUTO: %s",cadastro[produtosEmpatados[i]].nome);
            printf("\nPreço: R$%.2f",cadastro[produtosEmpatados[i]].preco);
            printf("\nQuantidade: %d",cadastro[produtosEmpatados[i]].estoque);
        }
     }

     else {
        printf("\nNOME DO PRODUTO: %s",cadastro[posProduto].nome);
        printf("\nPreço: R$%.2f",cadastro[posProduto].preco);
        printf("\nQuantidade: %d",cadastro[posProduto].estoque);
     }

     printf("\n=========================================");
}

// ==========================
// FUNÇÃO MÉDIA DE PREÇOS
// ==========================
void mediaPrecos(Produto cadastro[], int total)
{
    float soma = 0;
    float media;

    printf("\n\n=========== Média de preços ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n=========================================");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        soma += cadastro[i].preco;
    }

    media = soma / total;

    printf("\nMédia de preços: R$%.2f", media);
    printf("\n=========================================");
}

// ==========================
// FUNÇÃO PRODUTOS COM ESTOQUE BAIXO
// ==========================
void produtosEstoqueBaixo(Produto cadastro[], int total)
{
    int limiteEstoque = 5; // Exemplo: produtos com estoque menor que 5
    int encontrados = 0;

    printf("\n\n=========== Produtos com estoque baixo ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n=========================================");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        if (cadastro[i].estoque < limiteEstoque)
        {
            if (encontrados == 0)
            {
                printf("\nOs seguintes produtos têm estoque baixo:");
            }
            printf("\n\nNOME DO PRODUTO: %s", cadastro[i].nome);
            printf("\nPreço: R$%.2f", cadastro[i].preco);
            printf("\nQuantidade: %d", cadastro[i].estoque);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\nNenhum produto com estoque baixo encontrado.");
    }

    printf("\n=========================================");
}

// ===============================
// FUNÇÃO ALTERAR DADOS DO PRODUTO
// ===============================
void alterarDadosProduto(Produto cadastro[], int total)
{
    int posicao;

    printf("\n\n=========== Alterar dados do produto ==========");

    if (total == 0)
    {
        printf("\nNenhum produto cadastrado.");
        printf("\n=========================================");
        return;
    }

    posicao = buscar(cadastro, total);

    if ((posicao >= 0) && (posicao < total))
    {
        printf("\nProduto encontrado:");
        printf("\n\nNOME DO PRODUTO: %s", cadastro[posicao].nome);
        printf("\nPreço: R$%.2f", cadastro[posicao].preco);
        printf("\nQuantidade: %d", cadastro[posicao].estoque);

        // Solicitar novos dados
        printf("\n\nDigite os novos dados do produto:");
        printf("\nNome: ");
        limparTexto();
        scanf("%[^\n]", cadastro[posicao].nome);
        printf("Preço: ");
        scanf("%f", &cadastro[posicao].preco);
        printf("Quantidade: ");
        scanf("%d", &cadastro[posicao].estoque);
    }
    else
    {
        printf("\n=====================================");
    }

    printf("\n=========================================");
}

// ==========================
// MENU
// ==========================
void mostrarMenu()
{
    printf("\n\n=============================\n");
    printf(" SISTEMA DE PRODUTOS\n");
    printf("=============================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("6 - Produto mais barato\n");
    printf("7 - Média de preços\n");
    printf("8 - Produtos com estoque baixo\n");
    printf("9 - Alterar dados do produto\n");
    printf("0 - Sair\n");
}

int lerOpcao()
{
    int opcao;
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// ========================== 
// FUNÇÃO PRINCIPAL
// ==========================
int main()
{
    SetConsoleOutputCP(65001);

    //Setando Cadastro
    Produto cadastro[MAX];

    //Inicializando os cadastros
    for(int i = 0; i < MAX; i++)
    {
        strcpy(cadastro[i].nome, "Sem cadastro");
        cadastro[i].preco = 0;
        cadastro[i].estoque = 0;
    }
    
    //Variáveis
    int total = 0;
    int opcao;
    

    //Loop do Menu
    do
    {
        system("cls");
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao)
        {

        case 1:
            total = cadastrarProduto(cadastro,total);
            esperarEnter();
            break;

        case 2:
            lista(cadastro,total);
            esperarEnter();
            break;

        case 3:
        {
            int posProduto = buscar(cadastro,total);

            if((posProduto >= 0) && (posProduto < total) )
            {
                printf("\nProduto: %s",cadastro[posProduto].nome);
                printf("\nPreço: R$%.2f",cadastro[posProduto].preco);
                printf("\nQuantidade: %d",cadastro[posProduto].estoque);
            }
            else
            {
                printf("\n=====================================");
            }

            esperarEnter();
            break;
        }

        case 4:
            produtoMaisCaro(cadastro,total);
            esperarEnter();
            break;

        case 5:
            valorTotal(cadastro,total);
            esperarEnter();
            break;
        case 6:
            produtoMaisBarato(cadastro,total);
            esperarEnter();
            break;
        case 7:
            mediaPrecos(cadastro,total);
            esperarEnter();
            break;
        case 8:
            produtosEstoqueBaixo(cadastro,total);
            esperarEnter();
            break;
        case 9:
            alterarDadosProduto(cadastro,total);
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