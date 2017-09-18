/****************************************************************************
Задача 4_3. Количество инверсий.

Дана последовательность целых чисел из диапазона (-10^9 .. 10^9). Длина последовательности не больше 10^6. Числа записаны по одному в строке. Количество чисел не указано.

Пусть количество элементов n, и числа записаны в массиве a = a[i]: i из [0..n-1].

Требуется напечатать количество таких пар индексов (i,j) из [0..n-1], что (i <> j и a[i] > a[j]).

Указание: количество инверсий может быть больше 4*10^9 - используйте int64_t.

    #include "stdint.h"

    int64_t cnt = 0;
    printf("%ld", cnt);

in | out
-- | ---
1  | 0
2  |
3  |
4  |

in | out
-- | ---
4  | 6
3  |
2  |
1  |

in | out
-- | ---
3  | 2
2  |
2  |

****************************************************************************/

#include <iostream>

int main()
{
    return 0;
}

