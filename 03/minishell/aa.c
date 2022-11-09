#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int number = 15;

typedef struct node *nodePointer;
typedef struct node{
    int data;
    nodePointer left, right;
} node;

// 전위
void preorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

// 중위
void inorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        inorder(pointer->left);
        inorder(pointer->right);
    }
}

// 후위
void postorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        postorder(pointer->left);
        postorder(pointer->right);
    }
}

int main(void){
    node nodes[number+1];
    // 초기화
    for(int i=1; i<= number; i++){
        nodes[i].data = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    
    for(int i=2; i<=number; i++){
        if(i%2==0){
            nodes[i/2].left = &nodes[i];
        }else{
            nodes[i/2].right = &nodes[i];
        }
    }
    
    preorder(&nodes[1]);
    inorder(&nodes[1]);
    postorder(&nodes[1]);
    
    return 0;
}
