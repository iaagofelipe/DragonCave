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
    int id;
    int pv;
    int forca;
    int defesa;
    int velocidade;
    int xp;
    int nivel;
    int cura;
};

struct Arqueiro{
    int id;
    int pv;
    int forca;
    int defesa;
    int velocidade;
    int xp;
    int nivel;
    int cura;
};

struct Mago{
    int id;
    int pv;
    int magia;
    int forca;
    int defesa;
    int velocidade;
    int xp;
    int nivel;
    int cura;
};

// *** Estrutura dos Inimigos ***

struct Goblin{
    int pv;
    int nivel;
    int forca;
    int defesa;
    int velocidade;
    int cura;
};

struct Elfo{
    int pv;
    int nivel;
    int forca;
    int defesa;
    int velocidade;
    int cura;
};

struct Bruxa{
    int pv;
    int magia;
    int nivel;
    int forca;
    int defesa;
    int velocidade;
    int cura;
};

// ***DECLARAÇÃO DE FUNÇÕES***

void menu();
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


int main(int argc, char const *argv[]) {
    menu();

    struct Guerreiro guerreiro;
    struct Arqueiro arqueiro;
    struct Mago mago;
    struct Goblin goblin;
    struct Bruxa bruxa;
    struct Elfo elfo;
  

    iniciarGuerreiro(&guerreiro);
    iniciarArqueiro(&arqueiro);
    iniciarMago(&mago);
    
    iniciarGoblin(&goblin);
    iniciarElfo(&elfo);
    iniciarBruxa(&bruxa);

    guerreiroAtacaGoblin(&guerreiro, &goblin);
    guerreiroAtacaElfo(&guerreiro, &elfo);
    guerreiroAtacaBruxa(&guerreiro, &bruxa);
    
    arqueiroAtacaGoblin(&arqueiro, &goblin);
    arqueiroAtacaElfo(&arqueiro, &elfo);
    arqueiroAtacaBruxa(&arqueiro, &bruxa);

    magoAtacaGoblin(&mago, &goblin);
    magoAtacaElfo(&mago, &elfo);
    magoAtacaBruxa(&mago, &bruxa);


    // printf("%d\n", goblin.pv);
}


void menu(){
    printf ("\n\nBem vindo ao DragonCave!!\n\n");
    printf ("Agora preciso que voce escolha uma classe\n\n");
    printf ("Escolha 1 para Guerreiro\n\n");
    printf ("Escolha 2 para Arqueiro\n\n");
    printf ("Escolha 3 para Mago\n\n");
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
}

void iniciarArqueiro(struct Arqueiro *arqueiro){
    arqueiro->pv = 100;
    arqueiro->velocidade = 30;
    arqueiro->defesa = 15;
    arqueiro->forca = 30;
    arqueiro->xp = 0;
    arqueiro->nivel = 1;
    arqueiro->cura = 5;
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

void guerreiroAtacaGoblin(struct Guerreiro *guerreiro, struct Goblin *goblin){
    int dano = (guerreiro->forca - goblin->defesa)/10;
    goblin->pv -= dano;
}

void guerreiroAtacaElfo(struct Guerreiro *guerreiro, struct Elfo *elfo){
    int dano = (guerreiro->forca - elfo->defesa)/10;
    elfo->pv -= dano;
}

void guerreiroAtacaBruxa(struct Guerreiro *guerreiro, struct Bruxa *bruxa){
    int dano = (guerreiro->forca - bruxa->defesa)/10;
    bruxa->pv -= dano;
}
void arqueiroAtacaGoblin(struct Arqueiro *arqueiro, struct Goblin *goblin){
    int dano = (arqueiro->forca - goblin->defesa)/10;
    goblin->pv -= dano;
}

void arqueiroAtacaElfo(struct Arqueiro *arqueiro, struct Elfo *elfo){
    int dano = (arqueiro->forca - elfo->defesa)/10;
    elfo->pv -= dano;
}

void arqueiroAtacaBruxa(struct Arqueiro *arqueiro, struct Bruxa *bruxa){
    int dano = (arqueiro->forca - bruxa->defesa)/10;
    bruxa->pv -= dano;
}
void magoAtacaGoblin(struct Mago *mago, struct Goblin *goblin){
    int dano = (mago->forca - goblin->defesa)/10;
    goblin->pv -= dano;
}

void magoAtacaElfo(struct Mago *mago, struct Elfo *elfo){
    int dano = (mago->forca - elfo->defesa)/10;
    elfo->pv -= dano;
}

void magoAtacaBruxa(struct Mago *mago, struct Bruxa *bruxa){
    int dano = (mago->forca - bruxa->defesa)/10;
    bruxa->pv -= dano;
}

// *** Historia do jogo ***

void apresentacao(){
    if (/*chose*/ 1 ||/*chose*/ 2 ||/*chose*/ 3)
    {
        printf("\n Bem vindo a nossa aventura no mundo magico do RPG!\n");
        printf("\n Bom, esse jogo NAO tera algo foda que lhe fara nunca mais esquece-lo.\n");
        printf("\n Porem, ele tera uma coisa que com certeza eh muito significante, a força de vontade dos desenvolvedores!!\n");
        printf("\n Portanto, isso eh uma homenagem feita de mim para mim :) \n\n");
    }
}
