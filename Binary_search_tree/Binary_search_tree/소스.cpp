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
	if ((*tree) == NULL) //�̵��� �ȿ� ��尡 ������ �߰�
	{
		(*tree) = new_node;
	}
	else
	{
		if ((*tree)->value > new_node->value)             // ���ο� ����� ����  ������ ������ �۴�.
		{												  // ���� ���� �̵��ؾ���
			insert_node(&((*tree)->l_arm), new_node);
		}
		else if ((*tree)->value < new_node->value)        // ���ο� ����� ���� ������ ������ ũ��.
		{												  // ������ ���� �̵��ؾ���
			insert_node(&((*tree)->r_arm), new_node);
		}
	}
}

NodePtr search_node(NodePtr tree, int find_value)
{
	NodePtr return_ptr;

	if (tree->value == find_value)
		return_ptr = tree;

	if (tree->value > find_value)             //ã�� ����� ����  ���� ��Ʈ�� ������ �۴�.
		return_ptr = search_node(tree->l_arm, find_value); // �������� �̵��ؼ� ��ġ
	else if (tree->value < find_value)         //ã�� ����� ����   ���� ��Ʈ�� ������ ũ��.
		return_ptr = search_node(tree->r_arm, find_value); // ���������� �̵��ؼ� ��ġ

	return return_ptr;
}

void delete_node(NodePtr *tree, int delete_value)
{
	if ((*tree)->value == delete_value) // ����� ����Ʈ
	{
		if ((*tree)->l_arm == NULL && (*tree)->r_arm == NULL)   // subtree����.
		{
			free((*tree));  // �׳� ����
		}
		else if (((*tree)->l_arm == NULL && (*tree)->r_arm != NULL) || ((*tree)->r_arm == NULL && (*tree)->l_arm != NULL))  //�����ϳ� subtree ����
		{
			if ((*tree)->l_arm == NULL)  //  �����ʸ� subtree ����.
				(*tree) = (*tree)->r_arm;
			else if ((*tree)->r_arm == NULL)  // ���ʸ� subtree ����.
				(*tree) = (*tree)->l_arm;
		}
		else if ((*tree)->l_arm != NULL && (*tree)->r_arm != NULL) // ���ʴ� subtree �ִ�.
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














