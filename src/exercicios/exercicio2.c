#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define TAM 10000
int vetor01[TAM][TAM]; //global
int vetor02[TAM][TAM]; //global
int vetor03[TAM][TAM]; //global

void preencheVetor_01_02(){
	int i=0;
    int j=0;
	for (i=0;i<TAM;i++) {
        for (j=0;j<TAM;j++) {
            vetor01[i][j]=1;
            vetor02[i][j]=2;
        }
	}
}

void func1(){
	int i=0;
    int j=0;
    for (i=0;i<TAM;i++) {
        for (j=0;j<TAM;j++) {
            vetor03[i][j]=vetor01[i][j] + vetor02[i][j];
        }
	}
}

void mostrar(){
    int i=0;
    int j=0;
    for (i=0;i<TAM;i++) {
        for (j=0;j<TAM;j++) {
            printf("%d ", vetor03[i][j]);
        }
	}
}

int main() {
	printf ("\n\tInicio do main()");fflush(stdout);
	preencheVetor_01_02();
	func1();
	printf("\n\tFim do processo\n\n");
	fflush(stdout);
	mostrar();
	return 0;
}