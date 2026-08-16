#include <iostream>
#include <string>
using namespace std;

int id[100];
string title[100], author[100];
bool available[100];
int book_count = 0;
int choice = 0;

void Addbook() {

	cout << "Enter book id : ";
	cin >> id[book_count];

	cout << "Enter book title : ";
	cin.ignore();
	getline(cin, title[book_count]);

	cout << "Enter author name : ";
	cin.ignore();
	getline(cin, author[book_count]);

	available[book_count] = true;

	book_count++;
}
int searching() {
	int Id = 0;
	cout << "Enter book Id : ";
	cin >> Id;

	for (int i = 0;i < book_count;i++) {

		if (Id == id[i]) {
			return i;
		}
	}
		return -1;
}
void Updatebook() {
	int Index = searching();
	if (Index == -1) {
		cout << "Book not found" << endl;
		return;
	}

			cout << "Enter new title : " << endl;
			cin.ignore();
			getline(cin, title[book_count]);

			cout << "Enter new Author : " << endl;
			cin.ignore();
			getline(cin, author[book_count]);

			cout << "Book updated successfully"<<endl;
}
void Removebook() {

	int Index = searching();
	if (Index == -1) {
		cout << "Book not found" << endl;
		return;
	}
	for (int i=Index;i< book_count-1;i++) {
		id[i] = id[i + 1];
		title[i] = title[i+1];
		author[i] = author[i + 1];
		available[i] = available[i + 1];
	}
		book_count--;
		cout << "Book removed successfully" << endl;
}
void Borrowbook() {

	int Index = searching();
	if (Index == -1) {
		cout << "Book not found" << endl;
		return;
	}

	if (available[Index] == true) {
		available[Index] = false;
		cout << "Book borrowed successfully "<<endl;
	}
	else if (available[Index] == false) {
		cout << "Book is not available" << endl;
	}
}
void Returnbook() {
	int Index = searching();
	if (Index == -1) {
		cout << "Book not found" << endl;
		return;
	}

	if (available[Index] == false) {
		available[Index] = true;
		cout << "Book returned successfully " << endl;
	}
	else if (available[Index] == true) {
		cout << "Book is already available" << endl;
	}
}
void Displaybooks() {
	if (book_count == 0) {
		cout << "No books in the library" << endl;
		return;
	}

	for (int i = 0;i < book_count;i++) {
		cout << "Id :" << id[i] << endl;
		cout << "Title :" << title[i] << endl;
		cout << "Author :" << author[i] << endl;
		if (available[i] == true) { cout << "Book available : Yes " << endl; }
		else { cout << "Book available : No " << endl; }
		cout << "----------------------------------" << endl;
	}
}
void Exit() {
	cout << "Thank you for visiting the library " << endl;
}
void menu() {

	cout << " to 'Add book' write (1) " << endl;
	cout << " to 'searching book' write (2) " << endl;
	cout << " to 'Update book' write (3) " << endl;
	cout << " to 'Remove book' write (4) " << endl;
	cout << " to 'Borrow book' write (5) " << endl;
	cout << " to 'Return book' write (6) " << endl;
	cout << " to 'Display books' write (7) " << endl;
	cout << " to 'Exit' write (8) " << endl;

	while (choice != 8) {

		cin >> choice;

		switch (choice)
		{
		case 1:Addbook();
			break;
		case 2:searching();
			break;
		case 3:Updatebook();
			break;
		case 4:Removebook();
			break;
		case 5:Borrowbook();
			break;
		case 6:Returnbook();
			break;
		case 7:Displaybooks();
			break;
		case 8:Exit();
			break;

		default: cout << "Invalid Option ,Please try again "<<endl;
		}
		if(choice!=8)
		cout << "Choose another option :" << endl;
	}
}

int main()
{
	cout << "Welcome to Alex library :" << endl;
	cout << "*************************" << endl;
	menu();

}