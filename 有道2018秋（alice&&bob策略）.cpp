#include <iostream>
#include <vector>
using namespace std;
/*
规则每次从1开始翻转后面的0和1，最后使整个序列全部为0，需要多少次？
input: 
3 
0 1 1
output: 1;
input:
6
101010
output:
6
*/
int main() {
	int n;
	cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin >> x;
		v.push_back(x);
	}
	int start = 0;
	int count = 1;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] == 1)
		{
			start = i;
			break;
		}
	}
	for (int i = start; i < n - 1; ++i)
	{
		if (v[i + 1] != v[i])
		{
			count++;
		}
	}
	printf("%d\n", count);
	system("PAUSE");
	return 0;
}