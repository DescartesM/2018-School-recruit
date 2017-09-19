#include <iostream>
#include <vector>
using namespace std;
/*
input: 2 4 1 3 5;
output: 3;
input: 1 2 3 4 5;
output: 5;
可以去除数组中任意数字，实现不递减数组，使这个不递减数组最长。
*/
vector<int> ans;
void digui(int i, int xianzhi, int count, int J[], int n) {
	if (i == n)
	{
		ans.push_back(count);
		return;
	}
	if (J[i] >= xianzhi)
	{
		count++;
		digui(i + 1, J[i], count, J, n);
		count--;
		digui(i + 1, xianzhi, count, J, n);
	}
	else {
		digui(i + 1, xianzhi, count, J, n);
	}
}

int func(int N, int K, int J[]) {
	int t = J[0];
	digui(0, 0, 0, J, N);
	int max_ans = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans[i] > max_ans)
			max_ans = ans[i];
	}
	return max_ans;
}


int main() {
	int J[5] = {2,4,1,3,5};
	int ans;
	ans = func(5, 0, J);
	cout << ans;
	system("PAUSE");
	return 0;
}