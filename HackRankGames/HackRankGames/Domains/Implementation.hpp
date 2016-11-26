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

namespace Implementation
{
	namespace MatrixLayerRotation
	{
		void PrintMatrix(vector<vector<int>>& inputMatrix)
		{
			for (int i = 0; i < (int)inputMatrix.size(); ++i)
			{
				for (int j = 0; j < (int)inputMatrix[i].size(); ++j)
				{
					cout << inputMatrix[i][j] << ' ';
				}
				cout << endl;
			}
		}
		vector<vector<int>> DecomposeMatrix(vector<vector<int>>& inputMatrix)
		{
			int numRows = inputMatrix.size();
			int numColumns = inputMatrix[0].size();
			int numResultVectors = min(numRows, numColumns)/2;
			vector<vector<int>> result(numResultVectors);
			for (int i = 0; i < numResultVectors; ++i)
			{
				// Top row
				for (int j = i; j < numColumns - i; j++)
				{
					result[i].push_back(inputMatrix[i][j]);
				}

				// Right most column (the corner two are not included)
				for (int j = i + 1; j < numRows - 1 - i; j++)
				{
					result[i].push_back(inputMatrix[j][numColumns - 1 - i]);
				}
				
				// Bottom Row
				for (int j = numColumns - 1 - i; j >= i; j--)
				{
					result[i].push_back(inputMatrix[numRows -1 - i][j]);
				}

				// Left most row (the corner two are not included)
				for (int j = numRows - 2 - i; j >= i + 1; j--)
				{
					result[i].push_back(inputMatrix[j][i]);
				}
			}
			
			return result;
		}

		vector<vector<int>> ComposeMatrix(vector<vector<int>>& inputMatrix,
			const int numRows, const int numColumns)
		{
			vector<vector<int>> result; 
			for (int i = 0; i < numRows; ++i)
			{
				vector<int> temp(numColumns);
				result.push_back(temp);
			}
			int numResultVectors = min(numRows, numColumns) / 2;

			for (int i = 0; i < numResultVectors; ++i)
			{
				int indexCounter = 0;
				// Top row
				for (int j = i; j < numColumns - i; j++)
				{
					result[i][j] = inputMatrix[i][indexCounter];
					indexCounter++;
				}

				// Right most column (the corner two are not included)
				for (int j = i + 1; j < numRows - 1 - i; j++)
				{
					result[j][numColumns - 1 - i] = inputMatrix[i][indexCounter];
					indexCounter++;
				}

				// Bottom Row
				for (int j = numColumns - 1 - i; j >= i; j--)
				{
					result[numRows - 1 - i][j] = inputMatrix[i][indexCounter];
					indexCounter++;
				}

				// Left most row (the corner two are not included)
				for (int j = numRows - 2 - i; j >= i + 1; j--)
				{
					result[j][i] = inputMatrix[i][indexCounter];
					indexCounter++;
				}
			}

			return result;
		}

		vector<vector<int>> rotateVector(vector<vector<int>>& inputVectorList, const int numRotation)
		{
			vector<vector<int>> result = inputVectorList;
			for (int i = 0; i < (int) inputVectorList.size(); ++i)
			{
				int vectorLength = (int)inputVectorList[i].size();
				for (int j = 0; j < vectorLength; ++j)
				{
					result[i][j] = inputVectorList[i][(j + numRotation) % vectorLength];
				}
			}
			return result;
		}

		vector<vector<int>> RotateMatrix(vector<vector<int>>& inputMatrix, int numRotation)
		{
			int numRows = inputMatrix.size();
			int numColumns = inputMatrix[0].size();

			vector<vector<int>> CircularVectors = DecomposeMatrix(inputMatrix);
			vector<vector<int>> afterRotation = rotateVector(CircularVectors, numRotation);
			vector<vector<int>> result = ComposeMatrix(afterRotation, numRows, numColumns);
			return result;
		}

		void Solution()
		{
			//int numRow, numColumn, numRotation;
			//cin >> numRow >> numColumn >> numRotation;
			//vector< vector<int> > inputMatrix;
			//for (int i = 0; i < numRow; ++i)
			//{
			//	vector<int> thisRow;
			//	for (int i = 0; i < numColumn; ++i)
			//	{
			//		int temp;
			//		cin >> temp;
			//		thisRow.push_back(temp);
			//	}
			//	inputMatrix.push_back(thisRow);
			//}
			vector< vector<int> > inputMatrix;
			inputMatrix.push_back(vector<int>{1, 2, 3, 4});
			inputMatrix.push_back(vector<int>{5, 6, 7, 8});
			inputMatrix.push_back(vector<int>{9, 10, 11, 12});
			inputMatrix.push_back(vector<int>{13, 14, 15, 16});
			inputMatrix.push_back(vector<int>{17, 18, 19, 20});

			int numRotation = 0;
			//RotateMatrix(inputMatrix, numRotation);
			PrintMatrix(RotateMatrix(inputMatrix, numRotation));
		}
	}

	namespace LarrysArray
	{
		bool CanBeSortedWithRotation(vector<int>& inputNumbers)
		{

		}
		
		void Solution()
		{
			int T;
			cin >> T;
			vector<bool> result(T);
			for (int i = 0; i < T; ++i)
			{
				int length;
				cin >> length;
				vector <int> inputNumbers;
				for (int j = 0; j < length; j++)
				{
					int temp;
					cin >> temp;
					inputNumbers.push_back(temp);
				}
				result[i] = CanBeSortedWithRotation(inputNumbers);
			}
			for (int i = 0; i < T; ++i)
			{
				if (result[i])
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}
	}
}
