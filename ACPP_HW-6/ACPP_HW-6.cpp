#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <stdlib.h>
#include "pcout.h"
#include "findPrime.h"

using namespace std;

std::mutex pcout::_mutexPrint{};

void printId()
{
    pcout{} << "Thread " << this_thread::get_id() << " started." << endl;
    this_thread::sleep_for(1s);
    pcout{} << "Thread " << this_thread::get_id() << " stoped." << endl;
}

int main()
{
    thread th1(printId);
    thread th2(printId);
    thread th3(printId);
    th1.join();
    th2.join();
    th3.join();

    size_t n;
    system("cls");
    std::cout << "Enter index of prime number: ";
    std::cin >> n;
    thread t_prime(findPrime, n);
    t_prime.join();
}
