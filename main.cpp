#include "sorter.hpp"
#include "algorithm.hpp"
#include <iostream>

int main(){
    int list_len;
    int algorithm_type;

    system("cls");
    
    std::cout << "Amount of lines you would like to sort?"<< std::endl;
    std::cout << std::endl;
    std::cin >> list_len;
    
    system("cls");

    std::cout << "What sorting algorithm?" << std::endl;
    std::cout << "1. Bubble sort" << std::endl;
    std::cout << "2. Selection sort" << std::endl;
    std::cout << "3. Merge sort" << std::endl;

    std::cout << std::endl;
    std::cin >> algorithm_type;
    
    system("cls");

    Sorter sort(list_len);

    switch (algorithm_type){
        case 1:
            bubble_sort(sort);
            break;
        case 2:
            selection_sort(sort);
            break;
        case 3:
            merge_sort(sort);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            return 1;
    }

	return 0;
}