#include "t_queue.h"

template <class T>
Queue<T>::Queue()
{
	front = back = NULL;
	size = 0;
}



template <class T>
T Queue<T>::popFront() //removes first node and returns data
{
	T d = front->data;//get the data at the front

	if (getSize() == 1) // if this node is the last node
	{
		delete front; //delete the node
		front = back = NULL;	 //make sure you don't use the ptrs
	}

	else
	{
		//next is towards front; prev is towards back
		front = front->prev; //set the front to the prev node
		delete front->next; // delete the old front; or the next from the new front
		front->next = NULL; //set the PTR to the old front to null
	}
	size --; //decrease the size
	return d;
}

template <class T>
void Queue<T>::pushBack(T d) //adds node to the back of queue
{
	node<T>* nn = new node<T>(d);
	if (isEmpty()) //if this is an empty queue
	{
		front = back = nn; //set the front and back to be the new node
	}

	else //if there's already things in our queue
	{
		nn->next = back; // nn's next PTR points to back
		back->prev = nn; //  back's prev PTR points to new node
		back = back->prev; //back is now NN;
	}
	size++; //increase size by 1
}

template<class T>
void Queue<T>::clear()
{
	while (!isEmpty()) //as long as it's not empty
	{popFront(); } //pop the queue
}



template <class T>
bool Queue<T>::operator == (const Queue<T>& q)
{
	if (this->size != q.size)
		return false;
	else
	{
		node<T>* th = this->front;
		node<T>* it = q.front;
		bool b = true;
		while (th != NULL && b == true)
		{
			b = (th->data == it->data);
			th = th->next;
			it = it->next;
		}
		return b;
	}
}


template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& q)
{
	this->clear();

	node<T>* it = q.front;

	while (it != NULL)
	{
		this->pushBack(it->data);
		it = it->next;
	}
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator +(const Queue<T>& q)
{
	Queue<T>* out = new Queue<T>;

	node<T>* it = this->front;

	while (it != NULL)
	{
		out->pushBack(it->data);
		it = it->next;
	}

	it = q.front;
	
	while (it != NULL)
	{
		out->pushBack(it->data);
		it = it->next;
	}

	return *out;
}

template class Queue<int>;
//template class Queue<int*>;
//template class Queue<float>;
//template class Queue<double>;
//template class Queue<double*>;
//template class Queue<char>;
//template class Queue<char*>;

