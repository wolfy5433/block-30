#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <deque>
#include <algorithm>
#include <future>
#include <numeric>

class ArThread
{
public:
	ArThread(int size);
	~ArThread();

	void devideArrayAndPushPartsToTheArrayContainer(int value);
	void asyncWork();
	void sumResult(int value);

	int getResult() { return _result; };

private:
	std::deque<int> _array;

	std::vector<std::vector<int>> _arrayContainer;
	int _result = 0;
};