#ifndef __USTACK_H
#define __USTACK_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class UStack{
private:
	int sp;
	vector<T> stack;
public:
	void push(T);
	T pop();
	inline T top() { return sp; }
	void spSet(int n){ sp = n; }
	T& operator[](int);
	UStack();

};

#endif
