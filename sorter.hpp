#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>

class Sorter{
    public:
    
    Sorter(int len);
    void shuffle_list();
    int generate_random_number(int min, int max);
    const int get_list_len() const;
    std::vector<int>& get_list();
    void print_list() const;

    private:

    const int list_len;
    std::vector<int> list;
};

#endif