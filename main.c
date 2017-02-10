#include <stdio.h>
#include <stdlib.h>

#define MAXF 1 //nombre de bateau (modifiable)
#define MACB 5 //taille max des bateaux (pas modifiable, mais aurait pu l'être en créant une boucle lors de la création d'un bateau






//Le jeu fonctionne, mais il ne prends pas en compte le fait qu'un bateau doit être entièrement touché pour couler, et on peut tirer deux fois sur le même bateau.J'ai essayé de rester sur 4h pour tout faire.


typedef enum compare compare; //on déclare une énumération de type "compare" qui peut être vrai ou faux
enum compare
{
    VRAI,FAUX
};





typedef struct cellule { //on déclare une structure cellule avec les deux coordonnées


    int x, y;



}cell;

typedef struct bateau { //on déclare une structure bateau qui est un tableau 1D de cellules


    cell boat[MACB];



}bateau;


typedef struct flotte { //on déclare une structure flotte qui est un tableau 1D de bateaux


    bateau flotte1[MAXF];


}flotte;

cell initcell(int x, int y); //fonction qui crée une cellule
bateau initbateau(int x, int y, int d); //fonction qui crée un bateau
compare fonctioncompare(cell cellulea, cell celluleb); //fonction qui compare deux cases
compare fonctioncompareboat(cell cellulea,bateau boata); //fonction qui vérifie qu'on touche un bateau
compare fonctioncompareflotte(cell cellulea, flotte joueur); //fonction qui vérifie qu'on touche un bateau dans une flotte

//programme principal

int main()
{
    flotte j1;        //on déclare la flotte des deux joueurs
    flotte j2;

    cell tir; //la cellule "tir", lorsqu'un joueur tire
    int i,j,a,b,d,scorej1,scorej2;
    scorej1=0;
    scorej2=0;
    printf("Bienvenue dans la bataille navale!\n \n Le joueur 1 commence ! \n Choisissez une coordonnée en x et en y pour placer vos bateaux.");

    for (i=0;i<MAXF;i++){

//on recommence l'opération autant qu'il y a de bateaux à placer
            printf("Placez le bateau numero %d,j1! (Entre 0 et 20) \n",i+1);
            do {
            scanf("%d",&a);
            scanf("%d",&b);
            }while((a>20)||(a<0)||(b<0)||(b>20)); //on redemande les données à l'utilisateur si il ne rentre pas une valeur entre 0 et 20
            printf("Donnez une direction en nombre (4=gauche 6=droite 8=haut 2=bas) \n");
            do{
            scanf("%d",&d);
            }while((d!=4)&&(d!=6)&&(d!=8)&&(d!=2)); //on redemande les données à l'utilisateur si il ne rentre pas une valeur qui n'est pas attendue
           j1.flotte1[i]=initbateau(a,b,d); //on crée le bateau du joueur avec les données qu'il a donné, et on la range dans sa flotte

           printf("Le bateau %d est a %d %d \n",i+1,j1.flotte1[i].boat[0].x,j1.flotte1[0].boat[0].y); //on affiche les coordonnées du bateau que l'on vient de olacer
           printf("                   %d %d \n",j1.flotte1[i].boat[1].x,j1.flotte1[0].boat[1].y);
            printf("                   %d %d \n",j1.flotte1[i].boat[2].x,j1.flotte1[0].boat[2].y);

    }
//on recommence avec le j2
 for (i=0;i<MAXF;i++){


            printf("Placez le bateau numero %d,j2! \n",i+1);
      do {
            scanf("%d",&a);
            scanf("%d",&b);
            }while((a>20)||(a<0)||(b<0)||(b>20));
            printf("Donnez une direction en nombre (4=gauche 6=droite 8=haut 2=bas) \n");

           do{
            scanf("%d",&d);
            }while((d!=4)&&(d!=6)&&(d!=8)&&(d!=2));


           j2.flotte1[i]=initbateau(a,b,d);

           printf("Le bateau %d est a %d %d \n",i+1,j2.flotte1[i].boat[0].x,j2.flotte1[0].boat[0].y);
           printf("                   %d %d \n",j2.flotte1[i].boat[1].x,j2.flotte1[0].boat[1].y);
            printf("                   %d %d \n",j2.flotte1[i].boat[2].x,j2.flotte1[0].boat[2].y);

    }
    do {
    printf("j2, a vous de tirer! Ou voulez vous tirer? \n");
    scanf("%d",&tir.x); //on récupère les données du tir
    scanf("%d",&tir.y);
    if (fonctioncompareflotte(tir,j1)==VRAI){
        printf("Touche! \n"); //on utilise la fonction de comparasion en lui donnant la flotte du joueur adverse, et le tir. Si elle renvoie vrai, c'est que le bateau adverse a été touché.
        scorej2++; //on incrémente le score.

    }
    else{
        printf("Rate!\n");
    }
//on recommence avec le j2
      printf("j1, à vous de tirer! Ou voulez vous tirer? \n");
    scanf("%d",&tir.x);
    scanf("%d",&tir.y);
    if (fonctioncompareflotte(tir,j2)==VRAI){
        printf("Touché!");
        scorej1++;

    }
    else{
        printf("Raté!\n");
    }


    }while ((scorej1!=MAXF)&&(scorej2!=MAXF)); //on boucle tant que le joueur n'a pas touché tout les bateaux

if(scorej1==MAXF){
    printf("Bravo j1, tu as gagne!"); //On affiche quel joueur a gagné.
}

if(scorej2==MAXF){
    printf("Bravo j2, tu as gagne!");
}
/*   j1.flotte1[0]=initbateau(3,5);
   j1.flotte1[1]=initbateau(4,8);



*/

    return 0;
}

