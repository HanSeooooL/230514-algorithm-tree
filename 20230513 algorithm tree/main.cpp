//
//  main.cpp
//  20230513 algorithm tree
//  201911695 한설
//  Created by 한설 on 2023/05/13.
//  트리 생성, 테스트케이스 수행 및 실행시간 체크
#include "tree.hpp"
#include <time.h>

extern Node *root;
static void checktime(void (*func)(void));

int main(int argc, const char * argv[]) {
    maketree();
    printf("트리 생성 완료.");
    checktime(TC1_printNode);       //TC1 테스트
    checktime(TC2_findNode);        //TC2 테스트
    checktime(TC3_insertLeft);      //TC3 테스트
    checktime(TC4_insertRight);     //TC4 테스트
    deleteNode(root, root);         //트리 삭제
}

void checktime(void (*func)(void))  //실행시간 체크 함수
{
    clock_t start, finish;
    double duration;
    start = clock();
    (*func)();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\n=================== %lf 초입니다. ===================\n", duration);
}
