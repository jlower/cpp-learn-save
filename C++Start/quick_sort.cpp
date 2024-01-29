#include <iostream>
#include <vector>

using namespace std;


void q_sort(vector<int> &v, int left, int right)
{
	if (left >= right)
		return;
	int key = v[left];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && v[end] > key)
		{
			--end;
		}
		if (begin < end)
		{
			v[begin] = v[end];
			++begin;
		}
		while (begin < end && v[begin] <= key)
		{
			++begin;
		}
		if (begin < end)
		{
			v[end] = v[begin];
			--end;
		}
	}
	v[begin] = key;
	q_sort(v, left, begin - 1);
	q_sort(v, begin + 1, right);
}

int main(int argc, char *argv[])
{
	vector<int> v{1, 7, 8, 2, 3, 6, 5, 4, 4, 4, 4, 4, 4};
	for (const auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	q_sort(v, 0, v.size() - 1);
	for (const auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
