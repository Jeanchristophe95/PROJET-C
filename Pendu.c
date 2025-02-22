#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "draw.h"
#include <ctype.h>

#define MAX_MOTS 20

// Liste de mots d'animaux
const char *listeMots[MAX_MOTS] = {
        "lion", "tigre", "éléphant", "girafe", "hippopotame",
        "singe", "koala", "kangourou", "ours", "renard",
        "cheval", "chien", "chat", "souris", "lapin",
        "serpent", "crocodile", "hibou", "aigle", "pingouin"
};

// Fonction pour choisir un mot aléatoire
const char *choisirMotAleatoire() {
    int indiceMot = rand() % MAX_MOTS;
    return listeMots[indiceMot];
}

// Fonction pour afficher le mot caché avec les lettres trouvées
void afficherMotCache(const char *mot, const char *lettresTrouvees) {
    for (int i = 0; i < strlen(mot); i++) {
        if (strchr(lettresTrouvees, mot[i]) != NULL) {
            // Afficher la lettre si elle a été trouvée
            DrawText(TextFormat("%c ", mot[i]), 10 + i * 30, 10, 20, BLUE);
        } else {
            // Afficher un trait souligné si la lettre n'a pas été trouvée
            DrawText("_ ", 10 + i * 30, 10, 20, BLUE);
        }
    }
    printf("\n");
}

int main(void) {
    int count = 0;  // Variable pour le nombre d'essais
    int currentKey;  // Variable pour stocker la touche actuellement pressée
    int lastKey;     // Variable pour stocker la dernière touche pressée

    SetTargetFPS(60);

    // Charger les images d'arrière-plan
    Image illus = LoadImage("C:\\Users\\ayemi\\CLionProjects\\untitled4\\Ressources\\pendu_illus.png");
    Image layer = LoadImage("C:\\Users\\ayemi\\CLionProjects\\untitled4\\Ressources\\pendu_layer1.png");
    const int screenWidth = illus.width;
    const int screenHeight = illus.height;

    InitWindow(screenWidth, screenHeight, "Projet C Hangman/Pendu");


    Texture2D texture = LoadTextureFromImage(illus);
    Texture2D texture1 = LoadTextureFromImage(layer);
    UnloadImage(illus);

    // Utiliser la fonction pour choisir un mot aléatoire
    const char *motADeviner = choisirMotAleatoire();

    char lettresTrouvees[strlen(motADeviner)];
    memset(lettresTrouvees, 0, sizeof(lettresTrouvees));

    char lettre;

    // Afficher un message d'accueil + l'interface de démarrage avec illustration
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(texture, 0, 0, WHITE);
    DrawText("Bienvenue sur le jeu. Écrivez une lettre pour commencer.", 190, 200, 30, BLUE);
    EndDrawing();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);

        // Obtenir la touche actuellement pressée
        currentKey = GetKeyPressed();

        // Dessiner le bonhomme du pendu
        dessinerBonhomme(count);

        // Afficher le nombre d'essais
        DrawText(TextFormat("Nombre d'essais : %d", count), 10, 200, 20, BLUE);

        // Si une nouvelle touche a été pressée
        if (currentKey != -1 && currentKey != lastKey) {
            lettre = tolower(currentKey);

            // Vérifier si la lettre est dans le mot à deviner
            if (strchr(motADeviner, lettre) != NULL) {
                lettresTrouvees[strlen(lettresTrouvees)] = lettre;
            } else {
                // Si la lettre n'est pas dans le mot, incrémenter le nombre d'essais
                count++;
            }
        }

        // Vérifier si le joueur a trouvé le mot
        if (strspn(motADeviner, lettresTrouvees) == strlen(motADeviner)) {
            DrawText(TextFormat("Vous avez trouvé le mot : %s", motADeviner), 10, 260, 20, GREEN);
            printf("Félicitations, vous avez trouvé le mot : %s\n", motADeviner);
        }

        // Vérifier si le joueur a atteint le nombre maximum d'essais
        if (count == 6) {
            printf("Vous avez perdu :(");
            DrawText("Vous avez perdu :(", 10, 230, 20, RED);
        }

        // Afficher le mot caché
        afficherMotCache(motADeviner, lettresTrouvees);

        // Afficher la deuxième image d'arrière-plan (pendu partiellement dessiné)
        DrawTexture(texture1, 0, 0, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
