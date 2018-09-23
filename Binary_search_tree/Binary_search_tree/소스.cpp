#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct Node * NodePtr;
typedef struct Node
{
	int value;
	NodePtr l_arm;
	NodePtr r_arm;

}Node;


NodePtr start_point;

void inorder(NodePtr tree);
NodePtr make_node(int value);
void insert_node(NodePtr * tree, NodePtr new_node);
NodePtr search_node(NodePtr tree, int find_value);
void delete_node(NodePtr *tree, int delete_value);
int find_min_arm(NodePtr* tree);


int main()
{
	printf("Enter num(10개) : ");

	for (int i = 0; i < 10; i++)
	{
		int num;
		scanf("%d", &num);

		insert_node(&start_point, make_node(num));
	}

	printf("Entered Num is : ");
	inorder(start_point);
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		int num;
		printf("Enter search num : ");
		scanf("%d", &num);

		NodePtr result_ptr = search_node(start_point, num);
		if (NULL == result_ptr)
			printf("Can not Find %d\n", num);
		else
			printf("%d is detected in address : %#x \n", num, result_ptr);
	}

	for (int i = 0; i < 5; i++)
	{
		int num;
		printf("Delete num : ");
		scanf("%d", &num);

		delete_node(&start_point, num);

		inorder(start_point);
		printf("\n");
	}

	system("pause");
}


void inorder(NodePtr tree)
{	
	if (tree != NULL)
	{
		inorder(tree->l_arm);
		printf("[%d] ", tree->value);
		inorder(tree->r_arm);
	}
}

NodePtr make_node(int value)
{
	NodePtr temp_node = (NodePtr)malloc(sizeof(Node));
	temp_node->value = value;
	temp_node->l_arm = NULL;
	temp_node->r_arm = NULL;

	return temp_node;
}

void insert_node(NodePtr * tree, NodePtr new_node)
{
	if ((*tree) == NULL) //이동한 팔에 노드가 없으면 추가
	{
		(*tree) = new_node;
	}
	else
	{
		if ((*tree)->value > new_node->value)             // 새로운 노드의 값이  기존의 값보다 작다.
		{												  // 왼쪽 으로 이동해야함
			insert_node(&((*tree)->l_arm), new_node);
		}
		else if ((*tree)->value < new_node->value)        // 새로운 노드의 값이 기존의 값보다 크다.
		{												  // 오른쪽 으로 이동해야함
			insert_node(&((*tree)->r_arm), new_node);
		}
	}
}

NodePtr search_node(NodePtr tree, int find_value)
{
	NodePtr return_ptr = NULL;
	if (tree == NULL)
		return return_ptr;
	
	if (tree->value == find_value)
		return_ptr = tree;

	if (tree->value > find_value)             //찾는 노드의 값이  지금 루트의 값보다 작다.
		return_ptr = search_node(tree->l_arm, find_value); // 왼쪽으로 이동해서 서치
	else if (tree->value < find_value)         //찾는 노드의 값이   지금 루트의 값보다 크다.
		return_ptr = search_node(tree->r_arm, find_value); // 오른쪽으로 이동해서 서치

	return return_ptr;
}

void delete_node(NodePtr *tree, int delete_value)
{
	if ((*tree)->value == delete_value) // 지울애 디텍트
	{
		if ((*tree)->l_arm == NULL && (*tree)->r_arm == NULL)   // subtree없다.
		{
			free((*tree));  // 그냥 제거-
			(*tree) = NULL;
		}
		else if (((*tree)->l_arm == NULL && (*tree)->r_arm != NULL) || ((*tree)->r_arm == NULL && (*tree)->l_arm != NULL))  //둘중하나 subtree 존재
		{
			if ((*tree)->l_arm == NULL)  //  오른쪽만 subtree 있음.
				(*tree) = (*tree)->r_arm;
			else if ((*tree)->r_arm == NULL)  // 왼쪽만 subtree 있음.
				(*tree) = (*tree)->l_arm;
		}
		else if ((*tree)->l_arm != NULL && (*tree)->r_arm != NULL) // 양쪽다 subtree 있다.
		{
			int temp_value = find_min_arm( &((*tree)->r_arm )); // 오른쪽 팔을 출발 시점으로 지정 // return 값은 왼쪽으로 더이상 갈 수 없는 노드.
			
			(*tree)->value = temp_value;
	
		}
		
	}
	else if ((*tree)->value > delete_value)
		delete_node(&((*tree)->l_arm), delete_value);
	else if ((*tree)->value < delete_value)
		delete_node(&((*tree)->r_arm), delete_value);
}


int find_min_arm(NodePtr* tree)
{
	if ((*tree)->l_arm == NULL)   // 왼쪽으로 더이상 갈 수 없다.
	{
		int rtn_value = (*tree)->value;
		NodePtr temp = (*tree);
		if ((*tree)->r_arm != NULL)    //지금의 node에서 r_arm에 값이 있으면 포인터를 대체 해야함. 
			(*tree) = (*tree)->r_arm;
		else
			(*tree) = NULL;
		free(temp);
		
		return rtn_value;
	}
	else
		return find_min_arm( &((*tree)->l_arm) );  // 왼쪽으로 계속이동
}

//http://leeyongjeon.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89-%ED%8A%B8%EB%A6%ACBinary-Search-Trees-in-C












