#include <iostream>
#include <vector>

using namespace std;
vector<int> arr = {8, 1, 12, 5, 11, 75, 54, 12, 98, 111, 86};

vector<int> insertSort(vector<int> array, int length) {
    int i, key = 0;
    for (int j = 1; j < length; j++) {
        key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
    return array;
}

void merge(vector<int> array, int first, int last) {
    int it1 = 0, it2 = 0;
    vector<int> result(last - first + 1);
    int mid = (first + last) / 2;
    while (first + it1 < mid && mid + it2 < last) {
        if (array[first + it1] < array[mid + it2]) {
            result[it1 + it2] = array[first + it1];
            it1++;
        }
        else{
            result[it1 + it2] = array[mid + it2];
            it2++;
        }
    }
    while (first + it1 < mid){
        result[it1 + it2] = array[first + it1];
        it1++;
    }
    while (mid + it2 < last){
        result[it1 + it2] = array[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++){
        array[first + i] = result[i];
    }
}

void mergeSort(vector<int> array, int first, int last) {
    if (first < last) {
        mergeSort(array, first, (first + last) / 2);
        mergeSort(array, (first + last) / 2 + 1, last);
        merge(array, first, last);
    }
}

int main() {
    mergeSort(arr, 0, 11);
    for (int i = 0; i < 11; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

