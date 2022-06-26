#include <iostream>

using namespace std;

class Sorting;


class Sorting {
public:
    int *Array, size;

    Sorting(int *array, int size) : Array(array), size(size) {}

    void showArray(int flag = 0, int low = 0, int high = -1);

    virtual void sort() = 0;

    void swapElements(int i, int j) {
        int k = Array[i];
        Array[i] = Array[j];
        Array[j] = k;
    }

    int getArraySize(int Arr[]) {
        return (sizeof(&Arr)) / (sizeof(int));
    }

};

void Sorting::showArray(int flag, int low, int high) {

    if (high == -1)
        high = size;

    if (flag == 0)
        cout << endl << "========================================================" << endl;
    else if (flag == 1)
        cout << endl << "==================== [  B E F O R ] ====================" << endl;


    else if (flag == 2)
        cout << endl << "==================== [  A F T E R ] ====================" << endl;

    if (flag != 3) {
        cout << "Size of Array : " << size << endl;
        cout << "Array         : ";
    }

    for (int i = low; i < high; ++i) {
        if (i == low)
            cout << "[  ";
        cout << Array[i] << "  ]";
        if (i != high - 1)
            cout << "[  ";
    }
    if (flag != 3)
        cout << endl << "========================================================" << endl;
}


class BubbleSort : public Sorting {
public:
    BubbleSort(int *array, int size) : Sorting(array, size) {}

    void sort() {
        int counter = 1;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; ++j) {
                {
                    if (Array[j] > Array[j + 1])
                        swapElements(j, j + 1);
                    cout << endl << "    Pass " << counter << "    : ";
                    showArray(3);
                    cout << endl;
                    counter++;
                }
            }
        }
    }
};

class InsertionSort : public Sorting {
public:
    InsertionSort(int *array, int size) : Sorting(array, size) {}

    void sort() {
        int counter = 1;
        for (int i = 1; i < size; ++i) {
            int current = Array[i];

            int j = i - 1;

            while (j >= 0 && Array[j] > current) {
                Array[j + 1] = Array[j];
                j--;
            }
            Array[j + 1] = current;
            cout << endl << "    Pass " << counter << "    : ";
            showArray(3);
            cout << endl;
            counter++;
        }
    }

};

class SelectionSort : public Sorting {
public:
    SelectionSort(int *array, int size) : Sorting(array, size) {}

    void sort() {
        int counter = 1;
        for (int i = 0; i < size; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size - 1; ++j) {
                if (Array[minIndex] > Array[j + 1])
                    minIndex = j + 1;
            }
            swapElements(i, minIndex);

            cout << endl << "    Pass " << counter << "    : ";
            showArray(3);

            counter++;
        }

    }

};

class MergeSort : public Sorting {
public:
    MergeSort(int *array, int size) : Sorting(array, size) {}

    void sort() {
        sort(Array, 0, size - 1);
    }

    void Merge(int *a, int low, int high, int mid) {
        int i, j, k, temp[high - low + 1];
        i = low;
        k = 0;
        j = mid + 1;

        while (i <= mid && j <= high) {
            if (a[i] < a[j]) {
                temp[k] = a[i];
                k++;
                i++;
            } else {
                temp[k] = a[j];
                k++;
                j++;
            }
        }

        while (i <= mid) {
            temp[k] = a[i];
            k++;
            i++;
        }

        while (j <= high) {
            temp[k] = a[j];
            k++;
            j++;
        }


        for (i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }


    }

    void sort(int *a, int low, int high) {
        int mid;
        if (low < high) {
            mid = (low + high) / 2;

            sort(a, low, mid);
            sort(a, mid + 1, high);


            Merge(a, low, high, mid);


        }
    }

};

int main() {

    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    MergeSort b1(arr, size);
    b1.showArray(1);
    b1.sort();
    b1.showArray(2);
    return 0;
}
