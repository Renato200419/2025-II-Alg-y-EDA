#ifndef __VECTOR_H__
#define __VECTOR_H__

// PC1: deben hacer:
//      2 problemas de nivel 2
//      3 problemas de nivel 1
// Cada solucion enviarla como un Pull request

// TODO (Nivel 2): Agregar Traits

// TODO (Nivel 2): Agregar Iterators (forward, backward)

// TODO (Nivel 1): Agregar Documentacion para generar con doxygen

// TODO  (Nivel 2): Agregar control de concurrencia en todo el vector
template <typename T>
class CVector{
   
    T      *m_pVect = nullptr;
    size_t  m_count = 0; // How many elements we have now?
    size_t  m_max   = 0; // Max capacity
public:
    // TODO  (Nivel 1) Agregar un constructor por copia
    CVector(const CVector &v); // Constructor por copia  

    CVector(size_t n);
    // TODO  (Nivel 2): Agregar un move constructor
    CVector(CVector &&v);

    // TODO: (Nivel 1) implementar el destructor de forma segura
    vrtual CVector();
    void insert(T &elem);
    void resize();
};

template <typename T>
CVector<T>::CVector(size_t n){

}

// Constructor por copia - IMPLEMENTACIÓN (Nivel 1)
template <typename T>
CVector<T>::CVector(const CVector &v) {
    if (v.m_pVect == nullptr || v.m_max == 0) {
        // Inicializar como vector vacío válido
        m_pVect = nullptr;
        m_count = 0;
        m_max = 0;
    } else {
        // Copiar metadatos del objeto fuente
        m_count = v.m_count;
        m_max = v.m_max;

        // Reservar nueva memoria
        m_pVect = new T[m_max];
        
        // Copiar solo los elementos válidos
        for (size_t i = 0; i < m_count; ++i) {
            m_pVect[i] = v.m_pVect[i];
        }
    }
}

// TODO (Nivel 1): hacer dinamico el delta de crecimiento
template <typename T>
void CVector<T>::resize(){
    T *pTmp = new T[m_max+10];
    for(auto i=0; i < m_max ; ++i)
        pTmp[i] = m_pVect[i];
    delete [] m_pVect;
    m_max += 10;
    m_pVect = pTmp;
}

// TODO (ya está hecha): la funcion insert debe permitir que el vector crezca si ha desbordado
template <typename T>
void CVector<T>::insert(T &elem){
    if(m_count == m_max)
        resize();
    m_pVect[m_count++] = elem;
}

#endif // __VECTOR_H__