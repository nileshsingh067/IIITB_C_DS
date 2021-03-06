struct bst{
	int key;
	struct bst *lc,*rc,*p;
};
struct bst * newNode(int data){
	struct bst *node;
	node=(struct bst *)malloc(sizeof(struct bst));
	if(node!=NULL){
		node->key=data;
		node->lc=NULL;
		node->rc=NULL;
		node->p=NULL;
		return node;
	}else{
		printf("Not Enough Memory\n");
		return NULL;
	}
}
struct bst * insert(struct bst * root,int data){
	if(root==NULL)return newNode(data);
	else{	
		struct bst *tmp;
		if(data>root->key){
		tmp=insert(root->rc,data);
		root->rc=tmp;
		tmp->p=root;
		}
		else{
		tmp=insert(root->lc,data);
		root->lc=tmp;
		tmp->p=root;
		}
		return root;
	}
}
void inorderTraversal(struct bst *root){
	if(root!=NULL){
		inorderTraversal(root->lc);
		printf("%d\t",root->key);
		inorderTraversal(root->rc);
	}
}
void preorderTraversal(struct bst *root){
	if(root!=NULL){
		printf("%d\t",root->key);
		preorderTraversal(root->lc);
		preorderTraversal(root->rc);
		}
}
int search(struct bst *root,int key){
	int result=-1;
	while(root){
		if(root->key==key)return 1;
		else if(key>root->key)root=root->rc;
		else root=root->lc;
		}
	return 0;
}
struct bst * searchNode(struct bst *root,int key){
	struct bst *node=NULL;
	while(root){
		if(root->key==key)return root;
		else if(key>root->key)root=root->rc;
		else root=root->lc;
		}
	return NULL;
}
int serach_rec(struct bst *root,int key){
	if(root==NULL)return -1;
	else{
		if(root->key==key){return 1;}
		else if(key>root->key) return serach_rec(root->rc,key);
		else return serach_rec(root->lc,key);
	}
}
struct bst * findMin(struct bst *root){
	if(root==NULL)return NULL;
	else{
		struct bst *min=root;
		while(min->lc){
			min=min->lc;
		}
		return min;
	}
}
struct bst * findMax(struct bst *root){
	if(root==NULL)return NULL;
	else{	
		struct bst *max=root;
		while(max->rc){
			max=max->rc;
		}	
		return max;
	}
}
struct bst * inorderSuccessor(struct bst *root){
	if(root->rc)return findMin(root);
	else{
		struct bst *p=root->p;
		while(p!=NULL&&root==p->rc){
		root=p;
		p=p->p;
		}
		return p;
		}
		
	}

struct bst * inorderPredecessor(struct bst *root){
	if(root->lc)return findMax(root);
	else{
		struct bst *p=root->p;
		while(p!=NULL&&root==p>lc){
		root=p;
		p=p->p;
		}
		return p;
}
struct bst *deleteNode(struct bst* root,int key){
	if(root==NULL)return NULL;
	if(key>root->key){
		root->rc=deleteNode(root->rc,key);		
	}else if(key<root->key){
		root->lc=deleteNode(root->lc,key);
	}else{
		if(root->lc==NULL){
			struct bst* temp=root->lc;
			free(root);
			return temp;
		}else if(root->lc==NULL){
			struct bst* temp=root->rc;
			free(root);
			return temp;
		}else{
			struct bst* min=findMin(root->rc);
			root->key=min->key;
			root->rc=deleteNode(root->rc,min->key);
		}
	
	}
	return root;
}
