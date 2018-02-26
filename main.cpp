//Test file for cracking the code interview programming questions
#include <iostream>
#include <string>
#include <functional>
#include "hash_table.h"

using namespace std;

void implementHashTable();

//Hash Table Implementation
//Data structure that maps keys to values for efficient lookups
//Utilizes a hash function (keys --> int/long) and then map the hash code to an index in the array
//Map the hash code to an index in the array
//Handle collisions by utilizing linked lists



int main()
{
	int choice;

	while(1)
	{
        cout<<"\n*************************************"<<endl;
        cout<<"Data Structure Implementation Examples"<<endl;
        cout<<"\n*************************************"<<endl;
        cout<<"1.Hash Table"<<endl;
        cout<<"2.Exit"<<endl;		
        cout<<"Enter your choice: ";
        cin >> choice;
        switch(choice){
			case 1:
				implementHashTable();
				break;
			case 2:
				exit(1);
				break;
			default:
				cout << "\nERROR: Please enter  valid Selection\n";
       }		
		
	}
	
}

void implementHashTable(){

    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice){
			case 1:
				cout << "Enter element to be inserted: ";
				cin >> value;
				cout << "Enter key at which element to be inserted: ";
				cin >> key;
				hash.Insert(key, value);
				break;
			case 2:
				cout << "Enter key of the element to be searched: ";
				cin >> key;
				cout << "Element at key "<<key<<" : ";
				hash.Search(key);
				break;
			case 3:
				cout << "Enter key of the element to be deleted: ";
				cin >> key;
				hash.Remove(key);
				break;
			case 4:
				return;
			default:
				cout << "\nEnter correct option\n";
       }
    }
}


