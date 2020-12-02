#include <stdio.h>
#include <stdlib.h>
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
          // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int* numbers, int array_size)
{
    // Формируем нижний ряд пирамиды
    int i = (array_size / 2) - 1;
    while (i >= 0) {
        siftDown(numbers, i, array_size - 1);
        i--;
    }

    // Просеиваем через пирамиду остальные элементы
    int j;
    for (j = array_size - 1; j >= 1; j--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[j];
        numbers[j] = temp;
        siftDown(numbers, 0, j - 1);
    }
}
int main()
{   int z;
    printf ("Enter count of elements: ");
    scanf("%d", &z);
    int a[z];
    int i;
    int j;
    // Заполнение массива случайными числами
    for ( i = 0; i < z; i++) {
        a[i] = rand() % 20 - 10;
    }

    // Вывод элементов массива до сортировки
    printf ("Start array: ");
    for ( j = 0; j < z; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
    heapSort(a, z); // вызов функции сортировки
    printf ("Sort array: ");
    // Вывод элементов массива после сортировки
    int k = 0;
    while (k<z) {
        printf ("%d  ", a[k]);
        k++;
    }

    printf("\n");
    return 0;
}
