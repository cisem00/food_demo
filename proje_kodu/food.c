#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "food.h"
#define min(x,y) (((x)<(y))?(x):(y))

void signup(){
	printf("Entrez votre prenom: ");
	scanf("%s",temp_prenom);
	printf("\nEntrez votre nom: ");
	scanf("%s",temp_nom);
	printf("\nEntrez votre email: ");
	scanf("%s",temp_email);
	printf("\nEntrez votre mot de passe: ");
	scanf("%s",temp_password1);
	printf("\nEntrez votre mot de passe pour confirmer: ");
	scanf("%s",temp_password2);
	printf("\nEntrez votre numero de telephone: ");
	scanf("%s",temp_numero_de_phone);
	
	int x=validate();
	if(x==1) account_check();
}

int validate(){
	int i,check=1,count=0,caps=0,small=0,special=0,numbers=0,success=0;
	for(i=0;temp_prenom[i]!='\0';i++){
		if(!((temp_prenom[i]>='a' && temp_prenom[i]<='z') || (temp_prenom[i]>='A' && temp_prenom[i]<='Z'))){
			printf("Veuillez entrer un prenom valide\n");
			check=0;
			break;
		}
	}
	for(i=0;temp_nom[i]!='\0';i++){
		if(!((temp_nom[i]>='a' && temp_nom[i]<='z') || (temp_nom[i]>='A' && temp_nom[i]<='Z'))){
			printf("Veuillez entrer un nom valide\n");
			check=0;
			break;
		}
	}
	
	if(check==1){
		count=0;
		for(i=0;temp_email[i]!='\0';i++){
			if (temp_email[i] == '@' || temp_email[i] == '.') count++;
		}
		if(count>=2 && strlen(temp_email)>=5){
			if(!strcmp(temp_password1,temp_password2)){
				if(strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12){
					caps=0;
					small=0;
					special=0;
					numbers=0;
					for(i=0;temp_password1[i]!='\0';i++){
						if (temp_password1[i]>='A' && temp_password1[i]<='Z') caps++;
						else if (temp_password1[i]>='a' && temp_password1[i]<='z') small++;
						else if (temp_password1[i]=='@' || temp_password1[i]=='&' || temp_password1[i]=='#' || temp_password1[i]=='*') special++;
						else if (temp_password1[i]>='0' && temp_password1[i]<='9') numbers++;
					}
					if (caps>=1 && small>=1 && special>=1 && numbers>=1){
						if(strlen(temp_numero_de_phone)==11){
							for(i=0;i<11;i++){
								if(temp_numero_de_phone[i]>='\0' && temp_numero_de_phone[i]<='9') success=1;
								else{
									printf("Veuillez entrer un numero de phone qui est valide\n");
									return 0;
									break;
								}
							}
							if(success==1) return 1;
						}
						else{
							printf("Veuillez entrer le numéro de téléphone mobile à 11 chiffres\n");
							return 0;
						}
					}
				}
				else {
					printf("Votre mot de passe doit contenir au moins une majuscule, une minuscule, un chiffre et un caractère spécial.\n");
					return 0;
				}
			}
			else{
				printf("Votre mot de passe est très court. La longueur doit être comprise entre 8 et 12\n");
				return 0;
			}
		}
		else{
			printf("Inadéquation du mot de passe.\n");
			return 0;
		}
	}
	else{
		printf("Veuillez entrer un e-mail valide\n");
		return 0;
	}
	return 0;
}

void account_check(){
	int a,j=0;
	for(a=0;a<20;a++){
		if(!(strcmp(temp_email, i[a].email) && strcmp(temp_password1,i[a].password))){
			printf("Le compte existe déjà. Veuillez vous connecter.\n");
			break;
		}
	}
	if(a==20){
		strcpy(i[j].prenom,temp_prenom);
		strcpy(i[j].nom,temp_nom);
		strcpy(i[j].password, temp_password1);
		strcpy(i[j].email, temp_email);
		strcpy(i[j].numero_de_phone, temp_numero_de_phone);
		j++;
		printf("Compte créé avec succès!\n");
	}
}

