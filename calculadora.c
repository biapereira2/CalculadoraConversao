// Beatriz Carla Bandeira da Silva Pereira - 3°A - 2024.2
// Implementação da função de conversão de decimal para binário (1A) às 11h47 do dia 23/08/2024
// Ajuste na funçao decimalParaBin para mostrar na tela os passos para conversão de decimal para binário às 12h09 do dia 23/08/2024
// Implementação da função de conversão de decimal para octal (1B) às 12h49 d0 dia 23/08/2024
// Implementação da função de conversão de decimal para hexadecimal (1C) às 16h do dia 23/08/2024
// Implementação da função de conversão de decimal para BCD (1D) às 15h06 do dia 27/08/2024
// Implementação da função de conversão de decimal para binário com sinal (2) às 16h21 do dia 27/08/2024

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

void decimalParaHexa(int val, int hex[64]){
    int i = 0, resto;
    int temp = val;

    while(val >= 16){
        resto = val % 16;
        if(resto < 10){
            hex[i] = resto + '0';

        } else {
            hex[i] = resto - 10 + 'A';

        }
        printf("%d / 16 = %d\n", val, resto);
        val = val / 16;
        i++;
    }
    if(val < 10){
        hex[i] = val + '0';

    } else {
        hex[i] = val - 10 + 'A';
    }

    printf("%d em hexadecimal: ", temp);
    for(int bit = i; bit >= 0; bit--){
        printf("%c", hex[bit]);
    }
}

void decimalParaBCD(int val, int bcd[64]){
    int i = 0;
    int temp = val;
    
    while (val > 0) {
        int digit = val % 10;
        for (int j = 0; j < 4; j++) { 
            bcd[i + j] = (digit >> j) & 1;
        }
        val = val / 10;
        i += 4;

    }

    printf("%d em BCD: ", temp);
    for (int bit = i - 1; bit >= 0; bit--) {
        printf("%d", bcd[bit]);
        if (bit % 4 == 0 && bit != 0) {
            printf(" ");

        }
    }
}

void decimalParaBinarioComSinal(int val, int bin[64]) {
    int i = 15;
    int negativo = 0;
    int temp = val;
    
    if (val < 0) {
        val = -val;
        negativo = 1;
    }

    while (i >= 0) {
        bin[i] = val % 2;
        val = val / 2;
        i--;
    }

    if (negativo) {
        for (i = 0; i < 16; i++) {
            bin[i] = bin[i] == 0 ? 1 : 0;

        }
        for (i = 15; i >= 0; i--) {
            if (bin[i] == 0) {
                bin[i] = 1;
                break;

            } else {
                bin[i] = 0;

            }
        }
    }

    printf("%d em binario com sinal (16 bits): ", temp);
    for (i = 0; i < 16; i++) {
        printf("%d", bin[i]);
    }
}


int main (void){

    int valor, arrBin[64], arrOct[64], arrHex[64], arrBCD[64], arrBinSinal[64], operacao;

    printf("Selecione a conversao que deseja realizar:\n1 - Decimal para binario\n2 - Decimal para octal\n3 - Decimal para Hexa\n4 - Decimal para BCD\n5 - Decimal para binario com 16 bits\n");
    scanf("%d", &operacao);

    if(operacao == 1){

        printf("Digite o valor decimal que deseja converter para binario: ");
        scanf("%d", &valor);

        decimalParaBin(valor, &arrBin[64]);

    } else if (operacao == 2){
        printf("Digite o valor decimal que deseja converter para octal: ");
        scanf("%d", &valor);

        decimalParaOctal(valor, &arrOct[64]);

    } else if (operacao == 3){
        printf("Digite o valor decimal que deseja converter para hexadecimal: ");
        scanf("%d", &valor);

        decimalParaHexa(valor, &arrHex[64]);

    } else if (operacao == 4){
        printf("Digite o valor decimal que deseja converter para BCD: ");
        scanf("%d", &valor);
        decimalParaBCD(valor, &arrBCD[64]);

    } else if (operacao == 5){
        printf("Digite o valor decimal que deseja converter para binario com 16 bits: ");
        scanf("%d", &valor);
        decimalParaBinarioComSinal(valor, &arrBinSinal[64]);
    }

    return 0;
}