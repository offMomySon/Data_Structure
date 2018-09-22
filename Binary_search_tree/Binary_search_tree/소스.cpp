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
















