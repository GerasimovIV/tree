#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

// Интерфейс
class Container
{
public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};

Container::~Container() { }

// Реализация интерфейса

typedef struct tree {
    int value;
    int hight;
    struct tree* left;
    struct tree* right;
} tree;


class SimpleTree: public Container
{
public:
    SimpleTree();
    ~SimpleTree();
    void insert(int value);
    bool exists(int value);
    void remove(int value);
    void print();

protected:
    tree* create(int i);
    tree* find(int i);
    tree* root;
    void insert_into_tree(tree* Head, tree* element);
    tree* search_by_value(tree* Head, int val);
    void delete_element_tree(tree* Head, tree* el_del);
    void delete_struckt(tree* Head);
    tree* search_head_for_delete(tree* Head, tree* el_del);
    void print_tree(tree* Head);
};

SimpleTree::SimpleTree()
{
    this->root = NULL;
}

void SimpleTree::delete_struckt(tree* Position)
{
    if (Position->left != NULL)
    {
        delete_struckt(Position->left);
    }
    free(Position);
    if (Position->right != NULL)
    {
        delete_struckt(Position->right);
    }
}
SimpleTree::~SimpleTree()
{
    delete_struckt(this->root);
}


tree* SimpleTree::create(int value)
{
    tree* Head = (tree*)malloc(sizeof(tree));
    Head->value = value;
    Head->right = NULL;
    Head->left = NULL;
    return Head;
}

void SimpleTree::insert_into_tree(tree* Head, tree* element)
{
	int t = 0;
    //printf("in func %d\n", Head->value);
    if (Head->value <= element->value)
    {
		t = 0;
        if (Head->right == NULL)
        {
            Head->right = element;
            Head = Head->right;
			t = 1;
            //printf("add element %d\n", Head->value);
        }
        if ((Head->right != NULL)&&(t != 1))
        {
            insert_into_tree(Head->right, element);
        }
    }


    if (Head->value > element->value)
    {
		t = 0;
        if (Head->left == NULL)
        {
            Head->left = element;
            Head = Head->left;
			t = 1;
            //printf("add element %d\n", Head->value);
        }
        if ((Head->left != NULL)&&(t != 1))
        {
            insert_into_tree(Head->left, element);
        }
    }


}

void SimpleTree::insert(int value)
{
    tree* element = this->create(value);
    if (this->root == NULL)
    {
        this->root = element;
    }
    else
    {
        insert_into_tree(this->root, element);
    }
}

tree* SimpleTree::search_by_value(tree* Head, int val)
{
    tree* rezult;
    if (Head->value == val)
    {
        return Head;
    }
    if (Head->value < val)
    {
        if (Head->right == NULL)
        {
            return NULL;
        }
        if (Head->right != NULL)
        {
            rezult = search_by_value(Head->right, val);
        }
    }


    if (Head->value > val)
    {
        if (Head->left == NULL)
        {
            return NULL;
        }
        if (Head->left != NULL)
        {
            rezult = search_by_value(Head->left, val);
        }
    }
    return rezult;
}

tree* SimpleTree::find(int value)
{
    return search_by_value(this->root, value);
}

bool SimpleTree::exists(int value)
{
    tree* el_for_find = this->find(value);
    return el_for_find != NULL;

}


void SimpleTree::remove(int value)
{
    tree* el_del = this->find(value);
    if (el_del != NULL)
    {
        delete_element_tree(this->root, el_del);
    }

}


tree* SimpleTree::search_head_for_delete(tree* Head, tree* el_del)
{
    tree* rezult = NULL;
    if (Head->left == el_del)
    {
        return Head;
    }

    if (Head->right == el_del)
    {
        return Head;
    }
    if (Head->value <= el_del->value)
    {
        if (Head->right == NULL)
        {
            return NULL;
        }
        if (Head->right != NULL)
        {
            rezult = search_head_for_delete(Head->right, el_del);
        }
    }


    if (Head->value > el_del->value)
    {
        if (Head->left == NULL)
        {
            return NULL;
        }
        if (Head->left != NULL)
        {
            rezult = search_head_for_delete(Head->left, el_del);
        }
    }
    return rezult;
}

void SimpleTree::delete_element_tree(tree* Head, tree* el_del)
{

    /*if (Head == el_del)
    {
        tree* t = new_element_for_tree(2);
        t->value = Head->value;
        t->
        insert_into_tree(t, Head->right);
        printf("Now %d is head element\n", t->value);
        free(Head);
    }
    else
    {*/
        tree* s;
        s = search_head_for_delete(Head, el_del);
        if ((el_del->left == NULL) && (el_del->right == NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = NULL;
            }
            else
            {
                s->left = NULL;
            }
            free(el_del);
        }
        if ((el_del->right == NULL) && (el_del->left != NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->left;
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->left;
            }
            free(el_del);
        }
        if ((el_del->right != NULL) && (el_del->left == NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->right;
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->right;
            }
            free(el_del);
        }
        if ((el_del->right != NULL) && (el_del->left != NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->left;
                insert_into_tree(s->right, el_del->right);
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->left;
                insert_into_tree(s->left, el_del->right);
            }
            free(el_del);
        }
    //}
}

void SimpleTree::print()
{
    print_tree(this->root);
}
void SimpleTree::print_tree(tree* Position)
{
    if (Position->left != NULL)
    {
        print_tree(Position->left);
    }
    printf("%d\n", Position->value);
    if (Position->right != NULL)
    {
        print_tree(Position->right);
    }
}
// TODO

int main()
{
    Container* c = new SimpleTree();

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "Tree after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}
