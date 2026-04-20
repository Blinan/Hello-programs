#include <iostream>
#include <vector>
#include <queue>

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