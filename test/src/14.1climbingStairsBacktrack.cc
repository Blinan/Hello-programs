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


int A_climbingStairsBacktrack(int n){
    vector<int> choices = {1, 2}; // 可选择向上爬 1 阶或 2 阶
    int state = 0;                // 从第 0 阶开始爬
    vector<int> res = {0};        // 使用 res[0] 记录方案数量
    A_backtrack(choices, state, n, res);
    return res[0];
}
void A_backtrack(vector<int> &choices, int state, int n, vector<int> &res){
    if(state == n)
    ++res[0];

    for(auto it: choices){
        if(state + it > n)
        continue;
        A_backtrack(choices, state+it, n, res);
    }
}

int B_climbingStairsDP(int n);

int C_climbingStairsDFSMem(int n);
int C_dfs(int i){
    
}