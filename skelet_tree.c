#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int value;
    int hight;
    struct tree* left;
    struct tree* right;
} tree;

tree* search_by_value(tree* Head, int val)
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
    //printf("in func %d\n", Head->value);
    if (Head->value <= element->value)
    {
        if (Head->right == NULL)
        {
            Head->right = element;
            Head = Head->right;
            //printf("add element %d\n", Head->value);
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
            //printf("add element %d\n", Head->value);
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

tree* search_head_for_delete(tree* Head, tree* el_del)
{
    tree* rezult;
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

void delete_element_tree(tree* Head, tree* el_del)
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
int get_hight(tree* node)
{
    if (node == NULL)
    {
        return 0;
    }
    if ((node->left == NULL) && (node->right == NULL))
        return 0;
    else
    {
        if (get_hight(node->right) <= get_hight(node->left))
        {
            return  get_hight(node->left) + 1;
        }
        if (get_hight(node->right) > get_hight(node->left))
        {
            return get_hight(node->right) + 1;
        }
    }
}
void print_tree_with_hight (tree* Position)
{
    if (Position->left != NULL)
    {
        print_tree_with_hight(Position->left);
    }
    printf("node: %d hight: %d \n", Position->value, Position->hight);
    if (Position->right != NULL)
    {
        print_tree_with_hight(Position->right);
    }
}
void change_hight(tree* Position)
{
    if (Position->left != NULL)
    {
        change_hight(Position->left);
    }
    Position->hight = get_hight(Position);
    if (Position->right != NULL)
    {
        change_hight(Position->right);
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
    tree* Ivan13 = new_element_for_tree(13);
    tree* Ivan14 = new_element_for_tree(14);
    tree* Ivan15 = new_element_for_tree(15);

    insert_into_tree(Ivan5, Ivan1);
    insert_into_tree(Ivan5, Ivan3);
    insert_into_tree(Ivan5, Ivan_5);
    insert_into_tree(Ivan5, Ivan8);
    insert_into_tree(Ivan5, Ivan12);
    insert_into_tree(Ivan5, Ivan4);
    insert_into_tree(Ivan5, Ivan10);
    //insert_into_tree(Ivan5, Ivan44);
    insert_into_tree(Ivan5, Ivan9);
    insert_into_tree(Ivan5, Ivan11);
    //insert_into_tree(Ivan5, Ivan55);
    insert_into_tree(Ivan5, Ivan13);
    insert_into_tree(Ivan5, Ivan14);
    insert_into_tree(Ivan5, Ivan15);
    printf("tree:\n");
    print_tree(Ivan5);

    tree* for_find = NULL;
    for_find = search_by_value(Ivan5, 12);
    if (for_find == NULL)
    {
        printf("Not found\n");
    }
    else{ printf("found: %d\n", for_find->value);}
    tree* s = NULL;
    s = search_head_for_delete(Ivan5, Ivan8);
    if (s == NULL)
    {
        printf("Not found *\n");
    }
    else{ printf("found*: %d\n", s->value);}
    delete_element_tree(Ivan5, Ivan8);
    printf("after delete\n");
    //printf("1 :%d\n", Ivan5->right->right->left->right->value);
    //print_tree(Ivan5);
    change_hight(Ivan5);
    print_tree_with_hight(Ivan5);




    return 0;
}

