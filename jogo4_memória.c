#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pares, cont = 0, n1, n2, erro;

    printf("================ Jogo da Memória ================\n\n");
    printf("Com quantos pares de cartas deseja jogar? ");
    scanf("%d", &pares);
    
    char enter = getchar();
    
    if (enter=='\n') {
		
		system("clear");
	}

    erro = pares;  
    int arr[pares * 2];
    int visivel[pares * 2];  

    for (int i = 0; i < pares * 2; i++) {
        visivel[i] = 0;  
    }

    srand(time(NULL));
    
    for (int i = 0; i < pares * 2; i++) {
		
        arr[i] = (i / 2) + 1;  
    }
    
    for (int i = pares * 2 - 1; i > 0; i--) {
		
        int j = rand() % (i + 1);  
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    do {
		
        printf("================ Jogo da Memória ================\n\n");
        
        for (int i = 0; i < pares * 2; i++) {
			
            if (visivel[i]) {
				
                printf("   ");  
            }
            
            if (arr[i] != 0) {
				
                printf("[] "); 
            }
        }
        printf("\n");

        for (int i = 0; i < pares * 2; i++) {
			
            printf("%02d ", i);
        }
        printf("\n\n");

        printf("Escolha um par de cartas (dê espaço entre os números): ");
        scanf("%d %d", &n1, &n2);

        if (n1 >= pares * 2 || n2 >= pares * 2 || n1 == n2 || n1 < 0 || n2 < 0) {
			
            printf("Opção Inválida. Tente novamente.\n");
            
            system("sleep 1");
            system("clear");
            
            continue;
        }

        for (int i = 0; i < pares * 2; i++) {
			
            if (i == n1 || i == n2) {
				
                printf("%02d ", arr[i]);  
            }
            
            if (visivel[i]) {
				
                printf("   ");  
                
            } else {
				
                printf("[] ");  
            }
        }
        
        system("sleep 1");
        system("clear");

        if (arr[n1] == arr[n2] && arr[n1] != 0) {
			
            printf("SHOW! Você acertou um par!\n");
            
            visivel[n1] = 1;  
            visivel[n2] = 1;
            arr[n1] = 0;  
            arr[n2] = 0;
            
            erro--; 
            
            system("sleep 1");
            system("clear");
            
        } else {
			
            printf("\nAinda não foi dessa vez...\n");
            
            system("sleep 1");
            system("clear");
            
        }
        
        cont++;

        getchar(); 
        printf("\n");
        
    } while (erro > 0);

    printf("\nVocê precisou de %d tentativas para acertar todos os pares.\n", cont);
    
    return 0;
}
