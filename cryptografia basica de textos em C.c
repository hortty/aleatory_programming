#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h> 

int i=0;

void Read_text(char c[100],char copia[100], int j, unsigned long int s) {
    unsigned long int se=0;
    int bolean=1;
    while(bolean) {
        printf("\nQual a senha?\n");
        scanf("%ld", &se);
        if (se==s) {
            printf("\nA mensagem eh:\n");
            for(i=0;i<j;i++) {
                printf("%c", copia[i]);
            }
            printf("\n\n");
            bolean=0;
        }
        else {
            printf("\nSenha incorreta, tente novamente.\n");
            printf("\nMensagem criptografada: \n");
            for(i=0;i<j;i++) {
                printf("%c", c[i]);
            }
            printf("\n");
        }
    }
}

void Cryp_text(char c[100], int j) {
    char copia[100];
    unsigned long int total=0, f=0;
    srand(time(NULL));
    int random = rand()%20;
    for(i=0;i<j;i++) {
        random = rand()%1000;
        copia[i] = c[i];
        total = random;
        if (total>5 && total<50) {
            c[i] = '*';
        }
        else if (total>128 && total<300) {
            c[i] = '6';
        }
        else if (total>500 && total<1000) {
            c[i] = ';';
        }
        else {
            c[i] = '&';
        }
    }

    printf("\nDigite uma senha (somente numeros): \n");
    scanf("%ld", &f);
    Sleep(1000);
    Read_text(c, copia, j, f);
}

void Set_text(char c[100]) {
    int j=0;
    i=0;
    while(i<100) {
    scanf("%c", &c[i]);
    if(c[i]=='.') {
        i=100;
    }
    i++;
    j++;
    }
    Cryp_text(c,j);
}

int main() {
    char c[100];
    printf("Digite sua mensagem, termine a frase com . para sair do modo de escrita: \n");
    Set_text(c); //recursive functions try
    system("pause");
    return 0;
}