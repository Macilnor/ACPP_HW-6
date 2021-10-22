#pragma once
#include <vector>
#include "pcout.h"

void findPrime(size_t n)
{
    size_t size = n; // число элементов для массива чисел для просеивания
    std::vector<int> primes(n, 0); // массив простых чисел
    std::vector<int> numbers; // массив для чисел

    for (int i = 0; i < size; i++)
        numbers.push_back(i); // заполняем массив (число равно индексу элемента)

    primes[0] = 2; // первое простое число - 2
    size_t i = 0; // индекс текущего простого числа
    size_t found = 0;
    int progress = 0;
    while (i <= n) {
        int p = primes[i++]; // запоминаем текущее простое число

        for (int j = p * 2; j < size; j += p)
            numbers[j] = 0; // обнуляем все кратные ему числа в массиве
        try
        {
            while (numbers.at(p + 1) == 0)
                p++; // ищем следующее ненулевое число
        }
        catch (...)
        {
        }

        if (p + 1 >= size) { // если выйдем за границы, расширяем массив
            size *= 2;
            for (int j = size / 2; j < size; j++)
                numbers.push_back(j); // заполняем новую часть массива числами

            i = 0; // возвращаемся к начальной стадии просеивания
        }
        else
        {
            if (found < i)
            {
                found = i;
            }

            primes[i] = p + 1; // запоминаем новое простое число

            if (progress < static_cast<int>((static_cast<double>(found) / n) * 100))
            {
                progress = static_cast<int>((static_cast<double>(found) / n) * 100);
                system("cls");
                pcout{} << progress << "% completed." << std::endl;
            }
        }
    }
    system("cls");
    pcout{} << n << " prime number is " << primes[n - 1] << std::endl;
}