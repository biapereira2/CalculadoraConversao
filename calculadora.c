// Beatriz Carla Bandeira da Silva Pereira - 3°A - 2024.2
// Implementação da função de conversão de decimal para binário (1A) às 11h47 do dia 23/08/2024
// Ajuste na funçao decimalParaBin para mostrar na tela os passos para conversão de decimal para binário às 12h09 do dia 23/08/2024
// Implementaçãp da função de conversão de decimal para octal (1B) às 12h49 d0 dia 23/08/2024

#include <stdio.h>
#include <stdlib.h>

void decimalParaBin (int val, int bin[64]){
    int i = 0, resto, temp;
    temp = val;

    while (val > 0){
        resto = val % 2;
        bin[i] = resto;
        printf(" %d / 2 = %d\n", val, resto);
        val = val / 2;
        i++;
    }

    printf("%d em binario: ", temp);
    for (int bit = i - 1; bit >= 0; bit--){
        printf("%d", bin[bit]);
    }
}

void decimalParaOctal (int val, int oct[64]){
    int i = 0, resto, temp;
    temp = val; 

    if(val < 8){
        printf("Numeros menores que 8 na base 10 sao iguais na base 8. Logo, %d em decimal equivale a %d em octal.", val, val);

    } else{
        while(val >= 8){
            resto = val % 8;
            oct[i] = resto;
            printf(" %d / 8 = %d\n", val, resto);
            val = val / 8;
            i++;
        }
    }
    oct[i] = val; //armazena o ultimo valor, como eh menor que 8, tava dando errado ao printar
    
    printf("%d em octal: ", temp);

    for(int bit = i; bit >= 0; bit--){
        printf("%d", oct[bit]);
    }
}

int main (void){

    int valor, arrBin[64], arrOct[64], operacao;

    printf("Selecione a conversao que deseja realizar:\n1 - Decimal para binario\n2 - Decimal para octal\n3 - Decimal para Hexa\n4 - Decimal para BCD\n");
    scanf("%d", &operacao);

    if(operacao == 1){

        printf("Digite o valor decimal que deseja converter para binario: ");
        scanf("%d", &valor);

        decimalParaBin(valor, &arrBin[64]);

    } else if (operacao == 2){
        printf("Digite o valor decimal que deseja converter para octal: ");
        scanf("%d", &valor);

        decimalParaOctal(valor, &arrOct[64]);
    }
    return 0;
}