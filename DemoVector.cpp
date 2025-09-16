#include <iostream>
#include "DemoVector.h"
#include "vector.h"
using namespace std;

void DemoVector(){
    CVector<int> vector(10);
    vector.insert(5);
    vector[0] = 8;  // Prueba del operador []
    cout << "Vector[0]: " << vector[0] << endl;
}