//Test file for cracking the code interview programming questions
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include "hash_table.h"
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "bst.h"

using namespace std;

void implementHashTable();
void implementLinkedList();
void implementStack();
void implementQueue();
void implementGraphBFS();

//Graph BFS Functions
void dfs(vector<vector<int>> &graph, vector<vector<int>> &output, vector<int> path, int start, int end);
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
void printpath(vector<vector<int>> path);


//Algorithm: Find and output the only number that appears once in the array
vector<int> DistinctValues(vector<vector<int>> values)
{
	vector<int> output;
	
	for(vector<int> vec_val : values){
		unordered_map<int,int> values_map;		
		for(int val : vec_val){
			values_map[val]++;
		}
		for(unordered_map<int,int>::iterator it = values_map.begin(); it != values_map.end(); it++){
			if(it->second == 1){
				output.push_back(it->first);
			}
		}
	}
	return output;
}

//Algorithm: Find and output the values that we can autocomplete
vector<string> AutoComplete(vector<string> dict, string key)
{
	vector<string> completed;
	
	//First we need to parse the key into workable parts. 
	vector<string> key_subs;
	int st_idx = 0, idx = 0, len = 1;
		
	while(idx <= key.size()){
		if(isupper(key[idx])){
			st_idx = idx;
			idx++;
			while(islower(key[idx])){
				idx++;
				len++;
			}
			string subs = key.substr(st_idx,len);
			key_subs.push_back(subs);		
		}
		else{
			idx++;
		}
		len = 1;
	}
	
	//Then we iterate through the dictionary to output our string
	int count = 0;												
	for(string str : dict){										//Loop through Dictionary First
		int i = 0;
		for(string ss : key_subs){								//Loop through Key Vectors
			for(; i < str.size(); i++){				//Loop through String
				if(str.substr(i).find(ss) != string::npos){
					i += str.substr(i).find(ss);
					count += 1;
				}
				else
					break;
			}
		}
		if(count == key_subs.size()){
			completed.push_back(str);
		}
		count = 0;		
	}
	
	return completed;
}

int main()
{

	//Find and output the only number that appears once in the array
	//Sample Input: [2,2,2,6],[1,2,1,1,1,1]
	//Sample Output: [6,2]
	vector<vector<int>> values = {{2,2,2,6},{1,2,1,1,1,1,},{3,3,7},{9,9,9,10,9,9,9,9,9,9,9,9}};
	vector<int> output = DistinctValues(values);
	cout << "== Outputting the number that apperas only once ==\n";
	for(int i : output){
		cout << i << endl;
	}
	cout << endl;
	
	//Given a string, autocomplete the string depending on the given input_iterator
	//Sample Input: ["Data", "GVi", DaGVi","DataHandler"]
	//Sample Output: ["DataGraphView","DataGraphHandler","DataGraphVisual"]["GraphViewData","DataGraphVisual"]["DataGraphView"]["DataGraphHandler"]
	vector<string> s_values = {"DataGraphView", "DataGraphHandler", "DataGraphVisual", "GraphPartyOut"};
	string input = "DG";
	vector<string> s_output = AutoComplete(s_values, input);
	cout << "== Outputting the AutoCompleted string ==\n";
	for(string s : s_output){
		cout << s << endl;
	}
	
	
	int choice;
	while(0)
	{
        cout<<"\n*************************************"<<endl;
        cout<<"Data Structure Implementation Examples"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"1. Hash Table"<<endl;
		cout<<"2. Linked List"<<endl;
		cout<<"3. Stack"<<endl;
		cout<<"4. Queue"<<endl;
		cout<<"5. Graph"<<endl;
        cout<<"6. Exit"<<endl;	
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
				implementGraphBFS();
				break;
			case 6:
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

void implementGraphBFS()
{
	//Utilizes a vector<vector<int>> to demonstrate graphdefaults
	//e.g. 
	// [[1,2], [3], [3], []]
	// 0 --> 1
	// |	 |
	// v	 v
	// 2 --> 3
	vector<vector<int>> graph;
	graph.resize(4);
	graph[0].push_back(1);
	graph[0].push_back(2);
	graph[1].push_back(3);
	graph[2].push_back(3);
	
	printpath(allPathsSourceTarget(graph));
	cout << "End of Test" << endl;		
}

void printpath(vector<vector<int>> path)
{
    for (int i = 0; i < path.size(); i++) {
		for(int j = 0; j < path[i].size(); j++){
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(vector<vector<int>> &graph, vector<vector<int>> &output, vector<int> path, int start, int end){
    path.push_back(start);
    if(start == end){
        output.push_back(path);
        return;
    }
    for(auto node : graph[start]){
		cout << node;
        dfs(graph, output, path, node, end);
	}
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> all_paths;
    vector<int> path;
    int nodes = graph.size();
    if(nodes == 0) return all_paths; //If empty graph
    dfs(graph, all_paths, path, 0, nodes-1);
    return all_paths;
}

