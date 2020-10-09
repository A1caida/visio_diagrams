#include <iostream>
#include <ctime>

using namespace std;

struct node
{
	int element;
	node* left;
	node* right;
	int height;
};

typedef struct node* nodeptr;


int max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
int bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr srl(nodeptr& p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left), p1->height) + 1;
	return p2;
}
nodeptr srr(nodeptr& p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(p1->height, bsheight(p2->right)) + 1;
	return p2;
}
nodeptr drl(nodeptr& p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}
nodeptr drr(nodeptr& p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int nonodes(nodeptr p)
{
	int count = 0;
	if (p != NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;
}

void insert(int x, nodeptr& p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
		{
			cout << "Out of Space\n" << endl;
		}
	}
	else
	{
		if (x < p->element)
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2)
			{
				if (x < p->left->element)
				{
					p = srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x > p->element)
		{
			insert(x, p->right);
			if ((bsheight(p->right) - bsheight(p->left)) == 2)
			{
				if (x > p->right->element)
				{
					p = srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			cout << "Элемет существует\n" << endl;
		}
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = max(m, n);
	p->height = d + 1;
}
// Finding the Smallest
nodeptr findmin(nodeptr p)
{
	if (p == NULL)
	{
		cout << "В дереве нет элементов\n" << endl;
		return p;
	}
	else
	{
		while (p->left != NULL)
		{
			p = p->left;
			//return p;
		}
		return p;
	}
}
// Finding the Largest node
nodeptr findmax(nodeptr p)
{
	if (p == NULL)
	{
		cout << "В дереве нет элементов\n" << endl;
		return p;
	}
	else
	{
		while (p->right != NULL)
		{
			p = p->right;
			//return p;
		}
		return p;
	}
}
// Finding an element
void find(int x, nodeptr& p)
{
	if (p == NULL)
	{
		cout << "Простите, но такого элемента нет\n" << endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x, p->left);
		}
		else
		{
			if (x > p->element)
			{
				find(x, p->right);
			}
			else
			{
				cout << "Элемент, который вы искали есть в дереве!\n" << endl;
			}
		}
	}
}

void makeempty(nodeptr& p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d = p;
		free(d);
		p = NULL;
	}
}
nodeptr nodecopy(nodeptr& p)
{
	nodeptr temp;
	if (p == NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}
void copy(nodeptr& p, nodeptr& p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}



int deletemin(nodeptr& p)
{
	int c;
	cout << "Выбрано удаление минимального значения\n" << endl;
	if (p->left == NULL)
	{
		c = p->element;
		p = p->right;
		return c;
	}
	else
	{
		c = deletemin(p->left);
		return c;
	}
}

void del(int x, nodeptr& p)
{
	nodeptr d;
	if (p == NULL)
	{
		cout << "Простите, но такого элемента нет\n" << endl;
	}
	else if (x < p->element)
	{
		del(x, p->left);
	}
	else if (x > p->element)
	{
		del(x, p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d = p;
		free(d);
		p = NULL;
		cout << "Элемент удален\n" << endl;
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		cout << "Элемент удален\n" << endl;
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		cout << "Элемент удален\n" << endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}


void preorder(nodeptr p)
{
	if (p != NULL)
	{
		cout << p->element << "\t";
		preorder(p->left);
		preorder(p->right);
	}
}

// Inorder Printing
void inorder(nodeptr p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->element << "\t";
		inorder(p->right);
	}
}

// PostOrder Printing
void postorder(nodeptr p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->element << "\t";
	}
}





void print_Tree(nodeptr node, int level)
{
	if (node)
	{
		print_Tree(node->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->element << endl;
		print_Tree(node->right, level + 1);
	}
}

int main()
{

	nodeptr root, root1, min, max;//,flag;
	int a, choice, findele, delele;
	char ch = 'y';
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	//system("clear");
	root = NULL;
	root1 = NULL;

	do
	{

		cout << "1 Вставить новый узел" << endl;
		cout << "2 Найти минимальный элемент" << endl;
		cout << "3 Найти максимальный элемент" << endl;
		cout << "4 Поиск по значению" << endl;
		cout << "5 Удалить элемент" << endl;
		cout << "6 Вариант обхода1" << endl;
		cout << "7 Вариант обхода2" << endl;
		cout << "8 Вариант обхода3" << endl;
		cout << "9 Показать высоту дерева" << endl;
		cout << "0 Выход" << endl;


		cout << "\nВыберите нужное действие и нажмите Enter: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			for (size_t i = 1; i < 9; i++)
			{
				srand(time(0) / i);
				a = rand() % 20 + 1;
				insert(a, root);
			}

			cout << "\nНовый элемент добавлен успешно\n" << endl;
			break;
		case 2:
			if (root != NULL)
			{
				min = findmin(root);
				cout << "\nМинимальный элемент в дереве: " << min->element << endl;
			}
			break;
		case 3:
			if (root != NULL)
			{
				max = findmax(root);
				cout << "\nМаксимальный элемент в дереве: " << max->element << endl;
			}
			break;
		case 4:
			cout << "\nВведите искомый элемент: ";
			cin >> findele;
			if (root != NULL)
			{
				find(findele, root);
			}
			break;
		case 5:
			cout << "\nКакой узел удалять? : ";
			cin >> delele;
			del(delele, root);
			inorder(root);
			cout << endl;
			break;
		case 6:
			cout << "\n\t\tВариант обхода1" << endl;
			preorder(root);
			cout << endl;
			break;
		case 7:
			cout << "\n\t\tВариант обхода2" << endl;
			inorder(root);
			cout << endl;
			break;
		case 8:
			cout << "\n\t\tВарант обхода3" << endl;
			postorder(root);
			cout << endl;
			break;
		case 9:
			cout << "TДерево имеет высоту: " << bsheight(root) << endl;

			break;
		case 10:
			inorder(root);

			break;
		case 11:
			print_Tree(root, a);

			break;

		default:
			cout << "Sorry! wrong input\n" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 0);
	return 0;
}
