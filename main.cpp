#include <iostream>
#include "GenericArray.h"

int main()
{
    GenericArray<int> int_array;

    int_array.addElement(0);
    int_array.addElement(2);
    int_array.addElement(4);
    int_array.addElement(6);
    int_array.addElement(8);
    int_array.addElement(10);
    int_array.addElement(12);
    int_array.addElement(14);
    int_array.addElement(16);
    int_array.addElement(18);
    int_array.addElement(20);

    std::cout << "Array contents: ";
    int_array.printArray();

    std::cout << "Element at index 3 is " << int_array.at(3) << std::endl;
    std::cout << "Size of array is " << int_array.size() << std::endl;
    std::cout << "Sum of the array is " << int_array.sum() << std::endl;
    std::cout << "Maximum and minimum of array is "
              << int_array.min() << " and " << int_array.max() << std::endl;

    int begin = 5;
    int end = 10;
    int sliceSize = end - begin + 1;

    int* sliced_array = int_array.slice(begin, end);

    if (sliced_array != nullptr)
    {
        std::cout << "Sliced array from index " << begin << " to " << end << ": ";

        for (int i = 0; i < sliceSize; i++)
        {
            std::cout << sliced_array[i] << " ";
        }

        std::cout << std::endl;

        delete[] sliced_array;
    }

    return 0;
}