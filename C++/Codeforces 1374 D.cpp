#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long int res = 0;
		cin >> n >> k;
		int maxfreq = 0;
		map<int, int> map;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			if (t % k != 0)
			{
				++map[k - t % k];
				maxfreq = max(maxfreq, map[k - t % k]);
			}
		}
		for (auto a : map)
		{
			if (a.second == maxfreq)
			{
				res = k * 1ll * (maxfreq - 1) + a.first + 1;
			}
		}

		// vector<int> rem;
		// int res = 0;
		// unordered_set<int> set;
		// for (int i = 0; i < n; i++)
		// {
		// 	int temp = arr[i] % k;
		// 	if (temp != 0)
		// 	{
		// 		temp = k - arr[i] % k;
		// 		while (set.find(temp) != set.end())
		// 		{
		// 			temp += k;
		// 		}
		// 		res = max(temp, res);
		// 		set.insert(temp);
		// 	}
		// }
		if (res == 0)
			cout << 0 << "\n";
		else
			cout << res << "\n";
	}
	return 0;
}