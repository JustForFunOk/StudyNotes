#include <iostream>
#include <thread>
#include <climits>
#include <chrono>
#include <functional>
#include <atomic>

using namespace std;

// static int g_i;
static atomic<int> g_i(0);

void increase(int cnt)
{
    for(int i = 0; i < cnt; ++i)
    {
        g_i++;
        // cout << hash<thread::id>{}(this_thread::get_id()) << ":" << g_i << endl;
    }
}

int main()
{
    std::thread t1(increase, 10000); // 创建线程, 把10当做参数传入线程入口函数,并启动线程t1
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t2(increase, 10000);
    t1.join();  // 等待,直到线程t1退出线程
    t2.join();  // 等待,直到线程t2退出线程

    std::cout << g_i;
    return 0;
}
