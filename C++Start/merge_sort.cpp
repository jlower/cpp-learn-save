#include <iostream>
#include <vector>

using namespace std;


void merge_sort(vector<int> &v, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	merge_sort(v, left, mid);
	merge_sort(v, mid + 1, right);
	vector<int> cp(v);
	int begin = left, low1 = left, low2 = mid + 1;
	while (low1 <= mid && low2 <= right)
	{
		if (cp[low1] > cp[low2])
			v[begin++] = cp[low2++];
		else
			v[begin++] = cp[low1++];
	}
	while (low1 <= mid)
	{
		v[begin++] = cp[low1++];
	}
	while (low2 <= right)
	{
		v[begin++] = cp[low2++];
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
	merge_sort(v, 0, v.size() - 1);
	for (const auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
