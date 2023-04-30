#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 50

typedef struct {
   char ime[20];
   char prezime[20];
   int godina_rodjenja;
   char pozicija[20];
   float plata;
} Zaposleni;

void noviZaposleni();
void obrisiZaposlenog();
void azurirajZaposlenog();
void pretraziZaposlenog();
void brojZaposlenih();
void izlaz();

Zaposleni zaposleni[MAX_EMPLOYEES];
int broj_zaposlenih = 0;
int i, j;
int izbor;
int broj_pronadjenih = 0;
char pozicija[20];
float ukupna_plata = 0;

int main() {
	do{
		printf("Izaberite opciju:\n");
		printf("1. Dodaj novog zaposlenog\n");
		printf("2. Brisi postojeceg zaposlenog\n");
		printf("3. Azuriraj informacije o zaposlenom\n");
		printf("4. Pretrazi zaposlene po poziciji\n");
		printf("5. Broj zaposlenih\n");
		printf("6. Izlaz iz programa\n");
		scanf("%d", &izbor);

		if(izbor<1 || izbor>6){
			printf("\nProbajte ponovo\n");
		} 

	  switch(izbor)
	  {
	  case 1 :
		  noviZaposleni();
		  break;
	  case 2 :
		  obrisiZaposlenog();
		  break;
	  case 3 :
		  azurirajZaposlenog();
		  break;
	  case 4 :
		  pretraziZaposlenog();
		  break;
	  case 5 :
		  brojZaposlenih();
	  case 6 :
		  izlaz();
		  break;
	  }
	}while(izbor != 6);

   return 0;
}

void noviZaposleni()
{
         if(broj_zaposlenih == MAX_EMPLOYEES) {
            printf("Greska: ne mozete dodati vise zaposlenih\n");
         }
         printf("Unesite ime zaposlenog: ");
		 fflush(stdin);
         gets(zaposleni[broj_zaposlenih].ime);
		 fflush(stdin);
         printf("Unesite prezime zaposlenog: ");
         gets(zaposleni[broj_zaposlenih].prezime);
		 fflush(stdin);
         printf("Unesite godinu rodjenja zaposlenog: ");
         scanf_s("%d", &zaposleni[broj_zaposlenih].godina_rodjenja);
		 fflush(stdin);
         printf("Unesite poziciju zaposlenog: ");
         gets(zaposleni[broj_zaposlenih].pozicija);
		 fflush(stdin);
         printf("Unesite platu zaposlenog: ");
         scanf_s("%f", &zaposleni[broj_zaposlenih].plata);
		 fflush(stdin);
		 broj_zaposlenih++;
}

 void obrisiZaposlenog()
 {
     if(broj_zaposlenih == 0) {
         printf("Greska: nema zaposlenih za brisanje\n");
     }
     printf("Unesite redni broj zaposlenog za brisanje: ");
     scanf_s("%d", &i);
     if(i < 1 || i > broj_zaposlenih) {
          printf("Greska: neispravan redni broj zaposlenog\n");
	 }
	 for(j = i - 1; j < broj_zaposlenih - 1; j++) {
		strcpy(zaposleni[j].ime, zaposleni[j+1].ime);
		strcpy(zaposleni[j].prezime, zaposleni[j+1].prezime);
		zaposleni[j].godina_rodjenja = zaposleni[j+1].godina_rodjenja;
		strcpy(zaposleni[j].pozicija, zaposleni[j+1].pozicija);
		zaposleni[j].plata = zaposleni[j+1].plata;
	  }
	  broj_zaposlenih--;
}

 void azurirajZaposlenog()
 {
		if(broj_zaposlenih == 0) {
			printf("Greska: nema zaposlenih za azuriranje\n");
        }
		printf("Unesite redni broj zaposlenog za azuriranje: ");
		scanf_s("%d", &i);
		if(i < 1 || i > broj_zaposlenih) {
			printf("Greska: neispravan redni broj zaposlenog\n");
		}
		printf("Unesite novo ime zaposlenog: ");
		fflush(stdin);
		gets(zaposleni[i-1].ime);
		printf("Unesite novo prezime zaposlenog: ");
		fflush(stdin);
		gets(zaposleni[i-1].prezime);
		printf("Unesite novu godinu rodjenja zaposlenog: ");
		fflush(stdin);
		scanf_s("%d", &zaposleni[i-1].godina_rodjenja);
		printf("Unesite novu poziciju zaposlenog: ");
		fflush(stdin);
		gets(zaposleni[i-1].pozicija);
		printf("Unesite novu platu zaposlenog: ");
		fflush(stdin);
		scanf_s("%f", &zaposleni[i-1].plata);
}

 void pretraziZaposlenog()
 {
		if(broj_zaposlenih == 0) {
			printf("Greska: nema zaposlenih za pretragu\n");
		}
		printf("Unesite poziciju za pretragu: ");
		fflush(stdin);
		gets(pozicija);
     
		for(i = 0; i < broj_zaposlenih; i++) {
			if(strcmp(pozicija, zaposleni[i].pozicija) == 0) {
				printf("%d. %s %s %d %s %.2f\n", i+1, zaposleni[i].ime, zaposleni[i].prezime, zaposleni[i].godina_rodjenja, zaposleni[i].pozicija, zaposleni[i].plata);
				broj_pronadjenih++;
				ukupna_plata += zaposleni[i].plata;
			}
		}
		if(broj_pronadjenih == 0) {
			printf("Nema zaposlenih sa tom pozicijom\n");
		}
		else {
			printf("Prosecna plata za poziciju %s je %.2f\n", pozicija, ukupna_plata/broj_pronadjenih);
		}
}

void brojZaposlenih()
{
		if(broj_zaposlenih == 0) {
			printf("Greska: nema zaposlenih za ispis\n");
		}
		for(i = 0; i < broj_zaposlenih; i++) {
			printf("%d. %s %s %d %s %.2f\n", i+1, zaposleni[i].ime, zaposleni[i].prezime, zaposleni[i].godina_rodjenja, zaposleni[i].pozicija, zaposleni[i].plata);
		}
}

void izlaz()
{	
	printf("Kraj programa\n");
}