//programme principal


cell initcell(int x, int y){ //crée une cellule
    //BUT:Créer une "cellule", soit une variable composée de deux coordonnées
    //Entrée: La fonction reçoit deux variables x et y entrées par l'utilisateur
    //Sortie: La fonction renvoie une variable cellule utilisable composée de deux entiers
cell cellule;
cellule.x=x;
cellule.y=y;
return cellule;
};

bateau initbateau(int x, int y, int d){ //crée un bateau en fonction du positionnement
    //BUT:Créer un "bateau", un tableau composé de cellules.
    //ENTREE:La fonction reçoit deux variables x et y entrées par l'utilisateur,ainsi qu'une variable "direction" qui positionne le bateau dans l'espace selon ce que souhaite l'utilisateur
    //SORTIE:La fonction renvoie un "bateau" entièrement rempli.
    bateau barque;
/*barque.boat[0].x=x;
barque.boat[0].y=y+0;
barque.boat[1].x=x;
barque.boat[1].y=y+1;
barque.boat[2].x=x;
barque.boat[2].y=y+2; */
if (d==2){
barque.boat[0]=initcell(x,y);
barque.boat[1]=initcell(x,y+1);
barque.boat[2]=initcell(x,y+2);

}

else if(d==4){
barque.boat[0]=initcell(x,y);
barque.boat[1]=initcell(x-1,y);
barque.boat[2]=initcell(x-2,y);
}

else if(d==6){
barque.boat[0]=initcell(x,y);
barque.boat[1]=initcell(x+1,y);
barque.boat[2]=initcell(x+2,y);
}


else if(d==8){
barque.boat[0]=initcell(x,y);
barque.boat[1]=initcell(x,y-1);
barque.boat[2]=initcell(x,y-2);
}





return barque;
};


compare fonctioncompare(cell cellulea,cell celluleb){ //on crée une fonction qui compare deux cellules, renvoie vrai si c'est la même case
//BUT: Comparer deux "cellules"
//ENTREE: On lui envoie deux cellules
//SORTIE: La fonction renvoie "VRAI" si les deux cellules partagent les mêmes coordonnées.
compare valide;
valide=FAUX;
if ((cellulea.x==celluleb.x)&&(cellulea.y==celluleb.y)){
valide=VRAI;
}
else {
    valide=FAUX;
}

return valide;
}

compare fonctioncompareboat(cell cellulea,bateau boata){ //vérifie qu'une cellule touche un bateau
    //BUT: Comparer une case et les cases composant un bateau
    //ENTREE: On envoie une cellule et un bateau
    //SORTIE: Si la case correspond à une case d'un bateau, la fonction renverra "VRAI"
compare valide;
valide=FAUX;
int i;
for(i=0;i<MACB;i++){


       if(((fonctioncompare(cellulea,boata.boat[i]))==VRAI)&&(valide==FAUX)){
            valide=VRAI;

       }
}
return valide;
}






compare fonctioncompareflotte(cell cellulea, flotte joueur){ //vérifie dans la flotte qu'un bateau est touché
    //BUT: Vérifier si la case correspond à une case dans un bateau d'une flotte.
    //ENTREE: La fonction reçoit une case (le tir) et la flotte du joueur adverse.
    //SORTIE: La fonction renvoie VRAI si la case que l'on donne correspond à un bateau d'une flotte adverse.
int i;
compare valide;
valide=FAUX;

 for (i=0;i<MAXF;i++){


     if(((fonctioncompareboat(cellulea,joueur.flotte1[i]))==VRAI)&&(valide==FAUX)){
            valide=VRAI;
       }

    }
return valide;
}
