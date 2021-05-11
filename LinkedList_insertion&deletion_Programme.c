#include <stdio.h>
#include <stdlib.h>
struct node  //to make the linked list
{
    int data;
    struct node *next;
};
int linkedlisttravers(struct node *ptr) //to trverse the linked list as well as to know the lenght of the linked list
{
    int lenght = 0; //to stoe the lenght of the linked list
    struct node *temp = ptr;
    do
    {
        lenght++;
        printf("Element is : %d\n", temp->data);
        temp = temp->next;
    } while (temp != ptr);
    return (lenght);
}
struct node *insertatfirst(struct node *head, int num) //to insert the element at first index
{
    struct node *ptr = head->next;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->next = head;
    head = new;

    return head;
}
struct node *insertatindex(struct node *head, int index, int number)//to insert the element the at a particuler index
{
    struct node *ptr = head;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = number;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    // head=new;

    return head;
}
struct node *insertatlast(struct node *head, int number)//to insert the index at the last
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = number;
    struct node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->next = head;

    return head;
}
struct node *insertatnum(struct node *head, int number, int newnumber)//to insert the element after a particular number
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = newnumber;
    struct node *ptr = head;
    while (ptr->data != number)
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;

    return head;
}
struct node *deletefirst(struct node *head) //to delete the element at first index
{
    struct node *ptr = head;
    struct node *q = head;
    // head = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = q->next;
    head = head->next;
    free(q);

    return head;
}
struct node *deltatindex(struct node *head, int index) //to delete the element the at a particuler index
{
    struct node *ptr = head;
    struct node *pev = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        pev = pev->next;
    }

    ptr->next = pev->next;
    free(pev);
    return head;
}
struct node *deletelast(struct node *head)//to delete the last element
{
    struct node *ptr = head;
    struct node *pev = head->next;
    while (pev->next != head)
    {
        ptr = ptr->next;
        pev = pev->next;
    }
    ptr->next = head;
    free(pev);

    return head;
}
struct node *delafternum(struct node *head, int number)//to delete the element after a particular number
{
    struct node *ptr = head;
    struct node *pev = head->next;
    while (ptr->data != number)
    {
        ptr = ptr->next;
        pev = pev->next;
    }
    ptr->next = pev->next;
    free(pev);

    return head;
}
int checkifpresent(int num, struct node *head)//to check if the number is present in the lined list or not
{
    int loc;
    int flag = 0;
    struct node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == num)
        {
            loc = flag;
            return (loc);
        }
        else
        {
            flag++;
        }
        temp = temp->next;
    }

    return (-1);
}
int checkforindex(struct node *head, int index)//to check if the inputed index is valid or not
{
    int ind;
    int check;
    struct node *temp = head;
    check = linkedlisttravers(head);
    if (check >= index)
    {
        ind = 1;
    }
    else
    {
        ind = -1;
    }

    return (ind);
}
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *thrid;
    struct node *forth;
    int num; //to store the number from the user which we gonna further used in insertion and deletion 
    int index; // to store the index or second number from the user
    int choise; //to store the choice of user (either for insertion or deletion)
    int secondchoice; //to store the choice of performing which particular condition
    int location; //to check the location or index if present or avaliable or not
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    thrid = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = first;
    first->data = 20;
    first->next = second;
    second->data = 60;
    second->next = thrid;
    thrid->data = 30;
    thrid->next = forth;
    forth->data = 40;
    forth->next = head;
    printf("linked list is given by\n");
    linkedlisttravers(head);
    printf("ENTER 1 TO LAND IN THE WORLD OF INSERTION IN LINKED LIST\n");
    printf("ENTER 2 TO LAND IN THE WORLD OF DELETION IN LINKED LIST\n");
    scanf("%d", &choise);
    if (choise == 1)
    {
        printf("Enter 1 to insert the number at first index\n");
        printf("Enter 2 to insert the number after a particular index\n");
        printf("Enter 3 to insert the number at last\n");
        printf("Enter 4 to insert the number after a particular number\n");
        scanf("%d", &secondchoice);
        switch (secondchoice)
        {
        case 1:
            printf("Enter the number that you wanted to insert at the begining\n");
            scanf("%d", &num);
            printf("linked list afetr inserting %d at the begining is given by\n", num);
            head = insertatfirst(head, num);
            linkedlisttravers(head);
            break;
        case 2:
            printf("Enter the number that you wanted to insert after a particular index\n");
            scanf("%d", &num);
            printf("Enter it's index\n");
            scanf("%d", &index);
            location = checkforindex(head, index);
            if (location != -1)
            {

                printf("linked list afetr inserting %d at index %d is given by\n", num, index);
                head = insertatindex(head, index, num);
                linkedlisttravers(head);
            }
            else
            {
                printf("you have entered invalid index\n");
            }

            break;
        case 3:
            printf("Enter the number that you wanted to insert at the last\n");
            scanf("%d", &num);
            printf("linked list afetr inserting %d in the end is given by\n", num);
            head = insertatlast(head, num);
            linkedlisttravers(head);
            break;
        case 4:
            printf("Enter the number that you wanted to insert after a particular number\n");
            scanf("%d", &num);
            printf("Enter the number after which you wanted to do insertion\n");
            scanf("%d", &index);
            location = checkifpresent(index, head);
            if (location != -1)
            {

                printf("linked list afetr inserting %d after %d is given by\n", num, index);
                head = insertatnum(head, index, num);
                linkedlisttravers(head);
            }
            else
            {
                printf("The number is not present in the linked list\n");
            }

            break;
        default:
            printf("YOU HAVE ENTERED INVALID CHOICE\n");
            break;
        }
    }
    else if (choise == 2)
    {
        printf("Enter 1 to delete the number at first index\n");
        printf("Enter 2 to delete the number after a particular index\n");
        printf("Enter 3 to delete the number at last\n");
        printf("Enter 4 to delete the number after a particular number\n");
        scanf("%d", &secondchoice);
        switch (secondchoice)
        {
        case 1:
            printf("linked list after deleting first element is given by\n");
            head = deletefirst(head);
            linkedlisttravers(head);
            break;
        case 2:
            printf("Enter the position on which you wanted to delete the number\n");
            scanf("%d", &index);
            location = checkforindex(head, index);
            if (location != -1)
            {

                printf("linked list afetr deleting the number at index %d is given by\n", index);
                head = deltatindex(head, index);
                linkedlisttravers(head);
            }
            else
            {
                printf("YOU HAVE ENTERED INVALID INDEX\n");
            }

            break;
        case 3:
            printf("linked list after deleting last element is given by\n");
            head = deletelast(head);
            linkedlisttravers(head);
            break;
        case 4:
            printf("Enter the number that you wanted to delete\n");
            scanf("%d", &num);
            location = checkifpresent(index, head);
            if (location != -1)
            {
                printf("linked list afetr deleting the number which is just after %d is given by\n", num);
                head = delafternum(head, num);
                linkedlisttravers(head);
            }
            else
            {
                printf("The number is not present in the linked list\n");
            }

            break;
        default:
            printf("\nYOU HAVE ENTERED INVALID OPTION\n");
            break;
        }
    }
    else
    {
        printf("\nYOU HAVE ENTERED INVALID OPTION\n");
    }

    return 0;
}