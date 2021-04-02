// Copyright 2021 NNTU-CS

// 1 - реализация массива с полным перебором всех сумм (цикл в цикле)
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                k++;
    return k;
}
// 2 - улучшенный поиск сумм, с отбрасыванием заведомо лишних значений
int countPairs2(int* arr, int len, int value) {
    int l = 0, r = len -1, k = 0; // границы и счетчик
    if (arr[r] > value)
        while (arr[r] > value)
            r--; // отбрасываем лишние элементы
    while (r > l) {
        if (arr[r] + arr[l] > value) {
            int p = l; // чтобы в функции не изменялось значение левой границы
            if (arr[r] + arr[p] == value) {
                while (arr[r] + arr[p] == value) {
                    k++;
                    p++;
                }
                else
                    if (arr[r] + arr[l] < value)
                        l++;
            }
            r--;
        }
    }
    return k;
}
// алгоритм бинарного поиска второго элемента пары
int countPairs3(int* arr, int len, int value) {
    int l = 0, r = len - 1, k = 0; // границы и счетчик
    if (arr[r] > value)
        while (arr[r] > value)
            r--; // отбрасываем лишние элементы
    while (l < r) {
        int n = value - arr[l]; // искомый элемент (пара)
        int i = l, j = r; // чтобы границы не менялись
        while (i < j) { // бинарный поиск второго элемента пары
            int mid = (i + j) / 2;
            if (arr[mid] < n)
                i = mid + 1;
            else
                j = mid;
            if (arr[i] == n) {
                while (arr[i] == n) {
                    k++;
                    i++;
                }
            }
        }
        l++;
    }
    return k;
}
