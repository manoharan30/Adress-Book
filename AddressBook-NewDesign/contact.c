#include "contact.h"
#include<string.h>
#include <ctype.h>
int m;
int g;
void listContacts(AddressBook *addressBook) 
{
    printf("Contact Book\n__________________________________________________________________________________________________\n\n");
    for (int i=0;i<addressBook->contactCount;i++){
        printf("Name: %-30sPhone: %-30sE-mail: %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email );

    }
    printf("__________________________________________________________________________________________________");
    
}
void createContact(AddressBook *addressBook) 
{
char name[30];
char number[10];
char email[20];
int val1=1;
int val2=1;
int flag=1;
int flag2=1;

printf("Enter the name: ");
getchar();
scanf("%[^\n]",name);
strcpy(addressBook->contacts[addressBook->contactCount].name,name);

while(val1){
printf("\nEnter the phone number: ");
getchar();
scanf("%[^\n]",number);
int digits_only(const char *number)
{
    while (*number) {
        if (isdigit(*number++) == 0) return 0;
    }

    return 1;
}
if(strlen(number)==10 && digits_only(number)){
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,number)==0){
            printf("\nThe number you entered is already registered.");
            flag=0;
            break;
        }
    }
    if(flag){
            strcpy(addressBook->contacts[addressBook->contactCount].phone,number);
            val1=0;
    }
}
else{
    printf("\nPlease enter valid number");
}
}

while(val2){
printf("\nEnter the Email address: ");
getchar();
scanf("%[^\n]",email);
char *ptr=strrchr(email,'@');
int p=0;
if(ptr!=email){
    p=1;
}
if(strstr(email,".com")!=0 && strchr(email,'@') && p)
{
    for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,email)==0)
            {
                printf("\nThe email you entered is already in use");
                flag2=0;
                break;
            }
        }

    if(flag2){
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);
        addressBook->contactCount++;
        val2=0;
    }
}
else{
    printf("\nPlease enter a valid email");
}
}
}
void searchContact(AddressBook *addressBook) 
{
    int option;
    printf("1.Search by Name\n2.Search by Phone\n3.Search by E-mail\n");
    printf("\n\n");
    printf("Enter the option: ");
    scanf("%d",&option);
    printf("\n");
    char str[30];
    int flag=0;
    switch (option) {
        case 1:
            printf("Enter the name: ");
            scanf(" %[^\n]", str); 
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].name, str) == 0) {
                    printf("Name: %-30sPhone: %-30sE-mail: %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag = 1;
                    m=i;
                }
            }
            if (flag == 0) {
                printf("No details found\n");
                }
            break;
            break;

        case 2:
            printf("Enter the Phone number: ");
            scanf(" %[^\n]", str); // Corrected input format
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].phone, str) == 0) {
                    printf("Name: %s\nPhone: %s\nE-mail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag = 1;
                    m = i;
                }
            }
            if (flag == 0) {
                printf("No details found\n");
                }
            break;

        case 3:
            printf("Enter the E-mail: ");
            scanf(" %[^\n]", str); 
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].email, str) == 0) {
                    printf("Name: %s\nPhone: %s\nE-mail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag = 1;
                    m = i;
                }
            }
            if (flag == 0) {
                printf("No details found\n");
                }
            break;

        default:
            printf("Please enter a valid option\n");
            break;
    }
    g=flag;
}

void editContact(AddressBook *addressBook) 
{
    if(g){
    printf("New Name: ");
    getchar();
    scanf("%[^\n]",addressBook->contacts[m].name);

    char newPhone[10];
    int val1=1;
    while(val1)
    {
        printf("\nNew Phone Number: ");
        getchar();
        scanf("%[^\n]",newPhone);
        int digits_only(const char *newPhone)
        {
            while (*newPhone) {
                if (isdigit(*newPhone++) == 0) return 0;
                }
                return 1;
                }
        if(strlen(newPhone)==10 && digits_only(newPhone)){
            int f=1;
            for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].phone,newPhone)==0){
            printf("The number you entered is already registred");
            f=0;
            break;
            }
            }
            if(f){
                strcpy(addressBook->contacts[m].phone,newPhone);
                val1=0;
            }
        }
        else
        printf("\nPlease enter a valid phone number");
    }


    char newMail[30];
    int val2=1;
    while(val2)
    {
        printf("\nNew E-mail: ");
        getchar();
        scanf("%[^\n]",newMail);
        char *ptr=strrchr(newMail,'@');
        int p=0;
        if(ptr!=newMail){
            p=1;
            }
            
        if(strstr(newMail,".com")!=0 && strchr(newMail,'@') && p ){
            int f=1;
           for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].email,newMail)==0){
            printf("The mail address you entered is already registred");
            f=0;
            break;
            }
            }
            if(f){
                strcpy(addressBook->contacts[m].email,newMail);
                val2=0;
            } 
        }
        else
        printf("\nPlease enter a valid email");
    }
    
}
}


void deleteContact(AddressBook *addressBook) 
{
    if(g){
    int flag=1;
    char option;
    while(flag){
    printf("\nAre you sure you want to delete ? Y/N ");
    getchar();
    scanf("%c",&option);
    switch (option)
    {
    case 'Y':
        for(int i=m;i<addressBook->contactCount-1;i++){
            strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
            strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
            strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
        }
        addressBook->contactCount=(addressBook->contactCount)-1;
    
    case 'N':
        flag=0;
        break;
    default:
        printf("Please enter a valid input");
        break;
    }
    }
    }
}

