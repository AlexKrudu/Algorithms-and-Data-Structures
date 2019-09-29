#include <iostream>
#include <cstdio>



void merge(int array[], int first, int last) {
    int it1 = 0, it2 = 0;
    int result[last - first + 1];
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

void mergeSort(int* array, int first, int last) {
    if (first < last - 1) {
        mergeSort(array, first, (first + last) / 2);
        mergeSort(array, (first + last) / 2, last);
        merge(array, first, last);
    }
}

int main() {
    int n;
    freopen("sort.in","r", stdin);
    freopen("sort.out", "w", stdout);
    std::cin >> n;
    int arr[n];
    for (int i = 0; i< n; i++){
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    fclose(stdout);
    return 0;
}