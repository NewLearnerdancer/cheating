#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int stack[100], i, j, choice = 0, n, top = -1;
void push();
void pop();
void show();
void p1()
{
    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    printf("Stack operations using array");

    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}

void push()
{
    int val;
    if (top == n)
        printf("\n Overflow");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Underflow");
    else
        top = top - 1;
}
void show()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}

int linearSearch(int a[], int n, int val)
{
    // Going through array sequencially
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
            return i + 1;
    }
    return -1;
}
int p2()
{
    int a[] = {70, 40, 30, 11, 57, 41, 25, 14, 52}; // given array
    int val = 41;                                   // value to be searched
    int n = sizeof(a) / sizeof(a[0]);               // size of array
    int res = linearSearch(a, n, val);              // Store result
    printf("The elements of the array are - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nElement to be searched is - %d", val);
    if (res == -1)
    {
        printf("\nElement is not present in the array");
    }
    else
    {
        printf("\nElement is present at %d position of array", res);
    }

    return 0;
}
void p3()
{
    char a[5][10], val[10];
    int i, n = 5;
    printf("enter 5 elements");
    for (i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
    }
    printf("enter element to find");
    scanf("%s", &val);
    for (i = 0; i < n; i++)
    {
        if (strcmp(a[i], val) == 0)
        {
            printf("position of value is %d", i + 1);
            break;
        }
    }
    if (i == n)
    {
        printf("not found");
    }
}

void p4()
{
    int a[] = {11, 12, 14, 25, 27, 30, 40, 41, 45, 52, 57, 60, 70, 75, 90};
    int val = 70;
    int n = sizeof(a) / sizeof(a[0]);
    printf("The elements of the array are - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nElement to be searched is - %d", val);
    binary_Search4(a, 0, n - 1, val);
}

int binary_Search4(char *a[], int low, int high, char val[])
{
    int mid;
    if (high >= low)
    {
        mid = (low + high) / 2;

        if (strcmp(a[mid], val) == 0)
        {
            return mid + 1;
        }

        else if (strcmp(a[mid], val) < 0)
        {
            return binary_Search4(a, mid + 1, high, val);
        }

        else
        {
            return binary_Search4(a, low, mid - 1, val);
        }
    }
    return -1;
}
void p5()
{
    char *a[5] = {"co", "ej", "me", "ce", "ch"};
    char val[20] = "ej";
    int n = 5;
    int res = binary_Search4(a, 0, n - 1, val);
    printf("The elements of the array are - ");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", a[i]);
    }
    printf("\nElement to be searched is %s ", val);
    if (res == -1)
    {
        printf("\nElement is not present in the array");
    }
    else
    {
        printf("\nElement is present at%d  ", res);
    }
}

void print(int a[], int n) // function to print array elements
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int bubble(int a[], int n) // function to implement bubble sort
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void p6()
{
    int i, j, temp;
    int a[15], n; //= sizeof(a)/sizeof(a[0]);
    printf("enter size and elements");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    print(a, n);
    bubble(a, n);
    printf("\nAfter sorting array elements are - \n");
    print(a, n);
}

void printstring(char a[][20], int n) // function to print array elements
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s ", a[i]);
    }
}

int bubblestring(char a[][20], int n) // function to implement bubble sort
{
    int i, j;
    char temp[20];
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }
}

void p7()
{
    int i, n;
    char a[15][20];
    printf("Enter size and elements: ");
    scanf("%d", &n);
    getchar(); // Consume newline character
    for (i = 0; i < n; i++)
    {
        fgets(a[i], 20, stdin);
        a[i][strcspn(a[i], "\n")] = 0; // Remove newline character
    }
    printf("Before sorting array elements are - \n");
    printstring(a, n);
    bubblestring(a, n);
    printf("\nAfter sorting array elements are - \n");
    printstring(a, n);
}

void selection(int arr[], int n)
{
    int i, j, small;

    for (i = 0; i < n - 1; i++) // One by one move boundary of unsorted subarray
    {
        small = i; // minimum element in unsorted array

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[small])
                small = j;
        // Swap the minimum element with the first element
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int a[], int n) /* function to print the array */
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void p8()
{
    int a[20], n; //= sizeof(a) / sizeof(a[0]);
    printf("enter size and elements");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printArr(a, n);
    selection(a, n);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, n);
}

void selectionstring(char arr[][20], int n)
{
    int i, j, small;

    for (i = 0; i < n - 1; i++) // One by one move boundary of unsorted subarray
    {
        small = i; // minimum element in unsorted array

        for (j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[small]) < 0)
                small = j;
        // Swap the minimum element w11ith the first element
        char temp[20];
        strcpy(temp, arr[small]);
        strcpy(arr[small], arr[i]);
        strcpy(arr[i], temp);
    }
}

void p9()
{
    char a[20][20];
    int n; //= sizeof(a) / sizeof(a[0]);
    printf("enter size and elements");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printstring(a, n);
    selectionstring(a, n);
    printf("\nAfter sorting array elements are - \n");
    printstring(a, n);
}

void insert(int a[], int n) /* function to sort an aay with insertion sort */
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && temp <= a[j]; j--) /* Move the elements greater than temp to one position ahead from their current position*/
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}
void p10()
{
    int a[10], n; //= sizeof(a) / sizeof(a[0]);
    printf("enter size and elements");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printArr(a, n);
    insert(a, n);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, n);
}

