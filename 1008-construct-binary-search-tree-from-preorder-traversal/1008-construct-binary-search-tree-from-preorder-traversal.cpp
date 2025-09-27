class Solution {
public:
    void insert(TreeNode* root, int val){
        if(root==NULL) root = new TreeNode(val);
        else if(root->val > val){// go left
            if(root->left == NULL){//ATTACH IT HERE
                root->left = new TreeNode(val);
            }
            else insert(root->left, val);
        }
        else{// root->val < val : go right
            if(root->right == NULL){//ATTACH IT HERE
                root->right = new TreeNode(val);
            }
            else insert(root->right,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
            insert(root,pre[i]);
        }
        return root;
    }
};