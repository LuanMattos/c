#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include "funcoes.h"
#include <sys/types.h>
#include <winsock2.h>
#include <string.h>

#define AQUI_CONSTANTE = 5

#pragma comment(lib,"ws2_32.lib")

typedef struct{
    char name;
    int id;
    char address;
} Pessoa;

MAPA m;

void main(){
    // Teste de comentário
    printf("*********************************************\n");
    printf("***********Jogo de adivinhacao***************\n");
    printf("**********************************************\n");
    int numerosecreto = 42;
    int chute;
    printf("Variavel nao inicializada, note o endereco na memoria %d \n",chute);
    printf("Aqui entrada\n");
    scanf("%d", &chute);
    printf("Sua entrada digitada eh %d \n",chute);

    double pi = 3.1415;
    printf("Aqui um double %f \n",pi);
    float pidois = 3.1415;
    printf("Aqui um float %f \n",pidois);   
    int numeroum = 3;
    double operacao = (numeroum / 2);
    // Aqui temos um erro mais comum no C, lembrando que o código é executado sempre da direita para a esquerda
    printf("Exemplo de operacao errada %f \n", operacao);
    // Por isso vai dar caca, para resolver isso botamos o número como double
    int numeroumcorreto = 3;
    double operacaocorreta = numeroumcorreto / 2.0;
    printf("Exemplo de operacao correta %f \n",operacaocorreta);
    printf("Para deixar mais amigavel %.1f \n", operacaocorreta);
    printf("Para deixar mais amigavel part2 %.2f \n", operacaocorreta);

    /** 
        Relembrando alguns conceitos: 
        Inteiros
            short 2 bytes
            int 4 bytes = 32 bits = 2³²
            long 8 bytes = 64 bits = 2 na 64
        
        Ponto flutuante
            double 8 bytes
            float 4 bytes
    **/
    //Casting - mesm coisa que PHP
    int a = 3;
    int b = 5;
    double pontos = a / (double)b;
    printf("%f \n",pontos);
    //Converter negativo para positivo
    int negativo = -5;
    printf("%d \n",abs(negativo));

    int segundos = time(0);
    srand(segundos);
    int randomico = rand();
    
    printf("%d \n",randomico % 100);

    
    // For mesma coisa que PHP
    // If mesma coisa que PHP
    // break; para execução
    // continue; Volta para o início da execução
    //switch case -> mesmo do PHP

    char texto = 'M';
    printf("%c \n", texto);

    int notas[10];
    notas[0] = 0;
    notas[1] = 100;
    notas[2] = 200;
    printf("Notas %d %d %d \n ", notas[0], notas[1], notas[2]);

    //strlen() -> Length String
    // Toda vez que fazer scanf colocamos um espaço antes para ignorar o Enter, pois se não botar, fica no buffer
    char entrada;
    // scanf("%c", &entrada);
    scanf(" %c", &entrada);
    int variavelmesmonomedavariaveldafuncao = 1;
    umaFuncao(variavelmesmonomedavariaveldafuncao);

    /** PONTEIROS **/
    /**
        Note que o resultado será 10 | 10 | 11 | 10 porque a variavel numero do main não está no mesmo endereço de memória da função ponteiro
        Para pegar o endereço de memória usamos &
        Como parametro botamos &param e na função em si botamos int* param
        O * no int* pega o conteúdo do endereço, ou seja, o ponteiro
    **/
    int numero = 10;
    printf("-------PONTEIRO------- \n");
    printf("---------- main %d  no endereco de memoria %d \n", numero , &numero);
    ponteiro(numero);
    ponteiroEstrela(&numero);
    printf("---------- main %d no endereco de memoria %d \n", numero, &numero);
    /**
        Como um array é um ponteiro, não precisamos usar seu endereço como antes
    **/
    printf("-------PONTEIRO E ARRAYS------- \n");
    int i;
    int testeponteiroarray[3];
    testeponteiroarray[0]=0;
    testeponteiroarray[1]=1;
    testeponteiroarray[2]=2;
    int tamanhoarray = sizeof(testeponteiroarray)/sizeof(testeponteiroarray[0]); 
    for(i=0;i < tamanhoarray; i++){
        ponteiroArray(i, testeponteiroarray);
        printf("------Dentro do for INDEX %d %d \n",i, testeponteiroarray[i]);
    }
    /* 
        Header Files
        -Sabemos que o compilador do C executa tudo de cima para baido da direita para a esquerda,
        -Se instanciar uma função antes de ela ser criada vai dar erro no compilador
        -Para contonar isso colocamos assinatura da função acima através de um arquivo.h (não esquecer do include)
    */
    funcaoDeclaradaEmbaixo();
    /** 
        Lendo arquivos
        -fopen nos devolve um ponteiro
        -fscanf -> file scan f
     **/
    char palavrasecreta;
    FILE* f;
    f = fopen("palavras.txt","r");
    if (f == 0){
        printf("Banco de dados nao disponivel \n");
        exit(1);
    }
    int qtdpalavras;
    /* %d porque ele vai ler apenas inteiro */
    char arquivo[100];
	char textoainserir[100];
    FILE * pFile;
    printf("Informe o arquivo(COM CAMINHO) que você deseja escrever: \n");
    scanf("%s", &arquivo);
    pFile = fopen(arquivo , "w");
    if(pFile!=NULL){
        printf("Digite o que você deseja pôr no arquivo(SEM ESPAÇOS): \n");
        scanf("%s", &textoainserir);
        fputs(textoainserir, pFile);
        fclose(pFile);
    }
    /** 
        Alocação dinâmica de memória
        Sabemos muito bem que int tem 4 bytes, mas e se eu quiser algo mais dinamico
        Sempre que alocar memoria devemos fechar
        Como exemplo botei o mairo número que pode ser representado por um inteiro
     **/
     int* v = malloc(sizeof(int));
    //  ou
    //  int* v = malloc(4);
     *v = 2147483647;
     printf("%d \n",*v);
     free(v);
     /**
        Memória
        O Heap é a memória durante a execução do programa (runtime), ou seja, memória dinamicamente alocada para o programa
            Digamos que HEAP é a memória global do programa
            O Heap é mais bagunçado e mais flexivel, imagine um monte de livros organizados de qualquer maneira
            Por isso usamos a função free depois de alocar dinamicamente uma variavel com malloc
        Já a stack é onde alocamos os ponteiros conforme a imagem memoria.jpg
            Podemos dizer então que representa a memória local àquela função 
            A stack é realmente uma pilha
            A stack é apagada no fim da execução do programa
     **/
     /** 
        Como alocar um array de 50 posições dinamicamente com malloc
        Lembrando, esse array podera ter um tamanho máximo de um inteiro, e ficará na stack, poranto deve ser liberado logo após
        E Matriz ?
        Matriz é um ponteiro de ponteiro, ou ponteiro de ponteiro de... (depende da dimensão)

     **/
     int* arraydinamico = malloc(sizeof(int) *  50);
     arraydinamico[0] = 10;
     arraydinamico[1] = 10000000;
     arraydinamico[2] = 840;
     printf("Array dinamico %d %d %d \n", arraydinamico[0],arraydinamico[1],arraydinamico[2]);
     free(arraydinamico);
     /** Struct e typedef - conjunto de variáveis (Exemplo acima) **/
     Pessoa Aluno;
     Aluno.id = 15;
     printf("%d", Aluno.id);

    /** Ponteiros de Struct **/
    /**  Contrário do que dizia o curso, não precisamos, por algum motivo mover ponteiro para structs de outro arquivo para usa-lo**/
    /** Podemos usar também  m->colunas (não funcionou no curso) **/
    printf("%d", m.colunas);
    printf("%d",m.matriz);

}

void funcaoDeclaradaEmbaixo(){
    printf("Header Files \n");
}
void umaFuncao(int variavelmesmonomedavariaveldafuncao){
    variavelmesmonomedavariaveldafuncao++;
    printf("No C temos que ter cuidado com funcoes que possuem mesmo nome de variavel do codigo onde sera instanciada %d \n",variavelmesmonomedavariaveldafuncao);
    printf("Perceba que se for o mesmo nome, o escopo sera tambem o mesmo para o parametro \n");
}
void ponteiroEstrela(int* numero){
    (*numero)++;
    printf("---------- Aqui pegamos a variavel de acordo com seu endereco %d %d \n", numero, (*numero));
    printf("---------- Perceba que agora sim a variavel da funcao main eh modificada \n");
}
void ponteiro(int numero){
    printf("---- Primeira execucao do numero %d no endereco de memoria %d \n", numero, &numero);
    numero++;
    printf("---- Segunda execucao do numero %d no endereco de memoria %d \n", numero, &numero);
}
void ponteiroArray(int index, int testeponteiroarray[3]){
  testeponteiroarray[index]++;
  printf("O valor do index %d eh %d \n",index, testeponteiroarray[index]);  
}