void insertstring(char a[][20], int n) /* function to sort an aay with insertion sort */
{
    int i, j;
    char temp[20];
    for (i = 1; i < n; i++)
    {
        strcpy(temp, a[i]);
        for (j = i - 1; j >= 0 && strcmp(temp, a[j]) > 0; j--) /* Move the elements greater than temp to one position ahead from their current position*/
        {
            strcpy(a[j + 1], a[j]);
        }
        strcpy(a[j + 1], temp);
    }
}
void p11()
{
    char a[20][20];
    int n; // = sizeof(a) / sizeof(a[0]);
    printf("enter size and elements");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printstring(a, n);
    insertstring(a, n);
    printf("\nAfter sorting array elements are - \n");
    printstring(a, n);
}

int stack12[100], i, j, n, top;

void push12()
{
    int val;
    if (top == n)
        printf("\n Overflow");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top += 1;
        stack[top] = val;
    }
}

void pop12()
{
    top = -1;
    if (top == -1)
        printf("Underflow");
    else
        top = top - 1;
}
void show12()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}

void p12()
{
    int choice;
    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    printf("Stack operations using array");

    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push12();
            break;
        }
        case 2:
        {
            pop12();
            break;
        }
        case 3:
        {
            show12();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}

/* stack using linked list */

struct node13
{
    int val;
    struct node13 *next;
};
struct node13 *head = NULL;

void push13(int value)
{
    struct node13 *ptr = malloc(sizeof(struct node13));
    if (ptr == NULL)
    {
        printf("Not able to push the element");
    }
    else
    {
        ptr->val = value;
        ptr->next = head;
        head = ptr;
        printf("\nItem pushed %d", ptr->val);
    }
}

void pop13()
{
    int item;
    struct node13 *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        ptr = head;
        item = ptr->val;
        head = ptr->next;
        free(ptr);
        printf("\nItem popped %d", item);
    }
}

void display13()
{
    struct node13 *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\nPrinting Stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}

void p13()
{
    push13(67);
    push13(45);
    push13(98);
    push13(14);
    pop13();
    display13();
}

struct node
{
    int data;
    struct node *next;
};
struct node *front14;
struct node *rear14;

