#include <iostream>
#include <string.h>

using namespace std;

int main(void){
	int N, M, C1, C2;
	int data[501];
	int map[501][501];
	int s1[501], s2[501];
	int visited[501];
	int position = 0;

	memset(map, 0x7f, sizeof(data));
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	memset(visited, 0, sizeof(visited));

	cin>>N>>M>>C1>>C2;
	for(int i = 0; i < N; i ++)
	{
		cin>>data[i];
	}
	int a1, a2, d;
	for(int i = 0; i < M; i ++)
	{
		cin>>a1>>a2>>d;
		map[a1][a2] = d;
		map[a2][a1] = d;
	}
	position = C1;
	for(int i = 0; i < N; i ++)
	{
		s1[i] = map[position][i];	//点pistion到i的距离
		s2[i] = 0;
	}
	s1[position] = 0;
	s2[position] = data[position];

	for(int i = 0; i < N; i ++)
	{
		int min_key = 0x7fffffff;
		int min_value = 0x7fffffff;
		for(int j = 0; j < N; j ++)
		{
			if(visited[j] == 0 && s1[j] < min_value)
			{
				min_key = j;
				min_value = s1[j];
			}
		}
		if(min_value == 0x7fffffff)
			break;
		position = min_key;
		visited[position] = 1;		//标记已经被走过
		for(int j = 0; j < N; j ++)
		{
			if(s1[j] > s1[position] + map[position][j])
			{
				s1[j] = s1[position] + map[position][j];
				s2[j] = s2[position] + data[j];
				//parent[j] = position;
			}
			else if(s1[j] == s1[position] + map[position][j])
			{
				if(s2[j] < s2[position] + data[j])
				{
					s1[j] = s1[position] + map[position][j];
					s2[j] = s2[position] + data[j];
				}
			}
		}
	}
	printf("%d %d\n", s1[C2], s2[C2]);
	return 0;
}

