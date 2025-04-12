#include <vector>
#include "Windows.h"

class Screen{
    public:
    Screen();

    void set_screen_buffer();
    void display(std::vector<int> list, const int list_len);

    private:
    HANDLE h;
    HANDLE console;
    DWORD bytes_written;
};