//********************************* */
//*ORIGIN    Hello-algo13.2 2
//*PROGRAM    全排列问题-无重复元素
//********************************* */
//实现功能:解决全排列问题
#include <iostream>
#include <vector>

#pragma once

using namespace std;
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);
vector<vector<int>> permutationsI(vector<int> nums);

vector<vector<int>> permutationsI(vector<int> nums);
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);
