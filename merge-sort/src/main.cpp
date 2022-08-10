#include <iostream>

#define N 10

using namespace std;

void print(int array[]) {
    for (int i=0; i<N; i++) {
        cout << "array[" << i << "]=" << array[i] << endl;
    }
}

void merge(int array[], int buffer[], int start, int end) {
    int middle = (end-start)/2 + start;
    int firstIndex = start;
    int secondIndex = middle;
    int index = start;
    while (firstIndex < middle && secondIndex < end) {
        if (array[firstIndex] < array[secondIndex]) {
            buffer[index] = array[firstIndex];
            firstIndex++;
        } else {
            buffer[index] = array[secondIndex];
            secondIndex++;
        }
        index++;
    }
    while(firstIndex < middle) {
        buffer[index] = array[firstIndex];
        index++;
        firstIndex++;
    }
    while(secondIndex < end) {
        buffer[index] = array[secondIndex];
        index++;
        secondIndex++;
    }
    for (index=start; index<end; index++) {
        array[index] = buffer[index];
    }
}

void mergeSort(int array[], int buffer[], int start, int end) {
    if (start+1 >= end) {
        // Already sortted
        return;
    }
    int middle = (end-start)/2 + start;
    mergeSort(array, buffer, start, middle);
    mergeSort(array, buffer, middle, end);
    merge(array, buffer, start, end);
}

void mergeSort(int array[]) {
    int buffer[N];
    mergeSort(array, buffer, 0, N);
}

int main(int argc, char const *argv[])
{
    cout<< "Merge Sort" << endl;
    int array[N] = {5, 2, 1, 6, 8, 1, 0, 8, 9, 0};
    cout << "Before sorting:" << endl;
    print(array);
    mergeSort(array);
    cout << "After sorting:" << endl;
    print(array);
    return 0;
}
