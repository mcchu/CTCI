#include "main.h"
#include <fstream>
#include<thread>

int main(int argc, char *argv[])
{
	//Game Result Prediction
	testCase1();
	testCase2();
	return 0;
}

// Function: predict
// Input: 	 Team* team1, Team* team2
// Output: 	 Char ressult of relationship
// Operation:We have 4 potential results: ?, =, >, and <. Because of how we store our input in the data structures, we know that we can compare the relationship between each team's victories.
//			 We first check whether we beat the same teams. If so, we return '='. This takes precedence as to avoid redundant looping and recursion.
//			 Then we can check for '>' and '<' results by comparing if team1 will beat team2 and vice versa.
//			 We check for transitivity by applying recursion. For example, if we know that A > B and B > C, we first compare A > B, then B > C to return '>' because A > C.
//			 Finally, we return '?' if we do not pass any above operation as we do not know the relation.
char predict(Team* team1, Team* team2){
	vector<Team*> a = team1->willBeat();
	vector<Team*> b = team2->willBeat();
	
	char c = '?';
	if(a == b && a.size() > 0 && b.size() > 0){
		c = '=';
	}
	else{
		for(Team* node : a){		//Check if team1 can beat team2
			if(node == team2)
				c = '>';
			else{
				if(c == '?')		//This allows our recursio not "reset" our result as we have found our desired result
					c = predict(node, team2);
			}
		}
		for(Team* node : b){		//Check if team2 can beat team1
			if(node == team1)
				c = '<';
			else{
				if(c == '?')		//This allows our recursio not "reset" our result as we have found our desired result		
					c = predict(team1, node);
			}
		}
	}
	return c;
}

void testCase1(){
	//     E     A
	//      \   /
	//        B   
	//       / \  
	//      C   D 
	
	Team* A = new Team('A');
	Team* B = new Team('B');
	Team* C = new Team('C');
	Team* D = new Team('D');
	Team* E = new Team('E');	
	A->beat(B);
	B->beat(C);
	B->beat(D);
	E = A;	
	
	//Run Prediction
	cout << "A" << predict(A,B) << "B" << endl;
	cout << "B" << predict(B,A) << "A" << endl;
	cout << "A" << predict(A,C) << "C" << endl;
	cout << "C" << predict(C,D) << "D" << endl;
	cout << "A" << predict(A,E) << "E" << endl;
	cout << "E" << predict(E,B) << "B" << endl << endl;
}

void testCase2(){
	//     E     A
	//      \   / \
	//        B    C
	//       / \  
	//      D   Q 
	//     /
	//    F
	Team* A = new Team('A');
	Team* B = new Team('B');
	Team* C = new Team('C');
	Team* D = new Team('D');
	Team* E = new Team('E');
	Team* F = new Team('F');
	Team* Q = new Team('Q');
	
	A->beat(B);
	A->beat(C);
	B->beat(D);
	B->beat(Q);
	D->beat(F);
	E = A;
	
	//Run Prediction
	cout << "A" << predict(A,E) << "E" << endl;
	cout << "A" << predict(A,Q) << "Q" << endl;
	cout << "A" << predict(A,F) << "F" << endl;
	cout << "B" << predict(B,A) << "A" << endl;
	cout << "F" << predict(F,A) << "A" << endl;
	cout << "E" << predict(E,Q) << "Q" << endl;
	cout << "C" << predict(C,Q) << "Q" << endl;
	cout << "F" << predict(F,E) << "E" << endl << endl;	
}
