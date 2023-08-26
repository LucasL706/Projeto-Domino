//Dom-MSFT2-model.cpp: Felipe Carvalho Paleari, Joao Pedro Basso Coura, Joao Pedro de Souza Oliveira, Lucas Lombardi de Brito

struct domino //estrutura de informacoes do domino
{
    int lado1;
    int lado2;
    char status;
};
struct domino mesa[28]; //Matriz das pecas da mesa
struct domino peca[28]; //Matriz das pecas do jogo
struct domino aux;      //variável que guarda o valor do vetor que trocara de posiçao
int extreDir;    //extremidade direita da mesa
int extreEsq;    //extremidade esquerda da mesa
int qtdpecaMesa;     // quantas pecas tem na mesa
char jogador;
struct domino pecaEscolhida;
char primeiroJogador;
struct domino aux2;
int aux4;                   //pra mostrar só o primeiro lance
int aux1;                   //para trocar o status da mesa quando ela for lançada
int auxCompra;
int vencedor;   // pra sair do menu
int aux3;   //para mudar o status da peça
FILE *fp;


struct salvamento
{
    int sextreDir;    //extremidade direita da mesa
    int sextreEsq;    //extremidade esquerda da mesa
    int sqtdpecaMesa;     // quantas pecas tem na mesa
    char sjogador;
    int sauxCompra;
    char ssentinela;
};

struct salvamento jogo;
char sentinela;


