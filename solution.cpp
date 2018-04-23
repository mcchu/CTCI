#include "solution.h"

Solution::Solution(){
}

//Algorithm: Output TRUE if the string has all unique chars, otherwise output FALSE
bool Solution::isUnique(string s1){
	// Time   | Space : Approach
	//O(n^2)  | O(1)  : Check each char against each other char
	//O(n)    | O(n)  : Use Hashset to store each traversed object
	//O(nlogn)| O(1)  : Sort string based on ASCII values 
	//O(n)    | O(1)  : Utilize a binary implementation where each bit = 1 char
	
#if 0
	//Hashset Method
	unordered_set<char> unique_set;
	for(char c : s1){
		if(unique_set.find(c) == unique_set.end()){
			unique_set.insert(c);
		}
		else{
			return false;
		}
	}
	
	//Sort method
	sort(s1.begin(), s1.end());
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] == s1[i+1]){
			return false;
		}
	}
#endif
	
	//Binary Count Implementation
	int checker = 0;
	for(char c: s1){
		int bit_idx = c - 'a';
		if((checker & (1 << bit_idx)) > 0)
			return false;
		checker = checker | (1<<bit_idx);
	}
	
	return true;
}


//Algorithm: Output TRUE if s2 is 1 char difference from S1, otherwise output FALSE
bool Solution::oneAway(string s1, string s2){
	//Three potential criterias
	//1. pale --> ple 		1 char is added
	//2. pale --> pales		1 char is missing
	//3. pale --> bale 		1 char is different
	int s1_len = s1.length();
	int s2_len = s2.length();
	
	if(s1_len == s2_len){
		//Can only check if at MOST one character is different
		bool found_diff = false;
		for(int i = 0; i < s1.length(); i++){
			if(s1[i] != s2[i]){
				if(found_diff){
					return false;
				}
				found_diff == true;
			}
		}
		return true;
	}
	else if(s1_len+1 == s2_len || s1_len == s2_len+1){
		if(s1_len < s2_len)
			swap(s1,s2);
		int l = 0, r = 0; 		//l = s1 tracker, r = s2 tracker
		while(l < s1_len && r < s2_len){
			if(s1[l] != s2[r]){
				if(l != r) //2 chars are missing or added
					return false;
				l++;
			}
			else{
				l++;
				r++;
			}
		}
		return true;
	}
	return false;
}


//Algorithm: Output TRUE if s2 is a rotation of S1, otherwise output FALSE
//Input: waterbottle, terbottlewa
//Output: True
bool Solution::isRotation(string s1, string s2){
	if(s1.length() == s2.length() && s1.length() > 0){
		s1 += s1; //Concatenate expand s1 (waterbottlewaterbottle)
		if(s1.find(s2) != string::npos){
			return true;
		}
	}
	return false;	
}


//Algorithm: Find and output the only number that appears once in the array
//Sample Input: [2,2,2,6],[1,2,1,1,1,1]
//Sample Output: [6,2]
vector<int> Solution::distinctValues(vector<vector<int>> values)
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
//Sample Input: ["Data", "GVi", DaGVi","DataHandler"]
//Sample Output: ["DataGraphView","DataGraphHandler","DataGraphVisual"]["GraphViewData","DataGraphVisual"]["DataGraphView"]["DataGraphHandler"]
vector<string> Solution::autoComplete(vector<string> dict, string key)
{
	vector<string> completed;
	
	//First we need to parse the key into workable parts. 
	vector<string> key_subs;
	int size = key.size();
	int st_idx = 0, idx = 0, len = 1;
		
	while(idx <= size){
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
	int key_size = key_subs.size();
	for(string str : dict){							//Loop through Dictionary First
		int i = 0;
		for(string ss : key_subs){					//Loop through Key Vectors
			for(; i < str.size(); i++){				//Loop through String
				if(str.substr(i).find(ss) != string::npos){
					i += str.substr(i).find(ss);
					count += 1;
				}
				else
					break;
			}
		}
		if(count == key_size){
			completed.push_back(str);
		}
		count = 0;		
	}
	
	return completed;
}