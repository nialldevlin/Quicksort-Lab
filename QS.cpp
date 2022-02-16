#include "QS.h"
#include <sstream>

QS::QS()
{
    //ctor
    max_size = 0;
}

QS::~QS()
{
    //dtor
}

void QS::sortAll() {
    int left = 0;
    int right = arr.size() - 1;
    qsort(left, right);
}

void QS::qsort(int left, int right) {
    if ( right - left < 1 ) {
        return;
    }
    int pivot = medianOfThree(left, right);
    pivot = partition(left, right, pivot);
    cout << "l " << left << "r " << right << "p " << pivot << endl;
    if (pivot == -1) {
        cout << "return -1" << endl;
        return;
    }
    qsort(left, pivot - 1);
    qsort(pivot + 1, right);
}

int QS::medianOfThree(int left, int right) {
    if (arr.empty() ||
        left < 0 ||
        right >= arr.size() ||
        left >= right) {
        return -1;
    }
    int pivotIndex = (left + right)/2;
    if (arr[left] > arr[pivotIndex]) {
        swap(left, pivotIndex);
    }
    if (arr[pivotIndex] > arr[right]) {
        swap(pivotIndex, right);
    }
    if (arr[left] > arr[pivotIndex]) {
        swap(left, pivotIndex);
    }
    return pivotIndex;
}

int QS::partition(int left, int right, int pivotIndex) {
    if (arr.empty() ||
        left < 0 ||
        right >= arr.size() ||
        left >= right ||
        pivotIndex < left ||
        pivotIndex > right) {
        return -1;
    }
    int pivot = arr[pivotIndex];
    swap(left, pivotIndex);
    int up = left + 1;
    int down = right - 1;
    do {
        while (arr[up] <= pivot && up < right) {
            up++;
        }
        while (arr[down] > pivot && down > left) {
            down--;
        }
        if (up < down) {
            swap(up, down);
        }
    } while (up < down);
    swap(left, down);
    return down;
}

string QS::getArray()const {
    stringstream ss;
    string delim = "";
    for (auto i : arr) {
        ss << delim << i;
        delim = ",";
    }
    return ss.str();
}

int QS::getSize() const {
    return arr.size();
}

bool QS::addToArray(int value) {
    if (arr.size() < max_size) {
        arr.push_back(value);
        return true;
    }
    return false;
}

bool QS::createArray(int capacity) {
    if (capacity < 0) {
        return false;
    }
    max_size = capacity;
    arr.clear();
    arr.reserve(max_size);
    return true;
}

void QS::clear() {
    arr.clear();
}

void QS::swap(int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
