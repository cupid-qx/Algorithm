//
// Created by qcq on 2017/1/18.
//
#include <stdio.h>

int main() {
    for (int i = 1; i < 2000; i++) {
        if (i % 2 == 1 && i % 3 == 0 && i % 4 == 1 && (i + 1) % 5 == 0 && i % 6 == 3 && i % 7 == 0 && i % 8 == 1 &&
            i % 9 == 0) {
            printf("%d-------", i);
        }
    }
    return 0;
}