void insert14()
{
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (front14 == NULL)
        {
            front14 = ptr;
            rear14 = ptr;
            front14->next = NULL;
            rear14->next = NULL;
        }
        else
        {
            rear14->next = ptr;
            rear14 = ptr;
            rear14->next = NULL;
        }
    }
}
void delete14()
{
    struct node *ptr;
    if (front14 == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front14;
        front14 = front14->next;
        free(ptr);
    }
}
void display14()
{
    struct node *ptr;
    ptr = front14;
    if (front14 == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void p14()
{
    int choice;
    while (choice != 4)
    {
        printf("\n**Main Menu\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert14();
            break;
        case 2:
            delete14();
            break;
        case 3:
            display14();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}

/* linear queue by linked list*/

struct node15
{
    int data15;
    struct node15 *next15;
};
struct node15 *front15;
struct node15 *rear15;

void insert15()
{
    struct node15 *ptr15;
    int item;

    ptr15 = (struct node15 *)malloc(sizeof(struct node15));
    if (ptr15 == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr15->data15 = item;
        if (front15 == NULL)
        {
            front15 = ptr15;
            rear15 = ptr15;
            front15->next15 = NULL;
            rear15->next15 = NULL;
        }
        else
        {
            rear15->next15 = ptr15;
            rear15 = ptr15;
            rear15->next15 = NULL;
        }
    }
}
void delete15()
{
    struct node15 *ptr15;
    if (front15 == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr15 = front15;
        front15 = front15->next15;
        free(ptr15);
    }
}
void display15()
{
    struct node15 *ptr15;
    ptr15 = front15;
    if (front15 == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        while (ptr15 != NULL)
        {
            printf("\n%d\n", ptr15->data15);
            ptr15 = ptr15->next15;
        }
    }
}

void p15()
{
    int choice;
    while (choice != 4)
    {
        printf("\n**Main Menu\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert15();
            break;
        case 2:
            delete15();
            break;
        case 3:
            display15();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}

// circular queue using linked list

struct node16
{
    int data16;
    struct node16 *next16;
};
struct node16 *front16;
struct node16 *rear16;

void enqueue16()
{
    struct node16 *ptr16;
    int item;
    ptr16 = (struct node16 *)malloc(sizeof(struct node16));
    if (ptr16 == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\n enter value?\n");
        scanf("%d", &item);
        ptr16->data16 = item;
        if (front16 == NULL)
        {
            front16 = rear16 = ptr16;
            rear16->next16 = front16;
        }
        else
        {
            rear16->next16 = ptr16;
            rear16 = ptr16;
            rear16->next16 = front16;
        }
    }
}
void dequeue16()
{
    struct node16 *ptr16;
    if (front16 == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr16 = front16;
        front16 = front16->next16;
        free(ptr16);
        rear16->next16 = front16;
    }
}
void display16()
{
    struct node16 *ptr16;
    ptr16 = front16;
    if (front16 == NULL)
    {
        printf("\nempty queue\n");
    }
    else
    {
        printf("\nprinting values.....\n");
        while (ptr16->next16 != front16)
        {
            printf("\n%d\n", ptr16->data16);
            ptr16 = ptr16->next16;
        }
        printf("\n%d\n", ptr16->data16);
    }
}

void p16()
{
    enqueue16();
    enqueue16();
    enqueue16();
    enqueue16();
    display16();
    dequeue16();
    display16();
}

// circular queue using linked list

struct node17
{
    int data17;
    struct node17 *next17;
};
struct node17 *front17;
struct node17 *rear17;

void enqueue17()
{
    struct node17 *ptr17;
    int item;
    ptr17 = malloc(sizeof(struct node17));
    if (ptr17 == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\n enter value?\n");
        scanf("%d", &item);
        ptr17->data17 = item;
        if (front17 == NULL)
        {
            front17 = rear17 = ptr17;
            rear17->next17 = front17;
        }
        else
        {
            rear17->next17 = ptr17;
            rear17 = ptr17;
            rear17->next17 = front17;
        }
    }
}
void dequeue17()
{
    struct node17 *ptr17;
    if (front17 == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr17 = front17;
        front17 = front17->next17;
        free(ptr17);
        rear17->next17 = front17;
    }
}
void display17()
{
    struct node17 *ptr17;
    ptr17 = front17;
    if (front17 == NULL)
    {
        printf("\nempty queue\n");
    }
    else
    {
        printf("\nprinting values.....\n");
        while (ptr17->next17 != front17)
        {
            printf("\n%d\n", ptr17->data17);
            ptr17 = ptr17->next17;
        }
        printf("\n%d\n", ptr17->data17);
    }
}

void p17()
{
    enqueue17();
    enqueue17();
    enqueue17();
    enqueue17();
    display17();
    dequeue17();
    display17();
}

/*all operations on singly linked list*/
struct node18
{
    int data18;
    struct node18 *next18;
};
struct node18 *head18;

void beginsert18()
{
    struct node18 *ptr;
    int item;
    ptr = (struct node18 *)malloc(sizeof(struct node18 *));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &item);
        ptr->data18 = item;
        ptr->next18 = head18;
        head18 = ptr;
        printf("\nNode inserted");
    }
}
void lastinsert18()
{
    struct node18 *ptr, *temp;
    int item;
    ptr = (struct node18 *)malloc(sizeof(struct node18));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data18 = item;
        if (head18 == NULL)
        {
            ptr->next18 = NULL;
            head18 = ptr;
            printf("\nnode18 inserted");
        }
        else
        {
            temp = head18;
            while (temp->next18 != NULL)
            {
                temp = temp->next18;
            }
            temp->next18 = ptr;
            ptr->next18 = NULL;
            printf("\nnode18 inserted");
        }
    }
}
void randominsert18()
{
    int i, loc, item;
    struct node18 *ptr, *temp;
    ptr = (struct node18 *)malloc(sizeof(struct node18));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr->data18 = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d", &loc);
        temp = head18;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next18;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next18 = temp->next18;
        temp->next18 = ptr;
        printf("\nNode inserted");
    }
}
void begin_delete18()
{
    struct node18 *ptr;
    if (head18 == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head18;
        head18 = ptr->next18;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void last_delete18()
{
    struct node18 *ptr, *ptr1;
    if (head18 == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head18->next18 == NULL)
    {
        head18 = NULL;
        free(head18);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head18;
        while (ptr->next18 != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next18;
        }
        ptr1->next18 = NULL;
        free(ptr);
        printf("\nDeleted node18 from the last ...\n");
    }
}
void random_delete18()
{
    struct node18 *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node18 after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head18;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next18;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next18 = ptr->next18;
    free(ptr);
    printf("\nDeleted node18 %d ", loc + 1);
}
void search18()
{
    struct node18 *ptr;
    int item, i = 0, flag;
    ptr = head18;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data18 == item)
            {
                printf("item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next18;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}

void display18()
{
    struct node18 *ptr;
    ptr = head18;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data18);
            ptr = ptr->next18;
        }
    }
}
void p18()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n**Main Menu\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert18();
            break;
        case 2:
            lastinsert18();
            break;
        case 3:
            randominsert18();
            break;
        case 4:
            begin_delete18();
            break;
        case 5:
            last_delete18();
            break;
        case 6:
            random_delete18();
            break;
        case 7:
            search18();
            break;
        case 8:
            display18();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

// create copy of linked list

struct node20
{
    int data20;
    struct node20 *next20;
};
void lastinsert20(struct node20 **head20)
{
    struct node20 *ptr, *temp;
    int item;
    ptr = malloc(sizeof(struct node20));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data20 = item;
        if (*head20 == NULL)
        {
            ptr->next20 = NULL;
            *head20 = ptr;
            printf("\nnode20 inserted");
        }
        else
        {
            temp = *head20;
            while (temp->next20 != NULL)
            {
                temp = temp->next20;
            }
            temp->next20 = ptr;
            ptr->next20 = NULL;
            printf("\nnode20 inserted");
        }
    }
}

void print20(struct node20 *head20)
{
    printf("%d    ", head20->data20);

    if (head20->next20 == NULL)
    {

        return;
    }

    print20(head20->next20);
}

struct node20 *copyList(struct node20 *head20)
{
    if (head20 == NULL)
    {
        return NULL;
    }
    else
    {
        struct node20 *newnode20 = (struct node20 *)malloc(
            sizeof(struct node20));

        newnode20->data20 = head20->data20;
        newnode20->next20 = copyList(head20->next20);

        return newnode20;
    }
    printf("list copy");
}

void p20()
{
    struct node20 *head20 = NULL;
    lastinsert20(&head20);
    lastinsert20(&head20);
    lastinsert20(&head20);
    lastinsert20(&head20);
    printf("\n Value in linked list  : ");
    print20(head20);

    struct node20 *dup = copyList(head20);
    printf("\n Value in duplicate linked list  : ");
    print20(dup);
}

// performing  all operations on Circular Linked List
// Node structure for Circular Linked List
struct node21
{
    int data21;
    struct node21 *next21;
};
struct node21 *head21;

void beginsert21()
{
    struct node21 *ptr21, *temp21;
    int item21;
    ptr21 = (struct node21 *)malloc(sizeof(struct node21));
    if (ptr21 == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the node data?");
        scanf("%d", &item21);
        ptr21->data21 = item21;
        if (head21 == NULL)
        {
            head21 = ptr21;
            ptr21->next21 = head21;
        }
        else
        {
            temp21 = head21;
            while (temp21->next21 != head21)
                temp21 = temp21->next21;
            ptr21->next21 = head21;
            temp21->next21 = ptr21;
            head21 = ptr21;
        }
        printf("\nnode inserted\n");
    }
}
void lastinsert21()
{
    struct node21 *ptr21, *temp21;
    int item21;
    ptr21 = (struct node21 *)malloc(sizeof(struct node21));
    if (ptr21 == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data?");
        scanf("%d", &item21);
        ptr21->data21 = item21;
        if (head21 == NULL)
        {
            head21 = ptr21;
            ptr21->next21 = head21;
        }
        else
        {
            temp21 = head21;
            while (temp21->next21 != head21)
            {
                temp21 = temp21->next21;
            }
            temp21->next21 = ptr21;
            ptr21->next21 = head21;
        }

        printf("\nnode inserted\n");
    }
}

void begin_delete21()
{
    struct node21 *ptr21;
    if (head21 == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head21->next21 == head21)
    {
        head21 = NULL;
        free(head21);
        printf("\nnode deleted\n");
    }

    else
    {
        ptr21 = head21;
        while (ptr21->next21 != head21)
            ptr21 = ptr21->next21;
        ptr21->next21 = head21->next21;
        free(head21);
        head21 = ptr21->next21;
        printf("\nnode deleted\n");
    }
}
void last_delete21()
{
    struct node21 *ptr21, *preptr21;
    if (head21 == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head21->next21 == head21)
    {
        head21 = NULL;
        free(head21);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr21 = head21;
        while (ptr21->next21 != head21)
        {
            preptr21 = ptr21;
            ptr21 = ptr21->next21;
        }
        preptr21->next21 = ptr21->next21;
        free(ptr21);
        printf("\nnode deleted\n");
    }
}

void search21()
{
    struct node21 *ptr21;
    int item21, i21 = 0, flag21 = 1;
    ptr21 = head21;
    if (ptr21 == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item21);
        if (head21->data21 == item21)
        {
            printf("item found at location %d", i21 + 1);
            flag21 = 0;
        }
        else
        {
            while (ptr21->next21 != head21)
            {
                if (ptr21->data21 == item21)
                {
                    printf("item found at location %d ", i21 + 1);
                    flag21 = 0;
                    break;
                }
                else
                {
                    flag21 = 1;
                }
                i21++;
                ptr21 = ptr21->next21;
            }
        }
        if (flag21 != 0)
        {
            printf("Item not found\n");
        }
    }
}

void display21()
{
    struct node21 *ptr21;
    ptr21 = head21;
    if (head21 == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values ... \n");

        while (ptr21->next21 != head21)
        {

            printf("%d\n", ptr21->data21);
            ptr21 = ptr21->next21;
        }
        printf("%d\n", ptr21->data21);
    }
}

void p21()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert21();
            break;
        case 2:
            lastinsert21();
            break;
        case 3:
            begin_delete21();
            break;
        case 4:
            last_delete21();
            break;
        case 5:
            search21();
            break;
        case 6:
            display21();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

// Function to perform Insert, Search, and Traverse operations on Circular Linked List
void p23()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\n*********Circular Linked List Operations*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert\n2.Search\n3.Traverse\n4.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            lastinsert21();
            break;
        case 2:
            search21();
            break;
        case 3:
            display21();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Please enter a valid choice..\n");
        }
    }
}
struct node24
{
    int priority24;
    int data24;
    struct node24 *next24;
};

