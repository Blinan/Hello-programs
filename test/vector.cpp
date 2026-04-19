#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    for(int i = 0; i < 10; ++i){
        std::cout << *(v.begin() + i) << std::endl;
    }
    return 0;
}
int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for(int i = 0; i < k; ++i){
            min_heap.push(*(nums.begin()+i));
        }
        for(auto it = nums.begin()+k; it != nums.end(); ++it){
            if(*it > min_heap.top()){
                min_heap.pop();
                min_heap.push(*it);
            }
        }
        return min_heap.top();
    }