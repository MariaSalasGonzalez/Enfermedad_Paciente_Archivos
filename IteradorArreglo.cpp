#include "IteradorArreglo.h"

template <class T>
IteradorArreglo<T>::IteradorArreglo(T* ptrCont) {
	cur = 0;
	ar = ptrCont;
}

template <class T>
IteradorArreglo<T>::~IteradorArreglo() {
}

template <class T>
bool IteradorArreglo<T>::isDone() {
	return cur < ar->getK();
}

template <class T>
void IteradorArreglo<T>::first() {
	cur = 0;
}

template <class T>
void IteradorArreglo<T>::next() {
	cur++;
}

template <class T>
T* IteradorArreglo<T>::currenItem() {
	return ar->obtenerElemento(cur);
}

