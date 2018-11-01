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

void *func1(){
	int i=0;
    int j=0;
    for (i=0;i<TAM/4;i++) {
        for (j=0;j<TAM;j++) {
            vetor03[i][j]=vetor01[i][j] + vetor02[i][j];
        }
	}
}

void *func2(){
	int i=0;
    int j=0;
    for (i=TAM/4;i<TAM/4*2;i++) {
        for (j=0;j<TAM;j++) {
            vetor03[i][j]=vetor01[i][j] + vetor02[i][j];
        }
	}
}

void *func3(){
	int i=0;
    int j=0;
    for (i=TAM/4*2;i<TAM/4*3;i++) {
        for (j=0;j<TAM;j++) {
            vetor03[i][j]=vetor01[i][j] + vetor02[i][j];
        }
	}
}

void *func4(){
	int i=0;
    int j=0;
    for (i=TAM/4*3;i<TAM;i++) {
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
	pthread_t t1,t2,t3,t4;
	preencheVetor_01_02();
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
    pthread_create(&t3,NULL,func3,NULL);
    pthread_create(&t4,NULL,func4,NULL);
	printf("\n\tFim do processo\n\n");
	fflush(stdout); //'forca' imprimir buffer na tela
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
    pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	mostrar();
	return 0;
}