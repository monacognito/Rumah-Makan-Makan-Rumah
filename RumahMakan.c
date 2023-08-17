#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>
#include <dos.h>
const int banyak_menu = 50;
bool isBeginning = true;
bool isBeginningCat = true;
int timee=1;
bool loadingg=true;
char loggedin[100];

int totalcatatan=0;
char catatanfood[100][100];
int catatanharga[100];

int aorder=0,totalor=0;
int berhasil=1;
typedef struct{
	char id[100];
	char food[100];
	int harga;
	int tquan;
	int food_total;
}list;

typedef struct{
	char acclog[100];
	char accpass[100];
}accfind;
//data menu[banyak_menu]; //Isi banyak array sesuai dengan banyak menu

void swapint(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printatas(){
	printf("=========================================================\n");
	 printf("\t\tRumah Makan Makan Rumah\n");
	 printf("=========================================================\n");
	 printf("\t  ID\t    Nama Makanan\t  Harga\n");
	 printf("\t=========================================\n");
}

void cumi() {
	FILE *fp=fopen("cumi.txt","r");
	int banyakcumi=0;
	int i;
	list cumi[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",cumi[banyakcumi].id,cumi[banyakcumi].food,&cumi[banyakcumi].harga);
		banyakcumi++;
	}
	 
	 printatas();
	
	 for(i=0;i<banyakcumi;i++){
	 	if(strlen(cumi[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyakcumi; a++){
        for (b = 1; b < banyakcumi; b++)
        {
            if (cumi[b-1].harga>cumi[b].harga){
            	//swap harga
                swapint(&cumi[b-1].harga,&cumi[b].harga);
                
                //swap nama
                strcpy(tempstring,cumi[b-1].food);
                strcpy(cumi[b-1].food,cumi[b].food);
                strcpy(cumi[b].food,tempstring);
                
                //swap id
                strcpy(tempid,cumi[b-1].id);
                strcpy(cumi[b-1].id,cumi[b].id);
                strcpy(cumi[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyakcumi;i++){
		if(strlen(cumi[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyakcumi; a++){
	        for (b = 1; b < banyakcumi; b++){
	            if (strcmp(cumi[b-1].food,cumi[b].food)>0){
	            	//swap harga
	                swapint(&cumi[b-1].harga,&cumi[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,cumi[b-1].food);
	                strcpy(cumi[b-1].food,cumi[b].food);
	                strcpy(cumi[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,cumi[b-1].id);
	                strcpy(cumi[b-1].id,cumi[b].id);
	                strcpy(cumi[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyakcumi;i++){
			if(strlen(cumi[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",cumi[i].id,cumi[i].food,cumi[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

void udang() {
	FILE *fp=fopen("udang.txt","r");
	int banyakudang=0;
	int i;
	list udang[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",udang[banyakudang].id,udang[banyakudang].food,&udang[banyakudang].harga);
		banyakudang++;
	}
	 printatas();
	
	 for(i=0;i<banyakudang;i++){
	 	if(strlen(udang[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyakudang; a++){
        for (b = 1; b < banyakudang; b++)
        {
            if (udang[b-1].harga>udang[b].harga){
            	//swap harga
                swapint(&udang[b-1].harga,&udang[b].harga);
                
                //swap nama
                strcpy(tempstring,udang[b-1].food);
                strcpy(udang[b-1].food,udang[b].food);
                strcpy(udang[b].food,tempstring);
                
                //swap id
                strcpy(tempid,udang[b-1].id);
                strcpy(udang[b-1].id,udang[b].id);
                strcpy(udang[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyakudang;i++){
		if(strlen(udang[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyakudang; a++){
	        for (b = 1; b < banyakudang; b++){
	            if (strcmp(udang[b-1].food,udang[b].food)>0){
	            	//swap harga
	                swapint(&udang[b-1].harga,&udang[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,udang[b-1].food);
	                strcpy(udang[b-1].food,udang[b].food);
	                strcpy(udang[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,udang[b-1].id);
	                strcpy(udang[b-1].id,udang[b].id);
	                strcpy(udang[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyakudang;i++){
			if(strlen(udang[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",udang[i].id,udang[i].food,udang[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

void kuah() {
	FILE *fp=fopen("kuah.txt","r");
	int banyakkuah=0;
	int i;
	list kuah[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",kuah[banyakkuah].id,kuah[banyakkuah].food,&kuah[banyakkuah].harga);
		banyakkuah++;
	}
	 printatas();
	
	 for(i=0;i<banyakkuah;i++){
	 	if(strlen(kuah[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyakkuah; a++){
        for (b = 1; b < banyakkuah; b++)
        {
            if (kuah[b-1].harga>kuah[b].harga){
            	//swap harga
                swapint(&kuah[b-1].harga,&kuah[b].harga);
                
                //swap nama
                strcpy(tempstring,kuah[b-1].food);
                strcpy(kuah[b-1].food,kuah[b].food);
                strcpy(kuah[b].food,tempstring);
                
                //swap id
                strcpy(tempid,kuah[b-1].id);
                strcpy(kuah[b-1].id,kuah[b].id);
                strcpy(kuah[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyakkuah;i++){
		if(strlen(kuah[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyakkuah; a++){
	        for (b = 1; b < banyakkuah; b++){
	            if (strcmp(kuah[b-1].food,kuah[b].food)>0){
	            	//swap harga
	                swapint(&kuah[b-1].harga,&kuah[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,kuah[b-1].food);
	                strcpy(kuah[b-1].food,kuah[b].food);
	                strcpy(kuah[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,kuah[b-1].id);
	                strcpy(kuah[b-1].id,kuah[b].id);
	                strcpy(kuah[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyakkuah;i++){
			if(strlen(kuah[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",kuah[i].id,kuah[i].food,kuah[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

void ikan() {
	FILE *fp=fopen("ikan.txt","r");
	int banyakikan=0;
	int i;
	list ikan[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",ikan[banyakikan].id,ikan[banyakikan].food,&ikan[banyakikan].harga);
		banyakikan++;
	}
	 printatas();
	
	 for(i=0;i<banyakikan;i++){
	 	if(strlen(ikan[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyakikan; a++){
        for (b = 1; b < banyakikan; b++)
        {
            if (ikan[b-1].harga>ikan[b].harga){
            	//swap harga
                swapint(&ikan[b-1].harga,&ikan[b].harga);
                
                //swap nama
                strcpy(tempstring,ikan[b-1].food);
                strcpy(ikan[b-1].food,ikan[b].food);
                strcpy(ikan[b].food,tempstring);
                
                //swap id
                strcpy(tempid,ikan[b-1].id);
                strcpy(ikan[b-1].id,ikan[b].id);
                strcpy(ikan[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyakikan;i++){
		if(strlen(ikan[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyakikan; a++){
	        for (b = 1; b < banyakikan; b++){
	            if (strcmp(ikan[b-1].food,ikan[b].food)>0){
	            	//swap harga
	                swapint(&ikan[b-1].harga,&ikan[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,ikan[b-1].food);
	                strcpy(ikan[b-1].food,ikan[b].food);
	                strcpy(ikan[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,ikan[b-1].id);
	                strcpy(ikan[b-1].id,ikan[b].id);
	                strcpy(ikan[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyakikan;i++){
			if(strlen(ikan[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",ikan[i].id,ikan[i].food,ikan[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

void minuman() {
	FILE *fp=fopen("minuman.txt","r");
	int banyakminuman=0;
	int i;
	list minuman[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",minuman[banyakminuman].id,minuman[banyakminuman].food,&minuman[banyakminuman].harga);
		banyakminuman++;
	}
	 printatas();
	
	 for(i=0;i<banyakminuman;i++){
	 	if(strlen(minuman[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyakminuman; a++){
        for (b = 1; b < banyakminuman; b++)
        {
            if (minuman[b-1].harga>minuman[b].harga){
            	//swap harga
                swapint(&minuman[b-1].harga,&minuman[b].harga);
                
                //swap nama
                strcpy(tempstring,minuman[b-1].food);
                strcpy(minuman[b-1].food,minuman[b].food);
                strcpy(minuman[b].food,tempstring);
                
                //swap id
                strcpy(tempid,minuman[b-1].id);
                strcpy(minuman[b-1].id,minuman[b].id);
                strcpy(minuman[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyakminuman;i++){
		if(strlen(minuman[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyakminuman; a++){
	        for (b = 1; b < banyakminuman; b++){
	            if (strcmp(minuman[b-1].food,minuman[b].food)>0){
	            	//swap harga
	                swapint(&minuman[b-1].harga,&minuman[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,minuman[b-1].food);
	                strcpy(minuman[b-1].food,minuman[b].food);
	                strcpy(minuman[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,minuman[b-1].id);
	                strcpy(minuman[b-1].id,minuman[b].id);
	                strcpy(minuman[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyakminuman;i++){
			if(strlen(minuman[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",minuman[i].id,minuman[i].food,minuman[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

void nasi() {
	FILE *fp=fopen("nasi.txt","r");
	int banyaknasi=0;
	int i;
	list nasi[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",nasi[banyaknasi].id,nasi[banyaknasi].food,&nasi[banyaknasi].harga);
		banyaknasi++;
	}
	printatas();
	
	 for(i=0;i<banyaknasi;i++){
	 	if(strlen(nasi[i].food) > 15){
	 		printf("\t%s\t%s\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
	 	}
	 	else{
	 		printf("\t%s\t%s\t\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
	 	}
	 }
	 printf("=========================================================\n");
	fclose(fp);
	
	//menu
	while(true){
	int choice;
	printf("Pilihan :\n");
	printf("1. Urutkan berdasarkan harga\n2. Urutkan berdasarkan nama\n3. Kembali\n>> ");
	scanf("%d", &choice); getchar();
	
	if(choice == 1){
	system("cls");
	int a,b;
	char tempstring[2000];
	char tempid[2000];
    for (a = 1; a < banyaknasi; a++){
        for (b = 1; b < banyaknasi; b++)
        {
            if (nasi[b-1].harga>nasi[b].harga){
            	//swap harga
                swapint(&nasi[b-1].harga,&nasi[b].harga);
                
                //swap nama
                strcpy(tempstring,nasi[b-1].food);
                strcpy(nasi[b-1].food,nasi[b].food);
                strcpy(nasi[b].food,tempstring);
                
                //swap id
                strcpy(tempid,nasi[b-1].id);
                strcpy(nasi[b-1].id,nasi[b].id);
                strcpy(nasi[b].id,tempid);
            }
        }
    }
    printatas();
	for(i=0;i<banyaknasi;i++){
		if(strlen(nasi[i].food) > 15){
			printf("\t%s\t%s\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
		}
		else{
			printf("\t%s\t%s\t\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
		}
	}
	printf("=========================================================\n");
	}
	
	else if(choice == 2){
		system("cls");
		int a,b;
		char tempstring[2000];
		char tempid[2000];
	    for (a = 1; a < banyaknasi; a++){
	        for (b = 1; b < banyaknasi; b++){
	            if (strcmp(nasi[b-1].food,nasi[b].food)>0){
	            	//swap harga
	                swapint(&nasi[b-1].harga,&nasi[b].harga);
	                
	                //swap nama
	                strcpy(tempstring,nasi[b-1].food);
	                strcpy(nasi[b-1].food,nasi[b].food);
	                strcpy(nasi[b].food,tempstring);
	                
	                //swap id
	                strcpy(tempid,nasi[b-1].id);
	                strcpy(nasi[b-1].id,nasi[b].id);
	                strcpy(nasi[b].id,tempid);
	            }
	        }
	    }
	    printatas();
		for(i=0;i<banyaknasi;i++){
			if(strlen(nasi[i].food) > 15){
				printf("\t%s\t%s\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
			}
			else{
				printf("\t%s\t%s\t\tRp. %d\n",nasi[i].id,nasi[i].food,nasi[i].harga);
			}
		}
		printf("=========================================================\n");
		}
	
	else if(choice == 3){
		system("cls");
		break;
	}
}
}

int openMenu(){
	int x;
	if(isBeginningCat == true){
		system("cls");
	}
	isBeginningCat = false;
	printf("Kategori :\n");
	printf("1. Cumi-cumi\n2. Ikan\n3. Kuah\n4. Nasi\n5. Udang\n6. Minuman\n0. Kembali\n>> ");
	scanf("%d", &x); getchar();
	system("cls");
	if(x == 1){
		cumi();
	}
	else if(x == 2){
		ikan();
	}
	else if(x == 3){
		kuah();
	}
	else if(x == 4){
		nasi();
	}
	else if(x == 5){
		udang();
	}
	else if(x == 6){
		minuman();
	}
	else{
		system("cls");
	}
	isBeginningCat = true;
}

int order(){
	list torder[100];
	system("cls");
	int i,j;
	long long k;
	char order[100];
	int quan;
	FILE *fp=fopen("mix.txt","r");
	int ind=0;
	

	list menu[100];
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%d\n",menu[ind].id,menu[ind].food,&menu[ind].harga);
		ind++;
	}
	fclose(fp);

	for(k=0;k<100;k++){
	
	for(i=0;i<ind;i++){
		int len=strlen(menu[i].food);
	for(j=0;j<len;j++){
		menu[i].food[j]=tolower(menu[i].food[j]);
	}
}
		
	}
	loadingg=false;
	system("cls");
	begin:
	loadingg=true;
	printf("==========\n");
	printf("what's your order?\n");
	printf(">>");
	scanf("%[^\n]",order);
	
	
	
		getchar();
		int len=strlen(order);
		for(i=0;i<len;i++){
		order[i]=tolower(order[i]);
		
		}
	strcpy(torder[aorder].food,order);

		
	printf("How much do u want to order\n");
	printf(">>");
	scanf("%d",&quan);
	getchar();
	torder[aorder].tquan=quan;
	for(i=0;i<ind;i++){
		if(strcmp(order,menu[i].food)==0){
			int cc=menu[i].harga;
			cc*=quan;
			torder[aorder].food_total=cc;
			totalor+=cc;
			aorder++;
			
			}
	}
	char check[100];
	printf("is there anything else(Yes/No)\n");
	printf(">>");
	scanf("%s",check);
	getchar(); 
	len =strlen(check);
	for(i=0;i<len;i++){
		check[i]=tolower(check[i]);
	}
	if(strcmp(check,"yes")==0){
		system("cls");
		 openMenu();
	}
	else{
	FILE *mem=fopen("member.txt","r");
	int memberz=0;
	int ismember=0;
	char currentmem[100];
	while(!feof(mem)){
 	fscanf(mem,"%[^\n]\n",currentmem);
	if(!strcmp(currentmem,loggedin)){
		ismember=1;
	}
 	memberz++;
 	}
 	int discount=0;
 	
	if (ismember) {
		discount=totalor*10/100;
		totalor-=discount;
	}
	printf("============================================\n");
	for(i=0;i<aorder;i++){
	printf("\t%s\t  x%d \t   %d\n",torder[i].food,torder[i].tquan,torder[i].food_total);
	}
	printf("your discount is:               %d\n",discount);
	printf("your total is:               %d\n",totalor);
	puts("Press enter to continue");
	printf("============================================\n");
	getchar();
	system("cls");
	totalor=0;
	discount=0;
	aorder=0;
//	for(i=0;i<aorder;i++){
//	
//	strcpy(torder[i].food,"\0");
//	torder[i].tquan=0;
//	torder[i].food_total=0;
//}
	}
}

	
int openStartPage(){
    int x;
    if(isBeginning == true){
    	system("cls");
    	printf("Choose an action :\n");
	}
	else{
		printf("\nChoose an action :\n");
	}
    printf("1. Show Menu\n2. Checkout\n3. Contact Person\n4. Register Member\n5. Logout\n0. Exit Program\n>> ");
    scanf("%d", &x); getchar();
    isBeginning = false;
    return x;
}

void openContactPerson(){
	system("cls");
    printf("Bambang\n+62-8515-6969-6969\n");
}
int WhoIsLogin(){
	printf("Login page \n================\n");
	printf("(1) Login\n(2) Register\n(3) Close program\n>> ");
	int xx;
	scanf("%d", &xx); getchar();
return xx;
	
}
int openLoginUser(){ // Ganti aja dari void jadi apa seperlunya
	char username[50], password[50];
	char ch;
	int i=0,j;

	repeat:
	system("cls");
	printf("Please Enter Your Account\n================\n");
	printf("Username : "); gets(username);
	strcpy(loggedin,username);
	printf("Password : "); 
	 while((ch = _getch()) != 13){
  password[i] = ch;
  i++;
  printf("*");
 }
 accfind accheck[100];
 FILE *ou=fopen("account.txt","r");
 int y=0;
 while(!feof(ou)){
 	fscanf(ou,"%[^#]#%s\n",accheck[y].acclog,accheck[y].accpass);
 	y++;
 }
 bool account_check=false;
 for(j=0;j<y;j++){
 if(strcmp(username,accheck[j].acclog)==0&&strcmp(password,accheck[j].accpass)==0){
 	account_check=true;
 }
 }
 if(account_check==false){
 	system("cls");
 	printf("============================================\n");
 	printf("account/password salah silahkan coba kembali\n");
 	printf("============================================\n");
 	sleep(1);
	return 0;
 
 }
 else{
 	system("cls");
 	printf("============================================\n");
 	printf("========== Anda Berhasil Login =============\n");
 	printf("============================================\n");
 	berhasil=0;
 	sleep(1);
 }
}

void regismem(){
	char membername[500];
	FILE *memres=fopen("member.txt","a");
	printf("==============================================\n");
	printf("\tThankyou for being a member!\n");
	printf("==============================================\n");
	fprintf(memres,"%s\n",loggedin);
 	fclose(memres);		
}
 
void regis(){
	int u=0;
	char username[500],pass[500];
	char ch;
	int i=0,j;
	FILE *ut=fopen("account.txt","a");
	printf("==============================================\n");
	printf("Please input ur username/password without space\n");
	printf("Username :"); gets(username);
	fprintf(ut,"%s#",username);
		printf("Password : "); 
	 while((ch = _getch()) != 13){
  pass[i] = ch;
  i++;
  printf("*");
 }
 	fprintf(ut,"%s\n",pass);
 	fclose(ut);		
}

int main(){
	while(berhasil){
	system("cls");
	int shadow;
	restart:{
	int option=WhoIsLogin();
	if(option==1){
		openLoginUser();
} 
	else if(option==2){
//	begin:
	system("cls");
	regis();
	system("cls");
} 
	else if(option==3){
		return 0;
	}
}}

    bool isClose = false;
    
    while(isClose == false){
        int option = openStartPage();
        if(option == 1){
            openMenu();
        }
         
        else if(option == 2){
            order();
        }
        
        else if(option == 3){
            openContactPerson();
        }
        else if(option == 4){
			regismem();
		}
		else if(option == 5){
			system("cls");
			berhasil=1;
			aorder=0;
			totalor=0;
			goto restart;
		}
		
        else if(option == 0){
            return 0;
        }
    }
}

    
