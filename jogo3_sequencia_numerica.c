#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIM 100

int main() {
	
	int num, cont=0, seq[1000], erro=0;
	
	printf("================ Memória Numérica ================\n\n");
	printf("Você é bom para memorizar números? Vamos ver...\n");
	printf("A cada rodada um novo número é gerado (você tem 1 segundo ara memorizar).\n");
	printf("Você deve ser capaz de lembrar TODOS os números gerados anteriormente.\n");
	printf("LET'S PLAY\n\n");
	printf("tecle ENTER para começar o game...\n");
	
	char enter;
	
	enter = getchar();
	
	if (enter=='\n') {
		
		system("clear");
	}
	
	srand(time(NULL));
	
	for (int i = 0; i<1000; i++) {
		
		seq[i] = rand()%MAX_LIM;
		
	}
	
	do {
		
        printf("%d", seq[cont]);
		printf("\n");
			
		system("sleep 1");
		system ("clear");
			
		printf("Informe a sequência correta (dê espaço ou enter entre os números)...\n");
        
		for (int i = 0; i<=cont; i++) {
			
			scanf(" %d", &num);
            
            if (num != seq[i]) {
            
                erro = 1;
                break;
            }    
        }
            
		while (getchar() != '\n');
			
		if (!erro) {
				
			cont++;
		} else {
				
			break;
		}	
            
        system("clear");
		
	} while (!erro);
	
	
	printf("=(\n");
	printf("Você errou a sequência...\n");
	printf("Sequência correta: ");
	printf("[");
	
	for (int i = 0; i<=cont; i++) {
		
		printf(" %d ", seq[i]);
	}
	
	printf("]\n");
	printf("Fim de Jogo.\n");
	printf("Pontuação obtida: %d\n", cont);
	
	return 0;
}