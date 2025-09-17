/**
 * @file vector.h
 * @author Renato Olivera  
 * @brief Vector dinamico con templates y manejo de memoria

#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream> 

// PC1: deben hacer:
//      2 problemas de nivel 2
//      3 problemas de nivel 1
// Cada solucion enviarla como un Pull request

// TODO (Nivel 2): Agregar Traits
// TODO (Nivel 2): Agregar Iterators (forward, backward)
// TODO  (Nivel 2): Agregar control de concurrencia en todo el vector

/**
 * @brief Vector que crece automaticamente cuando se llena
 * @tparam T tipo de elemento que guarda
 */
template <typename T>
class CVector{
   
private:
    T      *m_pVect = nullptr;     // array dinamico
    size_t  m_count = 0;          // cuantos elementos hay
    size_t  m_max   = 0;          // capacidad total
    double  m_growth_factor = 1.5; // por cuanto se multiplica al crecer

public:
    /** Constructor copia - hace copia completa */
    CVector(const CVector &v);

    /** Constructor normal - reserva memoria inicial */
    CVector(size_t n);

    /** Move constructor - transfiere ownership */
    CVector(CVector &&v) noexcept;

    /** Destructor - libera memoria */
    virtual ~CVector();

    /** Agrega elemento al final */
    void insert(const T &elem);

    /** Aumenta el tamaño del vector */
    void resize();

    /** Acceso a elementos por indice */
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    /** Devuelve numero de elementos */
    size_t size() const { return m_count; }
};

// Constructor con tamaño inicial
template <typename T>
CVector<T>::CVector(size_t n) : m_count(0), m_max(n), m_growth_factor(1.5) {
    if (n > 0) {
        m_pVect = new T[m_max];
    }
}

// Operador [] - permite leer/escribir elementos
template <typename T>
T& CVector<T>::operator[](size_t index) {
    return m_pVect[index];
}

template <typename T>
const T& CVector<T>::operator[](size_t index) const {
    return m_pVect[index];
}

// Constructor por copia - duplica todo el vector
template <typename T>
CVector<T>::CVector(const CVector &v) {
    if (v.m_pVect == nullptr || v.m_max == 0) {
        m_pVect = nullptr;
        m_count = 0;
        m_max = 0;
    } else {
        m_count = v.m_count;
        m_max = v.m_max;
        m_growth_factor = v.m_growth_factor;    
        m_pVect = new T[m_max];
        
        for (size_t i = 0; i < m_count; ++i) {
            m_pVect[i] = v.m_pVect[i];
        }
    }
}

// Destructor - limpia la memoria
template <typename T>
CVector<T>::~CVector() {
    delete[] m_pVect;
    m_pVect = nullptr;
    m_count = 0;
    m_max = 0;
}

// Move constructor - mueve recursos sin copiar
template <typename T>
CVector<T>::CVector(CVector &&v) noexcept 
    : m_pVect(v.m_pVect),
      m_count(v.m_count),
      m_max(v.m_max),
      m_growth_factor(v.m_growth_factor) {

    // dejar el objeto origen vacio
    v.m_pVect = nullptr;
    v.m_count = 0;
    v.m_max = 0;
}

// Resize - aumenta capacidad cuando se llena
template <typename T>
void CVector<T>::resize(){
    size_t new_capacity = static_cast<size_t>(m_max * m_growth_factor);
    if(new_capacity <= m_max) {
        new_capacity = m_max + 1;  // por si el factor da igual
    }
    
    T *pTmp = new T[new_capacity];
    for(size_t i = 0; i < m_count; ++i) {
        pTmp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_max = new_capacity;
    m_pVect = pTmp;
}

// Insert - agrega elemento, crece si es necesario
template <typename T>
void CVector<T>::insert(const T &elem){ 
    if(m_count == m_max)
        resize();
    m_pVect[m_count++] = elem;
}

/** Permite imprimir el vector con cout << */
template <typename T>
std::ostream& operator<<(std::ostream& os, const CVector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) os << ", ";
        os << vec[i];
    }
    os << "]";
    return os;
}
#endif // __VECTOR_H__