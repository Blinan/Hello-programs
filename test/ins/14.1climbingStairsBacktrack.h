//********************************* */
//*ORIGIN    Hello-algo14.1
//*PROGRAM    climbingStairs
//********************************* */
//解决问题给定一个共有 n阶的楼梯，你每步可以上 1阶或者2 阶，请问有多少种方案可以爬到楼顶？

#include <iostream>
#include <vector>

using namespace std;

int A_climbingStairsBacktrack(int n);
void A_backtrack(vector<int> &choices, int state, int n, vector<int> &res);

int B_climbingStairsDP(int n);

int C_climbingStairsDFSMem(int n);
int C_dfs(int i); 
