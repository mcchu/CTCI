#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Team{
private:
	char name;
	vector<Team*> beaten = {};
	
public:
	//Parametrized Constructor
	Team(char c){
		name = c;
	}
	
	char getName(){
		return name;
	}

	void beat(Team* beat){
		beaten.push_back(beat);
	}
	
	void printBeaten(){
		for(Team* b : beaten){
			cout << b->getName() << " ";
		}
		cout << endl;
	}
	
	vector<Team*> willBeat(){
		return beaten;
	}
	
	Team operator=(const Team& a){
		beaten = a.beaten;
		return *this;
	}
};

char predict(Team *team1, Team *team2);
void testCase1();
void testCase2();

#endif