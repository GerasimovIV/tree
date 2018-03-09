#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    tree* Head = (tree*)malloc(sizeof(tree));
    Head->value = element;
    Head->right = NULL;
    Head->left = NULL;
    return Head;
}
void insert_into_tree (tree* Head, tree* element)
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
void small_left_rotation(tree* node_a)
{
	tree* node_b = node_a->right;
	node_a->right = node_b->left;
	node_b->left = node_a;
}
void big_left_rotation(tree* node_a)
{
	tree* node_b = node_a->right;
	tree* node_c = node_b->left;
	node_a->right = node_c->left;
	node_b->left = node_c->right;
	node_c->left = node_a;
	node_c->right = node_b;
}
void big_right_rotation(tree* node_a)
{
	tree* node_b = node_a->left;
	tree* node_c = node_b->right;
	node_a->left = node_c->right;
	node_b->right = node_c->left;
	node_c->left = node_b;
	node_c->right = node_a;
}
void small_right_rotation(tree* node_a)
{
	tree* node_b = node_a->left;
	node_a->left = node_b->right;
	node_b->right = node_a;
}
int get_hight_for_me(tree* node)
{
	if (node == NULL)
	{
		return -1;
	}
	return node->hight;
}

void balance(tree* node, tree** Head)//передаем head, head второй понадобтся позже
{
	//printf("Head:%d 1: %d\n",(*Head)->value, node->value);
	if (node->left != NULL)
	{
		//printf("Head:%d 2: %d\n",(*Head)->value, node->value);
		balance(node->left, Head);
	}
	change_hight(*Head);
	if (abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >=2 )
	{
		int t = 0;
		//printnf("%d %d", )
		if ((get_hight_for_me(node->right->left) < get_hight_for_me(node->right->right)) && (abs(get_hight_for_me(node->right)-get_hight_for_me(node->left)) >= 2) && (t != 1))
		{
			//малое левое вращение
			tree* prev = search_head_for_delete(*Head, node);
			if (prev != NULL)
			{
				//узнаем расположение prev и node
				if (prev->value <= node->value)
				{
					prev->right = node->right;
				}
				else
				{
					prev->left = node->right;
				}
				small_left_rotation(node);
				change_hight(*Head);
				t = 1;
			}
			else
			{
				*Head = node->right;
				small_left_rotation(node);
				change_hight(*Head);
				t = 1;
			}		
		}
		if ((abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->right->left) > get_hight_for_me(node->right->right)) && (t != 1))
		{
			//большое левое вращение
			tree* prev = search_head_for_delete(*Head, node);
			if (prev != NULL)
			{
				//узнаем расположение prev и node
				if (prev->value <= node->value)
				{
					prev->right = node->right->left;
				}
				else
				{
					prev->left = node->right->left;
				}
				big_left_rotation(node);
				change_hight(*Head);
				t = 1;
			}
			else
			{
				*Head = node->right->left;
				big_left_rotation(node);
				change_hight(*Head);
				t = 1;
			}		
			
		}
		if ((abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->left->right) < get_hight_for_me(node->left->left)) && (t != 1))
		{
			//малое правое вращение
			tree* prev = search_head_for_delete(*Head, node);
			if (prev != NULL)
			{
				//узнаем расположение prev и node
				if (prev->value <= node->value)
				{
					prev->right = node->left;
				}
				else
				{
					prev->left = node->left;
				}
				small_right_rotation(node);
				change_hight(*Head);
				t = 1;
			}
			else
			{
				*Head = node->left;
				small_right_rotation(node);
				change_hight(*Head);
				t = 1;
			}		
		}
		if ((abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->left->right) > get_hight_for_me(node->left->left)) && (t != 1))
		{
			//большое правое вращение
			tree* prev = search_head_for_delete(*Head, node);
			if (prev != NULL)
			{
				//узнаем расположение prev и node
				if (prev->value <= node->value)
				{
					prev->right = node->left->right;
				}
				else
				{
					prev->left = node->left->right;
				}
				big_right_rotation(node);
				change_hight(*Head);
				t = 1;
			}
			else
			{
				*Head = node->left->right;
				big_right_rotation(node);
				change_hight(*Head);
				t = 1;
			}		
		}
		change_hight(*Head);
	}
	
	if (node->right != NULL)
	{
		//printf("Head:%d 2*: %d\n",(*Head)->value, node->value);
		balance(node->right, Head);
		//printf("Head:%d 2**: %d\n",(*Head)->value, node->value);
	}
	
}
tree* balance_tree(tree* Head)
{
	tree* itog;
	tree* Head1 = Head;
	balance(Head, &Head1);
	change_hight(Head1);
	while (Head != Head1)
	{
		Head = Head1;
		balance(Head, &Head1);
		change_hight(Head1);
	}
	
	
	return Head1;
}
int main()
{
    printf("Hello world!!!!!!!!!!!!!!!\n");
	/*tree* Ivan1 = new_element_for_tree(1);
	tree* Ivan2 = new_element_for_tree(2);
	tree* Ivan3 = new_element_for_tree(3);
	tree* Ivan4 = new_element_for_tree(4);
	tree* Ivan5 = new_element_for_tree(5);
	tree* Ivan6 = new_element_for_tree(6);
	
	insert_into_tree(Ivan1, Ivan2);
	insert_into_tree(Ivan1, Ivan3);	
	insert_into_tree(Ivan1, Ivan4);
	insert_into_tree(Ivan1, Ivan5);	
	insert_into_tree(Ivan1, Ivan6);*/
	
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
	tree* Ivan66 = new_element_for_tree(6);
	tree* Ivan7 = new_element_for_tree(7);
	tree* Ivan16 = new_element_for_tree(16);
	

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
	//insert_into_tree(Ivan10, Ivan66);
	insert_into_tree(Ivan5, Ivan7);
	//insert_into_tree(Ivan10, Ivan11);
	//insert_into_tree(Ivan10, Ivan9);
	//insert_into_tree(Ivan10, Ivan66);
	//insert_into_tree(Ivan5, Ivan10);
	
    /*printf("tree:\n");
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
    //delete_element_tree(Ivan5, Ivan8);
    printf("after delete\n");*/
    //printf("1 :%d\n", Ivan5->right->right->left->left->left->value);
    //print_tree(Ivan5);
    //change_hight(Ivan5);
    //print_tree_with_hight(Ivan5);
	//small_left_rotation(Ivan8);
	//Ivan5->right = Ivan12;
	//printf("after\n");
	//Ivan5->right = Ivan12;
	//printf("hight: %d\n", get_hight_for_me(Ivan_5->left));
	//print_tree_with_hight(Ivan5);
	/*insert_into_tree(Ivan13, Ivan10);
	insert_into_tree(Ivan13, Ivan9);
	insert_into_tree(Ivan13, Ivan11);
	insert_into_tree(Ivan13, Ivan14);
	insert_into_tree(Ivan13, Ivan15);
	insert_into_tree(Ivan13, Ivan16);*/
	change_hight(Ivan5);
	print_tree_with_hight(Ivan5);
	tree* r = balance_tree(Ivan5);
	//tree* w = balance_tree(r);
	printf("after\n");
	change_hight(r);
	print_tree_with_hight(r);
	//printf("%d\n", r->right->right->left->value);



    return 0;
}

