#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;
node* insert(node* root, int data);
node* findMin(node* root);
node* delete(node* root, int data);
void postorderTraversal(node* root, int isFirst);
void inorderTraversal(node* root, int isFirst);
void preorderTraversal(node* root, int isFirst);
void levelOrderTraversal(node** root, int size, int level);
int main(){
    int ch, data;
    node* root = NULL;
    node* bst_root[1] = {root};
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
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                postorderTraversal(root, 1);
                printf("\n");
                break;
            case 4:
                inorderTraversal(root, 1);
                printf("\n");
                break;
            case 5:
                preorderTraversal(root, 1);
                printf("\n");
                break;
            case 6:
                levelOrderTraversal(bst_root, 1, 0);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
        bst_root[0] = root;
    }
}
node* insert(node* root, int data){
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Memory could not be allocated for new node!\n");
        return root;
    }
    K->left = NULL;
    K->right = NULL;
    K->val = data;
    if(root == NULL){
        return K;
    }
    node *ptr = root, *ptr1;
    while(ptr != NULL){
        ptr1 = ptr;
        if(data > ptr->val){
            ptr = ptr->right;
        }
        else if(data < ptr->val){
            ptr = ptr->left;
        }
        else{
            printf("Duplicates not allowed\n");
            free(K);
            return root;
        }
    }
    if(data > ptr1->val){
        ptr1->right = K;
        return root;
    }
    ptr1->left = K;
    return root;
}
node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
node* delete(node* root, int data){
    if(root == NULL){
        printf("No data to be deleted\n");
        return root;
    }
    if(data < root->val){
        root->left = delete(root->left, data);
    }
    else if(data > root->val){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            printf("Removed: %d\n", data);
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            node* temp = (root->left) ? root->left : root->right;
            printf("Removed: %d\n", data);
            free(root);
            return temp;
        }
        else{
            node* temp = findMin(root->right);
            root->val = temp->val;
            temp->val = data;
            root->right = delete(root->right, temp->val);
        }
    }
    return root;
}
void postorderTraversal(node* root, int isFirst){
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left, 0);
    postorderTraversal(root->right, 0);
    printf("%d ", root->val);
}
void inorderTraversal(node* root, int isFirst){
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left, 0);
    printf("%d ", root->val);
    inorderTraversal(root->right, 0);
}
void preorderTraversal(node* root, int isFirst){
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left, 0);
    preorderTraversal(root->right, 0);
}
void levelOrderTraversal(node** root, int size, int level){
    if(root[0] == NULL && size == 1){
        printf("--Empty--\n");
        return;
    }
    printf("Level %d: ", level++);
    size *= 2;
    node** queue = malloc(size * sizeof(node*));
    int index = 0, next_ptr = 0, null_val = 0;
    while(index < size / 2){
        if(root[index] == NULL){
            printf("%4c\t", 'X');
            queue[next_ptr++] = NULL;
            queue[next_ptr++] = NULL;
            null_val += 2;
        }
        else{
            printf("%4d\t", root[index]->val);
            queue[next_ptr++] = root[index]->left;
            if(queue[next_ptr - 1] == NULL){
                null_val++;
            }
            queue[next_ptr++] = root[index]->right;
            if(queue[next_ptr - 1] == NULL){
                null_val++;
            }
        }
        index++;
    }
    printf("\n");
    if(size != 2){
        free(root);
    }
    if(null_val == index * 2){
        free(queue);
        return;
    }
    return levelOrderTraversal(queue, size, level);
}