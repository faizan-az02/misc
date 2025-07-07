#include <iostream>
using namespace std;

struct Node {

	//data members

	int data;

	Node* next;
	Node* prev;

	//member operations

	Node(int val) {

		data = val;
		next = nullptr;
		prev = nullptr;
	}
};

struct LinkedList {

	//data members

	Node* head;

	//member operations

	LinkedList() {

		head = nullptr;
	}

	void insertAtLast(int val) {

		Node* newNode = new Node(val);

		if (!head)
		{
			head = newNode;
		}

		Node* cur = head;

		while (cur->next)
		{
			cur = cur->next;
		}

		cur->next = newNode;
		newNode->prev = cur;
	}

	void insertAtFirst(int val) {

		Node* newNode = new Node(val);

		if (!head)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void insertAtPosition(int val, int n) {

		Node* newNode = new Node(val);
		Node* temp = head;

		if (n == 1)
		{
			insertAtFirst(val);
			return;
		}

		for (int i = 1; i < n; i++)
		{
			temp = temp->next;
		}

		temp->prev->next = newNode;
		newNode->prev = temp->prev;
		newNode->next = temp;
		temp->prev = newNode;
	}

	void deleteAtFirst() {

		Node* temp = head;

		head->next->prev = NULL;
		head = head->next;

		delete temp;
	}

	void deleteAtLast() {

		Node* temp = head;

		while (temp->next) {

			temp = temp->next;
		}

		temp->prev->next = NULL;

		delete temp;
	}

	void deleteAtPosition(int n) {

		if (n == 1)
		{
			deleteAtFirst();
			return;
		}

		Node* temp = head;

		for (int i = 1; i < n; i++) {

			temp = temp->next;
		}

		temp->prev->next = temp->next;

		if (temp->next) {

			temp->next->prev = temp->prev;
		}

		delete temp;
	}

	void display() {

		Node* dis = head;

		while (dis) {

			cout << dis->data << endl;

			dis = dis->next;
		}
	}

	void removeDuplicates() {

		int size = 0, check = 0, j = 0;

		Node* temp = head;

		while (temp)
		{
			size++;
			temp = temp->next;
		}

		int* arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}

		temp = head;
		int i = 0;

		while (temp)
		{
			for (int i = 0; i < size; i++) {

				if (temp->data == arr[i])
				{
					check = 1;
				}
			}

			if (check == 0)
			{
				while (arr[j] != 0)
				{
					j++;
				}
				arr[j] = temp->data;
			}

			temp = temp->next;
			check = 0;
			j = 0;
		}

		temp = head;

		while (head->next)
		{
			deleteAtLast();
		}

		int k = 1;

		while (arr[k] != 0)
		{
			insertAtLast(arr[k]);
			k++;
		}
	}
};


int main() {
	LinkedList myList;

	myList.insertAtFirst(1);
	myList.insertAtLast(2);
	myList.insertAtLast(3);
	myList.insertAtLast(2);
	myList.insertAtLast(4);

	cout << "Original List: ";
	myList.display();

	myList.removeDuplicates();
	cout << "List after removing duplicates: ";
	myList.display();

	myList.insertAtPosition(5, 2);
	cout << "List after inserting at position 2: ";
	myList.display();

	myList.deleteAtFirst();
	cout << "List after deleting at the first position: ";
	myList.display();

	myList.deleteAtLast();
	cout << "List after deleting at the last position: ";
	myList.display();

	myList.deleteAtPosition(2);
	cout << "List after deleting at position 2: ";
	myList.display();

	return 0;
}
