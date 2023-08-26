//Dom-MSFT2-Controller.cpp: Felipe Carvalho Paleari, Joao Pedro Basso Coura, Joao Pedro de Souza Oliveira, Lucas Lombardi de Brito

#include "Dom-MSFT2-Controller.h"
#include "Dom-MSFT2-View.cpp"



//função de gerar as peças
void gerarPecas()
{
    int limit;
    int numer;
    limit=6;
    numer=0;

    for(int i=0; i<=6; i++) //Criacao da matriz
    {
        for(int j=0; j<=limit; j++)
        {
            peca[numer].lado1=i;
            peca[numer].lado2=i+j;
            peca[numer].status='b';
            numer++;
        }
        limit--;
    }
}

//função de embaralhar peças
void embaralharPecas()
{
    srand(time(NULL));
    int aleat;  //indice aleatorio para embaralhamento das peças

    for(int i=0; i<28; i++)
    {
        aleat = rand()%28;
        aux = peca[i];
        peca[i] = peca[aleat];
        peca[aleat] = aux;

    }
}

//função que torna opções do menu executáveis
void iniciarMenu()
{
    char op1;

    do
    {
        op1 = menuGeral();
        switch(op1)
        {
            case 1:
            {
                sentinela = 'x';
                iniciarJogo();
                mostraMesa();
                apresentarPeca();
                iniciarSubmenu();
                break;
            }
            case 2:
                sentinela = 'r';
                iniciarJogo();
                if(jogador == '1')
                {
                    mostraMesa();
                    apresentarPeca();
                }
                iniciarSubmenu();
                break;
            case 3:
                mostraMesa();
                apresentarPeca();
                iniciarSubmenu();
                break;
            case 4:
                break;
            case 5:
                salvarJogo();
                mensagens('9');
                break;
            case 6:
                recuperarJogo();
                mostraMesa();
                apresentarPeca();
                iniciarSubmenu();
                break;
        }
    }
    while(op1 != 0);
}

//função que torna opções do sub-menu(possíveis ações do jogador em seu turno durante a partida) executáveis
void iniciarSubmenu()
{
    int op2;



    do
    {
        if((jogador == '2') && (sentinela == 'r'))
        {
            jogaComputador();
            //vencedor = 1;//jogada do computador
        }
        else
        {
            op2 = subMenu();
            switch(op2)
            {
                case 1:
                    jogar();
                    break;
                case 2:
                    compraPeca();
                    mostraMesa();
                    apresentarPeca();
                    break;
                case 3:
                    if(auxCompra == 1)
                    {
                        if(verificaMao() == 1)
                        {
                             mensagens('6');    // informa que o jogador tem uma peca que pode ser jogada
                             mostraMesa();
                             apresentarPeca();
                        }
                        else
                        {
                            trocaJogador();
                            mostraMesa();
                            apresentarPeca();
                        }
                    }
                    else
                    {
                        mensagens('1');//'1' manda a mensagem para o usuario dizendo que ainda nao pode passar a vez
                        aux4++;
                        mostraMesa();
                        apresentarPeca();
                    }
                    break;
            }
        }
    }
    while((op2 != 0) && (vencedor == 0));

}

//função responsavel por separar as peças para cada jogador, verificar quem faz a primeira jogada juntamente com a peça que sera lançada automaticamente
void iniciarJogo()
{
    gerarPecas();
    embaralharPecas();
    vencedor = 0;




    int SomaMaior;
    int aux2;               //auxiliar que verifica quem vai começar o jogo,
    aux2=-1;
    aux4=1;
    SomaMaior=-1;           //buscar a peça que possui a maior soma entre os lados
    aux.lado1=-1;           //auxilia na busca por uma peca com dois lados iguais de maior valor possível


    for(int i = 0; i<7; i++)
        peca[i].status = '1';    //Peças do Jogador 1


    for(int j = 7; j<14; j++)
        peca[j].status = '2';    //Peças do Jogador 2


    for(int i = 0; i<14; i++)
    {
        if(peca[i].lado1 == peca[i].lado2)
        {
            if(aux.lado1 < peca[i].lado1)
            {
                aux = peca[i];
                aux2 = i;
            }
        }
    }

    if(aux.lado1 == -1)
    {
        for(int i = 0; i<14; i++)
        {
            if(SomaMaior < peca[i].lado1+peca[i].lado2)
            {
                SomaMaior = peca[i].lado1 + peca[i].lado2;
                aux = peca[i];
                aux2 = i;                                   //guardar os índices pra saber quem vai começar
            }
            else if(SomaMaior == peca[i].lado1 + peca[i].lado2)
            {
                if(aux.lado2 < peca[i].lado2)
                    {
                    aux = peca[i];
                    aux2 = i;           //auxiliar2 recebe o indice da peca
                    }
            }
        }
    }

    primeiroJogador = peca[aux2].status;
    peca[aux2].status = 'm';
    mesa[0] = peca[aux2];





    if(primeiroJogador == '1')
        jogador='2';
    else if(primeiroJogador == '2')
        jogador='1';

    qtdpecaMesa = 1;

    if(sentinela == 'r')
    {
        extreEsq = mesa[0].lado1;
        extreDir = mesa[0].lado2;
    }


}

