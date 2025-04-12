#include "Windows.h"
#include <iostream>
#include <vector>
#include "screen.hpp"

Screen::Screen(int height, int width) : screen_height(height), screen_width(width){
    wchar_t *screen;
    HANDLE console;
    DWORD bytes_written;
}

void Screen::set_screen_buffer(int screen_width, int screen_height){
    screen = new wchar_t[screen_width, screen_height];
    console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(console);
    bytes_written = 0;
};

void Screen::display(std::vector<int> list, int list_len){
    

    screen[screen_height * screen_width - 1] = '\0';
    WriteConsoleOutputCharacterW(
        console,
        screen,
        screen_width * screen_height,
        { 0, 0 },
        &bytes_written
    );

}   