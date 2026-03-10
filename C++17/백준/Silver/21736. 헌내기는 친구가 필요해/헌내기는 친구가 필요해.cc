#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<char>> campus;
int N, M;

void calculate(int startY, int startX) 
{
	int ans = 0;

	queue<pair<int, int>> que;

	que.push(make_pair(startY, startX));
	campus[startY].at(startX) = 'X';

	while (!que.empty())
	{
		int currentY = que.front().first;
		int currentX = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];

			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M)
			{
				char nextValue = campus[nextY].at(nextX);
				
				switch (nextValue)
				{
				case 'O':
					que.push(make_pair(nextY, nextX));
					campus[nextY].at(nextX) = 'X';
					break;
				case 'P':
					que.push(make_pair(nextY, nextX));
					campus[nextY].at(nextX) = 'X';
					ans += 1;
					break;
				default:
					break;
				}
			}
		}
	}

	if (ans == 0)
		cout << "TT\n";
	else
		cout << ans << '\n';
}

int main()
{
	int startX, startY;
	cin >> N >> M;

	campus = vector<vector<char>>(N, vector<char>(M, 'O'));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			campus[i].at(j) = temp;

			if (temp == 'I')
			{
				startX = j;
				startY = i;
			}
		}
	}

	calculate(startY, startX);

	return 0;
}