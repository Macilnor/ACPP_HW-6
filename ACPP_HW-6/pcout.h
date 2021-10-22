#pragma once
#include <mutex>
#include <iostream>
class pcout: public std::ostringstream
{
public:
    pcout() = default;

    ~pcout()
    {
        std::lock_guard<std::mutex> guard(_mutexPrint);
        std::cout << this->str();
    }

private:
    static std::mutex _mutexPrint;
};

