#include <bits/stdc++.h>
using namespace std;

struct contact{
	string name, surname, number;
};
vector <contact> contacts;
void addNumber(string name, string surname, string number){
	contact contact1;
	contact1.name = name;
	contact1.surname = surname;
	contact1.number = number;
	contacts.push_back(contact1);
	cout << "The number is successfully added!\n\n";
}
void deleteNumber(string name, string surname){
	bool ok = 1;
	for(int i=0; i<contacts.size(); i++){
		if(name == contacts[i].name && surname == contacts[i].surname){
			contacts.erase(contacts.begin() + i);
			ok = 0;
			break;
		}
	}
	if(ok)
		cout << "This person is not in your contacts!\n\n";
	else
		cout << "The contact is successfully deleted!\n\n";
}

void showContacts(){
	for(int i=0; i<contacts.size(); i++){
		cout << contacts[i].name << " " << contacts[i].surname << " " << contacts[i].number << "\n";
	}
	if(!contacts.size())
		cout << "Your contacts list is empty!\n";
	cout << "\n";
}
void findNumber(string name, string surname){
	bool ok = 1;
	for(int i=0; i<contacts.size(); i++){
		if(name == contacts[i].name && surname == contacts[i].surname){
			cout << contacts[i].number << "\n\n";
			ok = 0;
			break;
		}
	}	
	if(ok)
		cout << "This person is not in your contacts!\n\n";
}
int main() {
	while(true){
		cout << "Press 1 to add a number\n2 to delete a number\n3 to show contacts\n4 to find a number\n5 to exit\n\n";
		int num; cin >> num;
		if(num == 1){
			string name, surname, number;
			cout << "name: ";
			cin.ignore();
			getline(cin, name);
			cout << "surname: ";
			getline(cin, surname);
			cout << "number: ";
			getline(cin, number);
			addNumber(name, surname, number);
		}
		else if(num == 2){
			string name, surname;
			cout << "name: ";
			cin.ignore();
			getline(cin, name);
			cout << "surname: ";
			getline(cin, surname);
			deleteNumber(name, surname);
		}
		else if(num == 3){
			showContacts();
		}
		else if(num == 4){
			string name, surname;
			cout << "name: ";
			cin.ignore();
			getline(cin, name);
			cout << "surname: ";
			getline(cin, surname);
			findNumber(name, surname);
		}
		else if(num == 5)
			break;
	}
	return 0;
}
