/*Binary Tree*/

#include<stdio.h>
#include<stdlib.h>

#ifndef _Tree_H
typedef int ElementType;
typedef TreeNode *SearchTree;
typedef TreeNode *Position;
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
#endif // !_Tree_H

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

int main()
{

}SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	if (X < T->Element)
	{
		return Find(X, T->Left);//return 作为参数传递的一个人接口
	}
	if (X > T->Element)
	{
		return Find(X, T->Right);
	}
	else return T;
}
Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	if (T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right);
	}
}
Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	if (T->Left == NULL)
	{
		return T->Left;
	}
	else
	{
		return FindMin(T->Left);
	}
}