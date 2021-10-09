#include<stdio.h>

/* 
? cilem tohoto programu je overeni sily hesel, ktera budou zadana na vstupu, a to podle predem stanovenych podminek
? hesla, ktera projdou podminkami se na konci celeho programu vypisi do konzole
? program dostane hesla a jedno po druhem zpracuje
! POZOR / program bude mit nekolik vstupnich argumentu (LEVEL, PARAM)
*podminky jsou nasledujici: 
*	1. heslo obsahuje alespon jedno velke a jedno male pismeno
*	2. od zadaneho argumnetu PARAM se odviji pocet skupin znaku, ktere heslo obsahuje:
*		--mala pismena(a-z)
*		--velka pismena(A-Z)
*		--cisla(0-9)
*		--specialni znaky(podporované musí být alespoň nealfanumerické znaky z ASCII tabulky na pozicích 33-126 32-126, tedy včetně mezery)
* 3. heslo neobsahuje PARAM po sobe jdoucich znaku
* 4. heslo neobsahuje dva stejne podretezce delky alespon PARAM
! pocita se s zpracovanim statistik o heslech (vice na wiki IZP)
*/

int main(){
	char pwd[100];

	printf("Zadejte heslo: \n");
	scanf("%s", &pwd);

	/* Zde overime, zda-li neni heslo prilis dlouhe.*/
	int pwd_length = 0;
	int pwd_length_correct = 0;

	while(pwd_length_correct == 0){
		while(pwd[pwd_length] != '\0'){
			pwd_length++;
		}
		printf("pwd_length = %d\n", pwd_length);

		if(pwd_length > 100){
			printf("Heslo je prilis dlouhe! Zadejte kratsi heslo. Maximalni delka hesla je 100 znaku. \n" );

			printf("Zadejte heslo: \n");
			scanf("%s", &pwd);
			pwd_length = 0;
		} else {
			pwd_length_correct = 1;
		}
	}


	int num_lowercase = 0; // pocet malych pismen v hesle
	int num_uppercase = 0; // pocet velkych pismen v hesle
	int num_numbers = 0; //  pocet cisel v hesle

	//cyklus pro vypocitani poctu malych, velkych pismen a cisel 
	int i;
	for(i = 0; pwd[i] != '\0'; i++){
		if(pwd[i] <= 'z' && pwd[i] >= 'a'){
			num_lowercase += 1;
		} //else 
		if(pwd[i] <= 'Z' && pwd[i] >= 'A') {
			num_uppercase += 1;
		} //else 
		if((pwd[i] >= '0') && (pwd[i] <= '9')){
			num_numbers += 1;
		}
	}

	if(num_lowercase > 0 && num_uppercase > 0){
		printf("Heslo obsahuje dostatecny pocet velkych a malych pismen.\n");
	}

	printf("Zadane heslo je %s\n", &pwd);
	//printf("\n");
	
	
	printf("Pocet malych pismen je %d\n", num_lowercase);
	printf("Pocet velkych pismen je %d\n", num_uppercase);
	printf("Pocet cisel je %d\n", num_numbers);


	return 0;
}
