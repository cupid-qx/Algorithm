//
// Created by qcq on 2017/3/2.
//

#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <cstdlib>

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

// 判断是否冲突
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

// 回溯法判断是否冲突
bool isClash2(int iArrQueen[], int nRow) {
    for (int i = 0; i < nRow; ++i) {
        if (iArrQueen[i] == iArrQueen[nRow])
            return true;
        if (abs(iArrQueen[i] - iArrQueen[nRow]) == abs(i - nRow))
            return true;
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


/**
 * 回溯法，将皇后放在一行中的某个位置，然后进行判断
 * @param iArrQueen
 * @param iRow
 * @param iSolutions
 */
void putQueenPosition(int iArrQueen[], int iRow,int iLength, int &iSolutions) {
    for (int i = 0; i < iLength; ++i) {
        iArrQueen[iRow] = i;
        if (!isClash2(iArrQueen,iRow))
        {
            // 皇后已经到达了最后的位置
            if(iRow == iLength-1)
            {
                iSolutions++ ;
                showQueen(iArrQueen,iLength,iSolutions);
            }else
            {
                putQueenPosition(iArrQueen,iRow+1,iLength,iSolutions);
            }
        }
    }

}

int main() {

    // 每一个成员代表一个皇后的位置
    int iLength = 11;
    int arrQueen[iLength];
    memset(arrQueen, -1, sizeof(int) * iLength);
//    arrQueen[1] = 2;
//    arrQueen[3] = 3;

    int iSolutinos = 0;
//    enumQueenPosition(arrQueen, iSolutins);
//    showQueen(arrQueen, 8,iSolutins);
    putQueenPosition(arrQueen,0,iLength,iSolutinos);

    return 0;
}