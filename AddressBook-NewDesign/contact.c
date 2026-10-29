#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("No contacts found.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-30s\n", "No.", "Name", "Phone", "Email");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-5d %-20s %-15s %-30s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book is full.\n");
        return;
    }

    int index = addressBook->contactCount;

    printf("Enter Name : ");
    scanf(" %[^\n]", addressBook->contacts[index].name);

    printf("Enter Phone: ");
    scanf("%s", addressBook->contacts[index].phone);

    printf("Enter Email: ");
    scanf("%s", addressBook->contacts[index].email);

    addressBook->contactCount++;

    printf("\nContact Added Successfully!\n");
}

int searchContact(AddressBook *addressBook)
{
    int choice;
    char search[50];

    printf("Search Contact By:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the search value: ");

    if (choice == 1)
        scanf(" %[^\n]", search);   // Read name (allows spaces)
    else
        scanf("%s", search);        // Read phone or email

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        switch (choice)
        {
            case 1:
                if (strcmp(addressBook->contacts[i].name, search) == 0)
                    return i;
                break;

            case 2:
                if (strcmp(addressBook->contacts[i].phone, search) == 0)
                    return i;
                break;

            case 3:
                if (strcmp(addressBook->contacts[i].email, search) == 0)
                    return i;
                break;

            default:
                printf("Invalid choice.\n");
                return -1;
        }
    }

    printf("Contact not found.\n");
    return -1;
}

void editContact(AddressBook *addressBook)
{
    int ret = searchContact(addressBook);

    if (ret == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    int choice;
    char name[50];

    printf("1. Edit Name\n");
    printf("2. Edit Phone\n");
    printf("3. Edit Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", name);
            strcpy(addressBook->contacts[ret].name, name);
            break;

        case 2:
            printf("Enter new phone: ");
            scanf("%s", addressBook->contacts[ret].phone);
            break;

        case 3:
            printf("Enter new email: ");
            scanf("%s", addressBook->contacts[ret].email);
            break;

        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("\nUpdated Contact:\n");
    printf("Name : %s\n", addressBook->contacts[ret].name);
    printf("Phone: %s\n", addressBook->contacts[ret].phone);
    printf("Email: %s\n", addressBook->contacts[ret].email);
}

void deleteContact(AddressBook *addressBook)
{
    int index = searchContact(addressBook);

    if (index == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact deleted successfully.\n");
}
