#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct Node* NodePtr;
typedef struct Node
{
	int value;
	NodePtr r_arm;
	NodePtr l_arm;
}Node;

NodePtr start_point;


NodePtr delete_node(NodePtr  tree, int delete_value);
NodePtr find_min(NodePtr tree);
NodePtr search_node(NodePtr tree, int find_value);
void insert_node(NodePtr *tree, NodePtr new_node);
NodePtr make_node(int value);


int main()
{

}

NodePtr make_node(int value)
{
	NodePtr temp = (NodePtr)malloc(sizeof(Node));
	temp->l_arm = NULL;
	temp->r_arm = NULL;
	temp->value = value;
	 
	return temp;
}

void insert_node(NodePtr *tree, NodePtr new_node)
{

	// start_point Empty ���� �˻�.
	if ((*tree) == NULL)
		(*tree) = new_node;

	// ���� ���� �� node���� ũ��
	if ((*tree)->value > new_node->value)   
	{
		//���� left ���� �Ǿ����� new_node ����.
		if ((*tree)->l_arm == NULL)
			((*tree))->l_arm = new_node;
		else
			insert_node( &((*tree)->l_arm) , new_node );
	}
	// ���� ���� ��node���� ����.
	else if ((*tree)->value < new_node->value)
	{
		//���� right ���� �Ǿ����� new_node ����.
		if ((*tree)->r_arm == NULL)
			((*tree))->r_arm = new_node;
		else
			insert_node(&((*tree)->r_arm), new_node);
	}
}

NodePtr search_node(NodePtr tree, int find_value)
{
	if (tree == NULL)
		return NULL;

	if (tree->value > find_value)
		search_node(tree->l_arm, find_value);
	else if (tree->value < find_value)
		search_node(tree->r_arm, find_value);
	else if (tree->value == find_value)
		return tree;
}

NodePtr find_min(NodePtr tree)
{
	if (tree->l_arm == NULL)
		return tree;
	else
		return find_min(tree->l_arm);
}

NodePtr delete_node(NodePtr  tree, int delete_value)
{
	
	if (tree->value == delete_value)
	{
		if (tree->l_arm != NULL && tree->r_arm != NULL)        //���� ������ �Ѵ� ��� ����. 
		{
			NodePtr temp_ptr = find_min(tree->r_arm);
			tree->value = temp_ptr->value;

			tree = delete_node(tree->r_arm, temp_ptr->value);
		}
		else if (tree->l_arm == NULL && tree->r_arm == NULL)  // �� ���.
		{
			free(tree);
			tree = NULL;
		}
		else                                                   // �� �� �ϳ��� ��� ����.
		{
			NodePtr temp_ptr = tree;

			if (tree->l_arm == NULL)
				tree = tree->r_arm;
			else if (tree->r_arm == NULL)
				tree = tree->l_arm;

			free(temp_ptr);
		}
	}
	else if (tree->value > delete_value)
		tree->l_arm = delete_node(tree->l_arm, delete_value);
	else if (tree->value < delete_value)
		tree->r_arm = delete_node(tree->r_arm, delete_value);

	return tree;
}




























































