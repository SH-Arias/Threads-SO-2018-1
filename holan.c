#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAXTHREAD 128

void* holan(void* arg) {
	int numHolas = (int)arg;
	for (int i = 0; i < numHolas; i++) {
		printf("Hola, soy el hilo %d\n", pthread_self());
	}
	return NULL;
}

int main(int argc, char** argv) {
	
	pthread_t ptarray[MAXTHREAD]; // almacena 'id' de hilos

	int numHilos = 5;

	int numHolas = 1;

	// Se crea y se le asigna a cada hilo un identificador e.g. 0, 1,...
	
	for (int i = 0; i < numHilos; i++) {
		pthread_create(&ptarray[i],NULL, holan, numHolas);
	}

	// Se espera por la terminacion de ejecucion de cada hilo
	for (int i = 0; i < numHilos; i++) {
		pthread_join(ptarray[i],NULL);
	}
}
//gcc -pthread holan.c -o holan
