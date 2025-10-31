/*
    Name : SIVABALAN S
    Date : 29-10-2025
    Descripton : 
        Address Book is an application written in C. It can work on all platforms which have a C compiler or cross-compiler.
    The application keeps track of contact names and telephone/mobile numbers and e-mail addresses. It is a console application
    which uses standard C I/O for adding names, phone numbers and e-mail addresses, searching names and associated numbers and
    email addresses, updating numbers and email addresses, and deleting contacts.
*/
#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); 

    do {
        printf("\n=======Address Book Menu======\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5: 
                printf("\n======List contacts=====\n");
                printf("\n1.sortbyName\n2.sortbyNumber\n3.sortbyEmail");
                printf("\nEnter your option : ");
                scanf(" %d",&sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("\n=====Exit=====\n\n");
        }

    } while (choice != 7);
    
       return 0;
}
