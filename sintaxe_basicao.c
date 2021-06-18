#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AQUI_CONSTANTE = 5
int main(){
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
    
    printf("%d",randomico % 100);

    
    // For mesma coisa que PHP
    // If mesma coisa que PHP
    // break; para execução
    // continue; Volta para o início da execução
    //switch case -> mesmo do PHP



}