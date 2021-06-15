class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root==NULL) return NULL;
		swap(root->left, root->right);

		TreeNode *a = invertTree(root->left);
		TreeNode *b = invertTree(root->right);

		return root;
	}
}

