#ifndef MAIN_H
#define MAIN_H

#include <iostream>
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

#endif