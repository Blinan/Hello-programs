#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>
bool binarySearch(std::vector<int> &arr, int search_num);

int main()
{

    std::vector<int> prime_nums = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    int size = prime_nums.size();
    std::cout.setf(std::ios::left);
    std::cout.setf(std::ios::fixed);
    std::setw(10);
    //std::cout << std::setprecision(10);
    for(int i = 0; i < size; ++i){
        if(prime_nums[i] % 4 == 3){
        std::cout 
        << "p = "<< std::setw(3) << prime_nums[i] 
        << ",2p+1 = " << std::setw(3) << 2*prime_nums[i]+1 
        <<", 2^p = " <<  std::setprecision(0) <<  std::setw(22) << pow(2,prime_nums[i])
        << ", 2p+1"
        << ((static_cast<unsigned long long int>(pow(2,prime_nums[i]))-1) % (2*prime_nums[i] + 1) == 0 ? " is  " : " is'n") 
        << " prime"<<"    ";
        std::cout << "The result of binarySearch is " << binarySearch(prime_nums, 2*prime_nums[i]+1) <<std::endl; 
    }
    }
    return 0;
}

bool binarySearch(std::vector<int> &arr, int search_num)
{
    auto left = arr.begin();
    auto right = arr.end()-1;
    auto mid = left + (right - left)/2;
    while(left < right ){
        if(*mid == search_num)return true;
        else if(search_num < *mid){
            right = mid - 1;
            mid = left + (right - left)/2;
        }
        else if(search_num > *mid){
            left = mid + 1;
            mid = left + (right - left)/2;
        }
    }
    return *mid == search_num;
}

