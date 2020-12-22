//[6086] 최대유량
#define MAX_VERTEX 53
#include<stdio.h>
#include<stdlib.h>
int queue[100000];//큐
int visi[53];//방문
int c[53][53];//용량
int f[53][53];//현재 흐르는 유량
int dummy;
int z = -1;
int count;
int front;
int total;//최대 유량
int U, V;
int now;//현재 탐색중인 정점의 번호
int inqueue(int i) {
	z++;
	queue[z + front] = i;
}
int dequeue() {
	if (z > -1) {
		dummy = queue[front];
		z--;
		front++;
	}
}
struct Node {
	int vertex;
	struct Node* next;
};
struct graph {
	int n;
	struct Node* nuber[MAX_VERTEX];
};
void graphmake(struct graph* g) {
	g->n = 0;
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->nuber[v] = NULL;
	}
}
void addnode(struct graph* g, int u, int v) {
	struct Node* node;
	if (u >= g->n && v >= g->n) {
		return;
	}
	node = (struct Node*)malloc(sizeof(struct Node));
	node->vertex = v;
	node->next = g->nuber[u];
	g->nuber[u] = node;

}
void addvertex(struct graph* g) {
	if (g->n + 1 < MAX_VERTEX) {
		g->n++;
	}
}


int main() {
	struct graph* G1;
	G1 = (struct graph*)malloc(sizeof(struct graph));//그래프생성
	graphmake(G1);//그래프 초기화
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));//현재 탐색중인 정점을 나타낼 포인터
	for (int i = 1; i <= 52; i++) {
		addvertex(G1);//정점 추가
	}

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char u[3], v[3];
		int w;
		scanf("%s%s%d", &u, &v, &w);//정점 A와 정점 B는 W의 용량으로 연결되어있다.
		if (u[0] <= 90) {
			U = (int)u[0] - 38;//문자열 형태로 입력받아서 숫자로 변환함 소문자는 1부터~26 대문자는 27~52
		}
		else {
			U = (int)u[0] - 96;
		}

		if (v[0] <= 90) {
			V = (int)v[0] - 38;
		}
		else {
			V = (int)v[0] - 96;
		}
		c[U][V] = c[U][V] + w;//양방향 파이프
		c[V][U] = c[V][U] + w;
		addnode(G1, U, V);//간선추가
		addnode(G1, V, U);

	}


	while (1) {
		int pre[53];//경로를 기억할 배열
		for (int i = 0; i <= 52; i++) {//초기화
			pre[i] = -1;
			visi[i] = 0;
		}
		z = -1;
		front = 0;
		inqueue(27);//A가 시작이기에 A를 큐에 넣어줌
		visi[27] = 1;

		while (z != -1 && pre[52] == -1) {//큐가 비거나 Z에 도착하는 경로가 있다면 종료
			now = queue[front];
			dequeue();//윗줄과 함께 pop과 같은기능
			p = G1->nuber[now];//p가 now번 정점과 연결된 정점을 탐색함
			for (; p != NULL; p = p->next) {//더이상 연결된 정점이 없을때까지 탐색
				if ((c[now][p->vertex]) - (f[now][p->vertex]) > 0 && pre[p->vertex] == -1 && visi[p->vertex] == 0) {//1.용량보다 유량이 커선안됌 2,3.다른 경로에서 방문한 정점이면 안됌
					inqueue(p->vertex);//BFS탐색을 위해 큐에 넣어줌
					pre[p->vertex] = now;//p->vertex번 정점은 now를 통해서 왔다 => 경로기억
					visi[p->vertex] = 1;//BFS를 위한 방문체크
					if (p->vertex == 52) {//52번(Z)가 마지막이므로 도착했다면 경로 하나를 찾은 것이기에 종료(while문 종료조건과 같음)
						break;
					}
				}

			}



		}
		if (pre[52] == -1)break;//큐가 비었음에도 Z로 가는 경로가 없다면 완전히 탐색이 끝난것이기에 종료

		int flow = 2000000000;

		for (int j = 52; j != 27; j = pre[j]) {//위에서 기억한 경로로 가장많이 흐를 수 있는 유량을 찾아서 flow에 저장
			if (flow > (c[pre[j]][j] - f[pre[j]][j])) {
				flow = (c[pre[j]][j] - f[pre[j]][j]);
			}

		}
		for (int i = 52; i != 27; i = pre[i]) {
			f[pre[i]][i] = f[pre[i]][i] + flow;//flow만큼 유량이 추가로 흐름
			f[i][pre[i]] = f[i][pre[i]] - flow;//반대방향으로는 -flow만큼의 유량이 추가로 흐름
		}
		total = total + flow;//flow만큼이 A-Z로 흐르기에 최대유량증가

	}
	printf("%d", total);
	free(G1);
	free(p);
}