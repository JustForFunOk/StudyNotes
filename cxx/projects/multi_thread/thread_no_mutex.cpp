#include <iostream>
#include <thread>
#include <limits>

static int g_i;

void increase(int cnt)
{
    for(int i = 0; i < cnt; ++i)
    {
        g_i++;
    }
}

int main()
{
    std::thread t1(increase, 10000);
    std::thread t2(increase, 10000);
    t1.join();
    std::cout << "t1.join" << std::endl;
    t2.join();
    std::cout << g_i;
    return 0;
}
