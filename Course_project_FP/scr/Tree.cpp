#include "Tree.h"

namespace factory
{
    void add(FNode** root, Factory* key, SP _priority, CMPFUNC(cmpfunc))
	{
		if (*root == nullptr)
		{
            *root = new FNode;
			(*root)->key = key;
			(*root)->left = nullptr;
			(*root)->right = nullptr;
			return;
		}
        int flag;
        FNode* temp = *root;
		while (true)
		{
			flag = cmpfunc( *temp->key, *key, _priority);
			if (!flag)
				return;
			if (flag == 1)
			{
				if (temp->right == nullptr)
				{
                    temp->right = new FNode;
					temp = temp->right;
					temp->key = key;
					temp->left = nullptr;
					temp->right = nullptr;
					return;
				}
				temp = temp->right;
			}
			else
			{
				if (temp->left == nullptr)
				{
                    temp->left = new FNode;
					temp = temp->left;
					temp->key = key;
					temp->left = nullptr;
					temp->right = nullptr;
					return;
				}
				temp = temp->left;
			}
		}
	}

    Factory* search(FNode* root, const size_t& _number)
	{
		while (true)
		{
			if (root == nullptr)
				return nullptr;
			if (root->key->number == _number)
				return root->key;
			if (root->key->number < _number)
				root = root->right;
			else
				root = root->left;
		}
	}

    void delNode(FNode** node)
	{
		delete (*node)->key;
		delete (*node);
		*node = nullptr;
	}

    void del(FNode** root, const size_t& _number)
	{
		if (!(*root)) return;
		if ((*root)->key->number > _number)
		{
            del(&(*root)->left, _number);
			return;
		}
		else  if ((*root)->key->number < _number)
		{
            del(&(*root)->right, _number);
			return;
		}
        FNode* left = (*root)->left;
        FNode* right = (*root)->right;
        delNode(root);
		if (!left) *root = right;
		else if (!right) *root = left;
		else
		{
			*root = left;
			while (left->right)
			{
				left = left->right;
			}
			left->right = right;
		}
	}

    void __reBuild(FNode* root, FNode** newRoot, SP _priority, CMPFUNC(cmpfunc))
	{
        if (root == nullptr)
			return;
        add(newRoot, root->key, _priority, cmpfunc);
        __reBuild(root->left, newRoot, _priority, cmpfunc);
        __reBuild(root->right, newRoot, _priority, cmpfunc);
        delete root;
	}

    void reBuild(FNode** root, SP _priority, CMPFUNC(cmpfunc))
	{
		if (*root == nullptr)
			return;
        FNode* newRoot = nullptr;
        __reBuild(*root, &newRoot, _priority, cmpfunc);
		*root = newRoot;
	}

    void clear(FNode** root)
	{
		if (*root == nullptr)
			return;
		clear(&((*root)->left));
		clear(&((*root)->right));
		delNode(root);
	}
}
