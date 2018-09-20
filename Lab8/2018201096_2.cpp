/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    int mxV(Node * root){
        if(root==NULL)
            return INT32_MIN;
        return max(root->data,max(mxV(root->left),mxV(root->right)));
    }
    int mnV(Node * root){
        if(root==NULL)
            return INT32_MAX;
        return min(root->data,min(mnV(root->left),mnV(root->right)));
    }
	bool checkBST(Node* root) {
        if(root==NULL)
            return true;
        if(((root->right!=NULL) && (mnV(root->right)<=root->data)) || ((root->left!=NULL)&&(mxV(root->left)>=root->data))){
            return false;
        }
        return checkBST(root->left)&&checkBST(root->right);
	}
