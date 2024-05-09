//bai1
void preOrder(Tree T)
{
    printf("%d ",T->Key);
    if(T->Left!=NULL)
        preOrder(T->Left);
    if(T->Right!=NULL)
        preOrder(T->Right);
}

//bai2
Tree getPrevious(int x, Tree T)
{
    Tree tmp = NULL;
    while(T!=NULL && T->Key !=x)
    {
        if(T->Key > x)
            T=T->Left;
        else
        {
            tmp = T;
            T=T->Right;
        }
    }
    if (T->Left == NULL)
        return tmp;
    else
	{
		T = T->Left;
		return T;
	}
}

//bai3
Tree getParent (int x, Tree T)
{
	Tree tmp=NULL;
	while(T!=NULL && T->Key!=x) 
	{
		tmp=T;
		if(x<T->Key) 
			T=T->Left;
		else
			T=T->Right;
	}
	return tmp;
}

//bai4
Tree initTree()
{
    Tree T = NULL;
    return T;
}

//bai5
Tree searchNode (int x, Tree T)
{
	while (T!=NULL && T->Key!=x)
	{
		if (x < T->Key)
			T=T->Left;
		else if (x > T->Key)
			T=T->Right;
	}
	return T;
}

//bai5
Tree rightSibling(int x, Tree T)
{
    Tree tmp = T;
    if(T == NULL)
        return NULL;
    while((T->Left!=NULL || T->Right!=NULL) && T->Key!=x)
    {
        if(T->Key < x)
        {
            tmp = NULL;
            T = T->Right;
        }
        if(T->Key > x)
        {
            tmp = T->Right;
            T=T->Left;
        }
    }
    return tmp;
}

//bai6
KeyType Min (Tree *T)
{
	KeyType k;
	if ((*T)->Left == NULL )
	{
		k = (*T)->Key;
		(*T) = (*T)->Right;
		return k;
	}
	else 
	    return Min(&(*T)->Left);
}
void deleteNode (int x, Tree *T)
{
	if ((*T) != NULL){
		if (x < (*T)->Key)
			deleteNode(x, &(*T)->Left);
		else if (x > (*T)->Key)
			deleteNode(x, &(*T)->Right);			
		else{
			if ((*T)->Left==NULL && (*T)->Right==NULL)
				(*T) = NULL;
			else if ((*T)->Left==NULL)
				(*T) = (*T)->Right;
			else if ((*T)->Right==NULL)
				(*T) = (*T)->Left;
			else 
				(*T)->Key = Min(&(*T)->Right);
		}
	}
	else printf("Loi: Hang rong!");
}

//bai7
int getHeight(Tree T)
{
    if(T==NULL) return -1;
    int sL=getHeight(T->Left);
    int sR=getHeight(T->Right);
    if(sL>=sR)
        sR=sL;
    return sR+1;
}

//bai8

void insertNode(int x, Tree *T){
	if((*T) == NULL){
		(*T) = (struct Node*)malloc(sizeof(struct Node));
		(*T)->Key = x;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
	}
	else 
	    if (x < (*T)->Key)
			insertNode(x,&((*T)->Left));
	    else if (x > (*T)->Key)
			insertNode(x,&((*T)->Right));
}

//bai9
void printPath(int x, Tree T){
	if(T == NULL)
		printf("-> Khong tim thay");
	else {
		printf("%d ", T->Key);
		if(T->Key == x)
			printf("-> Tim thay");
		else 
		    if(T->Key > x) 
			printPath(x, T->Left); 
		    else 
			printPath(x, T->Right);
	}
}

//bai10

void posOrder(Tree T)
{
    if(T!=NULL)
    {
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ",T->Key);
    }
}

//bai11
Tree getMin (Tree T){
	if (T->Left == NULL){
		return T;
	}
	else return getMin(T->Left);
}

Tree getNext (int x, Tree T){
	Tree temp=NULL; 
	while (T!=NULL && T->Key!=x){
		if (x < T->Key){
			temp = T;
			T = T->Left;
		}
		else if (x > T->Key)
			T = T->Right;
	}
	if (T==NULL)
		return NULL;
	else {
		if (T->Right==NULL){
			return temp;
		}
		return getMin(T->Right);
	}
	return NULL;
}

//bai12

int isEmpty(Tree T)
{
	return T==NULL;
}

//bai13
void inOrder(Tree T){
    if(T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}
//bai14
int height( Tree T)
{
    if (T==NULL ) return -1;
    else return 1+ (height(T->Left)>height(T->Right)? height(T->Left):height(T->Right));
}
int  hNode(int x, Tree T)
{
if (T==NULL) return -1;
else if (T->Key ==x) return height (T);
else if (T->Key <x) return hNode( x, T->Right);
else return hNode( x, T->Left);
}

//bai15
int getFullNodes(Tree T) {
    if (T == NULL) 
        return 0;
    if (T->Left != NULL && T->Right != NULL) 
        return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);
     else 
        return getFullNodes(T->Left) + getFullNodes(T->Right);
}

//bai16
int getNb_Nodes( Tree T)
{
    if (T==NULL) return 0;
    else
        return 1 +getNb_Nodes(T->Left) + getNb_Nodes(T->Right);
    
}

/////////////////
int preIndex =0;
Tree createTree( char pre[], char in[], int start, int end)
{
    Tree N = NULL;
    if(start<=end)
    {
        N = (Tree) malloc(sizeof(struct Node));
        N->Data = pre[preIndex];
        preIndex++;
        if(start==end)
        {
            N->Left = NULL;
            N->Right = NULL;
            return N;
        }
        int inIndex = findIndex(N->Data, in, start, end);
        N->Left = createTree(pre, in, start, inIndex-1);
        N->Right= createTree(pre, in, inIndex+1, end);
    }
    return N;
}

Tree createTree(char pre[], char in[], int Start, int End)
{
    static int preIndex =0;
    if(Start > End)
        return NULL;
    Tree node = (Tree)malloc(sizeof(struct Node));
    node->Data = pre[preIndex++];
    if(Start == End)
    {
        node->Left = NULL;
        node->Right= NULL;
        return node;
    }
    int inIndex = findIndex(node->Data, in, Start, End);
    node->Left = createTree(pre,in,Start,inIndex -1);
    node->Right = createTree(pre,in,inIndex+1,End);
    return node;
}
/////////
typedef int KeyType;
struct Node
{   
    KeyType Key;
    struct Node * Left;
    struct Node * Right;
} ;
typedef struct Node * TTree;
