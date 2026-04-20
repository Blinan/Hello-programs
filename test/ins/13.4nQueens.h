//********************************* */
//*ORIGIN    Hello-algo13.4
//*PROGRAM    nQueens
//********************************* */
/* 回溯算法：n 皇后 */
#include <iostream>
#include <vector>

using namespace std;

void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res, 
    vector<bool> &cols, vector<bool> &diags1, vector<bool> &diags2);

vector<vector<vector<string>>> nQueens(int n);

void printNQueens(vector<vector<vector<string>>> res);
