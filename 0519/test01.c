//
// Created by 김윤재 on 2025. 5. 19..
//

typedef struct TreeNode{
    int data;
    struct TreeNode *left,*right;
} TreeNode;

#include <stdio.h>
#include <stdlib.h>

// int main(void) {
//
//     TreeNode *n1,*n2,*n3;
//
//     n1 = malloc(sizeof(TreeNode));
//     n2 = malloc(sizeof(TreeNode));
//     n3 = malloc(sizeof(TreeNode));
//
//     n1->data = 10; n1->left = n2;
//     n1->right = n3;
//     n2->data = 20; n2->left = NULL;
//     n2->right = NULL;
//     n3->data = 30; n3->left = NULL;
//     n3->right = NULL;
//     free(n1); free(n2); free(n3);
//
//     return 0;
// }
//
