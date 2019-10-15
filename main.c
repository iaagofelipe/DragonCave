/*
    *** RPG DE TURNOS ***

    * CARACTERISTICA DOS PERSONAGENS [X]
    * CARACTERISTICA DOS INIMIGOS    [ ]
    * INVENTARIO                     [ ]
    * XP, NIVEIS                     [ ]



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void personagens();

int main(int argc, char const *argv[]) {
    printf ("\n\nBem vindo ao DragonCave!!\n\n");
    printf ("Agora preciso que voce escolha uma classe\n\n");
    printf ("Escolha 1 para Guerreiro\n\n");
    // scanf ("%d", &1);
    printf ("Escolha 2 para Arqueiro\n\n");

    printf ("Escolha 3 para Mago\n\n");


    struct Guerreiro guerreiro;
    struct Arqueiro arqueiro;
    struct Mago mago;
    guerreiro.id = 1;
    arqueiro.id = 2;
    mago.id = 3;
}
void personagen(void){

    
}

