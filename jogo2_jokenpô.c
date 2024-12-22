#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	int n, esc, pontoPc=0, pontoPlay=0, rod=1;
	
	srand(time(NULL));
	
	do {
		
		printf("=========== Jokenpô =============\n");
		
		printf("Rodada = %d\n\tponto PC: %d\n\tponto Pessoa: %d\n", rod, pontoPc, pontoPlay);
		
		n = rand()%4;
		while (n==0) {
			
			n = rand()%4;
		}
		
		printf("(1) tesoura\n(2) papel\n(3) pedra\n");
		scanf(" %d", &esc);
		while(getchar()!='\n');
	
		
		if(esc <= 0 || esc >= 4){
				printf("Opção inválida!\n"); 
				system("sleep 1"); 
				system("clear");
				
				continue; 
		} 
		rod++;
		
		if (n==esc) {
			
			printf("Empate\n");
		}
		
		
		if (esc==2) {
			switch (n){
					case 1: 
						printf("Pc: Papel\nPc venceu\n"); 
						pontoPc++; 
						break; 
					case 3: 
						printf("Pc: Pedra\nHumano vence\n");
						pontoPlay++;
						break; 
			}
		}
		if (esc==1){
				switch (n){
						case 2: 
							printf("Pc: Papel\nHumano vence\n");
							pontoPlay++;
							break; 
						case 3: 
							printf("Pc: Pedra\nPc vence\n");
							pontoPc++;
							break; 
				}
		}
		if (esc==3){
			
				switch (n) {
						case 1: 
							printf("Pc: Tesoura\nHumano vence\n");
							pontoPlay++;
							break;
						case 2: 
							printf("Pc: Papel\nPc vence\n");
							pontoPc++;
							break; 
				}
		}
		
		system ("sleep 1");
		system ("clear");
		
	} while (pontoPlay != 5 && pontoPc != 5);
	printf("ACABOU!\n"); 
	if(pontoPlay==5){
			printf("Player venceu!\n");
	}else{
			printf("Pc venceu!\n");
	}
}
