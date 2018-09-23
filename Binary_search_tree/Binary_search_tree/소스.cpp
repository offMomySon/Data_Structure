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
	printf("Enter num(10��) : ");

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
	NodePtr return_ptr = NULL;
	if (tree == NULL)
		return return_ptr;
	
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
			free((*tree));  // �׳� ����-
			(*tree) = NULL;
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
			int temp_value = find_min_arm( &((*tree)->r_arm )); // ������ ���� ��� �������� ���� // return ���� �������� ���̻� �� �� ���� ���.
			
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
	if ((*tree)->l_arm == NULL)   // �������� ���̻� �� �� ����.
	{
		int rtn_value = (*tree)->value;
		NodePtr temp = (*tree);
		if ((*tree)->r_arm != NULL)    //������ node���� r_arm�� ���� ������ �����͸� ��ü �ؾ���. 
			(*tree) = (*tree)->r_arm;
		else
			(*tree) = NULL;
		free(temp);
		
		return rtn_value;
	}
	else
		return find_min_arm( &((*tree)->l_arm) );  // �������� ����̵�
}

//http://leeyongjeon.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89-%ED%8A%B8%EB%A6%ACBinary-Search-Trees-in-C












