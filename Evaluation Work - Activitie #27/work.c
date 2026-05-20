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

*/



#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 10

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
int cadastrarProduto(char nomes[][50],float precos[],int estoques[],int total)
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
        fgets(nomes[i], 50, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        if (strlen(nomes[i]) == 0)
        {
            printf("Nome nao pode ser vazio!\n");
        }

    } while (strlen(nomes[i]) == 0);

    // Cadastro do preço
    precos[i] = lerPreco();

    // Cadastro do estoque
    estoques[i] = lerEstoque();

    // Incrementa quantidade de produtos
    total++;

    printf("\nProduto cadastrado com sucesso!");
    printf("\n================================");

    return total;
}
// ===========================
// FUNÇÃO PARA LISTAR PRODUTOS
// ===========================
void lista(char *nome, float preco, int quantidade)
{
    printf("\nProduto: %s  Preço do produto: R$%.2f  Quantidade em Estoque: %d",nome,preco,quantidade);
    
}
// ===========================
// FUNÇÃO PARA BUSCAR PRODUTO
// ===========================
int buscar(char nomes[][50])
{
    char nome[50] = "vazio";
    printf("\n\n========== BUSCA DE PRODUTOS ========\n");
    //Nome do produto
    do
    { 
        printf("Qual produto quer buscar? ");
        getchar();
        fgets(nome, 50, stdin);

        nome[strcspn(nome, "\n")] = '\0';

        if (strlen(nome) == 0)
        {
            printf("\nNome nao pode ser vazio!");
        }

    } while (strlen(nome) == 0);
    //Buscar produto
    for (int i=0;i<MAX;i++){
        if (strcmp(nomes[i], nome) == 0){
            return i;
        }
    }
    printf("Produto não encontrado!");
    return -1;
}
// ==========================
// FUNÇÃO VALOR TOTAL
// ==========================
void valorTotal(float precos[],int estoques[])
{
    float total = 0;
    for (int i=0;i<MAX;i++){
        total = total + (precos[i] * estoques[i]);
    }
    printf("\n\n=============================================\n");
    printf("O valor total em estoque é R$%.2f.",total);
    printf("\n=============================================");
}
// ==========================
// MENU
// ==========================
void menu()
{
    printf("\n\n=============================\n");
    printf(" SISTEMA DE PRODUTOS\n");
    printf("=============================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}
// ==========================
// FUNÇÃO PRINCIPAL
// ==========================
int main()
{
    SetConsoleOutputCP(65001);
    char nomes[MAX][50] = {"Sem cadastro", "Sem cadastro","Sem cadastro","Sem cadastro",
                            "Sem cadastro","Sem cadastro","Sem cadastro","Sem cadastro",
                            "Sem cadastro","Sem cadastro"};
    float precos[MAX];
    int estoques[MAX];

    int total = 0;
    int opcao;
    
    //Inicializando Variáveis
    for (int i=0;i<MAX;i++){
        precos[i] = 0;
        estoques[i] = 0;
    }

    do
    {
        menu();

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            total = cadastrarProduto(
                nomes,
                precos,
                estoques,
                total);
            break;

        case 2:
            printf("\n\n=========== LISTA DE PRODUTOS ==========");
            for (int i=0;i<MAX;i++){
                lista(nomes[i],precos[i],estoques[i]);
            }
            printf("\n========================================");
            break;

        case 3:
            int posProduto = buscar(nomes);
            if((posProduto >= 0) & (posProduto <= MAX) ){
                printf("\nProduto: %s",nomes[posProduto]);
                printf("\nPreço: R$%.2f",precos[posProduto]);
                printf("\nQuantidade: %d",estoques[posProduto]);
                printf("\n=====================================");
            }
            printf("\n=====================================");
            break;

        case 4:
            // IMPLEMENTAR
            break;

        case 5:
            valorTotal(precos,estoques);
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