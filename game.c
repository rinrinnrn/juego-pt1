#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

    char mapa[10][20] = {
    "###################",
    "#                 #",
    "#  #####          #",
    "#      #          #",
    "#      #   #####  #",
    "#          #      #",
    "#          #      #",
    "#   #####  #      #",
    "#                 #",
    "###################"
    };

    int jugadorX = 1;
    int jugadorY = 1;

    char tecla;

    while (1) {

        system("cls");

        // Dibujar mapa
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 19; x++) {

                if (x == jugadorX && y == jugadorY)
                    printf("P");
                else
                    printf("%c", mapa[y][x]);
            }
            printf("\n");
        }

        printf("\nMover: W A S D | Salir: Q\n");

        tecla = getch(); // lee tecla sin ENTER

        int nuevaX = jugadorX;
        int nuevaY = jugadorY;

        if (tecla == 'w' || tecla == 'W') nuevaY--;
        if (tecla == 's' || tecla == 'S') nuevaY++;
        if (tecla == 'a' || tecla == 'A') nuevaX--;
        if (tecla == 'd' || tecla == 'D') nuevaX++;
        if (tecla == 'q' || tecla == 'Q') break;

        // evitar atravesar paredes
        if (mapa[nuevaY][nuevaX] != '#') {
            jugadorX = nuevaX;
            jugadorY = nuevaY;
        }
    }

    return 0;
}