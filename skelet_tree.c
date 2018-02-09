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
    printf("Hello");
    tree* Head = malloc(sizeof(tree));
    Head->value = element;
    Head->right = NULL;
    Head->left = NULL;
    return Head;
}
void insert_into_tree (tree* Derevo, tree* element)
{
    if ((Derevo->left == NULL) && (Derevo->value > element->value))
    {
        Derevo->left = element;
        return 0;
    }
    if ((Derevo->right == NULL) && (Derevo->value <= element->value))
    {
        Derevo->right = element;
        return 0;
    }
    if ((Derevo->right != NULL) && (Derevo->value <= element->value))
    {
        insert_into_tree(Derevo->right, element);
    }
    if ((Derevo->left == NULL) && (Derevo->value > element->value))
    {
        insert_into_tree(Derevo->left, element);
    }
}


void print_tree (tree* Derevo)
{
    print_tree(Derevo->left);
    printf("%d\n", Derevo->value);
    print_tree(Derevo->right);
}

int main()
{
    printf("Hello world!!!!!!!!!!!!!!!\n");
    printf("Hello");

    tree* Ivan5 = new_element_for_tree(5);
    printf("Hello");
    tree* Ivan1 = new_element_for_tree(1);
    tree* Ivan3 = new_element_for_tree(3);
    tree* Ivan_5 = new_element_for_tree(-5);
    tree* Ivan8 = new_element_for_tree(8);
    tree* Ivan12 = new_element_for_tree(12);
    tree* Ivan4 = new_element_for_tree(4);

    insert_into_tree(Ivan5, Ivan1);
    insert_into_tree(Ivan5, Ivan3);
    /*
    insert_into_tree(Ivan5, Ivan_5);
    insert_into_tree(Ivan5, Ivan8);
    insert_into_tree(Ivan5, Ivan12);
    insert_into_tree(Ivan5, Ivan4);
    */
    //print_tree(Ivan5);
    return 0;
}
