#include "algorithm.hpp"
#include "sorter.hpp"
#include "vector"
#include "screen.hpp"

#include <iostream>

void bubble_sort(Sorter sorter){
    const int list_len = sorter.get_list_len();
    std::vector<int> list = sorter.get_list();

    Screen console;
    console.set_screen_buffer();

    for (int step = 0; step < (list_len-1); ++step) {
        int swapped = 0;

        for (int i = 0; i < (list_len-step-1); ++i) {
            if (list[i] > list[i + 1]) {
                int temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                
                swapped = 1;

                console.display(list, list_len);
            }
        }
    }
    
    console.display(list, list_len);
}

void selection_sort(Sorter sorter) {
    const int list_len = sorter.get_list_len();
    std::vector<int> list = sorter.get_list();

    Screen console;
    console.set_screen_buffer();

    for (int i = 0; i < list_len - 1; ++i) {
        int min_index = i;

        for (int j = i + 1; j < list_len; ++j) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
            console.display(list, list_len);
        }

        if (min_index != i) {
            std::swap(list[i], list[min_index]);
        }
    }

    console.display(list, list_len);
}

//Does not work yet

void merge_sort(Sorter sorter){
    const int list_len = sorter.get_list_len();
    std::vector<int> list = sorter.get_list();

    Screen console;
    console.set_screen_buffer();

    int left = 0;
    int right = list_len;
    int mid = left + (right - left) / 2;

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftArray(leftSize), rightArray(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = list[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = list[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            list[k] = leftArray[i];
            i++;
        } else {
            list[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        list[k] = leftArray[i];
        i++;
        k++;
        
        console.display(list, list_len);
    }

    while (j < rightSize) {
        list[k] = rightArray[j];
        j++;
        k++;

        console.display(list, list_len);
    }
    console.display(list, list_len);
}
