#include <iostream>
#include <ctime>
using namespace std;

int getNumber(int size)
{
    int random = rand() % size + 1;
    return random;
}
int *random(int size)
{
    int *temp = new int[size];
    int num = 0;
    while (num < size)
    {
        int number = getNumber(size);
        bool isInArray = false;
        for (int i = 0; i < num; i++)
        {
            if (temp[i] == number)
            {
                isInArray = true;
                break;
            }
        }
        if (!isInArray)
        {
            temp[num++] = number;
        }
    }
    return temp;
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int size = 10;
    int *array = random(size); // get array of random numbers
    cout << "Unordered array: ";
    printArray(array, size);

    // %%%%%%%%%%%%%%%%%%%%%%%%
    // %% ( selection sort ) %%
    // %%%%%%%%%%%%%%%%%%%%%%%%
    // store the index with lowest value in temp then swap the first with temp, the do this with second and so on.
    for (int i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[temp])
            {
                temp = j;
            }
        }
        swap(array[i], array[temp]);
    }
    cout << "Selection Sorted Array: ";
    printArray(array, size);

    // array = random(size); // get array of random numbers
    array = random(size); // get array of random numbers
    cout << "\nUnordered array: ";
    printArray(array, size);

    // %%%%%%%%%%%%%%%%%%%%%
    // %% ( bubble sort ) %%
    // %%%%%%%%%%%%%%%%%%%%%
    // keep swapping first element untill it is at its correct position. If swapping does not occur, it means array is already swapped. So stop the program
    for (int i = 0; i < size; i++)
    {
        bool swapped;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    cout << "Bubble Sorted Array: ";
    printArray(array, size);

    array = random(size); // get array of random numbers
    cout << "\nUnordered array: ";
    printArray(array, size);

    // %%%%%%%%%%%%%%%%%%%%%%%%%
    // %% ( insertion sort ) %%
    // %%%%%%%%%%%%%%%%%%%%%%%%
    // move from left to right, take second element as key and check if key is at the right place with respect to previous elements. If it is, move to next one and take it to it correct position in previously sorted array.
    for (int i = 1; i < size; i++)
    {
        int key = i;
        while (key > 0 && array[key] < array[key - 1])
        {
            swap(array[key], array[key - 1]);
            key--;
        }
    }
    cout << "Insertion Sorted Array: ";
    printArray(array, size);

    return 0;
}
