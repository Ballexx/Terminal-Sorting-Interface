#include <vector>
#include "Windows.h"

class Screen{
    public:
    
    Screen(int height, int width);

    void set_screen_buffer(int screen_width, int screen_height);
    void display(std::vector<int> list, int list_len);

    private:
    const int screen_height;
    const int screen_width;

    wchar_t *screen;
    HANDLE console;
    DWORD bytes_written;
};