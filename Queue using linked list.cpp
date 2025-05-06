// Queue using linked list.cpp 

#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node()
	{
		data = -1;
		next = nullptr;
	}
};
class LinkedQueue
{
private:
	Node* front;
	Node* rear;
public:
	LinkedQueue()
	{
		front = rear = nullptr;
	}
	~LinkedQueue()
	{
		Clear();
	}
	bool IsEmpty()
	{
		return front == nullptr;
	}
	void EnQueue(int value)
	{
		Node* newNode = new Node();
			newNode->data = value;
			if (IsEmpty())
			{
				front = rear = newNode;
			}
			else
			{
				rear->next = newNode;
				rear = newNode;
			}
	}
	int DeQueue()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty, no element to dequeue" << endl;
			return -1;
		}
		Node* temp = front;
		int delvalue = temp->data;
		front = front->next;
		delete temp;
		return delvalue;

	}
	void Print()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty, no elements to dequeue" << endl;
			return ;
		}
		cout << "Queue : ";
		Node* temp = front;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
	bool IsFound(int value)
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			if (temp->data == value)
				return true;
			temp = temp->next;
		}
		return false;
	}
	int GetFront()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty, no element on front" << endl;
			return -1;
		}
		return front->data;
	}
	int GetEnd()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty, no element on end" << endl;
			return -1;
		}
		return rear->data;
	}
	int Count()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != nullptr)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			DeQueue();
		}
	}

	
};
int main()
{
	LinkedQueue Q ;
	for (int i = 0; i < 5; i++)
	{
		int add;
		cout << "Enter value to queue " << endl;
		cin >> add;
		Q.EnQueue(add);
	}
	Q.Print();
	cout << "Front is : " << Q.GetFront() << endl;
	cout << "End is : " << Q.GetEnd() << endl;
	cout << "Number of element in queue = " << Q.Count() << endl;
	cout << "deleted value is : " << Q.DeQueue() << endl;
	cout << "deleted value is : " << Q.DeQueue() << endl;
	cout << "After deletion : " << endl;
	Q.Print();
	cout << "Number of element in queue = " << Q.Count() << endl;
	int check;
	cout << "Enter element to check if it exist " << endl;
	cin >> check;
	if (Q.IsFound(check))
	{
		cout << check << " is exist" << endl;
	}
	else
	{
		cout << check << " is not exist" << endl;
	}
}

