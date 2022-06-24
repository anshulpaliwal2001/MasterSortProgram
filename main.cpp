#include <iostream>

using namespace std;

class Sorting {
public:
    int *Array, size;

    Sorting(int *array, int size) : Array(array), size(size) {}

    void showArray(int flag = 0);

    virtual void sort() = 0;

    void swapElements(int i, int j) {
        int k = Array[i];
        Array[i] = Array[j];
        Array[j] = k;
    }

};

void Sorting::showArray(int flag) {
    if (flag == 0)
        cout << endl << "============================" << endl;
    else if (flag == 1)
        cout << endl << "====== [  B E F O R ] ======" << endl;


    else if (flag == 2)
        cout << endl << "====== [  A F T E R ] ======" << endl;

    if (flag != 3) {
        cout << "Size of Array : " << size << endl;
        cout << "Array         : ";
    }

    for (int i = 0; i < size; ++i) {
        if (i == 0)
            cout << "[  ";
        cout << Array[i] << "  ]";
        if (i != size - 1)
            cout << "[  ";
    }
    if (flag != 3)
        cout << endl << "============================" << endl;
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

class SelectionSort : public Sorting
{
public:
    SelectionSort(int *array, int size) : Sorting(array, size) {}

    void sort()
    {
        int counter = 1;
        for (int i = 0; i < size; ++i) {
            int minIndex = i;
            for (int j = i+1; j < size-1; ++j) {
                if(Array[minIndex] > Array[j+1])
                    minIndex = j+1;
            }
            swapElements(i,minIndex);

            cout << endl << "    Pass " << counter << "    : ";
            showArray(3);

            counter++;
        }

    }

};

int main() {

    int arr[] = {55, 48, 71, 2, 45, 78, 23, 15};
    int size = sizeof(arr) / sizeof(int);
    SelectionSort b1(arr, size);
    b1.showArray(1);
    b1.sort();
    b1.showArray(2);
    return 0;
}
