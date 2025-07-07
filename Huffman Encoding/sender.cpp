#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Node {

	//data members

	char data;

	int freq;

	//pointers to next nodes

	Node* left;

	Node* right;

	//operations

	Node(char c) {

		data = c;

		freq = 1;

		left = right = NULL;
	}

};

struct Temp {

	//data members

	Node* first;

	//operations

	Temp() {

		first = NULL;
	}

	void insertNode(Node* add)
	{
		Node* iter = NULL;

		if (!first)
		{
			first = add;

			return;
		}
		else
		{
			iter = first;

			while (iter)
			{
				if (iter->data == add->data)
				{
					iter->freq = iter->freq + 1;

					delete add;

					return;
				}
				else
				{
					iter = iter->right;
				}
			}

			iter = first;

			add->right = iter;

			first = add;

		}
	}

	int sortNsize() {

		int size = 0;

		int temp = 0;

		char tem = '-';

		if (!first)
		{
			cout << "List is empty" << endl;

			return -1;
		}

		Node* iter = first;

		while (iter)
		{
			size++;

			iter = iter->right;
		}

		for (int i = 0; i < size-1; i++)
		{
			iter = first;

			for (int j = 0; j < size-1; j++)
			{
				if (iter->freq > iter->right->freq)
				{
					temp = iter->freq;

					iter->freq = iter->right->freq;

					iter->right->freq = temp;

					tem = iter->data;

					iter->data = iter->right->data;

					iter->right->data = tem;
				}

				iter = iter->right;
			}
		}

		return size;
	}

	void display() {

		Node* di = first;

		while (di)
		{
			cout << "Data is " << di->data << endl << "Frequency is " << di->freq << endl;

			di = di->right;
		}
	}
};

struct Tree {
	
	//members

	Node* root;

	//operations

	Tree() {
	
		root = NULL;
	}

	void insertinTree(Node* add) {

		Node* newNode = new Node(' ');

		if (add->freq > root->freq)
		{
			newNode->right = add;

			newNode->left = root;

			root = newNode;
		}
		else
		{
			newNode->right = root;

			newNode->left = add;

			root = newNode;
		}

		root->freq = root->left->freq + root->right->freq;
	}

	void inOrderTraversal(Node* dis) {

		if (dis == NULL)
		{
			return;
		}

		inOrderTraversal(dis->left);

		cout << dis->data << "|" << dis->freq << endl;

		inOrderTraversal(dis->right);
	}

};

int main() {

	//declaring variables used

	char ch = ' ';

	int size = 0;

	Temp t;

	int i = 0;

	string inp = "";

	string data = "";

	//interface

	cout << "Enter the name of the file" << endl;

	getline(cin, inp);

	inp = inp + ".txt";

	//reading the file

	ifstream file(inp);

	getline(file, data);

	//creating a temporary list from the data in file

	while (data[i] != '\0')
	{
		Node* newNode = new Node(data[i]);

		t.insertNode(newNode);

		i++;
	}

	//sorting the list in ascending order and getting size of it

	size = t.sortNsize();

	//making an array of the nodes with data and frequency

	Node** arr = new Node*[size];

	Node* assign = t.first;

	for (int i = 0; i < size; i++)
	{
		arr[i] = assign;

		assign = assign->right;
	}

	//clearing the right pointer

	for (int i = 0; i < size; i++)
	{
		arr[i]->right = NULL;
	}

	//making the tree

	Tree T;

	Node* newNode = new Node(' ');

	newNode->freq = arr[0]->freq + arr[1]->freq;

	newNode->left = arr[0];

	newNode->right = arr[1];

	T.root = newNode;

	for (int i = 2; i < size; i++)
	{
		T.insertinTree(arr[i]);
	}

	//deriving codes and storing them in an array

	int temp = 0;

	string temp_c = "";

	string* codes = new string[size];

	char* chars = new char[size];

	Node* code = T.root;

	code = code->left;

	codes[0] = "0";

	chars[0] = code->data;

	code = T.root;

	for (int j = 0; j < size - 2; j++)
	{
		for (int i = j; i < size - 2; i++)
		{
			code = code->right;

			temp_c = temp_c + "1";

			temp++;
		}

		code = code->left;

		temp_c = temp_c + "0";

		chars[temp] = code->data;

		codes[temp] = temp_c;

		code = T.root;

		temp = 0;

		temp_c = "";
	}

	code = T.root;

	for (int i = 0; i < size - 1; i++)
	{
		code = code->right;

		temp_c = temp_c + "1";
	}

	chars[size - 1] = code->data;

	codes[size - 1] = temp_c;

	//writing the codes on the file

	ofstream out_code("codes.txt");

	for (int i = 0; i < size; i++)
	{
		out_code << codes[i] << endl << chars[i] << endl;
	}

	out_code.close();

	//writing the encoded text on the file

	cout << "Input is : " << data << endl;

	cout << "Derived code is : ";

	ofstream encode("encoded.txt");

	i = 0;

	while (data[i] != '\0')
	{
		ch = data[i];

		for (int j = 0; j < size; j++)
		{
			if (ch == chars[j])
			{
				encode << codes[j];

				cout << codes[j];

				break;
			}
		}

		i++;
	}

	cout << endl;

	cout << "Individual codes are as follows" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << chars[i] << '-' << codes[i] << endl;
	}

	return 0;
}