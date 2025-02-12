#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FIM 60

typedef struct {
	char nome[10], simb;
	int pt;
}Corrida;

int main() {
	int n, venc=0;
	
	printf("Quantos competidores: ");
	scanf(" %d", &n);
	system("clear");
	
	Corrida player[n];
	for(int i=0; i<n; i++) {
		printf("Nome e simbolo do player %d: ", i+1);
		scanf(" %s %c", player[i].nome, &player[i].simb);
		player[i].pt = 0;
	}
	system("clear");
	
	printf("Vamos começar a corrida... Façam suas apostas!\n");
	while(getchar() != '\n');
	system("clear");
		
	srand(time(NULL));
	do {
		for(int i = 0; i < n; i++)
            player[i].pt += 1 + rand() % 3;
            
        for(int i=0; i<n; i++)
			for(int j=0; j<n-i-1; j++)
				if(player[j].pt < player[j+1].pt) {
					Corrida aux= player[j];
					player[j]= player[j+1];
					player[j+1]= aux;
				}

        system("clear");

        for(int i=0; i<n; i++) {
            printf("%s\t", player[i].nome);

            for(int j=0; j<FIM; j++) {
                if(j <= player[i].pt)
                    printf("%c", player[i].simb);
                else
                    printf(" ");
            }

            printf("|\n");
        }
		
		system("sleep 1");
		system("clear");
		
		for(int t=0; t<n; t++) {
			if(player[t].pt >= FIM-1 && player[t].pt == player[t+1].pt) {
				venc= 1;
				printf("Empate entre %s e %s\n", player[t].nome, player[t+1].nome);
				break;
			}
			
			if(player[t].pt >= FIM-1) {
				venc= 1;
				printf("%s ganhou !!\n", player[t].nome);
				break;
			}
		}	
	}while(!venc);
	
	return 0;
}