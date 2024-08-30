// Beatriz Carla Bandeira da Silva Pereira - 3°A - 2024.2
// Implementação da função de conversão de decimal para binário (1A) às 11h47 do dia 23/08/2024
// Ajuste na funçao decimalParaBin para mostrar na tela os passos para conversão de decimal para binário às 12h09 do dia 23/08/2024
// Implementação da função de conversão de decimal para octal (1B) às 12h49 d0 dia 23/08/2024
// Implementação da função de conversão de decimal para hexadecimal (1C) às 16h do dia 23/08/2024
// Implementação da função de conversão de decimal para BCD (1D) às 15h06 do dia 27/08/2024
// Implementação da função de conversão de decimal para binário com sinal (2) às 16h21 do dia 27/08/2024
// Implementação da função de conversão de real para float (3) às 20h33 do dia 28/08/2024
// Implementação da função de conversão de real para double (3) às 10h54 do dia 30/08/2024
// Revisão de funções às 11h do dia 30/08/2024

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
        printf("vals menores que 8 na base 10 sao iguais na base 8. Logo, %d em decimal equivale a %d em octal.", val, val);

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

void realParaFloat(double val, int *i, int *bin, int resultado) {
    int parte_inteira;
    double parte_fracionaria;
    int armazena_fracao[24] = {0};
    int k = 0, cont = 1, expoente = 0, sinal;

    if (val < 0){
        sinal = 1;
    }
    else{
        sinal = 0;
    }

    printf("Numero original: %lf\n", val);
    printf("Sinal: %d (0 para positivo, 1 para negativo)\n", sinal);

    if (sinal) {
        val = -val;
    }

    parte_inteira = (int)val;
    parte_fracionaria = val - parte_inteira;

    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte fracionaria: %lf\n", parte_fracionaria);


    while (parte_fracionaria != 0 && cont <= 23) {
        printf("Multiplicacao: %lf x 2 = ", parte_fracionaria);
        parte_fracionaria = parte_fracionaria * 2;

        printf("%lf, ", parte_fracionaria);
        armazena_fracao[k] = (int)parte_fracionaria;

        printf("Parte inteira extraida: %d, ", armazena_fracao[k]);
        parte_fracionaria = parte_fracionaria - armazena_fracao[k];
        printf("Nova parte fracionaria: %lf\n", parte_fracionaria);

        k++;
        cont++;
    }

    while (resultado != 0) {
        printf("Dividindo %d por 2:\n", resultado);
        bin[*i] = resultado % 2;
        printf("Resto = %d\n", bin[*i]);
        resultado = resultado / 2;
        printf("Quociente = %d\n\n", resultado);
        (*i)++;
    }

    for (int j = 0; j < (*i) / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }

    printf("Parte inteira em binario (invertida): ");

    for (int j = 0; j < *i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n");

    if (*i > 0) {
        expoente = (*i) - 1; 
    } else {
        while (parte_fracionaria < 1 && parte_fracionaria > 0) {
            parte_fracionaria *= 2;
            expoente--;
            printf("Multiplicando a parte fracionaria por 2: %lf, novo expoente: %d\n", parte_fracionaria, expoente);
        }
    }
    printf("Expoente calculado: %d\n", expoente);
    int expoente_com_vies = expoente + 127;
    printf("Expoente com vies: %d\n", expoente_com_vies);
    
    printf("Mantissa: ");
    int mantissa_index = 0;
    
    for (int j = 1; j < *i; j++) {
        printf("%d", bin[j]);
        mantissa_index++;
    }
    
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    
    while (mantissa_index < 23) {
        printf("0");
        mantissa_index++;
    }
    
    printf("\n");

    printf("Representacao binaria = ");
    printf("%d ", sinal); 
    for (int j = 7; j >= 0; j--) {
        printf("%d", (expoente_com_vies >> j) & 1); 
    }
    printf(" ");
    mantissa_index = 0;  
    for (int j = 1; j < *i; j++) {  
        printf("%d", bin[j]);
        mantissa_index++;
    }
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    while (mantissa_index < 23) {
        printf("0");
        mantissa_index++;
    }
    printf("\n");
}

void realParaDouble(double val, int *i, int *bin, int resultado) {
    int parte_inteira;
    double parte_fracionaria;
    int armazena_fracao[53] = {0};
    int k = 0, cont = 1, expoente = 0, sinal;

    if (val > 0){
        sinal = 0;
    }
    else{
        sinal = 1;
    }

    if (sinal) {
        val = -val;
    }

    printf("Numero original: %lf\n", val);
    printf("Sinal: %d (0 para positivo, 1 para negativo)\n", sinal);

    parte_inteira = (int)val;
    parte_fracionaria = val - parte_inteira;

    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte fracionaria: %lf\n", parte_fracionaria);

    while (parte_fracionaria != 0 && cont <= 52) {
        printf("Multiplicacao: %lf x 2 = ", parte_fracionaria);
        parte_fracionaria = parte_fracionaria * 2;

        printf("%lf, ", parte_fracionaria);
        armazena_fracao[k] = (int)parte_fracionaria;

        printf("Parte inteira extraida: %d, ", armazena_fracao[k]);
        parte_fracionaria = parte_fracionaria - armazena_fracao[k];
        printf("Nova parte fracionaria: %lf\n", parte_fracionaria);
        k++;
        cont++;
    }

    while (resultado != 0) {
        printf("Dividindo %d por 2:\n", resultado);
        bin[*i] = resultado % 2;
        printf("Resto = %d\n", bin[*i]);
        resultado = resultado / 2;
        printf("Quociente = %d\n\n", resultado);
        (*i)++;
    }

    for (int j = 0; j < (*i) / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }

    printf("Parte inteira em binario (invertida): ");

    for (int j = 0; j < *i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n");

    if (*i > 0) {
        expoente = (*i) - 1; 
    } else {
        while (parte_fracionaria < 1 && parte_fracionaria > 0) {
            parte_fracionaria *= 2;
            expoente--;
            printf("Multiplicando a parte fracionaria por 2: %lf, novo expoente: %d\n", parte_fracionaria, expoente);
        }
    }
    printf("Expoente calculado: %d\n", expoente);

    int expoente_com_vies = expoente + 1023;
    printf("Expoente com vies: %d\n", expoente_com_vies);


    printf("Mantissa: ");
    int mantissa_index = 0;

    for (int j = 1; j < *i; j++) {
        printf("%d", bin[j]);
        mantissa_index++;
    }

    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }

    while (mantissa_index < 52) {
        printf("0");
        mantissa_index++;
    }
    
    printf("\n");

    printf("Representacao binaria = \n");
    printf("%d ", sinal); 
    for (int j = 10; j >= 0; j--) {
        printf("%d", (expoente_com_vies >> j) & 1);  
    }
    printf(" ");
    mantissa_index = 0;  
    for (int j = 1; j < *i; j++) { 
        printf("%d", bin[j]);
        mantissa_index++;
    }
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    while (mantissa_index < 52) {
        printf("0");
        mantissa_index++;
    }
    printf("\n");
}

int main (void){

    int valor, arrBin[64], arrOct[64], arrHex[64], arrBCD[64], arrBinSinal[64], operacao, *i, *bin, resultado;
    float valor_float;

    printf("Selecione a conversao que deseja realizar:\n1 - Decimal para binario\n2 - Decimal para octal\n3 - Decimal para Hexa\n4 - Decimal para BCD\n5 - Decimal para binario com 16 bits\n6 - Real para float com sinal, expoente e fracao\n7 - Real para double com sinal, expoente e fracao");
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

    } else if (operacao == 6){
        printf("Digite o valor real que deseja converter float e double: ");
        scanf("%f", &valor_float);
        realParaFloat(valor_float, i, bin, resultado);

    } else if (operacao == 7){
        printf("Digite o valor real que deseja converter float e double: ");
        scanf("%f", &valor_float);
        realParaDouble(valor_float, i, bin, resultado);

    } else {
        printf("Opcao invalida! Tente novamente.");

    }
    return 0;
}