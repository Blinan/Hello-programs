#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
int main()
{
    std::unordered_map<int, int> map;
    map[3] = 4;
    map[2] = 3;
    map[1] = 2;
    for(auto it : map)
    std::cout <<"map["<< it.first << "] = " << it.second << std::endl;
    
    for(auto it = map.begin(); it != map.end(); ++it)
    //std::cout << it->first << it->second << std::endl;
    //std::cout << map[1]++ << std::endl;
    //std::cout << map[1] << std::endl;
    std::cout << "s" << std::endl;

    std::map<int, int> rmap;
    for(auto it : map){
        rmap[it.second] = it.first;
    }
    for(auto it : rmap){
        std::cout <<"rmap[" <<it.first << "] = " << it.second << std::endl;
    }
    
    std::unordered_map<int, int> rrmap;
    for(auto it : rmap){
        rrmap[it.second] = it.first;
    }
    for(auto it : rrmap){
        std::cout <<"rrmap[" <<it.first << "] = " << it.second << std::endl;
    }
    return 0;  
}