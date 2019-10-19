/*
    *** RPG DE TURNOS ***

    * CARACTERISTICA DOS PERSONAGENS          [X]
    * CARACTERISTICA DOS INIMIGOS             [X]
    * CARACTERISTICA DOS BOSS                 [ ]
    * CONCLUIR OS PERSONAGENS                 [X]
    * INVENTARIO                              [ ]
    * XP, NIVEIS                              [X]
    * ESTABELECER AS REGRAS DO JOGO(DE AÇÃO)  [X]

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// *** Estrutura dos Personagens ***

struct Guerreiro{
    double id;
    double pv;
    double forca;
    double defesa;
    double velocidade;
    double xp;
    double nivel;
    double cura;
};

struct Arqueiro{
    double id;
    double pv;
    double forca;
    double defesa;
    double velocidade;
    double xp;
    double nivel;
    double cura;
};

struct Mago{
    double id;
    double pv;
    double magia;
    double forca;
    double defesa;
    double velocidade;
    double xp;
    double nivel;
    double cura;
};

// *** Estrutura dos Inimigos ***

struct Goblin{
    double pv;
    double nivel;
    double forca;
    double defesa;
    double velocidade;
    double cura;
};

struct Elfo{
    double pv;
    double nivel;
    double forca;
    double defesa;
    double velocidade;
    double cura;
};

struct Bruxa{
    double pv;
    double magia;
    double nivel;
    double forca;
    double defesa;
    double velocidade;
    double cura;
};

// ***DECLARAÇÃO DE FUNÇÕES***

void menu();
int escolha();
void apresentacao();
void iniciarGuerreiro(struct Guerreiro *guerreiro);
void iniciarArqueiro(struct Arqueiro *arqueiro);
void iniciarMago(struct Mago *mago);
void iniciarGoblin(struct Goblin *goblin);
void iniciarElfo(struct Elfo *elfo);
void iniciarBruxa(struct Bruxa *bruxa);

// ***DECLARAÇÃO DE REGRAS DE JOGO***

void guerreiroAtacaGoblin(struct Guerreiro *guerreiro, struct Goblin *goblin);
void guerreiroAtacaElfo(struct Guerreiro *guerreiro, struct Elfo *elfo);
void guerreiroAtacaBruxa(struct Guerreiro *guerreiro, struct Bruxa *bruxa);

void arqueiroAtacaGoblin(struct Arqueiro *arqueiro, struct Goblin *goblin);
void arqueiroAtacaElfo(struct Arqueiro *arqueiro, struct Elfo *elfo);
void arqueiroAtacaBruxa(struct Arqueiro *arqueiro, struct Bruxa *bruxa);

void magoAtacaGoblin(struct Mago *mago, struct Goblin *goblin);
void magoAtacaElfo(struct Mago *mago, struct Elfo *elfo);
void magoAtacaBruxa(struct Mago *mago, struct Bruxa *bruxa);

// chamada das funcoes de ataque e defesa
double ataque(double ataque, double defesa, int id_atacante, int id_vitima);

int main(int argc, char const *argv[]) {

    struct Guerreiro guerreiro;
    struct Arqueiro arqueiro;
    struct Mago mago;
    struct Goblin goblin;
    struct Bruxa bruxa;
    struct Elfo elfo;

    menu();
    int classes= escolha();

    switch (classes)
    {
    case 1:
        iniciarGuerreiro(&guerreiro);
        break;
    case 2:
        iniciarArqueiro(&arqueiro);
        break;
    case 3:
        iniciarMago(&mago);
        break;
    default:
        iniciarGuerreiro(&guerreiro);
        printf("\n\n A opcao guerreiro foi escolhida por padrao pois nenhuma opcao válida foi iniciada.\n\n");
        break;
    }

    //historia
    apresentacao();

    iniciarGoblin(&goblin);
    iniciarElfo(&elfo);
    iniciarBruxa(&bruxa);

}


void menu(){
    printf ("\n\nBem vindo ao DragonCave!!\n\n");
    printf ("Agora preciso que voce escolha uma classe\n\n");
    printf ("Escolha 1 para Guerreiro\n\n");
    printf ("Escolha 2 para Arqueiro\n\n");
    printf ("Escolha 3 para Mago\n\n");
}

int escolha(){
    int escolhaClasse = 0;
    scanf ("%d", &escolhaClasse);
    return escolhaClasse;
}
// *** Historia do jogo ***

void apresentacao(){
    printf("\n Bem vindo a nossa aventura no mundo magico do RPG!\n");
    printf("\n Bom, esse jogo NAO tera algo foda que lhe fara nunca mais esquece-lo.\n");
    printf("\n Porem, ele tera uma coisa que com certeza eh muito significante, a força de vontade dos desenvolvedores!!\n");
    printf("\n Portanto, isso eh uma homenagem feita de mim para mim :) \n\n");
}

// ***Status dos heróis e inimigos***

void iniciarGuerreiro(struct Guerreiro *guerreiro){
    guerreiro->pv = 125;
    guerreiro->velocidade = 15;
    guerreiro->defesa = 30;
    guerreiro->forca = 50;
    guerreiro->xp = 0;
    guerreiro->nivel = 1;
    guerreiro->cura = 5;
    printf("\n Guerreiro inicializado!\n");
}

void iniciarArqueiro(struct Arqueiro *arqueiro){
    arqueiro->pv = 100;
    arqueiro->velocidade = 30;
    arqueiro->defesa = 15;
    arqueiro->forca = 30;
    arqueiro->xp = 0;
    arqueiro->nivel = 1;
    arqueiro->cura = 5;
    printf("\n Arqueiro inicializado!\n");
}

void iniciarMago(struct Mago *mago){
    mago->pv = 100;
    mago->velocidade = 20;
    mago->defesa = 15;
    mago->forca = 35;
    mago->magia = 50;
    mago->xp = 0;
    mago->nivel = 1;
    mago->cura = 5;
    printf("\n Mago inicializado!\n");
}

void iniciarGoblin(struct Goblin *goblin){
    goblin->pv = 25;
    goblin->forca = 8;
    goblin->defesa = 4;
    goblin->velocidade = 3;
    goblin->nivel = 1;
    goblin->cura = 5;
}

void iniciarElfo(struct Elfo *elfo){
    elfo->pv = 20;
    elfo->forca = 5;
    elfo->defesa = 3;
    elfo->velocidade = 15;
    elfo->nivel = 1;
    elfo->cura = 5;
}

void iniciarBruxa(struct Bruxa *bruxa){
    bruxa->pv = 15;
    bruxa->magia = 10;
    bruxa->forca = 6;
    bruxa->defesa = 2;
    bruxa->velocidade = 6;
    bruxa->nivel = 1;
    bruxa->cura = 5;
}

// ***Ações de batalha***

/**
  Função de ataque geral, onde serão passados o ataque do atacante e a defesa da
  vitima, junto com suas id para serem identificadas pelas regras do jogo
*/

double ataque(double ataque, double defesa, int id_atacante, int id_vitima){

  return 0.0;
}
