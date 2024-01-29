#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;             // 全局互斥锁.
condition_variable cv; // 全局条件变量.
int ready = 0;         // 全局标志位.

void Print_A()
{
    unique_lock<mutex> lk(mtx);
    int cnt = 0;

    while (cnt < 10)
    {
        while (ready != 0) // 如果标志位不为 true, 则等待...
        {
            cv.wait(lk); // 当前线程被阻塞, 当全局标志位变为 true 之后, 线程被唤醒, 继续往下执行打印线程编号id.
        }

        cout << this_thread::get_id() << " : "
             << "A" << endl;
        ready = 1;
        ++cnt;
        cv.notify_all(); // 唤醒所有线程.
    }
}

void Print_B()
{
    unique_lock<mutex> lk(mtx);
    int cnt = 0;

    while (cnt < 10)
    {
        while (ready != 1)
        {
            cv.wait(lk);
        }

        cout << this_thread::get_id() << " : "
             << "B" << endl;
        ready = 2;
        ++cnt;
        cv.notify_all();
    }
}

void Print_C()
{
    unique_lock<mutex> lk(mtx);
    int cnt = 0;

    while (cnt < 10)
    {
        while (ready != 2)
        {
            cv.wait(lk);
        }

        cout << this_thread::get_id() << " : "
             << "C" << endl;
        ready = 0;
        ++cnt;
        cv.notify_all();
    }
}

int main()
{
    thread t1(Print_A);
    thread t2(Print_B);
    thread t3(Print_C);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