//permite o jogador escolher a peca que sera jogada
void selecaodaPeca()
{
    int contador;
    int Auxiliar;
    int cont = 0;
    aux1 = 0;

    contador = 0;
    Auxiliar = escolhadaPeca();
    for(int i = 0; i < 28; i++)
        if(peca[i].status == jogador)
            cont++;
    if(Auxiliar > cont)
        mensagens('7');
    else if(Auxiliar != 0)
    {
    for (int i=0;i<28;i++)
    {
        if(peca[i].status == jogador)
        {
            contador++;
            aux3 = i;

            if(contador == Auxiliar)
                {
                    pecaEscolhida = peca[aux3];
                    aux1 = aux3;         //pra sumir da mão do jogador
                }
        }
    }
    verificacaodaPeca();
    aux4 ++;//pra mostrar só o primeiro lance
    }
}

//verifica se peca pode ser ou não jogada
void verificacaodaPeca()
{
    char escolhadoLado;

    if((pecaEscolhida.lado1 == extreEsq) || (pecaEscolhida.lado1 == extreDir) || (pecaEscolhida.lado2 == extreEsq) || (pecaEscolhida.lado2 == extreDir)) // a peca escolhida pode ser jogada
    {
        if(((pecaEscolhida.lado1 == extreDir) && (pecaEscolhida.lado1 == extreEsq)) || ((pecaEscolhida.lado2 == extreDir) && (pecaEscolhida.lado2 == extreEsq)) || ((pecaEscolhida.lado2 == extreDir) && (pecaEscolhida.lado1 == extreEsq)) || ((pecaEscolhida.lado2 == extreEsq) && (pecaEscolhida.lado1 == extreDir)))//essa peca pode ser jogada em qualquer lugar
        {
            escolhadoLado = escolhaLadoMesa(); //opta por jogar na esqueda
            if((escolhadoLado == 'E') || (escolhadoLado == 'e') || (escolhadoLado == 'D') || (escolhadoLado == 'd'))
            {
                if((escolhadoLado == 'E')|| (escolhadoLado == 'e'))
                {
                    if(pecaEscolhida.lado2 == extreEsq)
                    {
                        lancamentoEsquerda();
                    }
                    else if(pecaEscolhida.lado1 == extreEsq)
                    {
                        mudaLado();
                        lancamentoEsquerda();
                    }
                }
                else if((escolhadoLado == 'D') || (escolhadoLado == 'd')) // escolhe jogar na direita
                {
                    if(pecaEscolhida.lado2 == extreDir) // não faz diferença inverter pecas de lados iguais
                    {
                        mudaLado();
                        lancamentoDireita();
                    }
                    else if(pecaEscolhida.lado1 == extreDir)
                    {
                        lancamentoDireita();
                    }
                }
            }
            else
                mensagens('8');
        }
        else // jogadas automaticas
        {
            if(pecaEscolhida.lado1 == extreDir)
            {
                lancamentoDireita();
            }
            else if(pecaEscolhida.lado1 == extreEsq)
            {
                mudaLado();
                lancamentoEsquerda();
            }
            else if(pecaEscolhida.lado2 == extreDir)
            {
                mudaLado();
                lancamentoDireita();
            }
            else if(pecaEscolhida.lado2 == extreEsq)
            {
                lancamentoEsquerda();
            }
        }
    }
    else
        mensagens('3');//  '3' fala que a peca e invalida
}

//faz a jogada
void jogar()
{

    selecaodaPeca();
    if(sentinela != 'r')
    {
        mostraMesa();
        teste();
        if(vencedor == 0)
        {
            apresentarPeca();
        }
    }
    else
    teste();
}

//alterna o lado quando necessario ou solicitado
void mudaLado()
{
    int auxIndice;
    auxIndice = pecaEscolhida.lado1;
    pecaEscolhida.lado1 = pecaEscolhida.lado2;
    pecaEscolhida.lado2 = auxIndice;
}

