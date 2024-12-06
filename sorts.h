//Harry Fung
//CSS342
//HW3
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>
#include <vector>

class Sorts{

    public:
        std::vector<int>& BubbleSort(std::vector<int>& items, int index, int size);
};


std::vector<int>& BubbleSort(std::vector<int>& items, int index, int size) {
    static std::vector<int> list = {1, 2, 3, 4, 5};
    std::vector<int>* list2 = new std::vector<int>({1, 2, 3, 4, 5});


    return *list2;
}


#endif