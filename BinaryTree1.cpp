#include<iostream>
#include<queue>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
	public:
		T data;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		BinaryTreeNode(T data) {
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~BinaryTreeNode() {
			delete left;
			delete right;
		}
};

class PairAns {
	public:
		int maximum;
		int minimum;
};

BinaryTreeNode<int> *takeInput() {
	int rootData;
	cout<<"Enter the root data:";
	cin>>rootData;
	if(rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int leftChildData;
		cout<<"Enter the left child data of "<<front->data<<":";
		cin>>leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		int rightChildData;
		cout<<"Enter the right child data of "<<front->data<<":";
		cin>>rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> ans;
	if(root != NULL) {
		ans.push(root);
	}
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		if(front != NULL) {
			cout<<front->data<<":";
		}
		if(front->left != NULL) {
			cout<<"L:"<<front->left->data<<", ";
			ans.push(front->left);
		} else if(front->left == NULL) {
			cout<<"L:-1, ";
		}
		if(front->right != NULL) {
			cout<<"R:"<<front->right->data;
			ans.push(front->right);
		} else if(front->right == NULL) {
			cout<<"R:-1";
		}
		ans.pop();
		cout<<endl;
	}
}

int countAllNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return 1;
	} else {
		return 1 + countAllNodes(root->left) + countAllNodes(root->right);
	}
}

int countLeafNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return 1;
	}
	int a = countLeafNodes(root->left);
	int b = countLeafNodes(root->right);
	return a + b;
}

int sumAllNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return root->data;
	}
	else {
		return root->data + sumAllNodes(root->left) + sumAllNodes(root->right);
	}
}

int sumLeafNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return root->data;
	}
	int a = sumLeafNodes(root->left);
	int b = sumLeafNodes(root->right);
	return a + b;
}

bool check(BinaryTreeNode<int> *root, int x) {
	if(root == NULL) {
		return false;
	}
	if(root->data == x) {
		return true;
	}
	queue<BinaryTreeNode<int>*> ans;
	ans.push(root);
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		ans.pop();
		if(front->data == x) {
			return true;
		}
		if(front->left != NULL) {
			ans.push(front->left);
		}
		if(front->right != NULL) {
			ans.push(front->right);
		}
	}
	return false;
}

int heightTree(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return 1;
	} else {
		return 1 + max(heightTree(root->left), heightTree(root->right));
	}
}

bool checkBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return true;
	}
	int a = heightTree(root->left);
	int b = heightTree(root->right);
	if(abs(a - b <= 1) && checkBalanced(root->left) && checkBalanced(root->right)) {
		return true;
	} else {
		return false;
	}
}

void inorder(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	inorder(root->left);
	cout<<root->data <<" ";
	inorder(root->right);
}

void preorder(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void printLevel(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	queue<BinaryTreeNode<int>*> ans;
	if(root != NULL) {
		ans.push(root);
		ans.push(NULL);
	}
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		ans.pop();
		if(front == NULL) {
			if(ans.empty()) {
				break;
			}
			cout<<endl;
			ans.push(NULL);
			continue;
		}
		cout<<front->data<<" ";
		if(front->left != NULL) {
			ans.push(front->left);
		}
		if(front->right != NULL) {
			ans.push(front->right);
		}
	}
}

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	if(root->left != NULL && root->right != NULL) {
		nodesWithoutSibling(root->left);
		nodesWithoutSibling(root->right);
	} else if(root->left != NULL) {
		cout<<root->left->data<<" ";
		nodesWithoutSibling(root->left);
	} else if(root->right != NULL) {
		cout<<root->right->data<<" ";
		nodesWithoutSibling(root->right);
	}
}


int findMax(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	int max = root->data;
	queue<BinaryTreeNode<int>*> ans;
	ans.push(root);
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		ans.pop();
		if(front->data > max) {
			max = front->data;
		}
		if(front->left != NULL) {
			ans.push(front->left);
		}
		if(front->right != NULL) {
			ans.push(front->right);
		}
	}
	return max;
}

int findMin(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	int min = root->data;
	queue<BinaryTreeNode<int>*> ans;
	ans.push(root);
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		ans.pop();
		if(front->data < min) {
			min = front->data;
		}
		if(front->left != NULL) {
			ans.push(front->left);
		}
		if(front->right != NULL) {
			ans.push(front->right);
		}
	}
	return min;
}

PairAns minMax(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		PairAns p;
		p.minimum = 0;
		p.maximum = 0;
		return p;
	}
	PairAns a;
	a.maximum = findMax(root);
	a.minimum = findMin(root);
	return a;
}