//mudança de posição quando lançado na esquerda
void lancamentoEsquerda()
{

    qtdpecaMesa++;
    aux = mesa[0];

    for (int i = 0; i < qtdpecaMesa; i++)
    {
        aux2 = mesa[i+1];
        mesa[i+1] = aux;
        aux = aux2;
    }

    mesa[0] = pecaEscolhida;
    mesa[qtdpecaMesa] = aux;
    peca[aux1].status = 'm';
    extreEsq = mesa[0].lado1;
    trocaJogador();
}

//permite o jogador jogar a peca na direita
void lancamentoDireita()
{
    mesa[qtdpecaMesa] = pecaEscolhida;
    mesa[qtdpecaMesa].status = 'm';
    peca[aux1].status = 'm';
    extreDir = mesa[qtdpecaMesa].lado2;
    qtdpecaMesa++;
    trocaJogador();



}

//permite o jogador realizar a compra
void compraPeca()
{
    aux4++;
    int cont;
    cont = 0;
    auxCompra = 0;

    for(int i = 0; i<28;i++)
    {
        if((peca[i].status == 'b') && (cont == 0))
        {
            peca[i].status = jogador;
            cont++;
        }
    }
    if(cont == 0)
    {
        //mensagens('2');// '2' mensagem dizendo que nao ha mais pecas disponiveis para compra
        auxCompra = 1;
        if(((jogador == '1') && (sentinela == 'r')) || (sentinela != 'r'))
        {
            mensagens('2');// '2' mensagem dizendo que nao ha mais pecas disponiveis para compra
        }
    }


}

//inverte o turno do jogo
void trocaJogador()
{
    if(jogador == '1')
    {
        jogador = '2';
    }
    else
        jogador = '1';
}

//verifica quem e o ganhador do jogo
void teste()
{
    vencedor = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int somaMaior1 = 0;
    int somaMaior2 = 0;
    int controlador = 0;
    for(int i =0; i < 28; i++)
    {
        if(peca[i].status == '1')
            cont1++;
        else if(peca[i].status == '2')
            cont2++;
        else if(peca[i].status == 'b')
            cont3++;
    }
    if((cont1 == 0) && (cont3 == 0))
    {
       mensagens('4');//  '4' informa que o jogador 1 ganhou o jogo
        vencedor = 1;
    }
    else if((cont2 == 0) && (cont3 == 0))
    {
        mensagens('5');// '5' informa que o jogador 2 ganhou o jogo
        vencedor = 1;
    }
    else if(cont3 == 0)
    {
        controlador = verificaMaoDosDois();
        if(controlador == 0)
        {
            if((cont1 < cont2) && (cont3 == 0))
            {
                mensagens('4');
                vencedor = 1;
            }

            else if((cont2 < cont1) && (cont3 == 0))
            {
                mensagens('5');
                vencedor = 1;
            }
            else if((cont1 == cont2) && (cont3 == 0))
            {
                for(int i = 0; i<28; i++)
                {
                  if(peca[i].status == '1')
                    {
                        soma1 = peca[i].lado1 + peca[i].lado2;
                        somaMaior1 = somaMaior1 + soma1;
                    }
                  if(peca[i].status == '2')
                    {
                        soma2 = peca[i].lado1 + peca[i].lado2;
                        somaMaior2 = somaMaior2 + soma2;
                    }
                }
                if(somaMaior1 < somaMaior2)
                {
                    mensagens('4');
                    vencedor = 1;
                }
                else if(somaMaior2 < somaMaior1)
                {
                    mensagens('5');
                    vencedor = 1;
                }
            }
        }
    }
}

// verifica se o jogador tem alguma peca que pode ser jogada
int verificaMao()
{
    for(int i = 0; i<28; i++)
    {
        if(peca[i].status == jogador)
        {
            if((peca[i].lado1 == extreEsq) || (peca[i].lado1 == extreDir) || (peca[i].lado2 == extreEsq) || (peca[i].lado2 == extreDir))
                return 1; // ainda ha uma peca que pode ser jogada
        }
    }
    return 0;
}

// verifica se qualquer um dos jogadores possuem alguma peca que pode ser jogada
int verificaMaoDosDois()
{
    for(int i = 0; i<28; i++)
    {
        if((peca[i].status == '1') || (peca[i].status == '2') || (peca[i].status == 'b')) //
        {
            if((peca[i].lado1 == extreEsq) || (peca[i].lado1 == extreDir) || (peca[i].lado2 == extreEsq) || (peca[i].lado2 == extreDir))
                return 1; // ainda ha uma peca que pode ser jogada
        }
    }
    return 0;
}


