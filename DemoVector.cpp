#include <iostream>
#include "DemoVector.h"
#include "vector.h"
using namespace std;

void DemoVector(){
    CVector<int> vector(10);
    vector.insert(5);
    // TODO  (Nivel 1) habilitar el uso de []
    vector[0] = 8;  // Prueba del operador []
    cout << "Vector[0]: " << vector[0] << endl;
    // TODO  (Nivel 2) habilitar que el vector pueda ser escrito con cout <<
    cout << "Vector completo: " << vector << endl;  
}