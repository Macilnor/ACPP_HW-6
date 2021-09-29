#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <set>
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

void owner(set<int>& items, size_t items_count)
{
    for (size_t i = 0; i < items_count; i++)
    {
        int item = rand() % 100;
        items.insert(item);
        pcout{} << "Owner brings item with value " << item << endl;
        this_thread::sleep_for(500ms);
    }
}

void thief(set<int>& items)
{
    this_thread::sleep_for(3s);
    while (!items.empty())
    {
        pcout{} << "Thief stole item with value " << *(--items.end()) << endl;
        items.erase(--items.end());
        this_thread::sleep_for(700ms);
    }
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

    set<int> items;
    thread owner(owner, ref(items), 10);
    thread thief(thief, ref(items));
    owner.detach();
    thief.join();
}
