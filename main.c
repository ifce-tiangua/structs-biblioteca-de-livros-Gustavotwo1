#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strutura livro
typedef struct{

    char titulo[100];
    char isbn[50];
    float preco;
    int score;
    char editora[50];

} Tlivro;

//Definição de um tipo struct livro para ponteiro 
typedef Tlivro* Plivro;

Plivro PontLivro(int qtde);
void lerDados(Plivro livro, int qtde);
void mostrarDados(Plivro livro, int qtde);
void liberarAlloc(Plivro livro);

int main(){

    int quantidade;

    scanf("%d", &quantidade);
    getchar();

    if(quantidade == 0){

        printf("Sem livros");

        return 0;

    }

    Plivro livros = PontLivro(quantidade);
    lerDados(livros, quantidade);
    mostrarDados(livros, quantidade);
    liberarAlloc(livros);
    
    return 0;
}

Plivro PontLivro(int qtde){

    return (Plivro)malloc(qtde * sizeof(Tlivro));

}

void lerDados(Plivro livro, int qtde){

    int i;
    //ler cada ponteiro de cada campo da struct livro
    for(i=0; i<qtde; i++){

        //usando o fgets para ler os espaços
        //nome do livro[i]
        fgets(livro[i].titulo, sizeof(livro[i].titulo), stdin);
        //substiruindo o '\n' pelo '\0' 
        livro[i].titulo[strcspn(livro[i].titulo, "\n")] = '\0'; 

        //ISBN do livro[i]
        fgets(livro[i].isbn, sizeof(livro[i].isbn), stdin);
        //substiruindo o '\n' pelo '\0' 
        livro[i].isbn[strcspn(livro[i].isbn, "\n")] = '\0'; 

        //preço do livro[i]
        scanf("%f", &livro[i].preco);
        getchar();

        //score do livro[i]
        scanf("%d", &livro[i].score);
        getchar();

        //editora do livro[i]
        fgets(livro[i].editora, sizeof(livro[i].editora), stdin);
        //substiruindo o '\n' pelo '\0' 
        livro[i].editora[strcspn(livro[i].editora, "\n")] = '\0'; 

    }

}

void mostrarDados(Plivro livro, int qtde){

    int i;
    for(i=0; i<qtde; i++){

        printf("Livro %d:\n", i+1);
        printf("Nome: %s\n", livro[i].titulo);
        printf("ISBN: %s\n", livro[i].isbn);
        printf("Preço: R$ %.2f\n", livro[i].preco);
        printf("Score: %d\n", livro[i].score);
        printf("Editora: %s\n", livro[i].editora);
        printf("\n");

    }

}

void liberarAlloc(Plivro livro){

    free(livro);

}
