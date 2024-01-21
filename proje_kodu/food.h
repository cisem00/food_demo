#ifndef _FOOD_H_
#define _FOOD_H_
#include <stdbool.h>

struct info {
	char prenom[30];
	char nom[30];
	char email[25];
	char password[15];
	char numero_de_phone [13];
};

struct restau {
	char restau[30];
	char food1[50];
	char food2[50];
	char food3[50];
	int premier, deuxieme, troisieme;
};

struct list{
	struct list *next;
	int fiyat;
};


typedef struct customerID{
	int no;
	char adress[20];
	char food[50];
	char prenom[15]; 
	char nom[20];  
}customerID;

struct sira{
    customerID* array;
    int size;
    int capacity;
};

struct restau r[20];
struct info i[50];

void signup();
void account_check();
int validate();
int login();
int cart(struct list *head);
void recherche_par_restau();
void recherche_par_food();
struct list* ordre_food(int food,struct list* head);
void restau_init();
struct list* restau(int choix_de_restau,struct list* head);
int menu();
struct list *insert(struct list* head,int x);


struct sira* init();
customerID* get(struct sira *sira, int no);
void pushBack(struct sira *sira,int no);
void remove_it(struct sira *sira,int no);
int taille(struct sira *sira);
int getCapacity(struct sira *sira);

void shell_sort(struct sira *sira, int size); //size degisebilir dikkat et
void print(struct sira* sira);


char temp_prenom[30], temp_nom[30], temp_password1[15], temp_password2[15], temp_email[25], temp_numero_de_phone[13];
struct list* list=NULL;
#endif