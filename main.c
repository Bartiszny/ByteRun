#include <stdio.h>
#include <stdlib.h>
#include "byte_run.h"
#include <string.h>

int main(int argc, char const *argv[]) {
//%%%%%%%%%ZMIENNE%%%%%%%%%%%%%%

	char temp[INPUT_MAX_LEN];
	short licznik=0;   //długość indeksów
	short licznik2 =0;
	short indeks =1;    // licznik indeksów tych samych liczb
	short j=0;          // indeks roboczy bufora
	char wyjscie[INPUT_MAX_LEN]; //bufor
	char *p;
	void *tmp;  /* tymczasowy wskaźnik typu void */
	p = malloc(1 * sizeof(char));  /* alokacja miejsca pod 10 elementów typu int */
	
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//Wprowadznie danych
	printf("Wpisz ciąg liczb\n");
	scanf("%s", &temp);
	while (*temp){
		licznik2++;
		if (temp[licznik2] == '\0')
			break;
	}
//%%%%%%% Inicjalizacja bufora %%%%
	for (size_t i = 0; i < sizeof(temp) /*INPUT_MAX_LEN*/; i++) {
		wyjscie[i]='0';
	}
//%%%%%%% Szukanie podobnych wystąpień %%%%
	for (size_t i=0; i<licznik2;i++)
		{
			if(temp[i]==temp[i+1])
			{
				while (temp[i+indeks]==temp[i+indeks+1])
					{
						if(indeks<sizeof(temp))
							indeks++;
					}
				indeks++;
				wyjscie[j]=temp[i];
				j++;
				wyjscie[j]=(char)(indeks+48);
				i=i+indeks-1;
				indeks=1;
			} else
			{
				wyjscie[j]=temp[i];
				j++;
				wyjscie[j]='1';
			}
			j++;
			licznik=j;
		}
	//printf("%d",j);

	if ((tmp = realloc(p, licznik * sizeof(char))) == NULL ) {
		printf("Realloc failed\n");
	}
	else
	{
		p = tmp;
		tmp = p;
	}
	
	//printf("%d\n",licznik);   
	memcpy(p, wyjscie, licznik);
	
	for (size_t i = 0; i < licznik; i++) {
		printf("%c",*p);
		p++;
	}
	//optional freeing
	//p=tmp;
	//p=NULL;
	//free(tmp);
	//free(p);
	
	
//%%%%%%KONIEC%%%%%%%%%%%%%%%%%%%%
	return 0;
}