#include<bits/stdc++.h>

using namespace std;

#define null NULL

/* khai báo node */
struct Node{
    int key;
    Node* left;
    Node* right;
};

/* 1 t?o m?t node m?i */
Node* createNode(int x){
    Node *newNode = new Node;
    newNode ->key = x;
    newNode ->left = newNode ->right = null;
    return newNode;
}
/* 2 chèn giá tr? m?i vào BST */
Node* insertNode(Node *root, int x){
    if(root == null){
        return createNode(x);
    }
    
    if (x < root->key){
        root->left = insertNode(root->left, x);
    } else if(x > root->key){
        root->right = insertNode(root->right, x);
    }
    return root;
}


/* 3 t?p Binary Search Tree */
void createTree(Node*&root, int a[], int n){
    for(int i = 0; i < n; i++){
        root = insertNode(root, a[i]);
    }
}

/* 4 tim kiem mot gia tri trong  BST */
Node* searchNode(Node*root, int x){
    if(root == null || root->key == x){
        return root;
    }
    if(root->key < x){
        return searchNode(root -> right, x);
    }
    return searchNode(root -> left, x);
}

Node* minValueNode(Node* node){
    Node*current = node;
    while(current -> left != null){
        current = current -> left;
    }
    return current;
}

/* 5 xoa mot gia tri trong BST */
Node* deleteNode(Node*&root, int x){
    if(root == null){
        return root;
    }
    if(x < root->key){
        return root->left = deleteNode(root->left, x);
    }else if(x > root->key){
        root->right = deleteNode(root->right, x);
    }else{
        if(root->left == null){
            Node*temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == null){
            Node *temp = root->left;
            delete root;
        }

        Node*temp = minValueNode(root->right);
        root->key = temp -> key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/*  Inorder Traversal */
void traversalTree(Node *root){
    if(root != null){
        traversalTree(root -> left);
        cout << root->key << ' ';
        traversalTree(root -> right);
    }
}

void inorder(Node *root){
    Node *temp = root;
    stack<Node*> stk;
    while (temp!=null || !stk.empty()){
        if(temp!=null){
            stk.push(temp);
            temp=temp -> left;
        }
        else {
            temp = stk.top();
            stk.pop();
            cout << temp->key <<  " ";
            temp=temp->right;
        }
    }
}


int size(Node* node){
    if(node == null) return 0;
    else return(size(node-> left) + 1 + size(node-> right)); 
}

void deleteTree(Node* root){
    if(root == null) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete(root);
}

Node *findNodeSmallestKey(Node *root){
	if(root -> left == NULL && root -> right == NULL){
		return root;
	}
//	cout << "tle\n";
	return findNodeSmallestKey(root -> left);
}


int main(){
    Node * root = NULL;
	// 2.2.a them 1 khoa co gia tri x vao cay nhi phan tim kiem
    int x; cin >> x;
    root = insertNode(root, x);
    
    // 2.2.b tao 1 cay nhi phan tim kiem voi day khoa nhap tu ban phim , key thuc khi nhap so 0
    int a;
    while(true){
    	cin >> a;
    	if(a == 0) break;
    	root = insertNode(root, a);
	}
	
	// 2.2.c tim node co khoa nho nhat tren cay nhi phan tim kiem
	
	Node * t = findNodeSmallestKey(root);
	
//	cout << "node co value nho nhat trong BST : " << t-> key;
	cout << "pk";
}
