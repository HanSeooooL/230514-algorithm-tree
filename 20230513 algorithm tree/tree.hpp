//
//  tree.hpp
//  20230513 algorithm tree
//  201911695 한설
//  Created by 한설 on 2023/05/13.
//  tree ADT와 Testcase prototype

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {              //노드 구조체 타입
    int value;
    struct _node *left;
    struct _node *right;
} Node;

//Tree ADTs
Node *maketree();                                   //트리구조 생성
Node *findNode(int value);                          //value값을 가진 노드 찾기
Node *insertRightNode(Node *where, Node *new_node); //where노드의 왼쪽 방향으로 new_node 삽입
Node *insertLeftNode(Node *where, Node *new_node);  //where노드의 오른쪽 방향으로 new_node 삽입
void printNode(Node *root);                         //node 출력
Node *createNode(int value);                        //node 생성
void deleteNode(Node *n, Node *parent);             //n및 그 노드에 포함된 하위 노드 삭제

//TC prototye
void TC1_printNode();                               //노드를 3가지 방식으로 출력
void TC2_findNode();                                //findNode함수 테스트
void TC3_insertLeft();                              //왼쪽 삽입 함수 테스트
void TC4_insertRight();                             //오른쪽 삽입 함수 테스트

#endif /* tree_hpp */
