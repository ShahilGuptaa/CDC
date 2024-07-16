#include <iostream>
#include <thread> // Correctly include the thread header
#include <unistd.h>
//run in codechef compiler, c++11 is not supported in the mingw version of this laptop

using namespace std;

void taskA()
{
    for(int i = 0; i < 10; i++) {
        sleep(1);
        cout << "Task A: " << i << '\n';
        fflush(stdout);
    }
}

void taskB()
{
    for(int i = 0; i < 10; i++) {
        sleep(1);
        cout << "Task B: " << i << '\n';
        fflush(stdout);
    }
}

int main()
{
    thread t1(taskA); 
    thread t2(taskB); 
    t1.join();
    t2.join();
    return 0;
}
