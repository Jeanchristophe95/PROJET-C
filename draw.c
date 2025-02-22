#include "draw.h"
#include <stdio.h>

const int screenWidth = 1209;
const int screenHeight = 750;

// Dessine la tête du bonhomme
void drawHead() {
    DrawCircle(screenWidth / 2, screenHeight / 2 - 40, 25, BLUE); // Tête
}

// Dessine le corps du bonhomme
void drawBody() {
    DrawRectangle((screenWidth - 15) / 2, screenHeight / 2 - 20, 15, 80, BLUE); // Corps
}

// Dessine les jambes du bonhomme
void drawLegs() {
    DrawLine(screenWidth / 2, screenHeight / 2 + 40, screenWidth / 2 - 10, screenHeight / 2 + 120, BLUE); // Jambe gauche
    DrawLine(screenWidth / 2 + 5, screenHeight / 2 + 40, screenWidth / 2 + 10, screenHeight / 2 + 120, BLUE); // Jambe droite
}

//Dessine le bras gauche du bonhomme
void drawLeftArm() {
    DrawLine(screenWidth / 2 - 10, screenHeight / 2 - 30, screenWidth / 2 - 20, screenHeight / 2 + 60, BLUE); // Bras gauche
}

//  Dessine le bras droit du bonhomme
void drawRightArm() {
    DrawLine(screenWidth / 2 + 10, screenHeight / 2 - 30, screenWidth / 2 + 20, screenHeight / 2 + 60, BLUE); // Bras droit
}

// Dessine le bonhomme en fonction du nombre d'erreurs
void dessinerBonhomme(int erreurs) {
    switch (erreurs) {
        case 1:
            drawHead();
            break;
        case 2:
            drawHead();
            drawBody();
            break;
        case 3:
            drawLegs();
            drawHead();
            drawBody();
            break;
        case 4:
            drawLeftArm();
            drawLegs();
            drawHead();
            drawBody();
            break;
        case 5:
            drawRightArm();
            drawLeftArm();
            drawLegs();
            drawHead();
            drawBody();
            break;
    }
}
