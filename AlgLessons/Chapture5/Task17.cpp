#include <iostream>
#include <string>
#include <format>
#include "Task17.h"

using namespace std;

/// <summary>
/// Запускает выполнение (Глава 5) Задача #17 (5.24)
/// Заголовок: Быстрая сортировка
/// Описание: 
/// 
///     (В целях экономии, часть описания задания опущена)
///     Напишите рекурсивную функцию quickSort для сортировки одномерного массива целых.
///     Функция должна принимать в качестве аргументов массив целых, начальный массив
///     и окончательный массив.Функция partition должна вызываться функцией quickSort
///     для выполнения шага декомпозиции.
/// 
/// </summary>
/// <returns>Код результата выполнения программы</returns>
int runTask17()
{
    std::string input;

    while (input != "\\q") {
        /// 
        /// Отображаем документацию и базовое меню
        /// 
        system("CLS");

        std::cout <<
            R"STRING(
Запуск решения (Глава 5) Задача #17 (5.24)...
Название: "Быстрая сортировка"
Описание: 
        
    (В целях экономии, часть описания задания опущена)
    Напишите рекурсивную функцию quickSort для сортировки одномерного массива целых.
    Функция должна принимать в качестве аргументов массив целых, начальный массив
    и окончательный массив. Функция partition должна вызываться функцией quickSort
    для выполнения шага декомпозиции.
    
    
    
         
Для запуска программы введите команду Y. Для выхода введите команду \q.)STRING" << endl;

        cin >> input;

        /// 
        /// Определяем, является ли введенное значение допустимым
        /// 
        if (input == "Y" || input == "y") {
            while (input != "\\q") {
                system("CLS");

                int arr[] = { 99, 12, 7, 16, 1, 5, 10, 19, 67, 124 };
                int n = 10;

                cout << "Исходный массив: ";

                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                cout << endl;

                quickSort(arr, 0, n - 1);

                cout << "Отсортированный массив: ";

                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                cout << endl;


                cout << "\n\nДля выхода введите \\q" << endl;
                cin >> input;
            }
        }
    }
    system("CLS");
    std::cout << "Завершение работы программы программы...";

    return 0;
}

/// <summary>
/// Выполняет декомпозицию массива, извлекая первый элемент несортированного
/// массива и определяя его окончательную позицию в сортированном массиве.
/// </summary>
/// <param name="arr">Исходный массив</param>
/// <param name="start">Левая граница диапазона</param>
/// <param name="end">Правая граница диапазона</param>
/// <returns>Индекс массива, при котором слева находятся все числа меньше, 
/// чем выбранный элемент, а справа - больше</returns>
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

/// <summary>
/// Выполняет сортировку массива методом "Быстрой сортировки"
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="start">Левая граница поиска</param>
/// <param name="end">Правая граница поиска</param>
void quickSort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