struct node24 *front24 = NULL;

void insert24(int data24, int priority24)
{
    struct node24 *temp24, *q24;

    // Corrected memory allocation
    temp24 = malloc(sizeof(struct node24));
    temp24->data24 = data24;
    temp24->priority24 = priority24;

    // Adjusted priority comparison
    if (front24 == NULL || priority24 < front24->priority24)
    {
        temp24->next24 = front24;
        front24 = temp24;
    }
    else
    {
        q24 = front24;
        while (q24->next24 != NULL && q24->next24->priority24 <= priority24)
        {
            q24 = q24->next24;
        }
        temp24->next24 = q24->next24;
        q24->next24 = temp24;
    }
}

void del24()
{
    struct node24 *temp24;

    if (front24 == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp24 = front24;
        printf("Deleted item is %d\n", temp24->data24);
        front24 = front24->next24;
        free(temp24);
    }
}

// Display method
void display24()
{
    struct node24 *ptr24;
    ptr24 = front24;
    if (front24 == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is :\n");
        printf("Priority       Item\n");
        while (ptr24 != NULL)
        {
            printf("%5d        %5d\n", ptr24->priority24, ptr24->data24);
            ptr24 = ptr24->next24;
        }
    }
}

void p24()
{ // Changed from void main() to int main()
    insert24(34, 6);
    insert24(37, 2);
    insert24(28, 1);
    display24();
    del24();
    display24();
}

struct node25
{
    int element25;
    struct node25 *left25;
    struct node25 *right25;
};

/* To create a new node */
struct node25 *createNode25(int val25)
{
    struct node25 *Node25 = (struct node25 *)malloc(sizeof(struct node25));
    Node25->element25 = val25;
    Node25->left25 = NULL;
    Node25->right25 = NULL;

    return (Node25);
}

/* function to traverse the nodes of binary tree in preorder */
void traversePreorder25(struct node25 *root25)
{
    if (root25 == NULL)
        return;
    printf(" %d ", root25->element25);
    traversePreorder25(root25->left25);
    traversePreorder25(root25->right25);
}

/* function to traverse the nodes of binary tree in Inorder */
void traverseInorder25(struct node25 *root25)
{
    if (root25 == NULL)
        return;
    traverseInorder25(root25->left25);
    printf(" %d ", root25->element25);
    traverseInorder25(root25->right25);
}

