#define MAX_VERTEX 10000

#include<stdio.h>
#include<stdlib.h>
int visi[10002];
int nodenum;
int edgenum;
int E1, E2;
int z = -1;
int dummy1;
int stack[100001];
int arr[10001];
int sortingarr[10001];
int a, b,c,d,e;
int ansnum;
int ansarr[2][10001];
int ansarrsort[2][10001];
int push(int i) {
	z++;
	stack[z] = i;
}

int hap(int first, int last) {
	if (first + 1== last) {
		if (arr[last] < arr[first]) {
			d = arr[first];
			arr[first] = arr[last];
			arr[last] = d;
		}
	}
	else if (first + 1 < last) {
		hap(first, (first + last) / 2);
		hap((first + last) / 2 + 1, last);
		a = first;
		b = (first + last) / 2 + 1;
		c = first;
		while (a <= (first + last) / 2 && b <= last) {
			if (arr[a] < arr[b]) {
				sortingarr[c] = arr[a];
				a++;
				c++;
			}
			else if (arr[b] < arr[a]) {
				sortingarr[c] = arr[b];
				b++;
				c++;
			}
		}

		if (b > last) {
			for (; a <= (first + last) / 2;) {
				sortingarr[c] = arr[a];
				a++;
				c++;
			}
		}
		else {
			for (; b<=last;) {
				sortingarr[c] = arr[b];
				b++;
				c++;
			}
		}

		for (int k = first; k < c; k++) {
			arr[k] = sortingarr[k];
		}
	}
}

int anshap(int first, int last) {
	if (first + 1 == last) {
		if (ansarr[1][last] < ansarr[1][first]) {
			d = ansarr[1][first];
			c = ansarr[0][first];
			ansarr[1][first] = ansarr[1][last];
			ansarr[0][first] = ansarr[0][last];
			ansarr[1][last] = d;
			ansarr[0][last] = c;
		}
	}
	else if (first + 1 < last) {
		anshap(first, (first + last) / 2);
		anshap((first + last) / 2 + 1, last);
		a = first;
		b = (first + last) / 2 + 1;
		c = first;
		while (a <= (first + last) / 2 && b <= last) {
			if (ansarr[1][a] < ansarr[1][b]) {
				ansarrsort[0][c] = ansarr[0][a];
				ansarrsort[1][c] = ansarr[1][a];
				a++;
				c++;
			}
			else if (ansarr[1][b] < ansarr[1][a]) {
				ansarrsort[1][c] = ansarr[1][b];
				ansarrsort[0][c] = ansarr[0][b];
				b++;
				c++;
			}
		}

		if (b > last) {
			for (; a <= (first + last) / 2;) {
				ansarrsort[0][c] = ansarr[0][a];
				ansarrsort[1][c] = ansarr[1][a];
				a++;
				c++;
			}
		}
		else {
			for (; b <= last;) {
				ansarrsort[1][c] = ansarr[1][b];
				ansarrsort[0][c] = ansarr[0][b];
				b++;
				c++;
			}
		}

		for (int k = first; k < c; k++) {
			ansarr[1][k] = ansarrsort[1][k];
			ansarr[0][k] = ansarrsort[0][k];
		}
	}
}

int pop() {
	if (z > -1) {
		dummy1 = stack[z];
		z--;
	}
}

typedef struct _Node {
	int vertex;

	struct _Node* next;
}Node;

typedef struct graphType {
	int n;
	Node* adjList_H[MAX_VERTEX];
}graphType;

void createGraph(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
	}
}

void insertVertex(graphType* g, int v) {
	if (((g->n) + 1 )> MAX_VERTEX) {
		return;
	}
	g->n++;
}
void printf_adjlist(graphType* g) {
	int i;
	Node* p;
	for (i = 0; ansarr[0][i] != NULL;i++) {
		p = g->adjList_H[ansarr[0][i]-1];
		while (p) {
			printf("%d ", p->vertex+1);
			p = p->next;
		}
		printf("-1\n");
	}
}

void inserEdge(graphType* g, int u, int v) {
	Node* node;
	if (u >= g->n || v >= g->n) {
		return;
	}
	node = (Node*)malloc(sizeof(Node));
	node->vertex = v;
	node->next = g->adjList_H[u];
	g->adjList_H[u] = node;
}

int Sdfs(int i,graphType*g) {
	if (visi[i] == 0) {
		visi[i] = 1;
		Node* p;
		p = g->adjList_H[i];
		while (p) {
			Sdfs(p->vertex, g);
			p = p->next;


		}
		push(i + 1);
	}
}

int Rdfs(int i, graphType* g) {
	if (visi[i] == 1) {
		visi[i] = 0;
		Node* p;
		p = g->adjList_H[i];
		while (p) {
			Rdfs(p->vertex, g);
			p = p->next;


		}
		arr[e] = i+1;
		e++;
	}
}

int main() {
	scanf("%d", &nodenum);
	graphType* G1,*G2,*G3;
	G1 = (graphType*)malloc(sizeof(graphType));
	G2 = (graphType*)malloc(sizeof(graphType));
	G3 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);
	createGraph(G2);
	createGraph(G3);
	scanf("%d",&edgenum);
	for (int j = 0; j < nodenum; j++) {
		insertVertex(G1, j);
		insertVertex(G2, j);
		insertVertex(G3, j);
	}
	for (int j = 0; j< edgenum; j++) {
		scanf("%d%d", &E1, &E2);
		inserEdge(G1, E1-1, E2-1);
		inserEdge(G2, E2 - 1, E1 - 1);
	}
	printf_adjlist(G1);
	for (int i = 0; i < nodenum; i++) {
		if (visi[i] == 0) {
			Sdfs(i, G1);
		}
	}
	for (; z >= 0;) {
		pop();
		if (visi[dummy1-1] == 1) {
			Rdfs(dummy1-1,G2);
			hap(0, e - 1);
			
			if (arr[0] !=0) {
				ansnum++;
				ansarr[0][ansnum - 1] = ansnum;
				ansarr[1][ansnum - 1] = arr[0];
			}
			
			for (int k = e-1; arr[k] != 0; k--) {
				inserEdge(G3, ansnum-1, arr[k]-1);
				arr[k] = 0;
			}
			e = 0;
		}
	}
	anshap(0, ansnum - 1);
	printf("%d\n", ansnum);
	printf_adjlist(G3);
	free(G1);
	free(G2);
	free(G3);
}