int login(){
	int a,choix_de_rechercher;
	printf("Connectez-vous.\n");
	printf("Entrez votre email: ");
	scanf("%s",temp_email);
	printf("Entrez votre mot de passe: ");
	scanf("%s",temp_password1);
	for(a=0;a<20;a++){
		if (!strcmp(i[a].email,temp_email)){
			if (!strcmp(i[a].password, temp_password1)){
				printf("\nBonjour %s!\n",i[a].prenom);
				printf("Vous êtes connecté avec succès.\n");
				printf("Appuyez sur 1 pour rechercher par restaurant.\n");
				printf("Appuyez sur 2 pour rechercher par le plat que vous voulez manger.\n");
				printf("Appuyez sur 3 pour quitter\n");
				printf("Votre choix: ");
				scanf("%d",&choix_de_rechercher);
				switch(choix_de_rechercher){
					case 1:
					recherche_par_restau();
					break;
					case 2:
					recherche_par_food();
					break;
					case 3:
					return 0;
					default:
					printf("\nVeuillez entrer le choix valide\n");
					break;
				}
			}
			else{
				printf("Mot de passe invalide! Veuillez entrer le mot de passe correct\n");
				break;
			}
		}
		else{
			printf("Le compte n'existe pas! Veuillez vous inscrire.\n");
			signup();
			break;
		}
	}
	return 0;
}

int menu(){
	int choix_de_rechercher;
	printf("Bonjour!\n");
	printf("Vous êtes connecté avec succès.\n");
	printf("Appuyez sur 1 pour rechercher par restaurant.\n");
	printf("Appuyez sur 2 pour rechercher parle plat que vous voulez manger.\n");
	printf("Appuyez sur 3 pour quitter\n");
	printf("Votre choix: ");
	scanf("%d",&choix_de_rechercher);
	switch(choix_de_rechercher){
		case 1:
		recherche_par_restau();
		break;
		case 2:
		recherche_par_food();
		break;
		case 3:
		exit(1);
		default:
		printf("\nVeuillez entrer le choix valide\n");
		break;
	}
	return 0;
}

struct list *insert(struct list* head,int x){
	if(head==NULL){
		head=malloc(sizeof(struct list));
		head->next=NULL;
		head->fiyat=x;
		return head;
	}
	else{
	    struct list *cur=head;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=malloc(sizeof(struct list));
		cur->next->fiyat=x;
	    cur->next->next=NULL;
	}
	return head;
}

void restau_init(){
	strcpy(r[1].restau,"House_of_B");
	strcpy(r[1].food1,"Cheeseburger");
	strcpy(r[1].food2,"Buffalo_Chicken_Wings");
	strcpy(r[1].food3,"Hamburger");
	r[1].premier=45;
	r[1].deuxieme=56;
	r[1].troisieme=40;
	
	strcpy(r[2].restau,"Eataly");
	strcpy(r[2].food1,"Pizza");
	strcpy(r[2].food2,"Chicken_Pasta");
	strcpy(r[2].food3,"Lasagna");
	r[2].premier=60;
	r[2].deuxieme=55;
	r[2].troisieme=65;
	
	strcpy(r[3].restau,"Coni.co");
	strcpy(r[3].food1,"Manti");
	strcpy(r[3].food2,"Beef_Pasta");
	strcpy(r[3].food3,"Fried_Chicken");
	r[3].premier=50;
	r[3].deuxieme=70;
	r[3].troisieme=45;
}

void recherche_par_restau(){
	int choix_de_restau;
	restau_init();
	printf("\nVeuillez choisir le restaurant.\n");
	printf("Appuyez sur 1 pour %s\n",r[1].restau);
	printf("Appuyez sur 2 pour %s\n",r[2].restau);
	printf("Appuyez sur 3 pour %s\n",r[3].restau);
	printf("Appuyez sur 4 pour quitter\n");
	printf("Votre choix: ");
	scanf("%d",&choix_de_restau);
	if(choix_de_restau>4){
		printf("\nVeuillez entrer le choix valide\n");
		recherche_par_restau();
	}
	else if(choix_de_restau==4) menu();
	else restau(choix_de_restau,list);
}

