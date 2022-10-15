#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct contact contact;  // raccourci permettant de ne plus avoir comme nom struct contact
struct contact{  // creation de la structure contenant mes variables
	char* firstname;
	char* lastname;
	int age;
};



void menu();

void f_buffer(void)  // fonction permettant de vider le buffer pour ne pas avoir de problemes avec scanf
{
   int c;
   while ((c=getchar())!=EOF && c!='\n');
}

void create_contact() {
 contact* structptr = malloc(sizeof(contact));  // allocation de memoire pour ma structure
 structptr->firstname = malloc(sizeof(1000));   // allocation de memoire pour ma variable firstname
 structptr->lastname = malloc(sizeof(1000));    // allocation de memoire pour ma variable lastname
 printf("Rentrez un prenom : \n");
 scanf("%s", structptr->firstname);
int i;
int taille_firstname = strlen(structptr->firstname);
for (i = 0; i < taille_firstname; i++) // Boucle permettant la gestion d'erreur (vérification si la chaine de caractère rentrée comporte un chiffre ou non)
{
	if (structptr->firstname[i] == 48 || structptr->firstname[i] == 49|| structptr->firstname[i] == 50 || structptr->firstname[i] == 51 || structptr->firstname[i] == 52 || structptr->firstname[i] == 53 || structptr->firstname[i] == 54 || structptr->firstname[i] == 55 || structptr->firstname[i] == 56 || structptr->firstname[i] == 57)
	{
		printf("vous ne pouvez pas rentrer de nombre \n");
		f_buffer();
		menu();
	}
}
f_buffer();
printf("Rentrez un nom : \n");
scanf("%s", structptr->lastname);

int j;
int taille_lastname = strlen(structptr->lastname);
for (j = 0; j < taille_lastname; j++)  // Boucle permettant la gestion d'erreur (vérification si la chaine de caractère rentrée comporte un chiffre ou non)
{
	if (structptr->lastname[j] == 48 || structptr->lastname[j] == 49 || structptr->lastname[j] == 50 || structptr->lastname[j] == 51 || structptr->lastname[j] == 52 || structptr->lastname[j] == 53 || structptr->lastname[j] == 54 || structptr->lastname[j] == 55 || structptr->lastname[j] == 56 || structptr->lastname[j] == 57)
	{
		printf("vous ne pouvez pas rentrer de nombre \n");
		f_buffer();
		menu();
	}
	
}

 printf("Rentrez un age : \n");
 scanf("%d", &structptr->age);
 if(structptr->age > 0 && structptr->age < 120 ) {  // condition permettant de ne pouvoir rentrer que des nombres allant de 0 à 120
	 printf("%s,%s,%d\n", structptr->firstname,structptr->lastname, structptr->age);

	 // bloc de code permettant de mettre les informations dans mon fichier .txt
	 
 FILE* fichier = NULL;  
 fichier = fopen("contact.txt", "a");
 if (fichier != NULL)
    {
        fprintf(fichier, "%s ",structptr->firstname);
		fprintf(fichier, "%s ",structptr->lastname);
		fprintf(fichier, "%d \n",structptr->age);
        fclose(fichier);
		printf("contact sauvegarde dans le fichier : contact.txt\n");
    }

	// fin du bloc 
	
	f_buffer(); // buffer vidé
	menu(); // appel de mon menu
 } else {  // gestion d'erreur
	 printf("Ce n'est pas un nombre, veuillez recommencer\n");
	 f_buffer();
	 menu();
 }

}


void menu() {  // fonction qui creer un menu
	printf("Bienvenue dans votre gestionnaire de contacts\n");
	printf("Choix 1 = Creer un contact -- Choix 2 = Quitter le programme\n");
	int choix = 0;
	printf("Veuillez faire un choix : ");
	scanf("%d", &choix);
	if (choix == 1)
	{
		create_contact();
	} else if (choix == 2)
	{
		exit(0);
	} else {
		printf("veillez choisir 1 ou 2\n");
		f_buffer();
		menu();
	}
	
	

}




int main() { // appel de fonction
	menu();  // appel de la fonction qui creer un menu
create_contact(); // appel de la fonction qui créer le contact
return 0;
}





