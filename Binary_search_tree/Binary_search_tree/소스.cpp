#include<stdio.h>
#include<stdlib.h>

typedef struct Node * NodePtr;
typedef struct Node
{
	int value;
	NodePtr l_arm;
	NodePtr r_arm;

}Node;


NodePtr start_point;



int main()
{



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
	NodePtr return_ptr;

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
			free((*tree));  // 그냥 제거
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
			NodePtr temp_ptr = find_min_arm( &((*tree)->r_arm ));
			temp_ptr->l_arm = (*tree)->l_arm;
			temp_ptr->r_arm = (*tree)->r_arm;

			free(*tree);

			(*tree) = temp_ptr;
		}
		
	}
	else if ((*tree)->value > delete_value)
		delete_node(&((*tree)->l_arm), delete_value);
	else if ((*tree)->value < delete_value)
		delete_node(&((*tree)->r_arm), delete_value);
}



NodePtr find_min_arm(NodePtr* tree)
{
	if ((*tree)->l_arm == NULL)
	{
		NodePtr result_ptr = *tree;

		if ((*tree)->r_arm != NULL)
			(*tree) = (*tree)->r_arm;
		
		return result_ptr;
	}
	else
		return find_min_arm( &((*tree)->l_arm) );
}