struct list *restau(int choix_de_restau,struct list *head){
	int choix_de_food,nombre_de_food;
	while(1){
		printf("\nListe d'aliments disponibles dans %s \n",r[choix_de_restau].restau);
		printf("1) %s Prix:%d\n",r[choix_de_restau].food1, r[choix_de_restau].premier);
		printf("2) %s Prix:%d\n",r[choix_de_restau].food2, r[choix_de_restau].deuxieme);
		printf("3) %s Prix:%d\n",r[choix_de_restau].food3, r[choix_de_restau].troisieme);
		printf("4) Cart\n 5) Quitter\n");
		printf("Votre choix: ");
		scanf("%d",&choix_de_food);
		if(choix_de_food==1){
			printf("Veuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[choix_de_restau].food1);
			scanf("%d",&nombre_de_food);
			head=insert(head,nombre_de_food*r[choix_de_restau].premier);
		}
		else if(choix_de_food==2){
			printf("Veuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[choix_de_restau].food2);
			scanf("%d",&nombre_de_food);
			head=insert(head,nombre_de_food*r[choix_de_restau].deuxieme);
		}
		else if(choix_de_food==3){
			printf("Veuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[choix_de_restau].food3);
			scanf("%d",&nombre_de_food);
			head=insert(head,nombre_de_food*r[choix_de_restau].troisieme);
		}
		else if(choix_de_food==4) cart(head);
		else if(choix_de_food==5) recherche_par_restau();
		else{
			printf("Veuillez entrer le choix valide\n");
		}
	}
}

void recherche_par_food(){
	int food;
	restau_init();
	while(1){
		printf("Veuillez choisir la nourriture\n");
		printf("1) %s Prix:%d\n",r[1].food1,r[1].premier);
		printf("2) %s Prix:%d\n",r[1].food2,r[1].deuxieme);
		printf("3) %s Prix:%d\n",r[1].food3,r[1].troisieme);
		printf("4) %s Prix:%d\n",r[2].food1,r[2].premier);
		printf("5) %s Prix:%d\n",r[2].food2,r[2].deuxieme);
		printf("6) %s Prix:%d\n",r[2].food3,r[2].troisieme);
		printf("7) %s Prix:%d\n",r[3].food1,r[3].premier);
		printf("8) %s Prix:%d\n",r[3].food2,r[3].deuxieme);
		printf("9) %s Prix:%d\n",r[3].food3,r[3].troisieme);
		printf("10)Cart \n  11)Quitter\n");
		printf("Votre Choix: ");
		scanf("%d", &food);
		if(food>10){
			printf("\nVeuillez entrer le choix valide\n");
			recherche_par_food();
		}
		else if(food==10) cart(list);
		else if(food==11) menu();
		else ordre_food(food,list);
	}
}

struct list* ordre_food(int food,struct list *head){
	int restau_id,nombre_de_food;
	if(food>=1 && food<3) restau_id=1;
	else if(food>=4 && food<=6) restau_id=2;
	else restau_id=3;
	if((food%3)==1){
		printf("\nVeuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[restau_id].food1);
		scanf("%d",&nombre_de_food);
		head=insert(head,nombre_de_food*r[restau_id].premier);
	}
	else if((food%3)==2){
		printf("\nVeuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[restau_id].food2);
		scanf("%d",&nombre_de_food);
		head=insert(head,nombre_de_food*r[restau_id].deuxieme);
	}
	else if((food%3)==0){
		printf("\nVeuillez entrer le nombre de %s(Combien en voulez-vous?)\n",r[restau_id].food3);
		scanf("%d",&nombre_de_food);
		head=insert(head,nombre_de_food*r[restau_id].troisieme);
	}
	return head;
}

int totalprix(struct list *head){
	int total=0;
	while(head->next!=NULL){
		total=total+head->fiyat;
		head=head->next;
	}
	total=total+head->fiyat;
	return total;
}


int cart(struct list *head){
	int total=totalprix(head);
	int ch,confirm;
	printf("\n ---Cart---\n");
	printf("Total:%d\n",total);
	printf("Appuyez sur 1 pour terminer le processus.");
		scanf("%d",&ch);
	if(ch==1){
		printf("Merci pour votre commande ! Votre nourriture est en route.\n");
		exit(1);
	}
	else if(ch==0){
		printf("Appuyez sur 1 pour quitter ou appuyez sur 0 pour revenir en arrière\n");
		scanf("%d",&confirm);
		if(confirm==1){
			printf("Votre commande est annulée."); return 0;
		}
		else{
			printf("\nMerci\n");
			login();
		}
	}
	else{
		printf("Veuillez entrer le choix correct\n");
		cart(head);
	}
	return 0;
}

struct sira* init(){
    struct sira *sira=malloc(sizeof(struct sira));
    sira->size=0;
    sira->capacity=2;
    sira->array=NULL;
    return sira;
}

customerID* get(struct sira *sira, int no){
    return &sira->array[no];
}


void pushBack(struct sira *sira, int no){
	if(sira->array==NULL){
	         sira->array=malloc(sizeof(customerID)*2);
	     }
    if(sira->capacity ==sira->size){
        sira->capacity *= 2;
        int new_capacity = sira->capacity;
        sira->array= (customerID*) realloc(sira->array, new_capacity*sizeof(customerID));

    }
    sira->array[sira->size].no = no; 
	char temp[15];
	
	printf("Entrez les informations du client!\n");
	printf("Prenom: ");
	scanf("%s",temp);
	strcpy(sira->array[sira->size].prenom,temp);
	
	printf("\nNom: ");
	scanf("%s",temp);
	strcpy(sira->array[sira->size].nom,temp);
	
	printf("\nAdress: ");
	scanf("%s",temp);
	strcpy(sira->array[sira->size].adress,temp);
	
	printf("\nNourriture: ");
	scanf("%s",temp);
	strcpy(sira->array[sira->size].food,temp);
	printf("L'ajout à la liste a reussi\n");
	sira->size++;
}
void remove_it(struct sira *sira, int no){
	int i=0;
	while(sira->array[i].no!=no){
		i++;
	}
	for(int a=i;a<sira->size;a++){
		sira->array[a]=sira->array[a+1];
	}
    sira->size--;
	printf("Supression de la liste a reussi\n");
}

int taille(struct sira *sira){
    return sira->size;
}

int getCapacity(struct sira *sira){
    return sira->capacity;
}

void print(struct sira* sira){
	int i;
	int size=taille(sira);
	for(i=0;i<size;i++){
		printf("%d. Customer\n",i+1);
		printf("Prenom:%s\n",sira->array[i].prenom);
		printf("Nom:%s\n",sira->array[i].nom);
		printf("Ordre:%s\n",sira->array[i].food);
		printf("Adress:%s\n",sira->array[i].adress);
	}
}


void shell_sort(struct sira *sira, int size){
    int gap, j, i, Temp;
	char temp_prenom[15], temp_nom[15], temp_adress[20], temp_food[15];
    for (gap = size/2; gap > 0; gap = gap/2){
        for (i = gap; i < size; i++) {
            Temp =sira->array[i].no;
            for (j = i; j >= gap && sira->array[j - gap].no > Temp; j = j-gap){
				strcpy(temp_prenom, sira->array[j].prenom);
				strcpy(temp_nom, sira->array[j].nom);
				strcpy(temp_adress, sira->array[j].adress);
				strcpy(temp_food, sira->array[j].food);
                sira->array[j] = sira->array[j - gap];
				strcpy(sira->array[j-gap].prenom,temp_prenom);
				strcpy(sira->array[j-gap].nom,temp_nom);
				strcpy(sira->array[j-gap].adress,temp_adress);
				strcpy(sira->array[j-gap].food,temp_food);
        }
        sira->array[j].no = Temp;
        }
    }
	for(int i=0;i<size;i++){
		sira->array[i].no=i+1;
	}
	printf("operation de tri reussie");
}
