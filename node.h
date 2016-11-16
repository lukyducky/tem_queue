#ifndef _NODE_H
#define _NODE_H
#include <iostream>
template <class T>
class node{
public:
	node<T>* next;
	node<T>* prev;
	T data;

	node()
	{ 
		next = prev = NULL; 
		data = 0;
	}
	node(T d)
	{
		next = prev = NULL;
		data = d;

	}
};




#endif