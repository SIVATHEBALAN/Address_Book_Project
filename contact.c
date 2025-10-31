#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>
int arr[100];
int  valid;
char ch;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listContacts(AddressBook *addressBook, int sortCriteria) 
 {
    //Calling sorting function by given sort criteria
    switch(sortCriteria)
    {
        case 1:
            sortbyName(addressBook);
            break;
        case 2:
            sortbyNumber(addressBook);
            break;
        case 3:
            sortbyEmail(addressBook);
            break;
        default:
            printf("\n**Ivalid option!\n\n");    
    }
    
}

   /* int S_NO=0;
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++){
        S_NO++;
        printf(" | %-5d  | %-30s| %-15s | %-35s |\n",S_NO,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf(" --------------------------------------------------------------------------------------------------\n");*/
    

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void createContact(AddressBook *addressBook)
{
    int valid1, valid2, valid3;     // Validation flags for name, phone, and email
    char name[50];                  // Buffer to store name
    char phone[20];                 // Buffer to store phone number
    char email[50];                 // Buffer to store email address

    printf("\n=====Create Contact=====\n\n");

    // ---------------------- NAME VALIDATION ----------------------
    do {
        valid1 = 1;
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        // Validate: only alphabets and spaces are allowed
        for (int i = 0; name[i]; i++) {
            if (!isalpha(name[i]) && name[i] != ' ')
                valid1 = 0;
        }

        if (!valid1)
            printf("Invalid! Only letters allowed.\n");

    } while (!valid1);

    // ---------------------- PHONE VALIDATION ----------------------
    do {
        valid2 = 1;
        printf("Enter phone: ");
        scanf(" %[^\n]", phone);

        // Validate: only digits and spaces are allowed
        for (int i = 0; phone[i]; i++) {
            if (!isdigit(phone[i]) && phone[i] != ' ')
                valid2 = 0;
        }

        if (!valid2)
            printf("Invalid! Only numbers allowed.\n");

    } while (!valid2);

    // ---------------------- EMAIL VALIDATION ----------------------
    do {
        printf("Enter Email: ");
        scanf(" %[^\n]", email);

        // Validate email using helper function
        valid3 = isValidEmail(email);

        if (!valid3)
            printf("Invalid email format! Try again.\n");

    } while (!valid3);

    // ---------------------- STORE CONTACT ----------------------
    int index = addressBook->contactCount;   // Get next available index

    strcpy(addressBook->contacts[index].name,  name);
    strcpy(addressBook->contacts[index].phone, phone);
    strcpy(addressBook->contacts[index].email, email);

    addressBook->contactCount++;             // Increment total contacts

    printf("\n=====Contact created successfully=====\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void searchContact(AddressBook *addressBook) 
 {
    printf("\n=====Search contact=====\n\n");
    int flag = 0;
    int choice;
    int S_NO = 0;
    int result;

          while (1) {
               printf("Search by Using\n1.Name\n2.phone\n3.Email\n4.Exit\nEnter your choice:");
               result = scanf(" %d", &choice);

                 if (result == 1 && choice >= 0 && choice <= 9) {
                 break; 
                 } 
                 else{
                   printf("\n=====Invalid input=====\n\n");
                   while (getchar() != '\n'); 
                    }
             }
    
    switch (choice) 
    {
        case 1:  // Search by Name
        {
            char Name[20];
            printf("Enter the Name:");
            
            
            scanf(" %[^\n]", Name);

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcasestr(addressBook->contacts[i].name, Name) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n",
                        S_NO,
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }

            S_NO = 0;
            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0)
                printf("\n=====search not found=====\n\n");
            else
                printf("\n======Search found======\n\n");
            
            flag = 0;
        }
        break;

        case 2:  // Search by Phone
        {
            char Phone[20];
            printf("Enter the Phone number:");
            
            
            scanf(" %[^\n]", Phone);

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strstr(addressBook->contacts[i].phone, Phone) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n",
                        S_NO,
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }

            S_NO = 0;
            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0)
                printf("\n=====search not found=====\n\n");
            else
                printf("\n======Search found======\n\n");

            flag = 0;
        }
        break;

        case 3:  // Search by Email
        {
            char Email[20];
            printf("Enter the Email:");
            
            
            scanf(" %[^\n]", Email);

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strstr(addressBook->contacts[i].email, Email) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n",
                        S_NO,
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }

            S_NO = 0;
            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0)
                printf("\n=====search not found=====\n\n");
            else
                printf("\n======Search found======\n\n");

            flag = 0;
        }
        break;

        case 4:  // Exit
            printf("\n=====Exit=====\n\n");
        break;

        default: // Invalid input handling
            printf("\n=====Invalid input=====\n\n");
        break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editContact(AddressBook *addressBook)
 {
    printf("\n=====Edit contact=====\n\n");
    int flag = 0;
    int choice;
    int S_NO = 0;
    int result;
    //int arr[100];
     while (1) {
         printf("Search By\n1.Name\n2.phone\n3.Email\n4.Exit\nEnter your choice:");
         result = scanf(" %d", &choice);
         if (result == 1 && choice >= 0 && choice <= 9) {
         break; 
         } else {
        printf("\n=====Invalid input=====\n\n");
        while (getchar() != '\n'); 
        }
         }

        switch (choice) {

        case 1: {
            char Name[50];
            printf("Enter the Name:");
            scanf(" %[^\n]", Name); 

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) {

                if (strcasestr(addressBook->contacts[i].name, Name) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
                }
            }

            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0)
                printf("\n=====contact not found=====\n");
            else {
                if (S_NO >= 2)
                    multi_edit(addressBook, S_NO);
                else
                    EDIT(addressBook, S_NO);
            }

            S_NO = 0;
            flag = 0;
            break;
        }

        case 2: {
            char Phone[20];
            printf("Enter the Phone number:");
            scanf(" %[^\n]", Phone);

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strstr(addressBook->contacts[i].phone, Phone) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
                }
            }

            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0) {
                printf("\n=====phone number not found=====\n");
            } else
                EDIT(addressBook, S_NO);

            S_NO = 0;
            flag = 0;
            break;
        }

        case 3: {
            char Email[50];
            printf("Enter the Email:");
            scanf(" %[^\n]", Email);

            printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strstr(addressBook->contacts[i].email, Email) != NULL) {
                    flag = 1;
                    S_NO++;
                    printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
                }
            }

            printf(" --------------------------------------------------------------------------------------------------\n");

            if (flag == 0) {
                printf("\n=====Email not found=====\n");
            } else {
                EDIT(addressBook, S_NO);
            }

            S_NO = 0;
            flag = 0;
            break;
        }

        case 4:
              printf("\n=====Exit=====\n");
            break;

        default:
            printf("\n=====Invalid input======\n");
            break;
        }
    } 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteContact(AddressBook *addressBook)
 {
     printf("\n=====Edit contact=====\n\n");
    int flag=0;
    int choice;
    int S_NO=0;
      int result;
     while (1) {
         printf("Search By\n1.Name\n2.phone\n3.Email\n4.Exit\nEnter your choice:");
         result = scanf(" %d", &choice);
         if (result == 1 && choice >= 0 && choice <= 9) {
         break; 
         } else {
        printf("\n=====Invalid input=====\n\n");
        while (getchar() != '\n'); 
        }
         }
    
    
      switch(choice){
        case 1:
             
             char Name[50];
             printf("Enter the Name:");
             getchar();
             scanf("%[^\n]",Name);
                  printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
             for(int i=0;i<addressBook->contactCount;i++){

                 if(strcasestr(addressBook->contacts[i].name,Name)!=NULL){
                    flag=1;
                    S_NO++;
                   printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
                  }
               }
               printf(" --------------------------------------------------------------------------------------------------\n");
          
             if(flag==0)
               printf("\n=====contact not found=====\n");
             else{
                if(S_NO>=2)
                 multi_delet(addressBook,S_NO);
                else
                 delet(addressBook,S_NO);
             }
               flag=0;
         break;
        case 2:
              
             char Phone[20];
             printf("Enter the Phone number:");
             getchar();
             scanf("%[^\n]",Phone);
              printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
             for(int i=0;i<addressBook->contactCount;i++){
             if(strstr(addressBook->contacts[i].phone,Phone)!=NULL){
                flag=1;
                S_NO++;
                  printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
             }
             }
              printf(" --------------------------------------------------------------------------------------------------\n");
             if(flag==0){
               printf("phone number not found");
             }
             else
                delet(addressBook,S_NO);
             flag=0;
         break;
        case 3:
            
             char Email[50];
             printf("Enter the Email:");
             getchar();
             scanf("%[^\n]",Email);
              printf("\n --------------------------------------------------------------------------------------------------\n");
            printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
            printf(" --------------------------------------------------------------------------------------------------\n");
             for(int i=0;i<addressBook->contactCount;i++){
             if(strstr(addressBook->contacts[i].email,Email)!=NULL){
                flag=1;
                S_NO++;
                 printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    arr[S_NO] = i;
             }
             }
              printf(" --------------------------------------------------------------------------------------------------\n");
             if(flag==0){
               printf("\n=====Email not found=====\n");
             }
             else{
                  delet(addressBook,S_NO);
             }
             flag=0;
         break;
        case 4:
        printf("\n=====Exit=====\n");
         break;
        default:
             printf("\n=====Invalid input=====\n");
         break;
      }
    
    
   
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////FUNCTIONS///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////functions/////////////////////////////functions////////////////////////////////
void multi_edit(AddressBook *addressBook,int S_NO){
  
               int multi;
               printf("Multiple contact found\nwhich one : ");
               scanf("%d",&multi);

                  if(multi<=S_NO){
                  int edit;
                  printf("EDIT\n1.Name\n2.Phone\n3.Email\nEnter your choice : ");
                  scanf("%d",&edit);
                  switch(edit){
                    case 1:
                        char new_name[50];
                         
                           do {
                                valid = 1;
                                printf("Enter Name: ");
                                scanf(" %[^\n]", new_name);
                                for (int i = 0; new_name[i]; i++)
                                if (!isalpha(new_name[i]) && new_name[i] != ' ')valid = 0;
                                if (!valid) printf("Invalid! Only letters allowed.\n");
                             } while (!valid);

                        printf("Are you sure(Y/N) : ");
                        
                        getchar();
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='Y'){
                        strcpy(addressBook->contacts[arr[multi]].name, new_name);
                        printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    case 2:
                     char new_phone[20];
                         
                           do {
                                valid = 1;
                                printf("Enter phone: ");
                                scanf(" %[^\n]", new_phone);
                                for (int i = 0; new_phone[i]; i++)
                                if (!isdigit(new_phone[i]) && new_phone[i] != ' ')valid = 0;
                                if (!valid) printf("Invalid! Only numbers allowed.\n");
                             } while (!valid);

                        printf("Are you sure(Y/N) : ");
                        
                        getchar();
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='Y'){
                        strcpy(addressBook->contacts[arr[S_NO]].phone, new_phone);
                        printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    case 3:
                       char new_email[50];
                           do {
                              printf("Enter Email: ");
                              scanf(" %[^\n]", new_email);
                              valid = isValidEmail(new_email);
                              if (!valid) printf("Invalid email format! Try again.\n");
                             } while (!valid);

                              printf("Are you sure (Y/N): ");
                              getchar();
                              scanf("%c", &ch);
                              if (ch == 'y' || ch == 'Y') {
                              strcpy(addressBook->contacts[arr[S_NO]].email, new_email);
                               printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    default:
                    printf("\n======Invalid input=====\n");
                    break;
                   }
                 }
                 else{
                printf("\n=====invalid=====\n");
                }

}

/////////////////
void EDIT(AddressBook *addressBook,int S_NO){
 
                  int edit;
                  printf("EDIT\n1.Name\n2.Phone\n3.Email\nEnter your choice : ");
                  scanf("%d",&edit);
                  switch(edit){
                    case 1:
                        char new_name[50];
                         
                           do {
                                valid = 1;
                                printf("Enter Name: ");
                                scanf(" %[^\n]", new_name);
                                for (int i = 0; new_name[i]; i++)
                                if (!isalpha(new_name[i]) && new_name[i] != ' ')valid = 0;
                                if (!valid) printf("Invalid! Only letters allowed.\n");
                             } while (!valid);

                        printf("Are you sure(Y/N) : ");
                        
                        getchar();
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='Y'){
                        strcpy(addressBook->contacts[arr[S_NO]].name, new_name);
                         printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    case 2:
                     char new_phone[20];
                         
                           do {
                                valid = 1;
                                printf("Enter phone: ");
                                scanf(" %[^\n]", new_phone);
                                for (int i = 0; new_phone[i]; i++)
                                if (!isdigit(new_phone[i]) && new_phone[i] != ' ')valid = 0;
                                if (!valid) printf("Invalid! Only numbers allowed.\n");
                             } while (!valid);

                        printf("Are you sure(Y/N) : ");
                        
                        getchar();
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='Y'){
                        strcpy(addressBook->contacts[arr[S_NO]].phone, new_phone);
                        printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    case 3:
                     char new_email[50];
                           do {
                              printf("Enter Email: ");
                              scanf(" %[^\n]", new_email);
                              valid = isValidEmail(new_email);
                              if (!valid) printf("Invalid email format! Try again.\n");
                             } while (!valid);

                              printf("Are you sure (Y/N): ");
                              getchar();
                              scanf("%c", &ch);
                              if (ch == 'y' || ch == 'Y') {
                              strcpy(addressBook->contacts[arr[S_NO]].email, new_email);
                               printf("\n=====Edit success=====\n");
                        }
                        else{
                          printf("\n======Edit cancel======\n");
                        }
                    break;
                    default:
                   printf("\n=====invalid=====\n");
                    break;
                  }
}

int isValidEmail(const char *email) {
    const char *atPos = strstr(email, "@");
    if (!atPos) return 0;

    if (strstr(atPos + 1, "@")) return 0;

    if (!strstr(atPos + 1, ".")) return 0;

    if (strstr(email, " ")) return 0;

    return 1;
}
/////////////////////////
void multi_delet(AddressBook *addressBook,int S_NO){
   int multi;
               printf("Multiple contact found\nwhich one : ");
               scanf("%d",&multi);
                    printf("Are you sure (Y/N): ");
                              getchar();
                              scanf("%c", &ch);
                               if (ch == 'y' || ch == 'Y') {
                  if(multi<=S_NO){
                    for(int i=arr[multi];i<addressBook->contactCount;i++){
                    addressBook->contacts[i]=addressBook->contacts[i+1];
                    }
                    printf("\n=====delete success=====\n");
                    addressBook->contactCount--;
                  }
                   else{
                printf("\n=====invalid=====\n");
                }
              }
                 else{
                printf("\n=====invalid=====\n");
                }
}//////////////////////
void delet(AddressBook *addressBook, int S_NO){
                             printf("Are you sure (Y/N): ");
                              getchar();
                              scanf("%c", &ch);
                              if (ch == 'y' || ch == 'Y') {
                                for(int i=arr[S_NO];i<addressBook->contactCount;i++){
                                  addressBook->contacts[i]=addressBook->contacts[i+1];
                                   }
                                 printf("\n=====delete success=====\n");
                                    addressBook->contactCount--;
                                   }
                            else{
                                  printf("\n=====invalid=====\n");
                                }

}

// Function: sortbyName
void sortbyName(AddressBook *addressBook)
 {
    // Sort contacts using bubble sort algorithm based on name
    // Swap name, phone, and email if they are out of order
    // Ask user for display order and print accordingly
    int option,i=0,j=0,k=addressBook->contactCount;
    int S_NO = 0;
    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {           
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);

    if(option ==  1)
    {
        printf("\n --------------------------------------------------------------------------------------------------\n");
        printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
        printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
          S_NO++;
             printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
      
        printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\n --------------------------------------------------------------------------------------------------\n");
        printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
        printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
          S_NO++;
             printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
         printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n**Invalid Option!\n\n");
    }
}

// Function: sortbyNumber
void sortbyNumber(AddressBook *addressBook)
 {
    // Sort contacts using bubble sort algorithm based on phone number
    // Swap all fields of contact structure if phone numbers are out of order
    // Ask user for display order and print accordingly
    int option,i=0,j=0,k=addressBook->contactCount;
      int S_NO = 0;
    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);
    
    if(option ==  1)
    {
         printf("\n --------------------------------------------------------------------------------------------------\n");
         printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
         printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
          S_NO++;
            printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\n --------------------------------------------------------------------------------------------------\n");
        printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
        printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
          S_NO++;
            printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
         printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n**Invalid Option!\n\n");
    }
}

// Function: sortbyEmail
void sortbyEmail(AddressBook *addressBook)
 {
    // Sort contacts using bubble sort algorithm based on email ID
    // Swap all fields if emails are out of order
    // Ask user for display order and print accordingl
    int option,i=0,j=0,k=addressBook->contactCount;
      int S_NO = 0;
    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);

    if(option ==  1)
    {
        printf("\n --------------------------------------------------------------------------------------------------\n");
        printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
        printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
          S_NO++;
            printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
         printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\n --------------------------------------------------------------------------------------------------\n");
        printf(" | S_NO\t  | NAME\t\t\t  | NUMBER\t    | Email\t\t\t\t  |\n");
        printf(" --------------------------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
          S_NO++;
             printf(" | %-5d  | %-30s| %-15s | %-35s |\n", S_NO, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
         printf(" --------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n**Invalid Option!\n\n");
    }
}