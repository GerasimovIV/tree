#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int value;
    struct tree* left;
    struct tree* right;
} tree;

tree* search_by_value(tree* Head, int val)
{
    if (Head->value == val)
    {
        return Head;
    }
    else
        {
            if ((Head->value <= val) && (Head->right != NULL))
            {
                search_by_value(Head->right, val);
            }
            if ((Head->value > val) && (Head->left != NULL))
            {
                search_by_value(Head->left, val);
            }
        }
    return NULL;
}
tree* new_element_for_tree (int element)
{
    tree* Head = malloc(sizeof(tree));
    Head->value = element;
    Head->right = NULL;
    Head->left = NULL;
    return Head;
}
void insert_into_tree (tree* Head, tree* element)
{
    printf("in func %d\n", Head->value);
    if (Head->value <= element->value)
    {
        if (Head->right == NULL)
        {
            Head->right = element;
            Head = Head->right;
            printf("add element %d\n", Head->value);
        }
        if (Head->right != NULL)
        {
            insert_into_tree(Head->right, element);
        }
    }


    if (Head->value > element->value)
    {
        if (Head->left == NULL)
        {
            Head->left = element;
            Head = Head->left;
            printf("add element %d\n", Head->value);
        }
        if (Head->left != NULL)
        {
            insert_into_tree(Head->left, element);
        }
    }


}


void print_tree (tree* Position)
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

int main()
{
    printf("Hello world!!!!!!!!!!!!!!!\n");

    tree* Ivan5 = new_element_for_tree(5);
    tree* Ivan1 = new_element_for_tree(1);
    tree* Ivan3 = new_element_for_tree(3);
    tree* Ivan_5 = new_element_for_tree(-5);
    tree* Ivan8 = new_element_for_tree(8);
    tree* Ivan12 = new_element_for_tree(12);
    tree* Ivan4 = new_element_for_tree(4);
    tree* Ivan44 = new_element_for_tree(4);
    tree* Ivan10= new_element_for_tree(10);
    tree* Ivan9 = new_element_for_tree(9);
    tree* Ivan11 = new_element_for_tree(11);
    tree* Ivan55 = new_element_for_tree(5);

    insert_into_tree(Ivan5, Ivan1);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan3);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan_5);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan8);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan12);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan4);
    printf("1\n");
    insert_into_tree(Ivan5, Ivan10);
    insert_into_tree(Ivan5, Ivan44);
    insert_into_tree(Ivan5, Ivan9);
    insert_into_tree(Ivan5, Ivan11);
    insert_into_tree(Ivan5, Ivan55);



    printf("%d\n", Ivan5->left->right->right->value);
    printf("2 Yes\n");
    print_tree(Ivan5);
    return 0;
}
