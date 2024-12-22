#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	int cc[17]; 
	int checksum=0, dig=0, soma=0, g1=0, g2=0, x=0;
	
	srand(time(NULL));

	
	do{
		checksum = g1 = g2 = 0;
		
		//Gerar números de 16 digitos
		for(int i=0; i<16; i++)
			cc[i] = (rand()%10);
			
		//Validar g1						
		for(int i = 0; i < 16; i +=2) {
			
			dig = cc[i]; 
			dig *= 2;

			if(dig >= 10) {
			
				soma = (dig / 10) + (dig % 10); 
				g1 += soma;
			} else 
				g1 += dig;
		}
		
		//Validar g2
		for(int i = 1; i < 16; i += 2) 
			g2 += cc[i]; 

		checksum = g1 + g2;
		
		cc[16] = 0;	

		//Condição final de loop
		if(checksum % 10 == 0) 
			x = 1;
	}while(!x);
	
	//Gerar cartão de crédito válido
	printf("Gerador cc: ");
	for(int j=0; j<16; j++)
		printf("%d", cc[j]);
		
	printf("\n");	
	
	return 0;
}
