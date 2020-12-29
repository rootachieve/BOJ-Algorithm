//[2188] 축사 배정
//BOJ : https://www.acmicpc.net/problem/2188
#define MAX 202
#include<stdio.h>
#include<stdlib.h>
int arrCowWhere[MAX];//n번째 소가 몇번째 축사로 들어가있는가
int arrInsideCow[MAX];//n번째 축사에 몇번째 소가 들어있는가
int arrCowWantList[MAX][MAX];//n번째 소가 m번째 축사에 만족하면 1 아니면 0
int arrVisit[MAX];//DFS용 방문체크
int gAnswer;
int N, M;//N : 소의 수 M : 축사의 수

int DFS(int xCow) {
	arrVisit[xCow] = 1;
	for (int i = 1; i <= M; i++) {
		if (arrCowWantList[xCow][i] == 1) {//xCow번째 소가 i번째 축사를 만족스러워한다면
			if (arrInsideCow[i] == 0 || (arrVisit[ arrInsideCow[i] ] == 0 && dfs( arrInsideCow[i] ))) {//축사가 비어있거나, 축사안에있는 소를 다른 축사로 이동할 수 있다면
				arrCowWhere[xCow] = i;//xCow번째 소는 i번 축사에 들어감
				arrInsideCow[i] = xCow;//i번 축사에는 xCow가 들어가있음
				return 1;//소가 성공적으로 축사로 들어갔기에 1
			}
		}
	}
	return 0;//소가 들어갈 수 있는 축사가 없다면 0
}
int main() {

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int cowWantNumber;//i번 소가 만족하는 축사의 갯수 
		scanf("%d", &cowWantNumber);
		for (int j = 1; j <= cowWantNumber; j++) {
			int cowWant;//i번 소가 만족하는 j번째 축사
			scanf("%d", &cowWant);
			arrCowWantList[i][cowWant] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (arrCowWhere[i] == 0) {//i번째 소가 아직 축사로 들어가지 않았다면
			for (int j = 1; j <= MAX; j++) {
				arrVisit[j] = 0;//초기화
			}
			int connect = DFS(i);
			if (connect == 1) {//소가 성공적으로 축사에 들어갔다면
				gAnswer++;//답에 1추가
			}
		}
	}
	printf("%d", gAnswer);//답 출력
}