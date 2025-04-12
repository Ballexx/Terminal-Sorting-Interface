#include "Sorter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Sorter::Sorter(int len) : list_len(len) {
    shuffle_list();
}

int Sorter::generate_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void Sorter::shuffle_list() {
    srand((unsigned) time(NULL));
    list = std::vector<int>(list_len);
    for (int i = 0; i < list_len; i++) {
        list[i] = i + 1;
    }

    for (int i = 0; i < list_len * 1000; i++) {
        int x = generate_random_number(0, list_len - 1);
        int y = generate_random_number(0, list_len - 1);
        std::swap(list[x], list[y]);
    }
}

const int Sorter::get_list_len() const {
    return list_len;
}

std::vector<int>& Sorter::get_list() {
    return list;
}

void Sorter::print_list() const {
    for (int i = 0; i < list_len; i++) {
        std::cout << list[i] << " ";
    }
}

void display(std::vector<int> list, int list_len){
    system("cls");

    for(int i = 0; i < list_len; i++){
        for(int j = 0; j < list_len; j++){
            std::cout << char(219) << char(219);
        }
        std::cout << '\n';
    }
}   