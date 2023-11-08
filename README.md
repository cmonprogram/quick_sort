# quick_sort
Реализация алгоритма быстрой сортировки с компаратором

```
template <typename T>
void PrintArray(std::vector<T> &input)
{
    for (const auto &elem : input)
    {
        std::cout << elem << " ";
    }
}

int main()
{
    std::vector<int> array{3, 1, 1, 12, 9, 5, 11};

    QuickSort(array);
    PrintArray(array);
    std::cout << std::endl;

    QuickSort(array, [](int i, int j) { return i > j; });
    PrintArray(array);
    std::cout << std::endl;
}
```
Вывод:
```
1 1 3 5 9 11 12 
12 11 9 5 3 1 1
```
