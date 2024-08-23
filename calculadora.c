// Beatriz Carla Bandeira da Silva Pereira - 3°A - 2024.2
// Implementação da função de conversão de decimal para binário (1A) às 11h47 do dia 23/08/2024
// Ajuste na funçao decimalParaBin para mostrar na tela os passos para conversão de decimal para binário às 12h09 do dia 23/08/2024

#include <stdio.h>
#include <stdlib.h>

void decimalParaBin (int val, int bin[64]){
    int i = 0, resto;
    while (val > 0){
        resto = val % 2;
        bin[i] = resto;
        printf(" %d / 2 = %d\n", val, resto);
        val = val / 2;
        i++;
    }

    for (int bit = i - 1; bit >= 0; bit--){
        printf("%d", bin[bit]);
    }
}

int main (void){

    int valor, arr[64];

    printf("Digite o valor decimal que deseja converter para binario: ");
    scanf("%d", &valor);

    decimalParaBin(valor, &arr[64]);

    return 0;
}