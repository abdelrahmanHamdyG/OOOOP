// DS_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class node {
public:
	int value;
	node* next=NULL;
	
};

class queue {

public:
	int maxSize;
	node* front=NULL;
	node* rear=NULL;
	int size=0;

	queue(int _max) {
	
		maxSize = _max;
		size = 0;
	}

	void enqueue(int value){
		size++;

		node* newNode = new node();
		newNode->value = value;
		
		if (front == NULL) {

			front = newNode;
			rear = newNode;
			
		}else{


			rear->next = newNode;
			rear = rear->next;
		}


	}

	int  dequeue() {

		size--;
		node* temp = front;
		front = front->next;
		int x = temp->value;
		
		delete temp;
		return x;

	}

	bool isFull() {

		if (size == maxSize)
			return true;
		return false;
	}

	bool isEmpty() {

		if (size == 0)
			return true;
		return false;
	}


};
int main()
{
	queue q(3);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(8);
	cout << "is FULL->" << q.isFull() << '\n';
	cout<<q.dequeue()<<'\n';
	q.dequeue();
	q.dequeue();
	cout << "is Empty->" << q.isEmpty() << '\n';
	
}
