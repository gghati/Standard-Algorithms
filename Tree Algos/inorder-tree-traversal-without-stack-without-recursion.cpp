# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
 
# define NODE 200003
 
struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};
 
void MorrisTraversal(struct tNode* root) {
    struct tNode *current, *pre;
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        }
        else { 
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
	            pre = pre->right;
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            else {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}
 
struct tNode* newtNode(int data)
{
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
int main()
{
 
    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
 
    MorrisTraversal(root);
 
    return 0;
}

