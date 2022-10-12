#include <stdio.h>
void funcaoCalculo(int contador_value, int indice, int ncpf[11]) {
 int i=0, soma=0, contador=contador_value, aux[11];

 for(i=0;i<indice;i++) {
 aux[i] = ncpf[i]*contador;
 contador--;
 soma+=aux[i];
 }
 soma=soma%11;

 if(soma<2) {
 ncpf[indice] = 0;
 }
 else {
 ncpf[indice] = 11 - soma;
 }
}
int main()
{
 char cpf[11];
 int ncpf[11], ccpf[11], i=0, flag=1;

 printf("Digite o CPF, sem caracteres especiais (somente numeros):\n");
 scanf("%s", cpf);
 for(i=0;i<11;i++) {
 if(i<9) {
 ncpf[i] = cpf[i] - '0';
}
ccpf[i] = cpf[i] - '0';
 }

 funcaoCalculo(10, 9, ncpf);
 funcaoCalculo(11, 10, ncpf);
printf("\n\nCPF calculado: \n");
 for(i=0;i<11;i++) {
 printf("%d", ncpf[i]);
 if(ncpf[i]!=ccpf[i]) {
 flag = 0;
}
 }
 printf("\n\nCPF digitado: \n");
 for(i=0;i<11;i++) {
 printf("%d", ccpf[i]);
 }

 if(flag==0) {
 printf("\n\nOs numeros diferem, CPF invalido!");
}
else {
printf("\n\nOs numeros sao iguais, CPF valido!");
}

 return 0;
}
