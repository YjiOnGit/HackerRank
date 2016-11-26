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

namespace GraphTheory
{
	namespace BreadthFirstSearchShortestReach
	{
		pair<vector<int>,int> SolutionToEachCase()
		{
			int numVertices, numEdges, s;
			cin >> numVertices >> numEdges;
			vector<pair<int, int>> edges;
			for (int i = 0; i < numEdges; ++i)
			{
				int n1, n2;
				cin >> n1 >> n2;
				edges.push_back(make_pair(n1-1, n2-1));
			}
			cin >> s;
			s = s - 1; // move indices of vertices starting from 0
			vector<int> colorList(numVertices);
			queue <int> frontierList;
			vector<int> result(numVertices);

			frontierList.push(s);
			colorList[s] = 1;
			int distanceCounter = 0;
			while (frontierList.size()>0)
			{
				int u = frontierList.front();
				frontierList.pop();
				for (int i = 0; i < (int) edges.size(); ++i)
				{
					int v = -1;
					int v1 = edges[i].first;
					int v2 = edges[i].second;
					if (v1 == u)
					{
						v = v2;
					}
					if (v2 == u)
					{
						v = v1;
					}
					if (v >= 0 && colorList[v] == 0)
					{
						colorList[v] = 1;
						frontierList.push(v);
						result[v] = result[u] + 1;
					}
				}
				colorList[u] = 2;
			}
			return make_pair(result, s);
		}
		void PrintResult(pair< vector<int>, int > result)
		{
			vector<int> distanceList = result.first;
			int s = result.second;
			for (int i = 0; i < (int) distanceList.size(); ++i)
			{
				if (i != s)
				{
					int toPrint;
					toPrint = distanceList[i] > 0 ? distanceList[i]*6 : -1;
					cout << toPrint << ' ';
				}
			}
			cout << endl;
		}
		void Solution()
		{
			int NumCases;
			cin >> NumCases;
			vector< pair< vector<int>,int > > allResult;
			for (int i = 0; i < NumCases; ++i)
			{
				allResult.push_back(SolutionToEachCase());
			}
			for (int i = 0; i < NumCases; ++i)
			{
				PrintResult(allResult[i]);
			}
		}
	}
}
