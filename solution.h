#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution{
public:
	Solution();
	bool isUnique(string s1);
	bool oneAway(string s1, string s2);
	bool isRotation(string s1, string s2);
	vector<int> distinctValues(vector<vector<int>> values);
	vector<string> autoComplete(vector<string> dict, string key);	
};

#endif