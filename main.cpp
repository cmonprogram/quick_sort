#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename C = std::nullptr_t>
void QuickSort(std::vector<T>& arr, int low, int high, C comp = nullptr)
{
	if (low < high) {
		T pivot = arr.at(high);
		int i = low - 1;
		for (int j = low; j <= high - 1; ++j) {
			if constexpr (std::is_same<C, std::nullptr_t>::value) {
				if (arr.at(j) < pivot) {
					++i;
					std::swap(arr.at(i), arr.at(j));
				}
			}
			else {
				if (comp(arr.at(j), pivot)) {
					++i;
					std::swap(arr.at(i), arr.at(j));
				}
			}
		}
		++i;
		std::swap(arr.at(i), arr.at(high));

		if constexpr (std::is_same<C, std::nullptr_t>::value) {
			QuickSort(arr, low, i - 1);
			QuickSort(arr, i + 1, high);
		}
		else {
			QuickSort(arr, low, i - 1, comp);
			QuickSort(arr, i + 1, high, comp);
		}

	}
}

template <typename T, typename C = std::nullptr_t>
void QuickSort(std::vector<T>& input, C comp = nullptr) {
	QuickSort(input, 0, input.size() - 1, comp);
}

int main() {
    std::vector<int> array{ 3,  1,  1, 6, 12,  9,  5,  11 };
    QuickSort(array, [](int i, int j) {return i < j; });
}
