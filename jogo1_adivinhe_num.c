#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIM 100

int main(){
	
	int num, tentativa, cont=0;
	
	printf("Adivinhe o número: \n");
	 
	srand(time(NULL));
	num = 1 + rand()%MAX_LIM;
	 
	do{
		 
		scanf(" %d", &tentativa);
			
		if(num<tentativa){
				
			printf("Menor\n");
			cont++;
			continue;
		}
			
		if(num>tentativa){
				
			printf("Maior\n");
			cont++;
			continue;
		}
			
		if(num==tentativa){
				
			printf("Acertou!!\n");
			cont++;
			break;
		}
			
	} while(num!=tentativa);
		
	system("sleep 2");
	system("clear");
		
	printf("Agora é a vez do computador jogar!\n");
	printf("Pense em um número de 1 a 100!\n\n");
				
	int num2, cont2=0, lim_inf = 1, lim_sup = MAX_LIM;
	char simb;
	
	do{
		
		num2 = lim_inf + rand() % (lim_sup - lim_inf + 1);
		
		printf("PC chutou... %d\n\n", num2);
		
		printf("Digite '<' se menor\n");
		printf("Digite '>' se maior\n");
		printf("Digite '=' se o pc acertar\n\n");
		
		scanf(" %c", &simb);
		
		switch(simb){
			
			case '<' :
				lim_sup = num2 - 1;
				cont2++;
				system("sleep 1");
				system("clear");
				break;
				
			case '>' : 
				lim_inf = num2 + 1;
				cont2++;
				system("sleep 1");
				system("clear");
				break;
				
			case '=' :
				cont2++;
				system("sleep 1");
				system("clear");
				break;
		}
		
	} while((simb != '='));
	
	printf("Tentativas do Humano : %d\n", cont);
	printf("Tentativas do PC : %d\n", cont2);
	
	if(cont<cont2)
		printf("\nHumano ganhou!\n");
		
	if(cont>cont2)
		printf("\nPC ganhou!\n");
		
	if(cont==cont2)
		printf("\nEmpate!\n");
	
	return 0;
}
