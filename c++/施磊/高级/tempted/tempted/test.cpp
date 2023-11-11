#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <functional>

std::mutex mtx;

void threadHandle1(int i, std::unique_lock<std::mutex> locc) {
    std::cout << "Thread " << i << " is running..." << std::endl;
    locc.unlock();  // 手动解锁
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main5() {
    std::vector<std::thread> vec;

    for (int i = 0; i < 3; i++) {
        std::unique_lock<std::mutex> locc(mtx); // 锁定互斥锁
        vec.push_back(std::thread(threadHandle1, i, std::move(locc))); // 创建线程并传递参数
    }

    for (std::thread& t : vec) {
        t.join(); // 等待线程完成
    }

    std::cout << "All threads have finished." << std::endl;

    return 0;
}