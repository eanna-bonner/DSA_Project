#include <iostream>
#include <vector>

using namespace std;

int findMedian(int arr[]) {
    int max_val = arr[0], min_val = arr[0], median;

    for (int i = 1; i < 3; i++) { // find max and min values
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    for (int i = 0; i < 3; i++) { // find median value
        if (arr[i] != max_val && arr[i] != min_val) {
            median = arr[i];
        }
    }

    return median;
}

int med3(vector<int> vec) {
    // get first mid and last values for med3
    int first = vec[0];
    int last = vec[vec.size()-1];
    int mid = vec[(vec.size()/2)-1];
    // put values in an array
    int firstMidLast[3] = {first, mid, last};
    int median = findMedian(firstMidLast); // find the median of the array
    int index;
    // determine the index of the median number i.e 0, 1 or 2
    for (int i = 0; i<3; i++) {
        if (firstMidLast[i] == median) {
            index = i;
        }
    }
    // return the index of the median in the full vector based on the index gotten from the 3 length array
    if (index == 0) {
        return 0;
    }
    else if (index == 1) {
        return (vec.size()/2)-1;
    }

    else if (index == 2) {
        return (vec.size()-1);
    }
    
    return 0;
}

int partition4(vector<int>& vec, int pivotIdx) {
    int pivot = vec[pivotIdx]; // set pivot value
    swap(vec[pivotIdx],vec[vec.size()-1]); // put pivot at the end
    int pivotPos = vec.size()-1; // keep track of pivot index
    for (int i = 0, j = pivotPos-1; j>i;) {
        // if i<pivot swap with j, then swap the pivot back one space to put i to the right
        if (vec[i] > pivot) {
            swap(vec[i], vec[j]);
            swap(vec[pivotPos-1],vec[pivotPos]);
            pivotPos--; // decrement the pivot index after the swap
            j--; //decrement j so it is just before the pivot index
        }
        else {
            i++; // if i!>j dont swap. Increment i and repeat
        }
    }
    // once i and j cross, check if the last value before the pivot is larger, if it is swao them
    if (vec[pivotPos-1]>vec[pivotPos]) {
        swap(vec[pivotPos-1],vec[pivotPos]);
        pivotPos--;
    }
    return pivotPos; // return final pivot index
}

int main() {
    // Create a vector to store the integers
    vector<int> dataVec;

    // Read the integers from the standard input stream and store them in the vector
    int num;
    while (cin >> num) {
        dataVec.push_back(num);
    }

    int pivotIndex = med3(dataVec);
    cout << "Pivot: " << dataVec[pivotIndex] << endl;
    
    int finalPivotIndex = partition4(dataVec,pivotIndex);
    cout << "Final Pivot Index: " << finalPivotIndex << endl;

    return 0;
}