#include <iostream>
#include <raylib.h>
#include <unistd.h>
#include <vector>
int main()
{
    // InitWindow(800, 800, "test");
    // double start_time = GetTime();
    // usleep(5*1000*1000);
    // double end_time = GetTime();
    // CloseWindow();
    // double delta_time =  end_time - start_time;
    // std::cout << delta_time << "\n";

    std::vector<int> vi;
    for(int i = 5; i != 0; --i)
    vi.push_back(i);

    int * pi ;
    *pi = 10;
    auto it = vi.rbegin();
    int temp = *pi;
    std::cout << *pi;
    std::cout << "5";
    return 0;
}