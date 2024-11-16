#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;
node* insert(node* root, int data);
node* delete(node* root, int data);
node* findMin(node* root);
void postorderTraversal(node* root);
void inorderTraversal(node* root);
void preorderTraversal(node* root);
void levelOrderTraversal(node* root);
int main(){
    int ch, data;
    node* root=NULL;
    while(1){
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to display postorder traversal\n");
        printf("Enter 4 to display inorder traversal\n");
        printf("Enter 5 to display preorder traversal\n");
        printf("Enter 6 to display level order traversal\n");
        printf("Enter 7 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root=insert(root, data);
                break;
            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                root=delete(root, data);
                break;
            case 3:
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
}
node* insert(node* root, int data){
    node* K=(node*)malloc(sizeof(node));
    if(K == NULL){
        printf("Memory could not be allocated for new node!\n");
        return root;
    }
    K->left=NULL;
    K->right=NULL;
    K->val=data;
    if(root == NULL){
        return K;
    }
    node* ptr=root, *ptr1;
    while(ptr != NULL){
        ptr1=ptr;
        if(data > ptr->val){
            ptr=ptr->right;
        }
        else if(data < ptr->val){
            ptr=ptr->left;
        }
        else{
            printf("Duplicates not allowed\n");
            free(K);
            return root;
        }
    }
    if(data >ptr1->val){
        ptr1->right=K;
        return root;
    }
    ptr1->left=K;
    return root;
}
node* findMin(node* root){
    while(root->left != NULL){
        root=root->left;
    }
    return root;
}
node* delete(node* root, int data){
    if(root == NULL){
        printf("No data to be deleted\n");
        return root;
    }
    if(data < root->val){
        root->left=delete(root->left, data);
    }
    else if(data > root->val){
        root->right=delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            printf("Removed: %d\n", data);
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            node* temp=(root->left) ? root->left : root->right;
            printf("Removed: %d\n", data);
            free(root);
            return temp;
        }
        else{
            node* temp=findMin(root->right);
            root->val=temp->val;
            temp->val=data;
            root->right=delete(root->right, temp->val);
        }
    }
    return root;
}
void postorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}
void inorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}
void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void levelOrderTraversal(node* root){
    node** queue = (node**)malloc(100 * sizeof(node*));
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        node* tempNode = queue[front++];
        printf("%d ", tempNode->val);
        if (tempNode->left != NULL) {
            queue[rear++] = tempNode->left;
        }
        if (tempNode->right != NULL) {
            queue[rear++] = tempNode->right;
        }
    }
    free(queue);
}