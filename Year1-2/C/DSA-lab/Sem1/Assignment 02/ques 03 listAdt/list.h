#define MAX 4 // Macro defines maximum no. of elements in the list. It is a user defined data type

struct
{
    int list[MAX];
    int element;     //new element to be inserted
    int pos;           //position of the element to be inserted or deleted
    int length;     //total no of elements
}l;
enum boolean
{
    true, false
};
typedef enum boolean boolean;        //function prototypes

int menu(void);           //This function displays the list of operations
void create(void);       //This function creates initial set of elements
void insert(int, int);    //This function inserts the element at specified position
void delet(int);       //This function deletes the element at given position
void find(int);        //This function finds the position of the given element, if exists
void display(void);       //This function displays the elements in the list
boolean islistfull(void);  //This function checks whether the list is full or not boolean
boolean islistempty(void);        //This function checks whether the list is empty or not

void create(void)
{
    int element;
    int flag=1;
    while(flag==1)
    {
        printf("Enter element : ");
        scanf("%d", &element);
        l.list[l.length] = element;
        l.length++;
        printf("To insert another element press '1' : ");
        scanf("%d", &flag);
    }
}
void display(void)
{
    int i;
    for (i=0; i<l.length; i++)
        printf("Element %d : %d \n", i+1, l.list[i]);
    printf("Press any key to continue...");
    getch();
}
void insert(int element, int pos)
{
    int i;
    if (pos == 0)
    {
        printf("\nCannot insert an element at 0th position");
        getch();
        return;
    }

    if (pos-1 > l.length)
    {
        printf("\nOnly %d elements exit. Cannot insert at %d position", l.length, pos);
        printf("\n Press any key to continue...");
        getch();
    }
    else
    {
        for (i=l.length; i>=pos-1; i--)
        {
            l.list[i+1] = l.list[i];
        }
        l.list[pos-1] = element;
        l.length++;
    }
}
void delet(int pos)
{
    int i;
    if(pos == 0)
    {
        printf("\nCannot delete at an element 0th position");
        getch();
        return;
    }
    if (pos > l.length)
    {
        printf("\n\n Only %d elements exit. Cannot delete", l.length, pos);
        printf("\n Press any key to continue...");
        getch();
        return;
    }
    for (i=pos-1; i<l.length; i++)
    {
        l.list[i] = l.list[i+1];
    }
    l.length--;
}

void find(int element)
{
    int i;

    for (i=0; i<l.length; i++)
    {
        if(l.list[i] == element)
        {
            printf ("%d exists at %d position",element, i+1);
            flag = 0;
            printf("\n Press any key to continue...");
            getch();
            break;
        }
    }
}
boolean islistfull(void)
{
    if (l.length == MAX)
        return true;
    else
        return false;
}
boolean islistempty(void)
{
    if (l.length == 0)
        return true;
    else
        return false;
}
