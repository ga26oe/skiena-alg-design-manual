// 114. Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

  /*
    - Pre order traversal: type of DFS, each node is visited in a certian order
    - Visit root node first, then recursively visit left subtree, then right sub tree
    - useful for creating a copy of the tree, prefix notation etc.
    - called pre order becuase the node is visted "before" the recursivee pre order     traversal of the left and right subtrees

 */

void flatten(struct TreeNode* root) {
    if (root != NULL) {
        struct TreeNode *right = root->right; 

        root->right = root->left;
        root->left = NULL;

        struct TreeNode *curr = root;
        while (curr->right){
            curr = curr->right;
        }
        curr->right = right;
        
        flatten(root->right);
    }

}


/*
- Morris Traversal Alg. 
     Current = root
     while current is not Null
        if not exists current.left 
            visit (current)
            current = current.right 
        
        else 
            predecessor = findPredecessor(current)

            if not exists predecessor.right 
                predecessor.right = current
                current= current.left 
                
                
            else (if you already traversed this path)
                precessor.right = NULL
                visit(current)
                current = curren.right 



*/