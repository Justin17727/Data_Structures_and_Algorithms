#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
    int height;
}node;

int get_max(int a, int b);
int height(node* root);
int balanceFactor(node* root);
node* rightRotate(node* root);
node* leftRotate(node* root);
node* balance(node* root);
node* insert(node* root, int data);
node* findMin(node* root);
node* delete(node* root, int data);
void postorderTraversal(node* root, int isFirst);
void inorderTraversal(node* root, int isFirst);
void preorderTraversal(node* root, int isFirst);
void levelOrderTraversal(node** root, int size, int level);

int main(){
    int data, ch;
    node* root = NULL;
    node* bst_root[1] = {root};  // for level order traversal of tree

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

int get_max(int a, int b){
    return a > b ? a : b;
}

int height(node* root){
    return root ? root->height : 0;
}

int balanceFactor(node* root){
    return height(root->left) - height(root->right);
}


node* rightRotate(node* root){
    node* child = root->left;
    root->left = child->right;
    child->right = root;

    root->height = 1 + get_max(height(root->left), height(root->right));
    child->height = 1 + get_max(height(child->left), height(child->right));

    return child;
}

node* leftRotate(node* root){
    node* child = root->right;
    root->right = child->left;
    child->left = root;

    root->height = 1 + get_max(height(root->left), height(root->right));
    child->height = 1 + get_max(height(child->left), height(child->right));

    return child;
}

node* balance(node* root){

    int balance = balanceFactor(root);
    if(abs(balance) > 1){
        if(balance > 0){
            if(balanceFactor(root->left) >= 0){
                return rightRotate(root);
            }
            else{
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else{
            if(balanceFactor(root->right) <= 0){
                return leftRotate(root);
            }
            else{
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
    }
    else{
        return root;
    }
}

node* insert(node* root, int data){

    if(root == NULL){

        node* K = malloc(sizeof(node));

        if(K == NULL){
            printf("Memory could not be allocated for new node!\n");
            return root;
        }

        K->left = NULL;
        K->right = NULL;
        K->height = 1;
        K->val = data;

        return K;
    }

    if(root->val == data){
        printf("Duplicates not allowed\n");
        return root;
    }

    if(data < root->val){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    root->height = 1 + get_max(height(root->left), height(root->right));

    return balance(root);
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
            return temp;  // return deleted node's child node
        }

        else{

            // next minimum value node to preserve BST order
            node* temp = findMin(root->right);

            root->val = temp->val;
            temp->val = data;

            root->right = delete(root->right, temp->val);
        }
    }

    root->height = 1 + get_max(height(root->left), height(root->right));

    return balance(root);
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
    
    if(queue == NULL){
        
        // if not first call then free root
        if(size != 2){
            free(root);
        }

        printf("Memory could not be allocated for next level display!\n");
        printf("Terminating level order display of BST\n");
        return;
    }

    int index = 0;     // index of root array
    int next_ptr = 0;  // index of queue array
    int null_val = 0;  // count of null child nodes in queue array
    
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

    // if not first call then free root
    if(size != 2){
        free(root);
    }

    if(null_val == index * 2){
        free(queue);
        return;
    }

    return levelOrderTraversal(queue, size, level);
}