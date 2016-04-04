#include "UStack.h"

template <typename T>
UStack<T>::UStack()
{
	sp = -1;
}

template <typename T>
void UStack<T>::push(T value)
{
	stack.push_back(value);
	++sp;
}

template <typename T>
T UStack<T>::pop()
{
	if(sp == -1) cout<<"error pop()"<<endl;
	sp --;
	T k = stack.back();
	stack.pop_back();
	return k;
}

template <typename T>
T& UStack<T>::operator[](int index)
{
	return stack[index];
}
