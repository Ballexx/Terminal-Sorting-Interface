#include "algorithm.hpp"
#include "sorter.hpp"
#include "vector"

#include <iostream>

void bubble_sort(Sorter sorter){
    const int list_len = sorter.get_list_len();
    std::vector<int> list = sorter.get_list();

    for (int step = 0; step < (list_len-1); ++step) {
        int swapped = 0;

        for (int i = 0; i < (list_len-step-1); ++i) {
            if (list[i] > list[i + 1]) {
                int temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                
                swapped = 1;
            }
        }
    }
}
