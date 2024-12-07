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
        std::vector<int>& InsertionSort(std::vector<int>& items, int index, int size);
        std::vector<int>& BubbleSort(std::vector<int>& items, int index, int size);


};


std::vector<int>& InsertionSort(std::vector<int>& items, int index, int size) {

    for(int i = 1; i <= size; i++) {
        int value = items[i];
        int j = i - 1;

        while(j >= 0 && value < items[j]) {
            items[j + 1] = items[j];
            j--;
        }

        items[j + 1] = value;
    }

    return items;
}

std::vector<int>& BubbleSort(std::vector<int>& items, int index, int size) {



    return items;
}


#endif