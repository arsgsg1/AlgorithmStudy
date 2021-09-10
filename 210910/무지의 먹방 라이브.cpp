#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector <int> a, vector <int> b)
{
	return a[1]<b[1];
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int n = food_times.size();
	vector<vector <int>> food;


	for (int i = 0; i<food_times.size(); i++)
	{
		vector <int> temp;
		temp.push_back(food_times[i]);
		temp.push_back(i);
		food.push_back(temp);
	}

	sort(food.begin(), food.end());


	for (int i = food.size() - 1; i>0; i--)
	{
		food[i][0] -= food[i - 1][0];
	}


	int sw = 0;
	for (int i = 0; i<food.size(); i++)
	{

		if (food[i][0] * n <= k)
		{
			k -= (long)food[i][0] * n;
			n--;
		}
		else
		{
			sort(food.begin() + i, food.end(), cmp);
			answer = food[i + k%n][1] + 1;
			sw = 1;

			break;
		}

	}

	if (sw == 0) answer = -1;


	return answer;
}