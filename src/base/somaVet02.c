#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define TAM 10000
int vetor01[TAM]; //global
int vetor02[TAM]; //global
int vetor03[TAM]; //global

void preencheVetor_01_02() {
	int i=0;
	for (i=0;i<TAM;i++) {
		vetor01[i]=1;
		vetor02[i]=2;
	}
}

void *func1() {
	int i=0;
	for(i=0; i<TAM/2;i++) {
		vetor03[i]=vetor01[i] + vetor02[i];
	}
}

void *func2() {
 	int i=0;
 	for(i=TAM/2; i<TAM;i++){
		vetor03[i]=vetor01[i] + vetor02[i];
	}
}

void mostrar(){
	int i=0;
	for(i=0; i<TAM;i++) {
		printf("%d ", vetor03[i]);
	}
}

 int main(){
	printf ("\n\tInicio do main()");fflush(stdout);
	pthread_t t1,t2;
	preencheVetor_01_02();
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	printf("\n\tFim do processo\n\n");
	fflush(stdout); //'forca' imprimir buffer na tela
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	mostrar();
	return 0;
}