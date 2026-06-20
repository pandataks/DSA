#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int queue[10000];
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->queue[++obj->rear] = t;

    while (obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front + 1;
}

int main() {

    RecentCounter* rc = recentCounterCreate();

    printf("%d\n", recentCounterPing(rc, 1));
    printf("%d\n", recentCounterPing(rc, 100));
    printf("%d\n", recentCounterPing(rc, 3001));
    printf("%d\n", recentCounterPing(rc, 3002));

    free(rc);

    return 0;
}