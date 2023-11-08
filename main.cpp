#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename C = std::nullptr_t>
void QuickSort(std::vector<T>& input, C comp = nullptr){

if(input.size() <= 1) return;

int middle = (input.size() - 1) / 2;
int base_elem = input[middle];

std::vector<T> v_low;
std::vector<T> v_high;

int i = 0;
for(const auto& elem : input){
    if(i != middle){
        if constexpr(std::is_same<C, std::nullptr_t>::value){
            if(elem <= base_elem){v_low.push_back(elem);}
            else{v_high.push_back(elem);}
        }else{
            if(comp(elem, base_elem)){v_low.push_back(elem);}
            else{v_high.push_back(elem);}
        }
    }
    ++i;
}

if constexpr(std::is_same<C, std::nullptr_t>::value){
    QuickSort(v_low);
    QuickSort(v_high);
}else{
    QuickSort(v_low,comp);
    QuickSort(v_high,comp);
}

v_low.push_back(std::move(base_elem));

std::move(v_low.begin(), v_low.end(),input.begin());
std::move(v_high.begin(), v_high.end(), input.begin() + v_low.size());
}

int main(){
std::vector<int> array {3,  1,  1, 12,  9,  5,  11};
QuickSort(array,[](int i, int j){return i > j;});
}
