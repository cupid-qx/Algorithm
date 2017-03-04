//
// Created by qcq on 2017/3/2.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <conio.h>

void showQueen(int iArrQueen[], int iLen, int iSolution) {
    int i, j;

    printf("..................Queen Position:%d.....................\n", iSolution);
    for (i = 0; i < iLen; ++i) {
        if (iArrQueen[i] == -1) {
            // 打印皇后的后面位置
            for (j = 0; j < iLen; ++j) {
                printf(" %d ", 0);
            }
            printf("\n");
            continue;
        }

        // 打印皇后前面部分
        for (j = 0; j < iArrQueen[i]; ++j) {
            printf(" %d ", 0);
        }
        // 打印皇后的位置
        printf(" %d ", 1);
        // 打印皇后的后面位置
        for (j = 0; j < iLen - iArrQueen[i] - 1; ++j) {
            printf(" %d ", 0);
        }
        printf("\n");
    }

    printf(".....................................................\n");

}

bool isClash(int iArrQueen[]) {
    int i, j;
    for (i = 1; i <= 8; ++i) {
        for (j = 0; j <= i - 1; ++j) {
            if (iArrQueen[i] == iArrQueen[j])
                return true;
            if (abs(iArrQueen[i] - iArrQueen[j]) == abs(i - j))
                return true;
        }
    }

    return false;
}


/**
 * 枚举法，将所有方案全部拿出来，在验证
 * @param iArrQueen
 * @param iLen
 */
void enumQueenPosition(int iArrQueen[], int &iSolutions) {
    for (iArrQueen[0] = 0; iArrQueen[0] < 8; iArrQueen[0]++) {
        for (iArrQueen[1] = 0; iArrQueen[1] < 8; ++iArrQueen[1]) {
            for (iArrQueen[2] = 0; iArrQueen[2] < 8; ++iArrQueen[2]) {
                for (iArrQueen[3] = 0; iArrQueen[3] < 8; ++iArrQueen[3]) {
                    for (iArrQueen[4] = 0; iArrQueen[4] < 8; ++iArrQueen[4]) {
                        for (iArrQueen[5] = 0; iArrQueen[5] < 8; ++iArrQueen[5]) {
                            for (iArrQueen[6] = 0; iArrQueen[6] < 8; ++iArrQueen[6]) {
                                for (iArrQueen[7] = 0; iArrQueen[7] < 8; ++iArrQueen[7]) {

                                    if (isClash(iArrQueen))
                                        continue;
                                    else {
                                        iSolutions++;
                                        showQueen(iArrQueen, 8, iSolutions);
                                        _getch();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {

    // 每一个成员代表一个皇后的位置
    int arrQueen[8];
    memset(arrQueen, -1, sizeof(int) * 8);
//    arrQueen[1] = 2;
//    arrQueen[3] = 3;

    int iSolutins = 0;
    enumQueenPosition(arrQueen, iSolutins);
    // showQueen(arrQueen, 8,iSolutins);

    return 0;
}