#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

    using namespace std;

void matriz(char m[15][15], int &a8, int &a9) {
	int i=0,j=0;
	
	srand(time(NULL));
	
	a9 = rand()%14;
	a8 = rand()%14;
	
	if (a9==0 && a8==0) {
	a9 = rand()%14;
	a8 = rand()%14;
	}
	
	for (i=0;i<15;i++) {
		for (j=0;j<15;j++) {
		m[i][j] = '-';
		m[0][0] = '*';
		m[a8][a9] = 'O';
	}
	}
}

void printm(char m[15][15], int &a8, int &a9, int &i, int &j, int var, int &seg) {
	int i1=0,j2=0;
	system("cls");
	if (i==a8 && j==a9) {
	
	srand(time(NULL));
	
	a9 = rand()%14;
	a8 = rand()%14;
	
	m[i][j] = 'X';
	
	
	seg++;
	
	m[a8][a9] = 'O';
	
	}
	
	for (i1=0;i1<15;i1++) {
		for (j2=0;j2<15;j2++) {
		cout << m[i1][j2];
		if (i1 == 0 && j2 == 14) {
			cout << "               score: " << seg;
		}
	}
	cout << endl;
	}
}

void andar(int var, char m[15][15], int &i, int &j, int seg) {


	if (var==1){
		
		j++;
        if (j>14) {
        m[i][j-1]='-';
		j=0;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
		m[i][j-1]='-';
		}
		
}
	else if (var==2){
	
		j--;
        if (j<0) {
        m[i][j+1]='-';
		j=14;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i][j+1]='-';
		}
		
	}
	else if (var==3){
		i--;
        if (i<0) {
        m[i+1][j]='-';
		i=14;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i+1][j]='-';
		}	
	}
	else if (var==4){
        i++;
        if (i>14) {
        m[i-1][j]='-';
		i=0;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i-1][j]='-';
		}
	}
}

int main()
{
	char m[15][15];
	int i=0,j=0,var=1, a8, a9;
	int seg=0;
	matriz(m, a8, a9);
    bool repeat = true;
    while (repeat)
    {
    	andar(var, m, i, j, seg);
        printm(m, a8, a9, i, j, var, seg);
        cout << "///////////////" << endl;
        Sleep(30);

        if (kbhit())
        {
            char ch = getch();
            switch (ch)
            {
            	
        case 77: //Seta para direita
        j++;
        if (j>14) {
        m[i][j-1]='-';
		j=0;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
		m[i][j-1]='-';
		}
        var=1;
            break;
			    	
        case 75: //Seta para esquerda
        j--;
        if (j<0) {
        m[i][j+1]='-';
		j=14;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i][j+1]='-';
		}
        var=2;
            break;
            
        case 72: //Seta para cima
        i--;
        if (i<0) {
        m[i+1][j]='-';
		i=14;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i+1][j]='-';
		}	
		var=3;
        break;
            
        case 80: //Seta para baixo
        i++;
        if (i>14) {
        m[i-1][j]='-';
		i=0;
		m[i][j]='*';
		}
		else {
		m[i][j]='*';
        m[i-1][j]='-';
		}
		var=4;
            break; 
			          
            }
        }
    }
    return 0;
}
