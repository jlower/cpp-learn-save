#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int a, int b)
{
	arr[a] = arr[a] ^ arr[b];
	arr[b] = arr[a] ^ arr[b];
	arr[a] = arr[a] ^ arr[b];
}

void adjustUp(vector<int> &v, int index)
{
	int parent = (index - 1) / 2;
	while (parent >= 0 && v[index] > v[parent])
	{
		swap(v, index, parent);
		index = parent;
		parent = (index - 1) / 2;
	}
}

void adjustDown(vector<int> &v, int index, int limit)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	while (left <= limit || right <= limit)
	{
		int ma = index;
		if (left <= limit && v[left] > v[ma])
			ma = left;
		if (right <= limit && v[right] > v[ma])
			ma = right;

		if (ma == index)
			break;
		swap(v, index, ma);
		index = ma;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}

void heap_sort(vector<int> &v)
{
	int i = (v.size() - 2) / 2;
	int n = v.size();
	while (i >= 0)
	{
		adjustDown(v, i, n - 1);
		--i;
	}
	for (i = n - 1; i > 0;)
	{
		swap(v, i, 0);

		adjustDown(v, 0, --i);
	}
}

int main(int argc, char *argv[])
{
	vector<int> v{-2, 5, -23, 4324, 3, 3, 3, 940, 1, 7, 8, 2, 3, 6, 5, 4, 4, 4, 4, 4, 4};
	for (const auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	heap_sort(v);
	for (const auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
