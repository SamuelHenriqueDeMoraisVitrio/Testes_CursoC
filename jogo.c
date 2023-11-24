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

    //Faca enquanto for verdadeira, no caso para sempre
    while(1){
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
        int acertou = (chute == numeroSecreto);
        //maior recebe valor boleano
        int maior = chute > numeroSecreto;

        //se acertou for verdadeiro sai do while.
        if(acertou){
            printf("Parabens! Voce acertou\n");
            printf("Jogue de novo, voce e um bom jogador!\n");

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

    printf("Fim de jogo!\n");
    printf("Voce acertou em %d tentativas\n", tentativas);
    printf("Total de pontos = %.2f \n", pontos);

    sleep(8);

    system("clear");
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    srand(time(0));
    int numerosecreto = rand() % 100;

    while(!acertou) {

        printf("Qual é o seu %do. chute? ", tentativas);
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        printf("Seu %do. chute foi %d\n", tentativas, chute);

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
        } else if(maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("Você fez %.2f pontos", pontos);
    printf("Obrigado por jogar!\n");

}
*/