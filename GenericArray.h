#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

template <typename T>
class GenericArray
{
private:
    T* data;
    int currentSize;

public:
    GenericArray()
    {
        data = nullptr;
        currentSize = 0;
    }

    ~GenericArray()
    {
        delete[] data;
    }

    void addElement(T value)
    {
        T* newData = new T[currentSize + 1];

        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = data[i];
        }

        newData[currentSize] = value;

        delete[] data;
        data = newData;
        currentSize++;
    }

    T at(int index) const
    {
        if (index < 0 || index >= currentSize)
        {
            std::cout << "Index out of bounds." << std::endl;
            return T();
        }

        return data[index];
    }

    int size() const
    {
        return currentSize;
    }

    T sum() const
    {
        T total = 0;

        for (int i = 0; i < currentSize; i++)
        {
            total += data[i];
        }

        return total;
    }

    T max() const
    {
        if (currentSize == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return T();
        }

        T largest = data[0];

        for (int i = 1; i < currentSize; i++)
        {
            if (data[i] > largest)
            {
                largest = data[i];
            }
        }

        return largest;
    }

    T min() const
    {
        if (currentSize == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return T();
        }

        T smallest = data[0];

        for (int i = 1; i < currentSize; i++)
        {
            if (data[i] < smallest)
            {
                smallest = data[i];
            }
        }

        return smallest;
    }

    T* slice(int begin, int end) const
    {
        if (begin < 0 || end >= currentSize || begin > end)
        {
            std::cout << "Invalid slice bounds." << std::endl;
            return nullptr;
        }

        int sliceSize = end - begin + 1;
        T* slicedArray = new T[sliceSize];

        for (int i = 0; i < sliceSize; i++)
        {
            slicedArray[i] = data[begin + i];
        }

        return slicedArray;
    }

    void printArray() const
    {
        for (int i = 0; i < currentSize; i++)
        {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }
};

#endif