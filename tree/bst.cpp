#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node(int data)
		{
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
};

class BST
{
	public:
		Node *root;

		BST(int data)
		{
			this->root = new Node(data);
		}
		
		~BST()
		{
			delete(root);
		}

		void insert(int data)
		{
			Node* newNode = new Node(data);
			Node* prevNode = root;
			Node* tmp = root;
			if(this->root->data == -1)
				this->root->data = data;
			else
			{
			while(tmp)
			{
				if(newNode->data < tmp->data)
				{
					prevNode = tmp;
					tmp = tmp->left;
				}

				else
				{
					prevNode = tmp;
					tmp = tmp->right;
				}
			}
			(newNode->data > prevNode->data)? prevNode->right = newNode : prevNode->left = newNode;
			}
		}

		Node* search(Node* root, int data)
		{
			if(!root)
				return nullptr;
			if(root->data == data)
				return root;
			if(data > root->data) 
				return search(root->right, data);
			else
				return search(root->left, data);
		}

		Node* remove(Node* root, int data)
		{
			if(!root)
				return nullptr;
			if(data < root->data)
				root->left = remove(root->left, data);
			else if(data > root->data)
				root->right = remove(root->right, data);

			else
			{
				if(!root->left)
				{
					Node* temp = root->right;
					delete root;
					return temp;
				}

				else if(!root->right)
				{
					Node* temp = root->left;
					delete root;
					return temp;
				}

				else
				{
					Node* succ = inorder_successor(root);
					root->data = succ->data;
					root->right = remove(root->right, succ->data);
				}
			}
				return root;
			
			

		}
		
		Node* inorder_successor(Node* curr)
		{
			Node* prev;
			
			curr = curr->right;
			while(curr)
			{
				prev = curr;
				curr = curr->left;
			}
			return prev;
		}
		void print_inorder(Node* root)
		{
			if(root)
			{
				print_inorder(root->left);
				cout<<root->data<<" ";
				print_inorder(root->right);
			}
		}
		
		Node* floor(Node* root, int data)
		{	
			/* floor of a 'x' in a bst is the largest value in bst which is just smaller than 'x'*/
			Node* res = nullptr;

			while(root)
			{
				if(data == root->data)
					res = root;
				else if(data < root->data)
				{
					root = root->left;
				}
				else
				{
					res = root;
					root = root->right;

				}
			}
			return res;
		}

		Node* ceil(Node* root, int data)
		{
			/* ceil of a 'x' in a bst is the smallest value in bst which is just greater than 'x'*/
			Node* res = nullptr;
			while(root)
			{
				if(data == root->data)
					res = root;
				else if(data > root->data)
				{
					root = root->right;
				}
				else
				{
					res = root;
					root = root->left;
				}
			}
			return res;
		}

		Node* ceil(int data)
		{
			return this->ceil(this->root, data);
		}


		Node* floor(int data)
		{
			return this->floor(this->root, data);
		}

		Node* search(int data)
		{
			return this->search(this->root, data);
		}

		void print_inorder()
		{
			return print_inorder(this->root);
		}

		bool remove(int data)
		{
			this->root = remove(this->root, data);
			return (this->root)? true:false;
		}
};

int main()
{
	string str;
	cout<<"enter elements of BST"<<endl;
	getline(cin,str);
	istringstream iss(str);
	string token;
	BST *bt = new BST(-1);
	while(iss >> token)
	{

		bt->insert(stoi(token));
	}
	bt->print_inorder();
	cout<<endl;
	cout<<"what do you want to remove?"<<endl;
	int r;
	cin>>r;
	cout<<"Enter value to find its floor"<<endl;
	int f;
	cin>>f;
	cout<<"Enter value to find its ceil"<<endl;
	int c;
	cin>>c;
	bt->remove(r);
	Node* f_val = bt->floor(f);
	Node* c_val = bt->ceil(c);
	cout<<"floor of "<<f<<"is:"<<f_val->data<<endl;
	cout<<"ceil of "<<c<<"is:"<<c_val->data<<endl;
	bt->print_inorder();
	cout<<endl;


	return 0;
}
