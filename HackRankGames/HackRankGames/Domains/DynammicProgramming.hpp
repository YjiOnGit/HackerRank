// HackRankGames.cpp : 定义控制台应用程序的入口点。
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

namespace DynammicProgramming
{
	namespace Abbrevisation
	{
		bool FindTinS(string s, string t, int startIndexS, int startIndexT)
		{
			if (startIndexT == t.size())
			{
				if (startIndexS == s.size() - 1)
				{
					return true;
				}
				else
				{
					for (int i = startIndexS; i < (int)s.size(); ++i)
					{
						if (s[i] >= 'A' && s[i] <= 'Z')
							return false;
					}
					return true;
				}
			}
			if (startIndexT < (int)t.size() && startIndexS >= (int)s.size())
			{
				return false;
			}

			if (s.size() <= 0 || t.size() <= 0)
			{
				return false;
			}

			for (int i = startIndexS; i < (int)s.size(); ++i)
			{
				if (t[startIndexT] == s[i] || t[startIndexT] == s[i] + ('A' - 'a'))
				{
					if (FindTinS(s, t, i + 1, startIndexT + 1))
					{
						return true;
					}
				}
				else if (s[i] >= 'A' && s[i] <= 'Z')
				{
					return false;
				}

			}
			return false;
		}

		void Solution()
		{
			char a[1000];
			char b[1000];
			int q;
			cin >> q;

			vector <string> results;
			results.reserve(q);

			for (int indexTest = 0; indexTest < q; ++indexTest)
			{
				cin >> a;
				cin >> b;
				string s(a);
				string t(b);
				if (FindTinS(s, t, 0, 0))
					results.push_back("YES");
				else
					results.push_back("NO");

			}
			for (int indexTest = 0; indexTest < q; ++indexTest)
			{
				cout << results[indexTest].c_str() << '\n';
			}
		}
	}

}
