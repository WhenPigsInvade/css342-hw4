//Harry Fung
//CSS342
//HW3
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>
#include <vector>


int InsertionSort(std::vector<int>& items, int index, int size);
int BubbleSort(std::vector<int>& items, int index, int size);
int MergeSort(std::vector<int>& items, int index, int size);
int Merge_(std::vector<int>& items, int left, int middle, int right);
int QuickSort(std::vector<int>& items, int low, int high);
int Partition_(std::vector<int>& items, int low, int high);
int ShellSort(std::vector<int>& items, int index, int size);
int IterativeMergeSort(std::vector<int>& items, int index, int size);


int InsertionSort(std::vector<int>& items, int index, int size) {

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

    return 0;
}

int BubbleSort(std::vector<int>& items, int index, int size) {

    for(int i = 0; i < items.size() - 1; i++) {

        for(int j = 0; j <= items.size() - i - 1; j++) {

            if(items[j] > items[j + 1]) {
                int temp = items[j];
                items[j] = items[i];
                items[i] = temp;
            }
        }

    }

    return 0;
}

int Merge_(std::vector<int>& items, int left, int middle, int right) {
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

    return 0;
}

int MergeSort(std::vector<int>& items, int left, int right) {
    if(left < right) {
        int middle = (left + right) / 2;

        // std::cout << left << " " << middle << " " << right << std::endl;

        MergeSort(items, left, middle);
        MergeSort(items, middle + 1, right);

        Merge_(items, left, middle, right);
    }

    return 0;
}

int Partition_(std::vector<int>& items, int low, int high) {
    int pivot = items[high];

    int index = low - 1;

    for(int i = low; i < high; i++) {
        if(items[i] <= pivot) {
            index++;
            int temp = items[i];
            items[i] = items[index];
            items[index] = temp;
        }
    }

    int temp = items[index + 1];
    items[index + 1] = items[high];
    items[high] = temp;

    return index + 1;
}


int QuickSort(std::vector<int>& items, int low, int high) {
    if(low < high) {
        int index = Partition_(items, low, high);

        QuickSort(items, low, index - 1);
        QuickSort(items, index + 1, high);

    }
    return 0;
}

int ShellSort(std::vector<int>& items, int index, int size) {
    for(int gap = items.size() / 2; gap > 0; gap--) {

        for(int i = gap; i < items.size(); i++) {
            int temp = items[i];
            int j = i;
            for(; j >= gap && items[j - gap] > temp; j -= gap) {
                items[j] = items[j - gap];
            }
            items[j] = temp;
        }
    }
    return 0;
}

int IterativeMergeSort(std::vector<int>& items, int index, int size) {
    std::vector<int> temp(items.size());

    for(int division_size = 1; division_size < items.size(); division_size*=2) {
        
        for(int left_index = 0; left_index + division_size < items.size(); left_index += division_size * 2) {

            int mid = left_index + division_size;
            int end = mid + division_size;

            if(end > items.size()) {
                end = items.size();
            }

            int counter = left_index;
            int left_sub_index = left_index;
            int right_sub_index = mid;

            while(left_sub_index < mid && right_sub_index < end) {
                if(items[left_sub_index] > items[right_sub_index]) {
                    temp[counter] = items[right_sub_index];
                    right_sub_index++;
                } else {
                    temp[counter] = items[left_sub_index];
                    left_sub_index++;
                }
                counter++;
            }

            while(left_sub_index < mid) {
                temp[counter] = items[left_sub_index];
                left_sub_index++;
                counter++;
            }

            while(right_sub_index < end) {
                temp[counter] = items[right_sub_index];
                right_sub_index++;
                counter++;
            }

            for(int i = left_index; i < end; i++) {
                items[i] = temp[i];
            }

        }
    }

    return 0;
}



#endif