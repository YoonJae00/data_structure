//
// Created by 김윤재 on 2025. 5. 19..
//

#include <stdio.h>


// 이진 노드 순회
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
//     15
//   4   20
//  1   16 25
TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;

// 중위 순회
void inorder( TreeNode *root ){
    if ( root ){
        inorder( root->left );
        printf("%d", root->data );
        inorder( root->right ); }
}
// 전위 순회
void preorder( TreeNode *root ){
    if ( root ){
        printf("%d", root->data );
        preorder( root->left );
        preorder( root->right ); }
}
// 후위 순회
void postorder( TreeNode *root ){
    if ( root ){
        postorder( root->left ); // 왼쪽 서브 트리 순회
        postorder( root->right ); // 오른쪽 서브 트리 순회
        printf("%d", root->data ); // 노드 방문
    }
}
int main(void) {
    printf("전위 순회=");
    preorder(root);
    printf("\n");

    return 0;
}
