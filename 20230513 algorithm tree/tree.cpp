//
//  tree.cpp
//  20230513 algorithm tree
//  201911695 한설
//  Created by 한설 on 2023/05/13.
//  트리ADT를 함수로 구현

#include "tree.hpp"

static Node *linkNode(Node* n, Node* l, Node* r);          //노드 연결
static Node *preorder(Node *root, int menu, int same);     //전위순회
static Node *inorder(Node *root, int menu, int same);      //중위순회
static Node *postorder(Node *root, int menu, int same);    //후위순회

Node *root;

Node *createNode(int value) //노드 생성
{
    Node *res;
    res = (Node*)malloc(sizeof(Node));  //메모리 할당
    res -> value = value;
    
    return res;
}

void deleteNode(Node *n, Node *parent)      //노드(서브트리)삭제 연산
{
    if (n == NULL)  //n이 노드를 가리키지 않을 경우
        return;
    if (n == parent)    //n과 parent가 같을 경우 (트리를 완전히 삭제하는 경우)
    {
        deleteNode(n -> left, n);
        deleteNode(n -> right, n);
        free(n);
    }
    else if (parent -> left != n && parent -> right != n)   //부모로 보낸 노드가 n을 가리키지 않을 경우
    {
        printf("잘못된 입력입니다. ");
    }
    else {
        if(parent -> left == n)     //left가 n을 가리킬 경우
            parent -> left = NULL;  //부모와 n 사이 연결 끊기
        else                        //right가 n을 가리킬 경우
            parent -> right = NULL; //부모와 n 사이 연결 끊기
        deleteNode(n -> left, n);
        deleteNode(n -> right, n);
        free(n);
    }
}

Node *linkNode(Node* n, Node* l, Node* r)    //노드 연결
{
    n -> left = l;
    n -> right = r;
    return n;
}

Node *maketree()    //트리 구조 생성
{
    Node *a, *b, *c, *d, *e;
    
    //노드 생성
    a = createNode(100);
    b = createNode(200);
    c = createNode(300);
    d = createNode(400);
    e = createNode(500);
    
    //노드 연결
    a = linkNode(a, b, c);
    b = linkNode(b, NULL, NULL);
    c = linkNode(c, d, e);
    d = linkNode(d, NULL, NULL);
    e = linkNode(e, NULL, NULL);
    root = a;
    
    return root;
}

Node* action(int menu, Node *node, int same)    //menu에 따라 수행을 달리하는 함수.
{
    if (menu == 1) //value 출력
    {
        printf("%d ", node -> value);
        return NULL;
    }
    
    if (menu == 2) //same과 같은 값 찾기
    {
        
        if(same == node -> value)
        {
            return node;
        }
    }
    return NULL;
}

void printNode(Node *root)
{
    printf("preorder \n");
    preorder(root, 1, 0);   //전위방식 출력
    printf("\ninorder \n");
    inorder(root, 1, 0);    //중위방식 출력
    printf("\npostorder \n");
    postorder(root, 1, 0);  //후위방식 출력
}

Node* preorder(Node *root, int menu, int same)  //전위방식
{
    if (root != NULL) {
        Node *p = NULL;
        p = action(menu, root, same);           //입력받은 메뉴에 따른 수행
        
        if (p != NULL)
            return p;
        else {
            p = preorder(root -> left, menu, same);
            if ( p != NULL)
                return p;
            else {
                p = preorder(root -> right, menu, same);
                if (p != NULL)
                    return p;
            }
        }
    }
    return NULL;
}

Node* inorder(Node *root, int menu, int same)   //중위방식
{
    if (root != NULL) {
        Node *p = NULL;
        p = preorder(root -> left, menu, same);
        
        if (p != NULL)
            return p;
        else {
            p = action(menu, root, same);       //입력받은 메뉴에 따른 수행
            if (p != NULL)
                return p;
            else {
                p = preorder(root -> right, menu, same);
                if (p != NULL)
                    return p;
            }
        }
    }
    return NULL;
}

Node* postorder(Node *root, int menu, int same) //후위방식
{
    if (root != NULL) {
        Node *p = NULL;
        p = preorder(root -> left, menu, same);
        if (p != NULL)
            return p;
        else {
            p = preorder(root -> right, menu, same);
            if (p != NULL)
                return p;
            else {
                p = action(menu, root, same);   //입력받은 메뉴에 따른 수행
                if (p != NULL)
                    return p;
            }
        }
    }
    return NULL;
}

Node *findNode(int value)   //value값과 같은 노드 포인터 반환
{
    Node *res = NULL;
    res = postorder(root, 2, value);    //후위방식 탐색
    
    return res;
}


Node *insertRightNode(Node *where, Node *new_node)  //특정 노드와 그 노드가 가리키는 right포인터에 있는 노드 사이에 삽입
{
    if (where == NULL)
        return NULL;
    new_node -> right = where -> right; //new_node의 오른쪽에 where노드의 오른쪽 삽입
    where -> right = new_node;          //where노드의 오른쪽에 new_node 삽입
    return where;
}

Node *insertLeftNode(Node *where, Node *new_node)   //특정 노드와 그 노드가 가리키는  left포인터에 있는 노드 사이에 삽입
{
    if (where == NULL)
        return NULL;
    new_node -> left = where -> left;   //new_node의 왼쪽에 where노드의 왼쪽 삽입
    where -> left = new_node;           //where노드의 왼쪽에 new_node 삽입
    return where;
}
