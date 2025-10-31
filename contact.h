#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
/////////////////////////////////////////////////////////////////
void sortbyName(AddressBook *addressBook);
void sortbyNumber(AddressBook *addressBook);
void sortbyEmail(AddressBook *addressBook);
int isValidEmail(const char *email);
void multi_edit(AddressBook *addressBook, int S_NO);
void EDIT(AddressBook *addressBook, int S_NO);
void multi_delet(AddressBook *addressBook, int S_NO);
void delet(AddressBook *addressBook, int S_NO);
#endif
