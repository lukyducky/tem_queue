#ifndef _T_QUEUE_H
#define _T_QUEUE_H
#include "node.h"
#include <iostream>

template <class T>
class Queue{
private:
	node<T>* front;
	node<T>* back;
	int size;
public:
	Queue();
	~Queue(){ clear(); }

	T popFront();
	void pushBack(T d);

	void clear();
	bool isEmpty(){ return (size != 0 )? true : false; }
	int getSize(){ return size; }

	bool operator == (const Queue<T>& q);
	Queue<T>& operator =(const Queue<T>& q);
	Queue<T>& operator +(const Queue<T>& q);

	friend std::ostream& operator <<(std::ostream& os, Queue<T>& q) //overloading operator to print out vaules of our Stack.
	{
		int size = q.getSize(); //getting size of stack
		for (int i = 0; i < size; ++i) //looping through every element in stack
		{
			os << q.popFront() << "; "; //printing with a ; to seperate elements; we can use os like cout to print things
			if (i != 0 && i % 10 == 0){ std::cout << std::endl; }//keeps it to 10 elements a line
		}
		return os; //return os
	}
};


#endif