#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    char cpf[12];
    int x, dv1=0, dv2=0, val, repetido;
    
    do{
		val = 0;
		
		do{		
			x = 1;
			
			printf("\nDigite o cpf: ");
			scanf(" %s", cpf);
		
			//Validação de tamanho
			if(strlen(cpf) != 11){
				printf("\nO cpf deve conter 11 números\n");
				x = 0;
			}
		
			//Validação de letras
			for(int i=0; i<strlen(cpf); i++)	
				if(cpf[i] < '0' || cpf[i] > '9'){
					printf("\nO cpf deve conter apenas números\n");
					x = 0;
					break;
				}	
		}while(!x);		
	
		//Validação dv1
		dv1 = 0;
		for(int i=0; i<9; i++)
			dv1 += ((cpf[i] - '0') * (i+1));
		
		dv1 = dv1%11;	
		
		if(dv1 == 10)
			dv1 = 0;
					
		//Validação dv2
		dv2 = 0;
		for(int i=0; i<10; i++)
			dv2 += ((cpf[i] - '0') *i);
		
		dv2 = dv2%11;	
		
		if(dv2 == 10)
			dv2 = 0;
			
		//Validação final
		if((cpf[9] - '0') != dv1)
			printf("\nDv1 incorreto\n");
			
		if((cpf[10] - '0') != dv2)
			printf("\nDv2 incorreto\n");
			
		repetido = 0;	
		for(int i=0; i<9; i++)
			if(cpf[i] == cpf[0])
				repetido++;
				
		if(repetido>7)
			printf("\nOs números não podem ser iguais\n");
		else {
			if((cpf[9] - '0') == dv1) 
			if((cpf[10] - '0') == dv2){
				printf("\nCPF válido\n");
				val = 1;
			}	
		}
	}while(!val);
			
    return 0;
}
