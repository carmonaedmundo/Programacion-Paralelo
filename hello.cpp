#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    // Inicializar la semilla para números aleatorios
    std::srand(std::time(0));

    // Crear dos arreglos de 1000 elementos cada uno
    int aDerecha[1000];
    int aIzquierda[1000];

    // Llenar los arreglos con números aleatorios
    for (int i = 0; i < 1000; ++i) {
        aDerecha[i] = std::rand();
        aIzquierda[i] = std::rand();
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        aDerecha[i] += aIzquierda[i];
        // imprimir el resultado de la suma en cada nodo y el número de hilo    
        std::cout << "Hilo " << omp_get_thread_num() << " - Suma en índice " << i << ": " << aDerecha[i] << std::endl;
    }

    return 0;
}