#include <stdio.h>
#include <stdlib.h>

// structure of a node in the tree
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
    int data;                    // data to insert
    int ch;                      // to indicate user's choice with given options
    node* root = NULL;           // memory location of root node of the tree
    node* bst_root[1] = {root};  // array (queue) for level order traversal of tree

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
        
        bst_root[0] = root;  // update array element whenever root pointer changes
    }
}

// insert data into BST
node* insert(node* root, int data){
    
    // allocate memory for new node
    node* K = malloc(sizeof(node));

    // if malloc failed to allocate memory for new node
    if(K == NULL){
        printf("Memory could not be allocated for new node!\n");
        return root;
    }

    // new node will be leaf node
    K->left = NULL;
    K->right = NULL;
    K->val = data;

    // if no nodes in BST
    if(root == NULL){
        return K;  // return node as the root of BST
    }

    // dummy pointers
    node* ptr = root;  // traverse nodes in BST
    node* ptr1;        // leaf node in BST
    
    // traverse until leaf node found
    while(ptr != NULL){

        // update ptr1 for potential leaf node
        ptr1 = ptr;

        // if data to be allocated already exists in BST then free node
        if(ptr->val == data){
            printf("Duplicates not allowed\n");
            free(K);
            return root;
        }

        // update ptr to left or right subtree according to data value against current node
        // go to left subtree if data less than value of current node, else right subtree
        ptr = (data < ptr->val) ? ptr->left : ptr->right;
    }

    // if data greater than the value of node then allocate new node as right child
    if(data > ptr1->val){
        ptr1->right = K;
        return root;
    }

    // else allocate as left child
    ptr1->left = K;
    return root;
}

// find the minimum value node in given tree/subtree
node* findMin(node* root){

    // traverse the left subtree until leaf node found
    while(root->left != NULL){
        root = root->left;
    }

    // return the node with least value in tree/subtree
    return root;
}

// delete a node from BST
node* delete(node* root, int data){

    // if BST is empty
    if(root == NULL){
        printf("No data to be deleted\n");
        return root;
    }

    // if data to be deleted (node value) less than current node value then perform delete in left subtree
    if(data < root->val){
        root->left = delete(root->left, data);
    }

    // if data to be deleted (node value) greater than current node value then perform delete in right subtree
    else if(data > root->val){
        root->right = delete(root->right, data);
    }

    // if node to be deleted found
    else{

        // if the node is leaf node
        if(root->left == NULL && root->right == NULL){
            printf("Removed: %d\n", data);
            free(root);
            return NULL;  // return null to parent of this leaf node
        }

        // if the node has one child node
        else if(root->left == NULL || root->right == NULL){
            node* temp = (root->left) ? root->left : root->right;  // pointer to child node
            
            printf("Removed: %d\n", data);
            free(root);
            return temp;  // return node's child node to node's parent node
        }

        // if the node has two child nodes
        else{

            // next minimum value node after current node's value to preserve BST order
            node* temp = findMin(root->right);

            // swap values between these two nodes
            root->val = temp->val;
            temp->val = data;

            // delete the temp node (contains data to be removed) from right subtree
            root->right = delete(root->right, temp->val);
        }
    }

    // return new root
    return root;
}

// display postorder node values
void postorderTraversal(node* root, int isFirst){

    // if the function called first time and BST empty
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }

    // if root of subtree is empty
    if(root == NULL){
        return;
    }

    postorderTraversal(root->left, 0);   // postorder values of left child
    postorderTraversal(root->right, 0);  // postorder values of right child
    printf("%d ", root->val);            // root node value
}

// display inorder node values
void inorderTraversal(node* root, int isFirst){

    // if the function called first time and BST empty
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }

    // if root of subtree is empty
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left, 0);   // inorder values of left child
    printf("%d ", root->val);          // root node value
    inorderTraversal(root->right, 0);  // inorder values of right child
}

// display preorder node values
void preorderTraversal(node* root, int isFirst){

    // if the function called first time and BST empty
    if(root == NULL && isFirst){
        printf("--Empty--");
        return;
    }

    // if root of subtree is empty
    if(root == NULL){
        return;
    }

    printf("%d ", root->val);           // root node value
    preorderTraversal(root->left, 0);   // preorder values of left child
    preorderTraversal(root->right, 0);  // preorder values of right child
}

// display level order node values
void levelOrderTraversal(node** root, int size, int level){

    // if size is 1 (first call) and root[0] is null then BST empty
    if(root[0] == NULL && size == 1){
        printf("--Empty--\n");
        return;
    }
    
    printf("Level %d: ", level++);
    
    // size of the queue holding child nodes for level order traversal (BFS)
    size *= 2;
    node** queue = malloc(size * sizeof(node*));  // queue for holding child node locations
    
    // if memory for queue not allocated
    if(queue == NULL){
        
        // if size is not 2 (not first call) then free root
        if(size != 2){
            free(root);
        }

        printf("Memory could not be allocated for next level display!\n");
        printf("Terminating level order display of BST\n");
        return;
    }

    int index = 0;     // index of root array
    int next_ptr = 0;  // index of queue array
    int null_val = 0;  // count of null value child nodes in queue array
    
    // traverse root array
    while(index < size / 2){

        // if the node value is null then display 'X'
        if(root[index] == NULL){
            printf("%4c\t", 'X');

            // null child have no child nodes
            queue[next_ptr++] = NULL;
            queue[next_ptr++] = NULL;

            // increment count of null value in queue
            null_val += 2;
        }

        // if the child node is not null then display it
        else{
            printf("%4d\t", root[index]->val);

            // add left child to queue
            queue[next_ptr++] = root[index]->left;

            // if left child doesn't exist then increment count of null values in queue
            if(queue[next_ptr - 1] == NULL){
                null_val++;
            }

            // add right child to queue
            queue[next_ptr++] = root[index]->right;

            // if right child doesn't exist then increment count of null values in queue
            if(queue[next_ptr - 1] == NULL){
                null_val++;
            }
        }

        // increment index to point to next element in root array
        index++;
    }

    printf("\n");

    // if size is not 2 (not first call) then free root
    if(size != 2){
        free(root);
    }

    // if all child nodes in queue are null then stop displaying
    if(null_val == index * 2){
        free(queue);
        return;
    }

    // level order display of next level in BST
    return levelOrderTraversal(queue, size, level);
}