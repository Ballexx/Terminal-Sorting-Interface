#include "Windows.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "screen.hpp"

Screen::Screen(){
    HANDLE console;
    DWORD bytes_written;
}

void Screen::set_screen_buffer(){
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    bytes_written = 0;
};

void Screen::display(std::vector<int> list, const int list_len){
    std::vector<wchar_t> grid(list_len * list_len * 2, L' ');
    std::vector<bool> value_hit(list_len, false);

    for (int i = 0; i < list_len; i++) {
        for (int j = 0; j < list_len; j++) {
            int index = (i * list_len + j) * 2;  

            if(list[j] + i == list_len){
                grid[index] = L'█'; 
                grid[index + 1] = L'█';
                value_hit[j] = true;
            }
            else if (value_hit[j] == true){
                grid[index] = L'█'; 
                grid[index + 1] = L'█';
            }
            else{
                grid[index] = L' '; 
                grid[index + 1] = L' '; 
            }
        }
    }

    for (int row = 0; row < list_len; row++) {
        WriteConsoleOutputCharacterW(
            console,
            &grid[row * list_len * 2], 
            list_len * 2,             
            { 0, (SHORT)row },    
            &bytes_written
        );
    }

    std::this_thread::sleep_for(std::chrono::nanoseconds(500));
}

