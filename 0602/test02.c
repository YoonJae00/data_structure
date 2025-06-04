//
// Created by 김윤재 on 2025. 6. 2..
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 초기화
void init(GraphType *g) {
    g->n = 0;
    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<MAX_VERTICES; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
}


// 정점 삽입
void insert_vertex(GraphType *g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr , "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 엣지 삽입
void insert_edge(GraphType *g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr , "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType *g) {
    int square = g->n;
    for (int i=0; i<square; i++) {
        for (int j=0; j<square; j ++) {
            printf("%d ",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    print_adj_mat(g);
    free(g);
}