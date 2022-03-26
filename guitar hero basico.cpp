#include <iostream> 
#include <conio.h> 
#include <windows.h>
#include <ctime>

using namespace std; 

int  score=0;

void matriz(char m[20][5]) {
	int i=0, j=0;
	for (i=0;i<20;i++) {
		for (j=0;j<5;j++) {
		m[i][j] = '_';
	}
	}
	for (i=17;i<20;i=i+2) {
		for (j=0;j<5;j++) {
		m[i][j] = '#';
	}
	}
}

void print(char m[20][5], int &a2, int &a1) {
	int i=0, j=0;
	system("cls");
	cout << endl << "score: " << score << endl;
	for (i=0;i<20;i++) {
		for (j=0;j<5;j++) {
		cout << m[i][j];
	}
	cout << endl;
	}
	cout << endl << "QWERV" << endl;
	cout << "\n\n##Comandos 1 -> sair" << endl;
	Sleep(80);
}

void create(char m[20][5], int &a2) {

	srand(time(NULL));

	a2 = rand()%5;
	if (a2==0) {
		m[0][a2] = 'Q';
	}
	if (a2==1) {
		m[0][a2] = 'W';
	}
	if (a2==2) {
		m[0][a2] = 'E';
	}
	if (a2==3) {
		m[0][a2] = 'R';
	}
	if (a2==4) {
		m[0][a2] = 'V';
	}
}


int main() 
{ 
	bool i=true;
	char a;
	int aux=0, var=0;
	char m[20][5];
	int a1=0, a2=0;
	string b = "0";

	while(b=="0") {
	system("cls");
	cout << "##Game estilo Guitar Hero##" << endl;
	cout << "##Comandos 1 -> sair / 2 -> comecar" << endl;
	cout << "##Teclas: Q / W / E / R / V" << endl << endl;
	cin >> b;
	i=true;

	if (b=="1") {
		cout << "fechando programa..." << endl;
		Sleep(300);
	}
	else if (b=="2") {
	while (i==true) {
	
	if (var==0) {
		matriz(m);
		create(m, a2);
	}

	print(m, a2, a1);

	if (var==17){
		if (m[var+1][a2]==m[var][a2])
		{
			score++;
		}
		
	}
	if (var>=18){
		var=0;
	}
	else {
		var++;
		char x;
		x = m[var-1][a2];
		m[var-1][a2] = m[var][a2];
		m[var][a2] = x;
	}
	
	if (aux==1) {
		m[18][0] = ' ';
		m[18][1] = ' ';
		m[18][2] = ' ';
		m[18][3] = ' ';
		m[18][4] = ' ';
		aux=0;
	}
	
	Sleep(200);
	if (kbhit()) {
		a=getch();
    	if (a=='q'){
    		m[18][0] = 'Q';
		}
		else if (a=='w'){
    		m[18][1] = 'W';
		}
		else if (a=='e'){
    		m[18][2] = 'E';
		}
		else if (a=='r'){
    		m[18][3] = 'R';
		}
		else if (a=='v'){
    		m[18][4] = 'V';
		}
		else if (a=='1'){
			score = 0;
    		i=false;
		}
	}
		aux++;
	}
	b="0";
	}
	else {
		cout << "digite um valor valido";
		Sleep(1000);
		b="0";
	}
	}
    
	system("pause");
    return 0; 
}
