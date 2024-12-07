//Harry Fung
//CSS342
//HW3
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>
#include <vector>


std::vector<int>& InsertionSort(std::vector<int>& items, int index, int size);
std::vector<int>& BubbleSort(std::vector<int>& items, int index, int size);
std::vector<int>& MergeSort(std::vector<int>& items, int index, int size);
std::vector<int>& MergeSort_(std::vector<int>& items, int left, int right);



std::vector<int>& InsertionSort(std::vector<int>& items, int index, int size) {

//  Also works:
//  for(int i = 1; i <= size; i++) {
    for(int i = 1; i < items.size(); i++) {
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

    for(int i = 0; i < items.size() - 1; i++) {

        for(int j = 0; j <= items.size() - i - 1; j++) {

            if(items[j] > items[j + 1]) {
                int temp = items[j];
                items[j] = items[i];
                items[i] = temp;
            }
        }

    }

    return items;
}

void Merge_(std::vector<int>& items, int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle;

    std::vector<int> left_side(left_size);
    std::vector<int> right_side(right_size);

    // std::cout << "here" << std::endl;
    // std::cout << left_size << " " << right_size << std::endl;
    for(int i = 0; i < left_size; i++) {
        left_side[i] = items[left + i];
    }

    for(int i = 0; i < right_size; i++) {
        right_side[i] = items[middle + i + 1];
    }


    int left_index = 0;
    int right_index = 0;
    int items_index = left;

    while(left_index < left_size && right_index < right_size) {
        if(left_side[left_index] > right_side[right_index]) {
            items[items_index] = right_side[right_index];
            right_index++;
        } else {
            items[items_index] = left_side[left_index];
            left_index++;
        }
        items_index++;
    }

    while(left_index < left_size) {
        items[items_index] = left_side[left_index];
        left_index++;
        items_index++;
    }

    while(right_index < right_size) {
        items[items_index] = right_side[right_index];
        right_index++;
        items_index++;
    }

}

std::vector<int>& MergeSort_(std::vector<int>& items, int left, int right) {
    if(left < right) {
        int middle = (left + right) / 2;

        // std::cout << left << " " << middle << " " << right << std::endl;

        MergeSort_(items, left, middle);
        MergeSort_(items, middle + 1, right);

        Merge_(items, left, middle, right);
    }

    return items;
}

std::vector<int>& MergeSort(std::vector<int>& items, int index, int size) {
    // std::cout << size << " " << items.size() << std::endl;
    return MergeSort_(items, 0, items.size() - 1);
}



#endif