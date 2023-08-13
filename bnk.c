#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define P 4
#define R 3

int sum(int x, int arr[P][R]) {
    int sum = 0;
    for (int i = 0; i < R; i++) {
        sum += arr[x][i];
    }
    return sum;
}

int max[P][R] = { { 7, 5, 3 },
                { 3, 2, 2 },
                { 9, 0, 2 },
                { 2, 2, 2 } };


int alloc[P][R] = { { 0, 1, 0 },
                    { 2, 0, 0 },
                    { 3, 0, 2 },
                    { 2, 1, 1 } };


int resources[R] = { 10, 5, 7 };

int available[R];

bool uprocess[P];

bool allflagged() {
    for (int i = 0; i < P; i++) {
        if (uprocess[i]) {
            return false;
        }
    }
    return true;
}

bool isSafe(int pid) {
    for (int i = 0; i < R; i++) {
        if (alloc[pid][i] > available[i]) {
            return false;
        }
    }
    return true;
}

void executeProcess(int pid) {
    for (int i = 0; i < R; i++) {
        available[i] += alloc[pid][i];
        alloc[pid][i] = 0;
        max[pid][i] = 0;
    }
    uprocess[pid] = false;
}

void bankers() {
    for (int i = 0; i < P; i++) {
        uprocess[i] = true;
    }

    for (int i = 0; i < R; i++) {
        available[i] = resources[i] - sum(i, alloc);
    }

    int safeSequence[P];
    int count = 0;

    while (!allflagged()) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (uprocess[i] && isSafe(i)) {
                executeProcess(i);
                safeSequence[count++] = i;
                found = true;
                break;
            }
        }
        if (!found) {
            printf("No safe sequence exists.\n");
            return;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}

int main() {
    bankers();
    return 0;
}
