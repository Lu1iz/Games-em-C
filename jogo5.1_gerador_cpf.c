#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	char cpf[12];
	int dv1=0, dv2=0;
	
	//Gerar 9 números e finalizar
	srand(time(NULL));
	for(int i=0; i<9; i++)
		cpf[i]= (rand()%10) + '0';
		
	cpf[9] = '0';
	cpf[10] = '0';
	cpf[11] = 0;	
		
	//Gerar dv1
	for(int i=0; i<9; i++)
		dv1 += ((cpf[i] - '0') *(i+1));
		
	dv1 = dv1%11;
	if(dv1 == 10)
		dv1 = 0;
		
	cpf[9] = dv1 + '0';
	
	//Gerar dv2
	for(int i=0; i<10; i++)
		dv2 += (cpf[i] - '0') *i;
		
	dv2 = dv2%11;
	if(dv2 == 10)
		dv2 = 0;
		
	cpf[10] = dv2 + '0';
	
	//Finalizar cpf	
	printf("Cpf gerado: %s\n", cpf);
	
	return 0;
}
