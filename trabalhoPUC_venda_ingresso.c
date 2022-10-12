#include <stdio.h>
#include <stdbool.h>

void mostrarPlateia(int matriz[14][10], char matriz2[14][10]) {
	int i=0, j=0;
		printf("ocupacao da sala:\n");
		for(i=0;i<14;i++) {
		for(j=0;j<10;j++) {
			if(matriz2[i][j] == '-') {
			
			if(matriz[i][j] > 99) {
				if(matriz2[i][j] == '-') {
				printf("%d", matriz[i][j]);
			}
							printf(" ");
			}
			else{
				if(matriz[i][j] > 9) {
										printf(" ");
					if(matriz2[i][j] == '-') {
					printf("%d", matriz[i][j]);
				}
									printf(" ");
				}
				else {
										printf("  ");
					if(matriz2[i][j] == '-') {
					printf("%d", matriz[i][j]);
				}
				printf(" ");
				}
			}
		}
		}
		printf("\n");
	}	
}

void venderIngresso(int matriz[14][10], char matriz2[14][10]) {
	mostrarPlateia(matriz, matriz2);
	int poltrona, i=0, j=0;
	char tipo_venda;
	bool flag= true;
	printf("Qual sua poltrona <1..144>: ");
	while(flag) {
	scanf("%d", &poltrona);
		getchar();
			for(i=0;i<14;i++) {
				for(j=0;j<10;j++) {
					if(matriz[i][j]==poltrona) {
						if(matriz2[i][j] == '-') {
						flag=false;
							printf("\nQual o tipo, meia ou inteira: ");
							scanf("%c", &tipo_venda);
							matriz2[i][j] = tipo_venda;
						}
					}
				}
			}
			if(flag) {
				printf("Cadeira ocupada, digite outro valor: ");
			}
}
}

void print(char matriz[][10]) {
	int i=0, j=0;
		printf("ocupacao da sala:\n");
		for(i=0;i<14;i++) {
			for(j=0;j<10;j++) {
				printf("%c ", matriz[i][j]);	
			}
			printf("\n");
		}
	}

int main() {
	
	int matriz[14][10], i=0, j=0, cont=1, estado=1;
	char matriz2[14][10];
	int menu = 1;
	
	for(i=0;i<14;i++) {
		for(j=0;j<10;j++) {
			matriz[i][j] = cont;
			cont++;
		}
	}
		for(i=0;i<14;i++) {
			for(j=0;j<10;j++) {
			matriz2[i][j] = '-';
		}
	}
	
	while(menu != 0) {
		printf("--- Cinema 'Ciber' ---\n0 - sair\n1 - vender ingresso\n2 - mostrar plateia\n3 - mostrar ocupacao\nQual sua opcao: ");
		scanf("%d", &menu);
		getchar();
		
		switch(menu) {
			case 1:
					venderIngresso(matriz, matriz2);
				break;
			case 2:
					mostrarPlateia(matriz, matriz2);
				break;
			case 3:
					print(matriz2);
				break;		
		}
	}



	
	return 0;
}
