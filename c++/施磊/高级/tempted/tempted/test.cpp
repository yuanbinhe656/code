#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <functional>

std::mutex mtx;

void threadHandle1(int i, std::unique_lock<std::mutex> locc) {
    std::cout << "Thread " << i << " is running..." << std::endl;
    locc.unlock();  // �ֶ�����
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main5() {
    std::vector<std::thread> vec;

    for (int i = 0; i < 3; i++) {
        std::unique_lock<std::mutex> locc(mtx); // ����������
        vec.push_back(std::thread(threadHandle1, i, std::move(locc))); // �����̲߳����ݲ���
    }

    for (std::thread& t : vec) {
        t.join(); // �ȴ��߳����
    }

    std::cout << "All threads have finished." << std::endl;

    return 0;
}