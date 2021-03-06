/****************************************************************************
Задача 2_* (3 балла)

Дан массив целых чисел A\[0..n). Массив произвольным образом заполнен
натуральными числами из диапазона \[0..n - 1). Одно или несколько значений
в массиве может повторяться. Необходимо найти любой повтор за O(n), памяти O(1).
Исходный массив хранить можно, модифицировать нельзя.
n ≤ 10000.

  in               | out
  -----------------|-----
  8                | 1
  1 2 4 5 6 1 0 3  |

****************************************************************************/

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int* A = new int[n];

    for(int i = 0; i<n; ++i)
        std::cin >> A[i];

    //указатель на элемент, на котром я буду в цикле после прохода n раз
    int count = n-1;
    //так я точно зайду в цикл
    for(int i = 0; i < n; ++i)
        count = A[count];
    //count указывает на элемент в цикле
    int cicleElem = A[count];
    //счетчик для длины цикла
    int k = 0;
    while(cicleElem != count)
    {
        count = A[count];
        ++k;
    }
    //делаем ползунки для поиска входа в первый цикл
    count = n - 1;
    int count1 = count;
    //двигаем втрой укзател в графе на k позиций вперед
    for(int i = 0; i < k; ++i)
        count1 = A[count1];
    //бежим по графу пока не установим, что полузнки будут на одном элемента - входе в цикл
    while(A[count] != A[count1])
    {
        count = A[count];
        count1 = A[count1];
    }
    //Ну усе, типа нашли вход
    //он будет A[count]

    std::cout << A[count];


    delete[] A;

    return 0;
}

