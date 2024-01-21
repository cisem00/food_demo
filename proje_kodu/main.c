#include <stdio.h>
#include <stdlib.h>
#include "food.h"

int main(){
	
	int choix,choix_de_connexion,choix_de_resto;
	struct sira *file=init();
	int numero, size, no_du_client;
	printf("Appuyez sur 1 pour connexion du client\n");
	printf("Appuyez sur 2 pour connexion du restaurant\n");
	scanf("%d",&choix_de_connexion);
	switch(choix_de_connexion){
		case 1:
		while(1){
			printf("Bienvenue au système de commande de nourriture\n");
			printf("Appuyez sur 1 pour vous inscrire\n");
			printf("Appuyez sur 2 pour vous connecter\n");
			printf("Appuyez sur 3 pour quitter\n");
			scanf("%d",&choix);
			switch(choix){
				case 1:
				signup();
				printf("inscription reussie\n");
				break;
				case 2:
				login();
				printf("\nBienvenue\n");
				break;
				case 3:
				printf("\nBye Bye");
				return 0;
				default:
				printf("Veuillez entrer le choix valide\n");
				break; 
			}
		}
		case 2:
		while(1){
			printf("\nBienvenue\n");
			printf("Appuyez sur 1 pour ajouter le client à la file d'attente\n");
			printf("Appuyez sur 2 pour trier les clients par numéro\n");
			printf("Appuyez sur 3 pour exclure le client\n");
			printf("Appuyez sur 4 pour afficher le file\n");
			printf("Appuyez sur 5 pour quitter\n");
			scanf("%d",&choix_de_resto);
			switch(choix_de_resto){
				case 1:
			    numero=rand()%10;
				pushBack(file,numero);
				break;
				case 2:
				size=taille(file);
				shell_sort(file,size);
				break;
				case 3:
				printf("Entrer le numero du client que vous voulez exclure:");
				scanf("%d",&no_du_client);
				remove_it(file,no_du_client);
				break;
				case 4:
				print(file);
				break;
				case 5:
				printf("Bye Bye");
				return 0;
				default:
				printf("Veuillez entrer le choix valide\n");
				break; 
			}
		}
	}
	
	
	
}