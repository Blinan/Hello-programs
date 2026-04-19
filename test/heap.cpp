#include<iostream>
#include<queue>
#include<vector>




class maxHeap{
public:
    int left(int i);
    int right(int i);
    int parent(int i);
    void siftDown(int );
    void swap(int i, int j);
private:
    std::vector<int> max_heap;
};

int main()
{
    
    std::vector<int> contain = {8,4,5,1,5,1,6,8,4,74,9,4};

    return 0;
}

int maxHeap::left(int i){
    return 2*i+1;
}

int maxHeap::right(int i){
    return 2*i+2;
}

int maxHeap::parent(int i){
    return (i-1)>>1;
}

void maxHeap::siftDown(int i){

}
void maxHeap::swap(int i, int j){
    auto it = max_heap[i];
    max_heap[i] = max_heap[j];
    max_heap[j] = it;
}
