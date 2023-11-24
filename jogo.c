#include <stdio.h>//bliblioteca para ler e escrever nescessarimente
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){

    /*escreve somente*/
    printf("*********************\n");
    printf("Jogo da adivinhacao\n");
    printf("*********************\n");

    srand(time(NULL));
    short numeroSecreto = rand() % 100 + 1;

    //variavel chute
    int chute;

    //vriavel tentativas
    int tentativas = 1;

    //variavel pontos
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int acertou = 0;
    short numeroTentativas;

    switch(nivel){
        case 1:
            numeroTentativas = 18;
            break;
        case 2:
            numeroTentativas = 10;
            break;
        default:
            numeroTentativas = 6;
            break;
    }

    //Faca enquanto for verdadeira, no caso para sempre
    for(int i = 1; i <= numeroTentativas; i++){
        //escreve o numero de tentativas
        printf("tentativa %d\n", tentativas);
        //escreve
        printf("Qual seu chute?\n");

        //coloca o chute na variavel chute
        scanf(" %d", &chute);
        //escreve o chute na tela
        printf("seu chute foi %d\n", chute);

        //se chute for menor do que zero, manda mensagem de erro e continua.
        if(chute < 0){
            printf("Voce nao pode chutar numeros negativs\n");
            continue;
        }

        //variavel acertou que recebe um valor boleano
        acertou = (chute == numeroSecreto);
        //maior recebe valor boleano
        int maior = chute > numeroSecreto;

        //se acertou for verdadeiro sai do while.
        if(acertou){
            break;
        //se maior for verdadeiro manda msg e prossegui
        }else if(maior){
            printf("Seu chute foi maior que o numero secreto\n");
        //prossegui
        }else{
            printf("Seu chute foi menor que o numero secreto\n");
        }

        //soma tentativas + 1
        tentativas ++;

        //pontosPerdidos é a diferença do chute para o numeroS.. e dividido por 2
        double pontosPerdidos = (chute - numeroSecreto) / (double)2;//vai ler o 2 como double em vez de inteiro
        //atribui pontos novos
        pontos = pontos - abs(pontosPerdidos);
    }

    printf("Fim de jogo!\n\n");
    if(acertou){
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo!\n");
    }

    sleep(8);

    system("clear");
}
/*
// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    // declarando variaveis que serao usadas mais a frente
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;

    // definindo a quantidade de pontos inicial
    double pontos = 1000;

    // gerando um numero secreto aleatorio
    srand(time(0));
    int numerosecreto = rand() % 100;

    // escolhendo o nivel de dificuldade
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel) {
        case 1: 
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    // loop principal do jogo
    for(int i = 1; i <= totaldetentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um número: ");
        scanf("%d", &chute);

        // tratando chute de numero negativo
        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }

        // verifica se acertou, foi maior ou menor
        acertou = chute == numerosecreto;

        if(acertou) {
            break;
        } else if(chute > numerosecreto) {
            printf("\nSeu chute foi maior do que o número secreto!\n\n");
        } else {
            printf("\nSeu chute foi menor do que o número secreto!\n\n");
        }

        // calcula a quantidade de pontos
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    // imprimindo mensagem de vitoria ou derrota
    printf("\n");
    if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns! Você acertou!\n");
        printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nVocê perdeu! Tente novamente!\n\n");
    }


}
*/