/* function to traverse the nodes of binary tree in postorder */
void traversePostorder25(struct node25 *root25)
{
    if (root25 == NULL)
        return;
    traversePostorder25(root25->left25);
    traversePostorder25(root25->right25);
    printf(" %d ", root25->element25);
}

void p25()
{
    struct node25 *root25 = createNode25(36);
    root25->left25 = createNode25(26);
    root25->right25 = createNode25(46);
    root25->left25->left25 = createNode25(21);
    root25->left25->right25 = createNode25(31);
    root25->left25->left25->left25 = createNode25(11);
    root25->left25->left25->right25 = createNode25(24);
    root25->right25->left25 = createNode25(41);
    root25->right25->right25 = createNode25(56);
    root25->right25->right25->left25 = createNode25(51);
    root25->right25->right25->right25 = createNode25(66);

    printf("\n The Preorder traversal of given binary tree is -\n");
    traversePreorder25(root25);

    printf("\n The Inorder traversal of given binary tree is -\n");
    traverseInorder25(root25);

    printf("\n The Postorder traversal of given binary tree is -\n");
    traversePostorder25(root25);
}

// Function to perform multiplication of two numbers using recursion
int multiply28(int a, int b)
{
    // Base case: if b becomes 0, return 0
    if (b == 0)
        return 0;

    // Recursive case: add 'a' to the result of multiplying 'a' with 'b-1'
    return a + multiply28(a, b - 1);
}

void p28()
{
    int num1, num2, result28;

    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);

    result28 = multiply28(num1, num2);

    printf("The product of %d and %d is: %d\n", num1, num2, result28);
}

void p29()
{
    int i, no, count = 0;
    char arr29[20][100], search29[100];

    printf("Enter number of elements in string\n");
    scanf("%d", &no);

    printf("Enter %d elements\n", no);
    for (i = 0; i < no; i++)
    {
        scanf("%s", arr29[i]);
    }

    printf("Enter a string for search\n");
    scanf("%s", search29);

    for (i = 0; i < no; i++)
    {
        if (strcmp(arr29[i], search29) == 0)
        {
            printf("%s is present at position %d.\n", search29, i + 1);
            count++;
        }
    }

    if (count == 0)
    {
        printf("%s is not present in the array.\n", search29);
    }
    else
    {
        printf("%s is present %d times in the array.\n", search29, count);
    }
}

