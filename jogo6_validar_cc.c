#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cartao[17];
    int val, dig, g1 = 0, g2 = 0, checksum = 0, soma = 0, x = 0;

    do {
        printf("\nDigite o n° do seu cartão: ");
        scanf(" %s", cartao);

        if (strlen(cartao) != 16) {
			
            printf("\nNúmero inválido\n");
            continue;
        }
		
		val = 0;
		do {
			
			for(int j=0; j<16; j++)
				if(cartao[j] < '0' || cartao[j] > '9') {
					
					printf("\nNúmero inválido\n");
					continue;
				} else
					val = 1;
		} while(!val);

        g1 = 0;
        g2 = 0;

        for (int i = 0; i < 16; i +=2) {
			
            dig = cartao[i] - '0'; 
            dig *= 2;

            if (dig >= 10) {
				
                soma = (dig / 10) + (dig % 10); 
                g1 += soma;
            } else 
                g1 += dig;
        }

        for (int i = 1; i < 16; i += 2) 
            g2 += cartao[i] - '0'; 

        checksum = g1 + g2;

        if (checksum % 10 == 0) {
			
            x = 1;
            printf("\nNúmero válido\n");
        } else 
            printf("\nNúmero inválido\n");
    } while (!x);

    return 0;
}
