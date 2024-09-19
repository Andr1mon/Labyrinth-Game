#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int pos_map(int i, int j){ // fonction de determination d'une position sur la carte
    if (j<=4 && i<=4)
        return 1;
    if (j>4 && j<10 && i<=4)
        return 2;
    if (j>=10 && i<=4)
        return 3;
    if (j<=4 && i>4 && i<10)
        return 4;
    if (j>4 && j<10 && i>4 && i<10)
        return 5;
    if (j>=10 && i>4 && i<10)
        return 6;
    if (j<=4 && i>=10)
        return 7;
    if (j>4 && j<10 && i>=10)
        return 8;
    if (j>=10 && i>=10)
        return 9;
}
/*
    *****
    *123*
    *346*
    *789*
    *****
*/

void main(){
reinitialisation: // etiquette de retour si l'utilisateur veut redemarrer le programme
    system("color 81"); // here 1 represents a text color and 8 - a background color
    int nL=15,nC=15,pas=1; // nL - nombre de ligne, nC - nombre de colonnes, pas - le compteur des pas
    int labyrinthe[100][100]; // tableau bidimensionnel qui correspond au labyrinthe
    int score; // score - le record d'utilisateur de finir le labyrinthe le plus vite possible

    FILE *fichierL;
    fichierL = fopen("Labyrinthe.txt","r");
    for (int i=0;i<nL;i++)
        for (int j=0;j<nC;j++)
            fscanf(fichierL,"%d",&labyrinthe[i][j]); // stockage d'un labyrinthe enregistré dans un fichier texte sous la forme d'une tableau bidimensionnel
    fclose(fichierL);

    FILE *fichierS;
    fichierS = fopen("Score.txt","r"); // stockage d'un score de l'utilisateur
    if (fichierS==NULL) // si c'est la premiere session de l'utilisateur et le fichier n'est pas créé
        score=99;
    else
        fscanf(fichierS,"%d",&score);
    fclose(fichierS);


    srand((unsigned)time(NULL)); // définit le point de départ pour produire une série d'entiers pseudo-aléatoires.

    int l=rand()%13+1; // on initialise le nombre pseudo-aléatoire qui correspond à la ligne de la matrice
    int c=rand()%13+1; //on initialise le nombre pseudo-aléatoire qui correspond à la colonne de la matrice

    while (labyrinthe[l][c]){ // on souhaite choisir le 0 (une case vide et pas un murs) comme une position initialle dans un labyrinthe
        l=rand()%13+1;
        c=rand()%13+1;
    }

    int map; //la valeur qui indique aux l'utilisateur la position approximative dans un labyrinthe

    while (labyrinthe[l][c]!=2 && pas <=40){
        // Goto XY
        map=pos_map(l,c);//on recupere la position actuelle
        system("CLS");
        COORD crd;
        crd.X = 0;
        crd.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);

        //interface graphique de la position actuelle et les murs proches (segment de 3x3) ainsi que de la carte, premiere ligne:
        printf("Labyrinthe        Carte\n %c%c%c%c%c%c%c          %c%c%c%c%c      Tapez %c pour se deplacer vers le haut.\n %c     %c          %c",219,219,219,219,219,219,219,219,219,219,219,219,30,219,219,219);
        //1ere ligne dynamique de la carte
        if (map==1)
            printf("x  ");
        if (map==2)
            printf(" x ");
        if (map==3)
            printf("  x");
        if (map!=1 && map!=2 && map!=3)
            printf("   ");
        printf("%c      Tapez %c pour se deplacer vers le bas.\n %c ",219,31,219);
        if (labyrinthe[l-1][c-1]==1)
            printf("%c",219);
        else
            printf(" ");
        if (labyrinthe[l-1][c]==1)
            printf("%c",219);
        else
            printf(" ");
        if (labyrinthe[l-1][c+1]==1)
            printf("%c",219);
        else
            printf(" ");
        printf(" %c          %c",219,219);
        //2eme ligne dynamique de la carte
        if (map==4)
            printf("x  ");
        if (map==5)
            printf(" x ");
        if (map==6)
            printf("  x");
        if (map!=4 && map!=5 && map!=6)
            printf("   ");
        printf("%c      Tapez %c pour se deplacer vers la droite.\n %c ",219,16,219);
        if (labyrinthe[l][c-1]==1)
            printf("%c",219);
        else
            printf(" ");
        printf("%c",207);
        if (labyrinthe[l][c+1]==1)
            printf("%c",219);
        else
            printf(" ");
        printf(" %c          %c",219,219);
        //3eme ligne dynamique de la carte
        if (map==7)
            printf("x  ");
        if (map==8)
            printf(" x ");
        if (map==9)
            printf("  x");
        if (map!=7 && map!=8 && map!=9)
            printf("   ");
        printf("%c      Tapez %c pour se deplacer vers la gauche.\n %c ",219,17,219);
        if (labyrinthe[l+1][c-1]==1)
            printf("%c",219);
        else
            printf(" ");
        if (labyrinthe[l+1][c]==1)
            printf("%c",219);
        else
            printf(" ");
        if (labyrinthe[l+1][c+1]==1)
            printf("%c",219);
        else
            printf(" ");
        printf(" %c          %c%c%c%c%c      Tapez R pour redemarrer le programme.\n %c     %c          score: %d\n %c%c%c%c%c%c%c          pas: %d/40\n",219,219,219,219,219,219,219,219,score,219,219,219,219,219,219,219,pas);

        char key=getch(); //on recupere de l'utilisation son choix de mouvement
        if (key==114)
            goto reinitialisation;
        if(key==75){ //arrow left
            if (labyrinthe[l][c-1]==1){
                printf ("Le mouvement vers la gauche est impossible.\n");
                system("PAUSE");
            }
            else{
                c--;
                pas++;
            }
        }
        if(key==77){ //arrow right
            if (labyrinthe[l][c+1]==1){
                printf ("Le mouvement vers la droite est impossible.\n");
                system("PAUSE");
            }
            else{
                c++;
                pas++;
            }
        }
        if(key==72){ //arrow up
            if (labyrinthe[l-1][c]==1){
                printf ("Le mouvement vers le haut est impossible.\n");
                system("PAUSE");
            }
            else{
                l--;
                pas++;
            }
        }
        if(key==80){ //arrow down
            if (labyrinthe[l+1][c]==1){
                printf ("Le mouvement vers le bas est impossible.\n");
                system("PAUSE");
            }
            else{
                l++;
                pas++;
            }
        }
        if (labyrinthe[l][c]==2){ //la condition de victoire
            printf ("Vous avez gagne! ");
            if (score>pas){
                printf("Votre nouveau score est: %d.",pas);
                FILE *fichier;
                fichier = fopen("Score.txt","w");
                fprintf(fichier,"%d",pas);
                fclose(fichier);
            }
            sleep(2);
            printf("\nSi vous voulez recommencer, taper R sinon l'autre symbole.\n");
            char key=getch();
            if (key==114 || key==82)
                goto reinitialisation;
            system("PAUSE");
            break;
        }
    }
    if (pas>40){ // la condition de defaite
        printf("Vous avez perdu.");
        sleep(2);
        printf("\nSi vous voulez recommencer, taper R sinon l'autre symbole.\n");
        char key=getch();
        if (key==114 || key==82)
            goto reinitialisation;
        system("PAUSE");
    }
}
