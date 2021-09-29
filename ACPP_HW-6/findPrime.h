#pragma once
#include <vector>
#include "pcout.h"

void findPrime(size_t n)
{
    size_t size = n; // ����� ��������� ��� ������� ����� ��� �����������
    std::vector<int> primes(n, 0); // ������ ������� �����
    std::vector<int> numbers; // ������ ��� �����

    for (int i = 0; i < size; i++)
        numbers.push_back(i); // ��������� ������ (����� ����� ������� ��������)

    primes[0] = 2; // ������ ������� ����� - 2
    size_t i = 0; // ������ �������� �������� �����
    size_t found = 0;
    int progress = 0;
    while (i <= n) {
        int p = primes[i++]; // ���������� ������� ������� �����

        for (int j = p * 2; j < size; j += p)
            numbers[j] = 0; // �������� ��� ������� ��� ����� � �������
        try
        {
            while (numbers.at(p + 1) == 0)
                p++; // ���� ��������� ��������� �����
        }
        catch (...)
        {
        }

        if (p + 1 >= size) { // ���� ������ �� �������, ��������� ������
            size *= 2;
            for (int j = size / 2; j < size; j++)
                numbers.push_back(j); // ��������� ����� ����� ������� �������

            i = 0; // ������������ � ��������� ������ �����������
        }
        else
        {
            if (found < i)
            {
                found = i;
            }

            primes[i] = p + 1; // ���������� ����� ������� �����

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