void oneChild(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return ;
	}
	if(root->left != NULL) {
		oneChild(root->left);
	}
	if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL) {
		cout<<root->data<<" ";
	}
	if(root->right != NULL) {
		oneChild(root->right);
	}
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns = heightDiameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;
	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

void printDiagonalUtil(BinaryTreeNode<int> *root, int diagLevel, map<int, vector<int> > &M) {
	if(root == NULL) {
		return ;
	}
	M[diagLevel].push_back(root->data);
	printDiagonalUtil(root->left, diagLevel + 1, M);
	printDiagonalUtil(root->right, diagLevel, M);
}

void printDiagonal(BinaryTreeNode<int> *root) {
	map<int, vector<int> > M;
	printDiagonalUtil(root, 0, M);
	map<int, vector<int> > :: iterator it;
	for(it = M.begin();it != M.end(); it ++) {
		vector<int> :: iterator vit;
		for(vit = it->second.begin(); vit!= it->second.end(); vit++) {
			cout<<*vit<<" ";
		}
		cout<<endl;
	}
}

void printBoundaryRight(BinaryTreeNode<int> *root) {
	if(root != NULL) {
		if(root->right) {
			cout<<root->data<<" ";
			printBoundaryRight(root->right);
		} else if(root->left) {
			cout<<root->data<<" ";
			printBoundaryRight(root->left);
		}
	}
}

void printBoundaryLeft(BinaryTreeNode<int> *root) {
	if(root != NULL) {
		if(root->left) {
			cout<<root->data<<" ";
			printBoundaryLeft(root->left);
		} else if(root->right != NULL) {
			cout<<root->data<<" ";
			printBoundaryLeft(root->right);
		}
	}
}

void printLeaves(BinaryTreeNode<int> *root) {
	if(root != NULL) {
		printLeaves(root->left);
		if(root->left == NULL && root->right == NULL) {
			cout<<root->data<<" ";
		}
		printLeaves(root->right);
	}
}

void printBoundary(BinaryTreeNode<int> *root) {
	if(root != NULL) {
		cout<<root->data<<" ";
		printBoundaryLeft(root->left);
		printLeaves(root->left);
		printLeaves(root->right);
		printBoundaryRight(root->right);
	}
}

void solve(BinaryTreeNode<int> *root) {
	printBoundary(root);
	cout<<endl;
}

int main() {
	BinaryTreeNode<int> *root = takeInput();
	printTree(root);
	int count = countAllNodes(root);
	cout<<"All nodes:"<<count<<endl;
	int countl = countLeafNodes(root);
	cout<<"Leaf noades:"<<countl<<endl;
	int sum = sumAllNodes(root);
	cout<<"Sum all:"<<sum<<endl;
	int suml = sumLeafNodes(root);
	cout<<"Sum Leaf:"<<suml<<endl;
	int x;
	cout<<"Enter the value of x:";
	cin>>x;
	bool ans = check(root, x);
	if(ans) {
		cout<<"yes"<<endl;
	} else {
		cout<<"no"<<endl;
	}
	int ans2 = heightTree(root);
	cout<<"Height of the tree is:"<<ans2<<endl;
	bool ans3 = checkBalanced(root);
	if(ans3) {
		cout<<"Yes Balanced!"<<endl;
	} else {
		cout<<"Not Balanced!"<<endl;
	}
	cout<<"INORDER TRAVERSAL OF THE BINARY TREE IS:"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"PREORDER TRAVERSAL OF THE BINARY TREEE IS:	"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"POSTORDER TRAVERSAL OF THE BINARY TREEE IS:"<<endl;
	postorder(root);
	cout<<endl;
	cout<<"LEVEL ORDER TRAVERSAL OF THE BINARY TREE IS:"<<endl;
	printLevel(root);
	cout<<endl;
	cout<<"Nodes wihtout siblings in the tree are:"<<endl;
	nodesWithoutSibling(root);
	cout<<endl;
	PairAns ans4 = minMax(root);
	cout<<"Maximum value of node present in the Binary tree is:"<<ans4.maximum<<endl;
	cout<<"Minimum value of node present in the Binary tree is:"<<ans4.minimum<<endl;
	cout<<"Root that has only one child are:"<<endl;
	oneChild(root);
	cout<<endl;
	pair<int, int> p = heightDiameter(root);
	cout<<"The height of the binary tree is:"<<p.first<<endl;
	cout<<"The diameter of the binary tree is:"<<p.second<<endl;
	cout<<"To print the tree diagonally:"<<endl;
	printDiagonal(root);
	cout<<endl;
	cout<<"The boundary nodes of the tree are:"<<endl;
	solve(root);
	cout<<endl;
	return 0;
}
