/****************************************************************************
Задача № 3. ДП (3 балла)

Дано N кубиков. Требуется определить каким количеством способов можно
выстроить из этих кубиков пирамиду.

*Формат входных данных:*

На вход подается количество кубиков N.

*Формат выходных данных:*

Вывести число различных пирамид из N кубиков.
****************************************************************************/

/****************************************************************************
Широкая пирамида.

Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.
N ≤ 300.

  ---- -----
  in   out
  3    2
  5    3
  7    5
  ---- -----

****************************************************************************/

/****************************************************************************
Идея:

Составим таблицу, где по горизонтали - размер нижележащего слоя, а по
вертикали - количество оставшихся блоков.
****************************************************************************/


#include <iostream>

void get_table(int64_t **table, size_t blocks) {
    for( size_t curr = 0; curr < 2*blocks + 1; ++curr ) {
        for( size_t m = 1; m <= curr + 1; ++m ) {
            //n - количество оставшихся блоков, m - размер нижележащего слоя
            size_t n = curr - m + 1;

            if( n == 0 )
            table[n][m] = 1;
            else {
                table[n][m] = 0;
                //спускаемся на уровень ниже, где был резльтат построения для n-1 случая блоков
                //при размере нижележащего слоя равным j
                for( size_t j = 1; j <= n; ++j ) {
                    size_t i = n - j;
                    if( j < m ) table[n][m] += table[i][j];
                }
            }
        }
    }
}

int main() {

    size_t blocks;
    std::cin >> blocks;

    int64_t **table = new int64_t*[2*blocks + 1];

    for( size_t i = 0; i < 2*blocks + 1; ++i ) {
        table[i] = new int64_t[blocks * 2 + 1];
        for( size_t  j = 0; j < 2*blocks + 1; ++j )
            table[i][j] = 0;
    }

    get_table(table, blocks);

    std::cout << (table[blocks][blocks] + 1);

    return 0;
}

