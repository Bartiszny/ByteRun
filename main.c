#include <stdio.h>
#include <stdlib.h>
#include "byte_run.h"
#include <string.h>

int sim_occur_search(char temp[], short licznik2, short indeks, char wyjscie[]);
char * array_resize(char *p, short licznik);
void arr_display(char *p, short licznik);
short input_procedure(char temp[], short licznik2);
int main(int argc, char const *argv[]) {
//%%%%%%%%%ZMIENNE%%%%%%%%%%%%%%

	char temp[INPUT_MAX_LEN];
	short licznik = 0;   //długość indeksów
	short licznik2 = 0;
	short indeks = 1;    // licznik indeksów tych samych liczb
	
	char wyjscie[INPUT_MAX_LEN]; //bufor
	char *p;
	p = malloc(1 * sizeof(char));  /* alokacja miejsca pod 10 elementów typu int */
	
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//Wprowadznie danych
	licznik2 = input_procedure(temp, licznik2);
	licznik = sim_occur_search(temp, licznik2, indeks, wyjscie);
	p = array_resize(p, licznik);
	memcpy(p, wyjscie, licznik);
	arr_display(p, licznik);
	
	//optional freeing
	//p=tmp;
	//p=NULL;
	//free(tmp);
	//free(p);
//%%%%%%KONIEC%%%%%%%%%%%%%%%%%%%%
	return 0;
}
int sim_occur_search(char temp[], short licznik2, short indeks, char wyjscie[]) {
	short i, j = 0;          // indeks roboczy bufora
	//%%%%%%% Szukanie podobnych wystąpień %%%%
	for (i = 0; i < licznik2; i++)
		{
			if (temp[i] == temp[i + 1])
			{
				while (temp[i + indeks] == temp[i + indeks + 1])
					{
						if (indeks < licznik2)
							indeks++;
					}
				indeks++;
				wyjscie[j] = temp[i];
				j++;
				wyjscie[j] = (char)(indeks + 48);
				i = i + indeks - 1;
				indeks = 1;
			} else
			{
				wyjscie[j] = temp[i];
				j++;
				wyjscie[j] = '1';
			}
			j++;
			
		}
		return j;
}
char * array_resize(char *p, short licznik){
	void * tmp;
	if ((tmp = realloc(p, licznik * sizeof(char))) == NULL ) {
		printf("Realloc failed\n");
		return NULL;
	}
	else
	{
		return tmp;
	}
}
void arr_display(char *p, short licznik) {
	short i;
	for (i = 0; i < licznik; i++) {
		printf("%c",*p);
		p++;
	}
}
short input_procedure(char temp[], short licznik2){
	printf("Wpisz ciąg liczb\n");
	scanf("%s", temp);
	while (*temp) {
		licznik2++;
		if (*(temp+licznik2) == '\0')
			return licznik2;
	}
	return -1;
}