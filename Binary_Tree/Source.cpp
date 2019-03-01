#include <iostream>
#include <cstdlib>
#include<locale.h>
#include<iomanip>
using namespace std;

/**
* \brief A class is created to show binary search tree
*/
class BinarySearchTree
{
	/** 
	* \brief A struct is created
	* \param left
	* \param right
	* \param data
	*/
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		int data;
	};
	tree_node* root;
	tree_node* parent;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const 
	{
		return root == NULL;
	}
	/** \brief Initialized the function of printed inorder list 
	*/
	void print_inorder();
	/** \brief Initialized the function of created inorder list
	 * \param node
	 */
	void inorder(tree_node*);
	/** \brief Initialized the function of printed preorder list
	*/
	void print_preorder();
	/** \brief Initialized the function of created inorder list
	* \param node
	*/
	void preorder(tree_node*);
	/** \brief Initialized the function of printed postorder list
	*/
	void print_postorder();
	/** \brief  Initialized the function of created postorder list
	* \param node
	*/
	void postorder(tree_node*);
	/** \brief  Initialized the function of added new nood
	* \param int
	*/
	void insert(int);
	/** \brief  Initialized the function of removed to wanted nood by user
	* \param int
	*/
	void remove(int);
	/** \brief  Initialized the function of counted
	* \param node
	*/
	void Count(tree_node*);
	/** \brief  Initialized the function of show the elements number
	*/
	void print_count();
};
/** \brief Insert function is created
* \param d
*/
void BinarySearchTree::insert(int d)
{
	tree_node* t = new tree_node;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		
		tree_node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}
/** \brief Remove function is created
* \param remove
*/
void BinarySearchTree::remove(int d)
{
	
	bool found = false;
	if (isEmpty())
	{
		cout << " No elements in tree " << endl;
		return;
	}
	tree_node* curr;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << "The element to delete is not found in the tree " << endl;
		return;
	}


	// 3 cases :
	// 1. We're removing a leaf node
	// 2. We're removing a node with a single child
	// 3. we're removing a node with 2 children

	// Node with single child
	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
		&& curr->right == NULL))
	{
		if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	//We're looking at a leaf node
	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return;
	}


	//Node with 2 children
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL)
	{
		tree_node* chkr;
		chkr = curr->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if ((curr->right)->left != NULL)
			{
				tree_node* lcurr;
				tree_node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree_node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}

		}
		return;
	}

}
/** 
* \brief Inorder print function
*/
void BinarySearchTree::print_inorder()
{
	inorder(root);
}
/**
* \brief Inorder function is created
*/
void BinarySearchTree::inorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else return;
}
/**
* \brief Print preorder function
*/
void BinarySearchTree::print_preorder()
{
	preorder(root);
}
/**
* \brief Preorder function is created
*/
void BinarySearchTree::preorder(tree_node* p)
{
	if (p != NULL)
	{
		cout << " " << p->data << " ";
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
	else return;
}
/** brief Print postorder function
*/
void BinarySearchTree::print_postorder()
{
	postorder(root);
}
/** brief Postorder function is created
*/
void BinarySearchTree::postorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->data << " ";
	}
	else return;
}
/** \brief count function
*/
void BinarySearchTree::Count(tree_node* p)
{
	int counter = 0;
	while (p != NULL)
	{
		if (p->left)
		{
			p = p->left;
			counter++;
		}
		if (p->right)
		{
			p = p->right;
			counter++;
		}
	}
	cout << "Aðaçtaki toplam eleman sayýsý : " << counter;
}
void BinarySearchTree::print_count()
{
	Count(root);
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	BinarySearchTree node;
	int seçim, ekle, silinen, gezinti_seçim;
	/**Creat a menu to choice by user
	*/
	while (1)
	{
		cout << endl << endl;
		cout << "\n\n\n\t******** MENU *******\n\n";
		cout << " ----------------------------- " << endl;
		cout << "\n\t1 - Add \n";
		cout << "\t2 - Delete \n";
		cout << "\t3 - List \n";
		cout << "\t4 - Count \n";
		cout << "\t6 - Exit " << endl<<endl;
		cout << "Please select the function : ";
		cin >> seçim;
		//Created a switch-case given choice by user
		switch (seçim)
		{
			//Called insert function and add taking number from user to tree
		case 1: cout << "Please enter the number: ";
			cin >> ekle;
			node.insert(ekle);
			system("cls");
			break;
			//Called remove function and delete taking number from user to tree
		case 2: cout << " Please enter the number : ";
			cin >> silinen;
			node.remove(silinen);
			system("cls");
			break;
		case 3:
			//Called Order functions which user want and show the list
			system("cls");
			cout << setw(45) << "Which listing would you like to do " << endl << endl << endl;
			cout << setw(50) << "1 - Preorder " << endl;
			cout << setw(46) << "2 - Inorder " << setw(50) << endl;
			cout << setw(50) << "3 - Postorder " << endl;
			cin >> gezinti_seçim;

			if (gezinti_seçim == 1)
			{
				cout << "Pre-Order List" << endl;
				cout << "-------------------" << endl;
				node.print_preorder();
			}
			if (gezinti_seçim == 2)
			{
				cout << " In-Order List " << endl;
				cout << " -------------------" << endl;
				node.print_inorder();
			}
			if (gezinti_seçim == 3)
			{
				cout << " Post-Order List " << endl;
				cout << " --------------------" << endl;
				node.print_postorder();
			}
			break;
		case 4:
			// Called count function
			node.print_count();
			break;
		case 5:
			//

		case 6: 
			system("pause");
			return 0;
			break;
		default:
			cout << "Wrong choice ";
			break;

		
		}
	}
	system("pause");
	return 0;
}