//funcao para salvar o jogo
void salvarJogo()
{

    jogo.sextreDir = extreDir;  //extremidade direita da mesa
    jogo.sextreEsq = extreEsq;  //extremidade esquerda da mesa
    jogo.sqtdpecaMesa = qtdpecaMesa;     // quantas pecas tem na mesa
    jogo.sjogador = jogador;
    jogo.sauxCompra = auxCompra;
    jogo.ssentinela = sentinela;


    fp = fopen("DOMINOP", "w");
    if((fp = fopen("DOMINOP", "w")) == NULL)
    {
        printf("O arquivo DOMINOP não pode ser aberto \n");
    }

    for(int i = 0; i < 28; i++)  //salva as pecas
        {
            if(fwrite(&peca[i],sizeof(struct domino),1,fp)!=1)
            {
                printf("\nErro na gravacao do arquivo DOMINOP");
                break;
            }
        }

    fclose(fp);

    fp = fopen("DOMINOM", "w");

    for(int i = 0; i < 28; i++) //salva  as pecas da mesa
    {
        if(fwrite(&mesa[i],sizeof(struct domino),1,fp)!=1)
        {
             printf("\nErro na gravacao do arquivo DOMINOM");
            break;
        }
    }

    fclose(fp);



    fp = fopen("DOMINOJ","w");

    if(fwrite(&jogo,sizeof(struct salvamento),1,fp)!=1)
    {
        printf("\nErro");
    }


    fclose(fp);

}







//funcao que recupera os arquivos, lendo os arquivos salvos
void recuperarJogo()
{
    fp = fopen("DOMINOP", "r");
    if((fp = fopen("DOMINOP", "r")) == NULL)
    {
        printf("\nO arquivo DOMINOP não pode ser aberto ");
    }

    for(int i = 0; i < 28; i++) //carrega as pecas da mesa
    {
        if(fread(&peca[i],sizeof(struct domino),1,fp)!=1)
        {
            printf("\nErro na leitura do arquivo DOMINOP");
            break;
        }
    }
    fclose(fp);

    fp = fopen("DOMINOM", "r");

    for(int i = 0; i < 28; i++) //carrega  as pecas da mesa
    {
        if(fread(&mesa[i],sizeof(struct domino),1,fp)!=1)
        {
            printf("\nErro na leitura do arquivo DOMINOM");
            break;
        }
    }

    fclose(fp);



    fp = fopen("DOMINOJ","r");

    if(fread(&jogo,sizeof(struct salvamento),1,fp)!=1)
    {
        printf("\nErro");
    }



    fclose(fp);

    extreDir = jogo.sextreDir;
    extreEsq = jogo.sextreEsq;
    qtdpecaMesa = jogo.sqtdpecaMesa;
    jogador = jogo.sjogador;
    auxCompra = jogo.sauxCompra;
    sentinela = jogo.ssentinela;

}

void jogaComputador()
{
    int cont = 0; // ver se alguma peça é jogavel
    int i = 0;
    aux1 = 0;
    int botpodeJogar;
    primeiroLance();

    botpodeJogar = verificaMao();

    while(((cont == 0) && (auxCompra == 0)) || ((botpodeJogar == 1) && (cont == 0))) //verificar
    {

      do
      {

          if(peca[i].status == '2')
          {
              if((peca[i].lado1 == extreEsq) || (peca[i].lado1 == extreDir) || (peca[i].lado2 == extreEsq) || (peca[i].lado2 == extreDir))
              {
                  cont++;
                  aux1 = i;
                  pecaEscolhida = peca[i];
                  peca[i].status = 'm';



                  if(pecaEscolhida.lado1 == extreDir)
                  {
                      lancamentoDireita();
                      extreDir = mesa[qtdpecaMesa - 1].lado2;
                  }
                  else if(pecaEscolhida.lado2 == extreDir)
                  {
                      mudaLado();
                      lancamentoDireita();
                      extreDir = mesa[qtdpecaMesa - 1].lado2;
                  }
                  else if(pecaEscolhida.lado1 == extreEsq)
                  {
                      mudaLado();
                      lancamentoEsquerda();
                      extreEsq = mesa[0].lado1;
                  }
                  else if(pecaEscolhida.lado2 == extreEsq)
                  {
                      lancamentoEsquerda();
                      extreEsq = mesa[0].lado1;
                  }

              }
          }
          i++;
        }
        while((cont == 0) && (i<28));
        i = 0;

        if(cont == 0)
        {
            compraPeca();
        }
    }
    if(jogador =='2')
        jogador = '1';

    mostraMesa();
    apresentarPeca();
    teste();



}

void flush_in() {
    int ch;

    do {

        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
