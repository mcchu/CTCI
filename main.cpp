//Test file for cracking the code interview programming questions
#include <string>
#include <functional>
#include "hash_table.h"
#include "linked_list.h"
#include "stack.h"
#include "queue.h"

using namespace std;

void implementHashTable();
void implementLinkedList();
void implementStack();
void implementQueue();

int main()
{
	int choice;

	while(1)
	{
        cout<<"\n*************************************"<<endl;
        cout<<"Data Structure Implementation Examples"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"1. Hash Table"<<endl;
		cout<<"2. Linked List"<<endl;
		cout<<"3. Stack"<<endl;
		cout<<"4. Queue"<<endl;
        cout<<"5. Exit"<<endl;	
        cout<<"Enter your choice: ";
        cin >> choice;
		cout<< endl;
        switch(choice){
			case 1:
				implementHashTable();
				break;
			case 2:
				implementLinkedList();
				break;
			case 3:
				implementStack();
				break;
			case 4:
				implementQueue();
				break;
			case 5:
				exit(1);
				break;
			default:
				cout << "\nERROR: Please enter  valid Selection\n";
       }			
	}
	return 0;	
}

void implementHashTable()
{
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
				hash.insert(key, value);
				break;
			case 2:
				cout << "Enter key of the element to be searched: ";
				cin >> key;
				cout << "Element at key "<<key<<" : ";
				hash.search(key);
				break;
			case 3:
				cout << "Enter key of the element to be deleted: ";
				cin >> key;
				hash.remove(key);
				break;
			case 4:
				return;
			default:
				cout << "\nEnter correct option\n";
       }
    }
}

void implementLinkedList()
{
    LinkedList list;
    list.push_back(1);
    cout << "Added 1 to the list and now front is " << list.front() << endl;
    list.pop_front();
    cout << "Removed item" << endl;
    list.push_front(2);
    cout << "Added 2 to the list and now back is " << list.back() << endl;
    list.pop_back();
    cout << "Removed item" << endl;
 
    for(int i=0; i < 5; i++)
    {
		list.push_back(10+i);
		list.push_front(20+i);
    }
    cout << "List size after adding 10 elements is " << list.size() << endl;
    while(!list.empty())
    {
		cout << "Popping front item = " << list.front() << endl;
		list.pop_front();
    }
    cout << "Trying to pop an item that doesn't exist" << endl;
    list.pop_front();
    cout << "Renitiatlizing list" << endl;
    for(int i=0; i < 5; i++)
    {
		list.push_back(10+i);
		list.push_front(20+i);
    }
    while(!list.empty())
    {
        cout << "Popping back item = " << list.back() << endl;
        list.pop_back();
    }
    cout << "Trying to pop an item that doesn't exist" << endl;
    list.pop_back();
 
    list.push_back(100);
    list.push_front(101);
    cout << "End of Test" << endl;	
}

void implementStack()
{
	Stack stack;
	stack.push_top(1);
	cout << "Added 1 to the stack and now front is: " << stack.peek() << endl;
	stack.pop();
	cout << "Removed Item. front is now: " << stack.peek() << endl;
	stack.push_top(10);
	cout << "Added 10 to the stack and now front is: " << stack.peek() << endl;
	stack.pop();
	cout << "Removed Item. front is now: " << stack.peek() << endl;
	
    for(int i=0; i < 5; i++)
    {
		stack.push_top(20+i);
    }	
    cout << "List size after adding 5 elements (in order of: 20, 21, 22, 23, 24) is " << stack.size() << endl;
    while(!stack.is_empty())
    {
        cout << "Popping back item = " << stack.peek() << endl;
		stack.pop();
    }
    cout << "Trying to pop an item that doesn't exist" << endl;
    stack.pop();
	
	cout << "End of Test" << endl;	
}

void implementQueue()
{
	Queue queue;
	queue.push_back(1);
	cout << "Added 1 to the queue and now front is: " << queue.peek() << endl;
	queue.pop();
	cout << "Removed Item. back is now: " << queue.peek() << endl;
	queue.push_back(10);
	cout << "Added 10 to the queue and now front is: " << queue.peek() << endl;
	queue.pop();
	cout << "Removed Item. back is now: " << queue.peek() << endl;
	
    for(int i=0; i < 5; i++)
    {
		queue.push_back(20+i);
    }	
    cout << "List size after adding 5 elements (in order of: 20, 21, 22, 23, 24) is " << queue.size() << endl;
    while(!queue.is_empty())
    {
        cout << "Popping back item = " << queue.peek() << endl;
		queue.pop();
    }
    cout << "Trying to pop an item that doesn't exist" << endl;
    queue.pop();
	
	cout << "End of Test" << endl;	
}

