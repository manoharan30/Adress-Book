#include "contact.h"

int main()
{
    AddressBook ads;
    initialize(&ads);
    int flag=1;
    while(flag){
    int option;
    printf("\n1.Create\n2.Search\n3.Edit\n4.Delete\n5.List\n6.Exit\n");
    printf("\nEnter the option:");
    scanf("%d",&option);
    printf("\n");
        switch (option)
        {
        case 1:
            createContact(&ads);
            break;
        case 2:
            searchContact(&ads);
            break;
        case 3:
            searchContact(&ads);
            editContact(&ads);
            break;
        case 4:
            searchContact(&ads);
            deleteContact(&ads);
            break;
        case 5:
            listContacts(&ads);
            break;
        case 6:
            flag=0;
            break;
        default:
            printf("Please enter valid option.");
            break;
        }
    }
}

