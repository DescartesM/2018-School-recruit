#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addstr(string x, string y) {
	return x + y;
}

int main(int argc, char const *argv[])
{
	long n;
	std::vector<string> a;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		string x;
		cin >> x;
		a.push_back(x);
	}
	long ans = 0;
	for (long i = 0; i < n; ++i)
	{
		for (long j = 0; j < n; ++j)
		{
			string temp;
			if (i != j)
			{
				temp = addstr(a[i], a[j]);
				long strlen = temp.size();

				long x = (temp[0]-'0') % 7;

				for (int i = 1; i < strlen; ++i)
				{
					x = (x * 10 + (temp[i] - '0')) % 7;
				}

				if (x == 0)
				{
					ans++;
				}
			}
		}
	}
	printf("%ld\n", ans);
	return 0;
}