void printReverseString29(char *str29)
{
    if (*str29 == '\0')
        return;

    printReverseString29(str29 + 1);
    printf("%c", *str29);

}
// traverse linked list in reverse order using Recursion
struct node30   
{  
    int data30;  
    struct node30 *next30;   
};  
//struct node30 *head30;  
void lastinsert30(struct node30 **head30)  
{  
    struct node30 *ptr30,*temp30;  
    int item;     
    ptr30 = (struct node30*)malloc(sizeof(struct node30));      
    if(ptr30 == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr30->data30 = item;  
        if(*head30 == NULL)  
        {  
            ptr30 -> next30 = NULL;  
            *head30 = ptr30;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp30 = *head30;  
            while (temp30 -> next30 != NULL)  
            {  
                temp30 = temp30 -> next30;  
            }  
            temp30->next30 = ptr30;  
            ptr30->next30 = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  


void printreverse30(struct node30 *head30)
{     
     
    if (head30== NULL)
    {
        return;
    }
    printreverse30(head30->next30);
    printf("%d    ", head30->data30);

}

void p30 ()  
{   struct node30 *head30 = NULL;
    lastinsert30(&head30);
    lastinsert30(&head30);
    printf("\n Value in linked list  : ");
    printreverse30(head30);
   
}  



// add two polynomial using linked list

struct Node31_32
{
    int coef31_32;
    int exp31_32;
    struct Node31_32 *next31_32;
};

typedef struct Node31_32 Node31_32;

void insert31_32(Node31_32 **poly31_32, int coef31_32, int exp31_32)
{
    Node31_32 *temp31_32 = (Node31_32 *)malloc(sizeof(Node31_32));
    temp31_32->coef31_32 = coef31_32;
    temp31_32->exp31_32 = exp31_32;
    temp31_32->next31_32 = NULL;

    if (*poly31_32 == NULL)
    {
        *poly31_32 = temp31_32;
        return;
    }

    Node31_32 *current31_32 = *poly31_32;

    while (current31_32->next31_32 != NULL)
    {
        current31_32 = current31_32->next31_32;
    }

    current31_32->next31_32 = temp31_32;
}

void print31_32(Node31_32 *poly31_32)
{
    if (poly31_32 == NULL)
    {
        printf("0\n");
        return;
    }

    Node31_32 *current31_32 = poly31_32;

    while (current31_32 != NULL)
    {
        printf("%dx^%d", current31_32->coef31_32, current31_32->exp31_32);
        if (current31_32->next31_32 != NULL)
        {
            printf(" + ");
        }
        current31_32 = current31_32->next31_32;
    }

    printf("\n");
}

Node31_32 *add31_32(Node31_32 *poly31_32_1, Node31_32 *poly31_32_2)
{
    Node31_32 *result31_32 = NULL;

    while (poly31_32_1 != NULL && poly31_32_2 != NULL)
    {
        if (poly31_32_1->exp31_32 == poly31_32_2->exp31_32)
        {
            insert31_32(&result31_32, poly31_32_1->coef31_32 + poly31_32_2->coef31_32, poly31_32_1->exp31_32);
            poly31_32_1 = poly31_32_1->next31_32;
            poly31_32_2 = poly31_32_2->next31_32;
        }
        else if (poly31_32_1->exp31_32 > poly31_32_2->exp31_32)
        {
            insert31_32(&result31_32, poly31_32_1->coef31_32, poly31_32_1->exp31_32);
            poly31_32_1 = poly31_32_1->next31_32;
        }
        else
        {
            insert31_32(&result31_32, poly31_32_2->coef31_32, poly31_32_2->exp31_32);
            poly31_32_2 = poly31_32_2->next31_32;
        }
    }

    while (poly31_32_1 != NULL)
    {
        insert31_32(&result31_32, poly31_32_1->coef31_32, poly31_32_1->exp31_32);
        poly31_32_1 = poly31_32_1->next31_32;
    }

    while (poly31_32_2 != NULL)
    {
        insert31_32(&result31_32, poly31_32_2->coef31_32, poly31_32_2->exp31_32);
        poly31_32_2 = poly31_32_2->next31_32;
    }

    return result31_32;
}
void p31_32()
{
    Node31_32 *poly31_32_1 = NULL;
    insert31_32(&poly31_32_1, 5, 4);
    insert31_32(&poly31_32_1, 3, 2);
    insert31_32(&poly31_32_1, 1, 0);

    Node31_32 *poly31_32_2 = NULL;
    insert31_32(&poly31_32_2, 4, 4);
    insert31_32(&poly31_32_2, 2, 2);
    insert31_32(&poly31_32_2, 1, 1);

    printf("First polynomial: ");
    print31_32(poly31_32_1);

    printf("Second polynomial: ");
    print31_32(poly31_32_2);

    Node31_32 *result31_32 = add31_32(poly31_32_1, poly31_32_2);
    printf("Result: ");
    print31_32(result31_32);
}

void p33()
{
    char a[5][10], val[10];
    int i, n = 5, found = 0;
    printf("Enter 5 elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    printf("Enter element to find (case-insensitive):\n");
    scanf("%s", val);
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(a[i], val) == 0)
        {
            printf("Position of value is %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("The position of the value is %d\n", i + 1);
    }
    else
    {
        printf("Not found\n");
    }
}

void sortFloatArray(float arr[], int n)
{
    int i, j;
    float temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printFloatArray(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void p34()
{
    float arr[10];
    int i, n;
    printf("Enter the number of elements (max 10): ");
    scanf("%d", &n);
    printf("Enter %d floating point numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("Original array: ");
    printFloatArray(arr, n);
    sortFloatArray(arr, n);
    printf("Sorted array: ");
    printFloatArray(arr, n);
}

// I know that it can be done with 34 but i want to do it with 35

void sortNegativeArray(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printNegativeArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void p35()
{
    int arr[10];
    int i, n;
    printf("Enter the number of elements (max 10): ");
    scanf("%d", &n);
    printf("Enter %d negative numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printNegativeArray(arr, n);
    sortNegativeArray(arr, n);
    printf("Sorted array: ");
    printNegativeArray(arr, n);
}

// not of our miss

struct node36
{
    char data36;
    struct node36 *next36;
};

struct node36 *top36 = NULL;

void push36(char data36)
{
    struct node36 *newNode36 = (struct node36 *)malloc(sizeof(struct node36));
    if (!newNode36)
    {
        printf("Stack overflow\n");
        return;
    }
    newNode36->data36 = data36;
    newNode36->next36 = top36;
    top36 = newNode36;
}

char pop36()
{
    if (top36 == NULL)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    char data36 = top36->data36;
    struct node36 *temp36 = top36;
    top36 = top36->next36;
    free(temp36);
    return data36;
}

void reverseString36(char *str36)
{
    int length36 = strlen(str36);
    for (int i36 = 0; i36 < length36; i36++)
    {
        push36(str36[i36]);
    }
    printf("Reversed string: ");
    for (int i36 = 0; i36 < length36; i36++)
    {
        printf("%c", pop36());
    }
    printf("\n");
}

void p36()
{
    char str36[100];
    printf("Enter a string: ");
    scanf("%s", str36);
    reverseString36(str36);
}

// reverse a string using stack
#define MAX 50
int top37 = -1, front37 = 0;
char stack37[MAX];
void push37(char);
void pop37();

void p37()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("1-enter string\n2-exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
            for (i = 0; s[i] != '\0'; i++)
            {
                b = s[i];
                push37(b);
            }
            for (i = 0; i < (strlen(s) / 2); i++)
            {
                if (stack37[top37] == stack37[front37])
                {
                    pop37();
                    front37++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break;
                }
            }
            if (front37 == strlen(s) / 2)
                printf("%s is palindrome\n", s);
            front37 = 0;
            top37 = -1;
            break;
        case 2:
            exit(0);
        default:
            printf("enter correct choice\n");
        }
    }
}

/* to push a character into stack */
void push37(char a)
{
    top37++;
    stack37[top37] = a;
}

/* to delete an element in stack */
void pop37()
{
    top37--;
}


// print fibonacci series using recursion


int fibonacci38(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci38(n-1) + fibonacci38(n-2);
    }
}

void p38() {
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");   

    for (i = 0; i < n; ++i) {
        printf("%d ", fibonacci38(i));
    }
}

int recurSum39(int n)
{
    if (n <= 1)
        return n;
    return n + recurSum39(n - 1);
}

// Driver code
void p39()
{
    int n;
    printf("enter num \t");
    scanf("%d", &n);
    printf("%d\n", recurSum39(n));
}

void copy_string40(char *s, char *t, int i)
{
    if (s[i] == '\0')
    {
        t[i] = '\0';
        return;
    }
    t[i] = s[i];
    copy_string40(s, t, i + 1);
}

void p40()
{
    char s[100], t[100];
    printf("Enter the string: ");
    scanf("%s", s);
    copy_string40(s, t, 0);
    printf("Copied string: %s\n", t);
}
typedef struct Node41
{
    int data41;
    struct Node41 *next41;
} Node41;

void traverse_linked_list41(Node41 *head41)
{
    if (head41 == NULL)
    {
        return;
    }
    printf("%d ", head41->data41);
    traverse_linked_list41(head41->next41);
}

void p41()
{
    Node41 *head41 = NULL;
    Node41 *temp41 = NULL;
    int choice41, count41 = 0, data41;

    while (1)
    {
        printf("Enter your choice41:\n");
        printf("1. Insert Node41\n");
        printf("2. Traverse Linked List41\n");
        printf("3. Exit41\n");
        scanf("%d", &choice41);

        switch (choice41)
        {
        case 1:
            temp41 = (Node41 *)malloc(sizeof(Node41));
            printf("Enter Node41 Data41: ");
            scanf("%d", &data41);
            temp41->data41 = data41;
            temp41->next41 = NULL;

            if (head41 == NULL)
            {
                head41 = temp41;
            }
            else
            {
                Node41 *temp41_1 = head41;
                while (temp41_1->next41 != NULL)
                {
                    temp41_1 = temp41_1->next41;
                }
                temp41_1->next41 = temp41;
            }
            count41++;
            break;
        case 2:
            if (head41 == NULL)
            {
                printf("Linked List41 is Empty41\n");
            }
            else
            {
                printf("Linked List41: ");
                traverse_linked_list41(head41);
                printf("\n");
            }
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Invalid Choice41\n");
        }
    }
}
// operations on binary search tree (BST)
// I have combined remaining
struct node42
{
    int data42;
    struct node42 *right42;
    struct node42 *left42;
};

struct node42 *new_node42(int x)
{
    struct node42 *temp42;
    temp42 = (struct node42 *)malloc(sizeof(struct node42));
    temp42->data42 = x;
    temp42->left42 = NULL;
    temp42->right42 = NULL;

    return temp42;
}

struct node42 *search42(struct node42 *root42, int x)
{
    if (root42 == NULL || root42->data42 == x)
        return root42;
    else if (x > root42->data42)
        return search42(root42->right42, x);
    else
        return search42(root42->left42, x);
}

struct node42 *insert42(struct node42 *root42, int x)
{
    if (root42 == NULL)
        return new_node42(x);
    else if (x > root42->data42)
        root42->right42 = insert42(root42->right42, x);
    else
        root42->left42 = insert42(root42->left42, x);
    return root42;
}
struct node42 *find_minimum42(struct node42 *root42)
{
    if (root42 == NULL)
    {
        return root42;
    }
    else

    {
        while (root42->left42 != NULL)
        {
            root42 = root42->left42;
        }
        return root42;
    }
}
struct node42 *find_maximum42(struct node42 *root42)
{
    if (root42 == NULL)
    {
        return root42;
    }
    else

    {
        while (root42->right42 != NULL)
        {
            root42 = root42->right42;
        }
        return root42;
    }
}

// find minimum and maximum using recursion
struct node42 *find_minimum42_recursion(struct node42 *root42)
{
    if (root42 == NULL)
        return NULL;
    else if (root42->left42 != NULL)
        return find_minimum42_recursion(root42->left42);
    return root42;
}
struct node42 *find_maximum42_recursion(struct node42 *root42)
{
    if (root42 == NULL)
        return NULL;
    else if (root42->right42 != NULL)
        return find_maximum42_recursion(root42->right42);
    return root42;
}
struct node42 *delete42(struct node42 *root42, int x)
{

    if (root42 == NULL)
        return NULL;
    if (x > root42->data42)
        root42->right42 = delete42(root42->right42, x);
    else if (x < root42->data42)
        root42->left42 = delete42(root42->left42, x);
    else
    {
        if (root42->left42 == NULL && root42->right42 == NULL)
        {
            free(root42);
            return NULL;
        }
        else if (root42->left42 == NULL || root42->right42 == NULL)
        {
            struct node42 *temp42;
            if (root42->left42 == NULL)
                temp42 = root42->right42;
            else
                temp42 = root42->left42;
            free(root42);
            return temp42;
        }
        else
        {
            struct node42 *temp42 = find_minimum42_recursion(root42->right42);
            root42->data42 = temp42->data42;
            root42->right42 = delete42(root42->right42, temp42->data42);
        }
    }
    return root42;
}

void inorder42(struct node42 *root42)
{
    if (root42 != NULL)
    {
        inorder42(root42->left42);
        printf(" %d ", root42->data42);
        inorder42(root42->right42);
    }
}

void p42()
{
    struct node42 *root42, *result42, *min42, *max42;
    root42 = new_node42(20);
    insert42(root42, 5);
    insert42(root42, 1);
    insert42(root42, 15);
    insert42(root42, 9);
    insert42(root42, 7);
    insert42(root42, 12);
    insert42(root42, 30);
    insert42(root42, 25);
    insert42(root42, 40);
    insert42(root42, 45);
    insert42(root42, 42);

    inorder42(root42);
    printf("\n");
    // delete the node
    root42 = delete42(root42, 1);
    root42 = delete42(root42, 5);
    // delete the node
    root42 = delete42(root42, 45);

    printf("After Delete \n ");
    inorder42(root42);
    printf("\n");
    // Search the element
    int find42 = 40;
    result42 = search42(root42, find42);
    if (result42 != NULL)
    {
        printf("Found %d", result42->data42);
    }
    else
    {
        printf(" Not Found ");
    }
    // find Minimum
    min42 = find_minimum42_recursion(root42);
    printf("\n Minimum element %d", min42->data42);
    max42 = find_maximum42_recursion(root42);
    printf("\n Minimum element %d", max42->data42);
}

void main()
{
    int choice_for_main, arr[10], s;
    char arrs[20][100];

    printf("Enter the choice:\n ");
    printf(" menu\nenter \n"
           "1. for to perform operations on array: Creation, Insertion, Deletion, Display.\n"
           "2. for to search a particular data in array of numbers using Linear search.\n"
           "3. for to search a particular data in array of strings using Linear search.\n"
           "4. for to search a particular data in array of numbers using Binary search.\n"
           "5. for to search a particular data in array of strings using Binary search.\n"
           "6. for to sort an array of numbers using bubble sort.\n"
           "7. for to sort an array of strings using bubble sort.\n"
           "8. for to sort an array of numbers using selection sort.\n"
           "9. for to sort an array of strings using selection sort.\n"
           "10. for to sort an array of numbers using Insertion sort.\n"
           "11. for to sort an array of strings using Insertion sort.\n"
           "12. for to perform PUSH, POP operation on stack using array.\n"
           "13. for to perform PUSH, POP operation on stack using linked list.\n"
           "14. for to perform Insert, Delete operation on Linear queue using array.\n"
           "15. for to perform Insert, Delete operation on Linear queue using linked list.\n"
           "16. for to perform Insert, Delete operation on Circular queue using array.\n"
           "17. for to perform Insert, Delete operation on Circular queue using linked list.\n"
           "18. for to perform Inzsert, Delete, Search, Traverse operation on Singly Linked List.\n"
           "19. for to perform Insert at beginning, insert at end, random insert, operation on Singly Linked List.\n"
           "20. for to perform Delete frowwm beginning, delete from end, delete after particular position operation on singly Linked List.\n"
           "21. for to perform Insert at beginning, insert at end, random insert, operation on Circular Linked List.\n"
           "22. for to perform Delete from beginning, delete from end, delete after particular position operation on Circular Linked List.\n"
           "23. for to perform Insert, Search, Traverse operation on Circular Linked List.\n"
           "24. for to create priority queue using linked list.\n"
           "25. for to create Binary Search Tree (BST) and traverse a tree using preorder traversal.\n"
           "26. for to create Binary Search Tree (BST) and traverse a tree using inorder traversal.\n"
           "27. for to create Binary Search Tree (BST) and traverse a tree using postorder traversal.\n"
           "28. for to perform multiplication of two numbers using recursion.\n"
           "29. for to print given string in reverse using recursion.\n"
           /*miss i didnt found it*/ "30. for to create singly linked list and traverse in reverse order using recursion.\n"
           "31. for to 2 polynomials using linked list.\n"
           "32. for to perform addition of two polynomials using linked list.\n"
           "33. for linear search on an array of string to find case-insensitive for a string.\n"
           "34. for to sort an array of floating point numbers.\n"
           "35. for to sort an array of negative numbers.\n"
           "36. for to reverse a string using stack.\n"
           "37. for to check whether the given string is palindrome or not using stack.\n"
         "38. for to print fibonacci series using recursion.\n"
           "39. for to calculate the sum of numbers from 1 to n using recursion.\n"
           "40. for to copy one string to another using recursion.\n"
           "41. for to traverse linked list using recursion.\n"
           "42. for to create binary search tree and display it.\n"
           "43. for to search a key element in binary search tree.\n"
           "44. for to find maximum element in binary search tree.\n"
           "45. for to find minimum element in binary search tree.\n"
           "46 to exit");

    scanf(" %d", &choice_for_main);

    switch (choice_for_main)
    {
    case 1:
        p1();
        break;
    case 2:
        p2();
        break;
    case 3:
        p3();
        break;
    case 4:
        p4();
        break;
    case 5:
        p5();
        break;
    case 6:
        p6();
        break;
    case 7:
        p7();
        break;
    case 8:
        p8();
        break;
    case 9:
        p9();
        break;

    case 10:
        p10();
        break;
    case 11:
        p11();
        break;
    case 12:
        p12();
        break;

    case 13:
        p13();
        break;
    case 14:
        p14();
        break;
    case 15:
        p15();
        break;
    case 16:
        p16();
        break;
    case 17:
        p17();
        break;
    case 18:
        p18();
        printf("I have done 18 and 19 combined\n");
        break;
    case 19:
        p18();
        printf("I have done 18 and 19 combined\n");
        break;
    case 20:
        p20();
        printf("I have done 20 and 21 combined\n");

        break;
    case 21:
        p21();
        printf("I have done 20 and 21 combined\n");

        break;
    case 22:
        p21();
    case 23:
        p23();
        break;
    case 24:
        p24();
        break;
    case 25:
        printf("I have done 25,26 and 27 combined\n");
        p25();
        break;
    case 26:
        printf("I have done 25,26 and 27 combined\n");

        p25();
        break;
    case 27:
        p25();
        printf("I have done 25,26 and 27 combined\n");

        break;
    case 28:
        p28();
        break;
    case 29:
        p29();
        break;
     case 30:
         p30();
         break;
    case 31:
        p31_32();
        break;
    case 32:
        p31_32();
        break;
    case 33:
        p33();
        break;
    case 34:
        p34();
        break;
    case 35:
        p35();
        break;
    case 36:
        p36();
        break;
    case 37:
        p37();
        break; 
     case 38:
         p38();
         break;
    case 39:
        p39();
        break;
    case 40:
        p40();
        break;
    case 41:
        p41();
        break;
    case 42:
        printf("I have done 42,43,44, and 45 combined\n");
        p42();

        break;
    case 43:
        printf("I have done 42,43,44, and 45 combined\n");

        p42();
        printf("I have done 42,43,44, and 45 combined\n");

        break;
    case 44:
        printf("I have done 42,43,44, and 45 combined\n");

        p42();
        break;
    case 45:
        printf("I have done 42,43,44, and 45 combined\n");

        p42();
        break;

    case 46:
         exit(0);
         break;

    default:
        printf("Wrong choice\n");
    }
}