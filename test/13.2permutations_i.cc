//********************************* */
//*ORIGIN    Hello-algo13.2 2
//*PROGRAM    全排列问题-无重复元素
//********************************* */
//实现功能:解决全排列问题
#include <iostream>
#include <vector>

using namespace std;
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);
vector<vector<int>> permutationsI(vector<int> nums);

int main(){
    vector<int> nums{1,2,3,4,5,6,7};
    vector<vector<int>> res;
    res = permutationsI(nums);
    cout << res.max_size() << endl;
    cout << res.size() << endl;
    return 0;
}
vector<vector<int>> permutationsI(vector<int> nums){
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res); 
    return res;
}
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res){
    if(state.size() == choices.size()){
        res.push_back(state);
        return;
    }

    for(int i = 0; i < choices.size(); ++i){
        if(!selected[i]){
            state.push_back(choices[i]);
            selected[i]=true;

            backtrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}
