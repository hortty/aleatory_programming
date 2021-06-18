#include <iostream>
#include <stdlib.h>
#include <time.h>       /* time */

using namespace std;

	char vet[10][10], maca[10][10], seg[10][10];
	int i=0,j=0,k=0,a=0,b=0, num=0, nu=0 , k1=0, k2=0, s=0, cont=0, x1=0, x2=0;
	char c='+', h='*', g=' ';
	char perseg[10][10], perseg2[10][10], pe1=8, pe2=9, pe3=6, pe4=1;
	
void ai1() {
	
		if (vet[8][x1] == vet[k1][k2]) {
		cout << "voce perdeu" << endl;
		g = 'p';
	}
	
	if (x1<10 && x2==0) {
		x1++;
		vet[8][x1]='X';
		vet[8][x1-1]='-';
		if(x1==10) {
			x2=1;
		}
	}
	
	if (x1>0 && x2==1) {
		x1--;
		vet[8][x1]='X';
		vet[8][x1+1]='-';
		if(x1==0) {
			x2=0;
		}
}

	if (vet[8][x1] == vet[k1][k2]) {
		cout << "voce perdeu" << endl;
		g = 'p';
	}
	
}	
	
void per() {
	perseg2[pe3][pe4] = 'Y';
	vet[pe3][pe4] = perseg2[pe3][pe4];
	
	
	if (pe3 > (k1+2) ){
		pe3--;
	}
	else if (pe3 < (k1-2)) {
		pe3++;
	}
	else if (pe4 > k2+1) {
		pe4--;
	}
	else if (pe4 < k2) {
		pe4++;
	}
	if (pe4 == k2 && pe3==k1) {
		cout << endl << "voce perdeu" << endl;
		g='p';
	}
}
	
	void per2() {
	perseg[pe1][pe2] = '0';
	vet[pe1][pe2] = perseg[pe1][pe2];
	if (pe1 > (k1+1) ){
		pe1--;
	}
	else if (pe1 < (k1-1)) {
		pe1++;
	}
	
	else if (pe2 > k2+1) {
		pe2--;
	}
	else if (pe2 < k2-1) {
		pe2++;
	}
	
	if (pe2 == k2 && pe1==k1) {
		cout << endl << "voce perdeu" << endl;
		g='p';
	}
}

void print() {
	
		for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			if (i==num && j==nu) {
				vet[i][j] = h;
				maca[i][j] = vet[i][j];
			}
			
				if (vet[k1][k2] == maca[k1][k2]) {
			vet[k1][k2] = '+';
			
		if (g == 'd') {
			s++;
				num=rand()%10;
				nu=rand()%10;
		}
		if (g == 'a') {
			s++;
				num=rand()%10;
				nu=rand()%10;
		}
		if (g == 'w') {
			s++;
				num=rand()%10;
				nu=rand()%10;
		}
		if (g == 's') {
			s++;	
				num=rand()%10;
				nu=rand()%10;
		}
	}
	
			cout << vet[i][j] << " ";
			vet[i][j] = '-';
		}
		cout << endl;
	}
	
}

void score() {
	cout << endl << s << endl << endl;	
	if (s==5) {
		cout << "VOCE GANHOU" << endl;
		g='p';
	}
}

int main() {
	
	srand (time(NULL));
	
	num=rand()%10;
	nu=rand()%10;
	
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			vet[i][j] = '-';
		}
	}
	
	vet[0][0] = c;
	
	
	cout << "use (w,a,s,d) para se mover, ou (p) para sair do jogo: " << endl;
	while (g != 'p') {
		cin >> g;
		if (g=='p') {
			break;
		}
		else {
			if (g == 'd' && (k2+1)<10) {
				k2++;
				vet[k1][k2] = c;
				vet[k1][k2-1] = '-';
				per();
				per2();
				ai1();
				print();
				score();
			}
			if (g == 'a' && (k2-1)>=0) {
				k2--;
				vet[k1][k2] = c;
				vet[k1][k2+1] = '-';
				per();	per2();
				ai1();
				print();
				score();
				
			}
			if (g == 'w' && (k1-1)>=0) {
				k1--;
				vet[k1][k2] = c;
				vet[k1+1][k2] = '-';
				per();per2();
				ai1();	
				print();
				score();
			}
			if (g == 's' && (k1+1)<10) {
				k1++;
				vet[k1][k2] = c;
				vet[k1-1][k2] = '-';
				per();per2();
				ai1();
				print();
				score();
			}
		}
	}
	
	
	system("pause");
	system("pause");
	return 0;
}
