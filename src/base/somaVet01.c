
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define TAM 10000
int vetor01[TAM]; //global
int vetor02[TAM]; //global
int vetor03[TAM]; //global

void preencheVetor_01_02(){
	int i=0;
	for (i=0;i<TAM;i++) {
		vetor01[i]=1;
		vetor02[i]=2;
	}
}
void func1(){
	int i=0;
	for(i=0; i<TAM;i++) {
		vetor03[i]=vetor01[i] + vetor02[i];
	}
}
void mostrar(){
	int i=0;
	for(i=0; i<TAM;i++) {
		printf("%d ", vetor03[i]);
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