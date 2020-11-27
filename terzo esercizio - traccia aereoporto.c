
/*
 ============================================================================
 Name        : terzo.c
 Author      : piersilvio
 Version     :
 Copyright   :
 Description : prova dell'aereoporto
 ============================================================================
 */

 /*
 ho un errore logico quando inserisco
 durante l'input
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_fly 100


//struct declaration
typedef struct{

	char cod_volo[10];
	char citta_partenza[10];
	char citta_arrivo[10];
	int tot_posti;
	int posti_occup;

}volo;

int n_voli = 0; //>0

//struct definition
volo vol[max_fly];

//inputs
int scelta;
int num_posti;

//working variables
int i = 0;
bool flag = false; //flag = false;

void prenotazione();
void inserimento();

int main(){


	do{
		printf(":: Insert the number of flys: \n");
		scanf("%d", &n_voli);

	}while(n_voli == 0);

    inserimento();

    do{

        prenotazione();
        printf(":: do you want to perform another operation? (1.yes) (2.no)");
        scanf("%d", &scelta);

    }while(scelta == 1);

    return 0;
}

void prenotazione(){
	char cod_volo = ' ';

    printf(":: insert the code of fly: \n");
    scanf("%s", &cod_volo);

    i = 0;

    do{

        if(strcmp(&cod_volo, vol[i].cod_volo) == 0){

            printf(":: insert the number of seat to prenotate: \n");
            scanf("%d", &num_posti);
            fflush(stdin);

            if(vol[i].tot_posti >= num_posti){
                flag = true;
                vol[i].posti_occup = vol[i].posti_occup + num_posti;
            }

            if(flag == true)
            	printf(":: fly rented with succesfuly! \n");
            else
            	printf(":: Could not rent the fly! \n");

        }else
        	printf(":: the inserted code is not valid! \n");

        i = i + 1;

    }while(i <= n_voli);

}

void inserimento(){

    for(i = 0; i < n_voli; i++){ //utilizzo il for per dbugguare

        printf(":: Insert code of vole: \n");
		scanf("%s", vol[i].cod_volo);
		printf(":: insert city of the departure: \n");
		scanf("%s", vol[i].citta_partenza);
		printf(":: insert city of the arrival: \n");
		scanf("%s", vol[i].citta_arrivo);
		printf(":: insert total of seats: \n");
		scanf("%d", &vol[i].tot_posti);
		printf(":: insert the number of occuped seats: \n");
		scanf("%d", &vol[i].posti_occup);
    }
}

