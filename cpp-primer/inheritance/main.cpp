#include <iostream>

class Item{
public:
    Item(){}
    ~Item(){}
    int cost(int n);
private:
    int price = 15;
};
int Item::cost(int n){
    return price*n;
}


class StageItem : public Item{
public:
    StageItem():n(0){}
    StageItem(int nums):n(nums){}
    ~StageItem(){}
private:
    int n;
};

int main()
{
    Item schoolBag;
    StageItem bag(100);
    std::cout << schoolBag.cost(50) << std::endl;
    std::cout << bag.cost(100) << std::endl;
    return 0;
}