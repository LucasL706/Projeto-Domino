//Dom-MSFT2-view.cpp: Felipe Carvalho Paleari, Joao Pedro Basso Coura, Joao Pedro de Souza Oliveira, Lucas Lombardi de Brito

#include "Dom-MSFT2-View.h"
//função que apresenta as opções do menu
int menuGeral()
{
   int auxiliar;
   int op;
    do
    {
    auxiliar = 0;

    printf("\n\n");
		printf("------------------------Menu-----------------------\n");   //Menu do programa
		printf("|  (1) - Iniciar Jogo (2 jogadores)               |\n");
		printf("|  (2) - Iniciar jogo (contra o computador)       |\n");
        printf("|  (3) - Retornar ao jogo interrompido            |\n");
        printf("|  (4) - Regras gerais do Jogo                    |\n");
        printf("|  (5) - Salvar o jogo                            |\n");
        printf("|  (6) - Recuperar o jogo salvo                   |\n");
        printf("|  (0) - Sair                                     |\n");
		printf("---------------------------------------------------\n");
		printf("Digite sua opcao: ");
		scanf("%d", &op);
		flush_in();
		if(op < 0 || op > 6)
        {
            mensagens('8');
        }
        else
            auxiliar = 1;
    }while(auxiliar != 1);
		return op;
}

//função que apresenta as peças do jogador que possui a vez
void apresentarPeca()
{
    int op = 1;

    printf("Jogador %c:     ",jogador);
    for(int i=0;i<28;i++)
        if(peca[i].status == jogador)
            {
            printf("%d.[%d|%d]   ",op,peca[i].lado1,peca[i].lado2);  //TIRAR O CHAR DEPOIS
            op++;
            }

}

//função que mostra a mesa e o jogador que realiza o primeiro lance.
void mostraMesa()
{
   if((qtdpecaMesa == 1) && (aux4 ==  1))
   {
       printf("\nO primeiro lance foi do jogador %c",primeiroJogador);       //mostrar quem fez a primeira jogada
   }
   printf("\n\n===============");
   printf("\nM E S A: ");
   for(int i = 0; i<qtdpecaMesa;i++)
   {
       printf("[%d|%d] ",mesa[i].lado1,mesa[i].lado2);       //TIRAR O CHAR DEPOIS
       extreEsq = mesa[0].lado1;
       extreDir = mesa[i].lado2;
   }
   printf("\n===============");

    printf("\n");
    printf("\n");
}

//função que apresenta as opções do jogador durante seu turno
int subMenu()
{
    int op3;
    printf("\n");
    printf("\n(1)- Jogar (possiveis: %d e %d)",extreEsq, extreDir);
    printf("\n(2)- Comprar");
    printf("\n(3)- Passar");
    printf("\n(0)- Sair(interromper o jogo)");
    printf("\n\nOpcao: ");
    scanf("%d", &op3);
    return op3;

}

//corresponde a qual peca o jogador vai escolher
int escolhadaPeca()
{
    int opPeca; //opção em que a peca escolhida esta

    printf("Jogador %c: Escolha a peca para jogar (0 para desistir): ",jogador); //mostrar qual jogador ele ta se referindo
    scanf("%d", &opPeca);
    return opPeca;
}

//da a opcao do jogador escolher o lado da mesa que ele deseja jogar
char escolhaLadoMesa()
{
    char op;

    printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D) ");
    scanf("%s",&op);

    return op;
}


//Informa ao usuario de algum erro ocorrido
void mensagens(char op)
{
    switch (op)
    {
    case '1':
        printf("\n--------------------------------------------------\n");
        printf("\nAinda nao e possivel passar a vez, compre uma peca\n");
        printf("\n--------------------------------------------------\n");
        break;
    case '2':
        printf("\n--------------------------------------------------\n");
        printf("\nNao ha pecas disponiveis para compra \n");
        printf("\n--------------------------------------------------\n");
        break;
    case '3':
        printf("\n--------------------------------------------------\n");
        printf("\nA peca e invalida");
        printf("\n--------------------------------------------------\n");
        break;
    case '4':
        printf("\n--------------------------------------------------\n");
        printf("\nPARABENS JOGADOR 1, VOCE GANHOU");
        printf("\n--------------------------------------------------\n");
        break;
    case '5':
        printf("\n--------------------------------------------------\n");
        printf("\nPARABENS JOGADOR 2, VOCE GANHOU");
        printf("\n--------------------------------------------------\n");
        break;
    case '6':
        printf("\n--------------------------------------------------\n");
        printf("\nVoce possui uma peca que pode ser jogada, por favor faca a jogada");
        printf("\n--------------------------------------------------\n");
        break;
    case '7':
        printf("\n--------------------------------------------------\n");
        printf("\nVoce nao tem essa peca");
        printf("\n--------------------------------------------------\n");
        break;
    case '8':
        printf("\n--------------------------------------------------\n");
        printf("\nOpcao invalida");
        printf("\n--------------------------------------------------\n");
        break;
    case '9':
        printf("\n--------------------------------------------------\n");
        printf("\nJogo Salvo");
        printf("\n--------------------------------------------------\n");
        break;
    }
}

void primeiroLance()
{
    if((qtdpecaMesa == 1) && (aux4 ==  1))
    {
       printf("\nO primeiro lance foi do jogador %c",primeiroJogador);       //mostrar quem fez a primeira jogada
    }
}
