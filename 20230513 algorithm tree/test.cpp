//
//  test.cpp
//  20230513 algorithm tree
//  201911695 한설
//  Created by 한설 on 2023/05/13.
//  테스트케이스들

#include "tree.hpp"

extern Node *root;

void TC1_printNode()    //트리 출력 테스트
{
    printf("\n==========TC1_printNode==========\n");
    printNode(root);
}

void TC2_findNode()     //노드 탐색 테스트
{
    printf("\n==========TC2_findNode==========\n");
    Node *res;
    res = findNode(200);
    printf("result -> value: %d", res -> value);
}

void TC3_insertLeft()   //노드 왼쪽 삽입 테스트
{
    printf("\n==========TC3_insertleft==========\n");
    Node *newno, *n;
    newno = createNode(700);
    n = insertLeftNode(findNode(300), newno);
    printNode(n);
}

void TC4_insertRight()  //노드 오른쪽 삽입 테스트
{
    printf("\n==========TC4_insertRight==========\n");
    Node *newno, *n;
    newno = createNode(1000);
    n = insertRightNode(findNode(700), newno);
    printNode(n);
}
