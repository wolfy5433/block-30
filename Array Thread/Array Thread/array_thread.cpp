#include "array_thread.h"

ArThread::ArThread(int size)
{
	for (int i = 0; i < size; ++i)
	{
		_array.push_back((i * 13) + 71);
	}

	std::cout << "Array's values: ";
	for (auto& val : _array)
	{
		std::cout << val << ' ';
	}
	std::cout << std::endl;
}

ArThread::~ArThread()
{
	_array.clear();
	_arrayContainer.clear();
}

void ArThread::devideArrayAndPushPartsToTheArrayContainer(int value)
{
	int mer;
	if (value > _array.size())
	{
		std::cout << "Value is bigger than array's size" << std::endl;
		return;
	}
	else if (_array.size() % value != 0)
	{
		mer = _array.size() / value + 1;
	}
	else
	{
		mer = _array.size() / value;
	}

	std::vector<int> buf;
	while (!_array.empty())
	{
		for (int i = 0; i < mer; ++i)
		{
			if (_array.empty())
			{
				break;
			}
			buf.push_back(_array.front());
			_array.pop_front();
		}
		_arrayContainer.push_back(buf);
		buf.clear();
	}
	int number = 1;
	for (auto& vec : _arrayContainer)
	{
		std::cout << "Array " << number << ": ";
		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
		++number;
	}
}

void ArThread::asyncWork()
{
	for (std::vector<int>& v : _arrayContainer)
	{
		std::future<int> f = std::async([&v] {return std::accumulate(std::begin(v), std::end(v), 0); });
		sumResult(f.get());
	}
}

void ArThread::sumResult(int value)
{
	std::cout << "Sum of array: " << value << std::endl;
	_result += value;
}