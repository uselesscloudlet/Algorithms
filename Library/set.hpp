template <class T>
class Set
{
public:
	Set();
	Set(size_t size);
	~Set();
	void set_add(T element);
	void set_remove(T element);
	bool set_search(T element);
	size_t set_size();
	size_t set_iter(size_t index);

private:
	size_t capacity;
	size_t realSize;
	T* array;
};

template <class T>
Set<T>::Set()
{
	realSize = 0;
	capacity = 100;
	array = new T[100];
}

template <class T>
Set<T>::Set(size_t size)
{
	realSize = 0;
	capacity = size;
	array = new T[size];
}

template <class T>
Set<T>::~Set()
{
	delete[] array;
}

template <class T>
void Set<T>::set_add(T element)
{
	if (realSize < capacity)
	{
		if (!set_search(element))
		{
			array[realSize] = element;
			realSize++;
		}
		else
		{
			throw "This item is already in the set!";
		}
	}
	else
	{
		throw "Set overflow!";
	}
}

template <class T>
void Set<T>::set_remove(T element)
{
	if (realSize != 0)
	{
		for (size_t i = 0; i < realSize; i++)
		{
			if (array[i] == element)
			{
				for (size_t j = i; j < realSize; j++)
				{
					array[j] = array[j + 1];
				}
				realSize--;
			}
		}
	}
	else
	{
		throw "Set is empty!";
	}
}

template <class T>
bool Set<T>::set_search(T element)
{
	int left = 0;
	int right = realSize;
	bool flag = false;

	while ((left <= right) && flag != true)
	{
		int mid = (left + right + 1) / 2;
		if (array[mid] == element)
		{
			flag = true;
		}
		else if (array[mid] > element)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (flag)
	{
		return true;
	}	
	else
	{
		return false;
	}
}

template <class T>
size_t Set<T>::set_size()
{
	return realSize;
}

template <class T>
size_t Set<T>::set_iter(size_t index)
{
	return array[index];
}