/*
    *** RPG DE TURNOS ***

    * CARACTERISTICA DOS PERSONAGENS [X]
    * CARACTERISTICA DOS INIMIGOS    [ ]
    * INVENTARIO                     [ ]
    * XP, NIVEIS                     [X]



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
};
struct Arqueiro{
    int id;
    int pv;
    int forca;
    int defesa;
    int velocidade;
    int xp;
    int nivel;
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
};

// *** Estrutura dos Inimigos ***

struct Inimigo{
    int pv;
    int nivel;
    int forca;
    int defesa;
    int velocidade;
};

void menu();
void iniciarGuerreiro(struct Guerreiro *guerreiro);
void iniciarArqueiro(struct Arqueiro *arqueiro);
void iniciarMago(struct Mago *mago);
void iniciarInimigo(struct Inimigo *inimigo);
void guerreiroAtacaInimigo(struct Guerreiro *guerreiro, struct Inimigo *inimigo);

int main(int argc, char const *argv[]) {
    menu();
    struct Guerreiro guerreiro;
    struct Arqueiro arqueiro;
    struct Mago mago;
    struct Inimigo inimigo;

    iniciarGuerreiro(&guerreiro);
    iniciarArqueiro(&arqueiro);
    iniciarMago(&mago);
    iniciarInimigo(&inimigo);

    guerreiroAtacaInimigo(&guerreiro, &inimigo);
    printf("%d\n", inimigo.pv);
}

void menu(){
    printf ("\n\nBem vindo ao DragonCave!!\n\n");
    printf ("Agora preciso que voce escolha uma classe\n\n");
    printf ("Escolha 1 para Guerreiro\n\n");
    printf ("Escolha 2 para Arqueiro\n\n");
    printf ("Escolha 3 para Mago\n\n");
}

void iniciarGuerreiro(struct Guerreiro *guerreiro){
    guerreiro->pv = 125; 
    guerreiro->velocidade = 15; 
    guerreiro->defesa = 30; 
    guerreiro->forca = 50;
    guerreiro->xp = 0;
    guerreiro->nivel = 1;
}

void iniciarArqueiro(struct Arqueiro *arqueiro){
    arqueiro->pv = 100; 
    arqueiro->velocidade = 30; 
    arqueiro->defesa = 15; 
    arqueiro->forca = 30;
    arqueiro->xp = 0;
    arqueiro->nivel = 1;
}

void iniciarMago(struct Mago *mago){
    mago->pv = 100; 
    mago->velocidade = 20; 
    mago->defesa = 15; 
    mago->forca = 35;
    mago->magia = 50;
    mago->xp = 0;
    mago->nivel = 1;
}

void iniciarInimigo(struct Inimigo *inimigo){
    inimigo->pv = 20;
    inimigo->forca = 5;
    inimigo->defesa = 2;
    inimigo->velocidade = 5;
    inimigo->nivel = 1;
}

void guerreiroAtacaInimigo(struct Guerreiro *guerreiro, struct Inimigo *inimigo){
    int dano = (guerreiro->forca - inimigo->defesa)/10;
    inimigo->pv-=dano;
}