#include <iostream>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize = 0;
	int currentCapacity;

	void resize()
	{
		int newCapacity = currentCapacity * 2;
		T* newData = new T[newCapacity];

		for (int i = 0; i < currentSize; i++)
		{
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		currentCapacity = newCapacity;
	}

public:
	SimpleVector()
	{
		currentCapacity = 10;
		data = new T[currentCapacity];
	}

	SimpleVector(int capacity)
	{
		currentCapacity = capacity;
		data = new T[currentCapacity];
	}

	~SimpleVector()
	{
		delete[] data;
		data = nullptr;
	}

	void push_back(const T& value)
	{
		if (currentSize == currentCapacity)
		{
			resize();
		}
		data[currentSize] = value;
		currentSize++;
	}

	int size() const
	{
		return currentSize;
	}

	int capacity() const
	{
		return currentCapacity;
	}
};