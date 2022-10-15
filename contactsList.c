#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void menu();

void f_buffer(void)  // fonction permettant de vider le buffer pour ne pas avoir de problemes avec scanf
{
   int c;
   while ((c=getchar())!=EOF && c!='\n');
}
 
int ligne(FILE *fichier) {
	int line;
	int totline = 0;
	int endline = '\0';
	while((line=fgetc(fichier)) != EOF)
	{
		if(line=='\n')
			totline++;
		endline = line;
	}
	
	if(endline != '\n')
		totline++; 
	return totline;
}


void show_list() {
printf("Voici vos contacts : \n");
     FILE *f;
    char contact;
    f=fopen("contact.txt","rt");
    while((contact=fgetc(f))!=EOF){
        printf("%c",contact);
    }
    fclose(f);
}


void nombre_contact() {
	FILE *fichier = fopen("contact.txt", "r");
	if(fichier != NULL)
	{
		int nLignes = ligne(fichier);
 
		printf("Nombre de contacts : %d\n", nLignes);
 
		fclose(fichier);
	}
	else
		puts("Erreur en ouverture du fichier.");

        show_list();
		menu();
}





int main(void) {
	nombre_contact();
	return 0;
}

void menu() {  // fonction qui creer un menu
	printf("Voici les options : \n");
	printf("Choix 1 = Voir ses contacts -- Choix 2 = Quitter le programme\n");
	int choix = 0;
	printf("Veuillez faire un choix : ");
	scanf("%d", &choix);
	if (choix == 1)
	{
		main();
	} else if (choix == 2)
	{
		exit(0);
	} else {
		printf("veillez choisir 1 ou 2\n");
		f_buffer();
		menu();
	}
}





