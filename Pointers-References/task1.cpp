#include <iostream>
#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void printArray(int array[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;  
}

void swap(int num1, int num2)
{
    num1 = num2;
    num2 = num1;
}

void sortNumbers(int* array, size_t size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
        
}

int main(int argc, char* argv[])
{
    int numbers[] = {17, -7, 221, 12, 0, 0, -4, 13};
    size_t arraySize = ARR_SIZE(numbers);
    sortNumbers(numbers, arraySize);
    printArray(numbers, arraySize);
    
    return 0;
}