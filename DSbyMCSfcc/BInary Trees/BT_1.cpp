#include <iostream>
#include <queue>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
} *rootptr = NULL; // this points to the root node and is not the root node itself

node *getsetNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *rootptr, int data)
{
    if (rootptr == NULL) // breaking condition for recursion
        rootptr = getsetNode(data);
    // these ifs below help to locate the position for new node in the tree and the new node can only be inserted if the left or right of another node points to NULL
    else if (data <= rootptr->data)
        rootptr->left = insert(rootptr->left, data);
    else
        rootptr->right = insert(rootptr->right, data);
    return rootptr;
}
/**
 * for deleting a node which has 2 child subtree we find the min of right subtree and replace it with the node to be deleted and remove the duplicate in right tree
 * max of left is also allowed
 */

bool search(node *rootptr, int target)
{
    if (rootptr == NULL)
        return false;
    else if (rootptr->data == target)
        return true;
    else if (target <= rootptr->data)
        return search(rootptr->left, target);
    else
        return search(rootptr->right, target);
}

/**
 * to find the ht of the tree: O(n) where n is the number of nodes
 * pseudo code
 * findht(root){
 *      if root is null return -1 // if we find a leaf node its ht will be 0 which is -1 + 1
 *      leftht=findht(root->left)
 *      rightht=findht(root->right)
 *      return (max of leftht and rightht)+1
 * }
 */

int findht(node *rootptr)
{
    if (rootptr == NULL)
        return -1;
    int leftht = findht(rootptr->left);
    int rightht = findht(rootptr->right);
    return leftht > rightht ? leftht + 1 : rightht + 1;
}

/**
 * bfs uses queue. s soon as we find a node we add its address to the queue
 * then u access it and pop the last node from queue and enqueue its child nodes
 * traversal is completed when the queue is empty
 * time complexity: O(n)
 * space complexity: O(n) in perfect tree or O(1) in linked list
 */
void printBFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop();
    }
    cout << endl;
}

int main()
{
    cout << "[1] to insert\n[2] to search\n[3] to show ht\n[4] BFS print\n[5] to quit\n\n";
    int ch;
    while (true)
    {
        do
        {
            cout << "Enter choice: ";
            cin >> ch;
        } while (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5);
        switch (ch)
        {
        case 1:
            cout << "Insert: ";
            int ins;
            cin >> ins;
            rootptr = insert(rootptr, ins);
            break;
        case 2:
            cout << "Enter Query: ";
            int query;
            cin >> query;
            if (search(rootptr, query))
                cout << "Found" << endl;
            else
                cout << "NOT Found" << endl;
            break;
        case 3:
            cout << "Ht of BINARY SEARCH TREE IS " << findht(rootptr) << endl;
            break;
        case 4:
            printBFS(rootptr);
            break;
        case 5:
            return 0;
        }
    }
}
/**
 * binary tree traversal is visiting all the elements of the tree exactly once
 * 2 ways
 * bfs is visiting all nodes at a level(top to bottom) from left to right
 * dfs if we area at a child then we completely visit the entire subtree of that child
 *      3 ways
 *      preorder    root->left subtree->right subtree short form data left right dlr
 *      inorder     left subtree->root->right subtree short form left data right dlr
 *      postorder   left subtree->right subtree->root short form left right data dlr
 *      data means read or access the data before moving to the next subtree
 */
