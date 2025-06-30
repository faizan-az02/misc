#pragma warning(disable:4996)
#include <iostream>
#include <ctime>
#include<chrono>
#include <string>


using namespace std;

struct Post {

	//data members of node

	int ID;
	string Text;
	time_t Time;
	Post* next;

	//member functions

	Post(string text, int id) {

		ID = id;
		Text = text;
		next = nullptr;
		Time = chrono::system_clock::to_time_t(chrono::system_clock::now());
	}
};

struct Feed {

	Post* head;

	//member functions

	Feed() {

		head = nullptr;
	}

	int getID() {

		int count = 1;
		Post* P = head;

		while (P) {
		
			count += 1;
			P = P->next;
		}

		return count;
	}

	void EditPost(int i, string new_str) {
	
		int check = 0;
		int count = 0;
		int j = 0;
		Post* current = head; 

		while (current) {
		
			count += 1;
			if (i == current->ID)
			{
				check = 1;
				break;
			}
			current = current->next;
		}

		if (check == 1)
		{
			current->Text = new_str;
			current->Time = chrono::system_clock::to_time_t(chrono::system_clock::now());
		}
	}

	void AddPost(string inp) {
	
		int I = getID();

		Post* P = new Post(inp, I);

		if (!head || P->Time < head->Time) {
			P->next = head;
			head = P;
			return;
		}

		Post* current = head;

		while (current->next && current->next->Time <= P->Time) {
			current = current->next;
		}

		P->next = current->next;
		current->next = P;
	}

	void displayForward() {
	
		Post* display = head;

		while (display) {
		
			cout << "Post ID is " << display->ID << endl << "Post Text is " << display->Text << endl << "Post time is " << ctime(&display->Time) << endl;

			display = display->next;
		
		}

	}

	void SearchByText(string str) {
	
		Post* current = head;
		string temp = " ";

		while (current) {
		
			temp = current->Text;

			if (temp.find(str) != string::npos) {
			
				cout << "Post ID is " << current->ID << endl << "Post Text is " << current->Text << endl <<  "Post Instance of Creation is " << ctime(&current->Time) << endl;
			
			}

			current = current->next;
		}
	}

	void displayLatest(Post* current) {

		if(current->next)
		{
			displayLatest(current->next);
		}
		else
		{
			cout << "Post ID is " << current->ID << endl << "Post Text is " << current->Text << endl << "Post Instance of Creation is " << ctime(&current->Time) << endl;
			return;
		}

		cout << "Post ID is " << current->ID << endl << "Post Text is " << current->Text << endl << "Post Instance of Creation is " << ctime(&current->Time) << endl;
	}

	void deletePost(int x) {
	
		int count = 0;
		int i = 0;

		if (head->ID == x)
		{
			head = head->next;
			return;
		}

		Post* current = head->next;
		Post* temp = head;

		while (current)
		{
			if (current->ID == x)
			{
				while (i < count)
				{
					temp = temp->next;
				}

				temp->next = current->next;
				return;
			}
			else 
			{
				current = current->next;
			}
			count += 1;
		}
	}
};


int main() {

	int del_inp;
	int inp = 0;
	int check = 0;
	string str_inp = " ";
	int inp_ID = 0;
	string inp_Text = " ";
	string search_str = " ";

	cout << "Welcome to the assigned feed!" << endl;

	Feed F;

	cout << "What do you want to do?" << endl;

	while (check == 0) {

		cout << "1. Add a post \n2. Edit a post\n3. Search for posts by text\n4. Delete a post\n5. Display all posts w.r.t latest first\n6. Display all posts w.r.t oldest first\n7. Exit the program" << endl;
		cin >> inp;

		while (inp < 1 || inp > 7) {

			cout << "Enter a valid input!" << endl;
			cin >> inp;
		}

		switch (inp) {

		case 1:

			cout << "Enter the text of the post: ";
			getline(cin, str_inp);
			getline(cin, str_inp);

			F.AddPost(str_inp);

			break;

		case 2:
			
			cout << "Enter the ID of the post" << endl;
			cin >> inp_ID;

			cout << "Enter the new text" << endl;
			getline(cin, inp_Text);
			getline(cin, inp_Text);

			F.EditPost(inp_ID, inp_Text);

			break;

		case 3:

			cout << "Enter the text" << endl;
			getline(cin, search_str);
			getline(cin, search_str);

			F.SearchByText(search_str);
			break;

		case 4:

			cout << "Enter the ID of the post you want to delete" << endl;
			cin >> del_inp;

			F.deletePost(del_inp);
			break;

		case 5:

			F.displayLatest(F.head);
			break;

		case 6:

			F.displayForward();
			break;

		case 7:
			
			check = 1;
			break;
		}
	}

	return 0;
}