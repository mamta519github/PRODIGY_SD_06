#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to represent a contact
struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};

// Function prototypes
void addContact(struct Contact contacts[], int *numContacts);
void viewContacts(const struct Contact contacts[], int numContacts);
void editContact(struct Contact contacts[], int numContacts);
void deleteContact(struct Contact contacts[], int *numContacts);

int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do
    {
        // Display menu
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(contacts, &numContacts);
            break;
        case 2:
            viewContacts(contacts, numContacts);
            break;
        case 3:
            editContact(contacts, numContacts);
            break;
        case 4:
            deleteContact(contacts, &numContacts);
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void addContact(struct Contact contacts[], int *numContacts)
{
    if (*numContacts < MAX_CONTACTS)
    {
        printf("Enter contact details:\n");
        printf("Name: ");
        scanf("%s", contacts[*numContacts].name);
        printf("Phone: ");
        scanf("%s", contacts[*numContacts].phone);
        printf("Email: ");
        scanf("%s", contacts[*numContacts].email);

        (*numContacts)++;
        printf("Contact added successfully!\n");
    }
    else
    {
        printf("Cannot add more contacts. Contact list is full.\n");
    }
}

void viewContacts(const struct Contact contacts[], int numContacts)
{
    if (numContacts == 0)
    {
        printf("No contacts available.\n");
    }
    else
    {
        printf("\nContact List:\n");
        for (int i = 0; i < numContacts; i++)
        {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
        }
    }
}

void editContact(struct Contact contacts[], int numContacts)
{
    if (numContacts == 0)
    {
        printf("No contacts available to edit.\n");
    }
    else
    {
        char searchName[50];
        int found = 0;

        printf("Enter the name of the contact to edit: ");
        scanf("%s", searchName);

        for (int i = 0; i < numContacts; i++)
        {
            if (strcmp(contacts[i].name, searchName) == 0)
            {
                printf("Enter new details for the contact:\n");
                printf("Name: ");
                scanf("%s", contacts[i].name);
                printf("Phone: ");
                scanf("%s", contacts[i].phone);
                printf("Email: ");
                scanf("%s", contacts[i].email);

                found = 1;
                printf("Contact edited successfully!\n");
                break;
            }
        }

        if (!found)
        {
            printf("Contact not found.\n");
        }
    }
}

void deleteContact(struct Contact contacts[], int *numContacts)
{
    if (*numContacts == 0)
    {
        printf("No contacts available to delete.\n");
    }
    else
    {
        char searchName[50];
        int found = 0;

        printf("Enter the name of the contact to delete: ");
        scanf("%s", searchName);

        for (int i = 0; i < *numContacts; i++)
        {
            if (strcmp(contacts[i].name, searchName) == 0)
            {
                // Remove the contact by shifting the remaining contacts
                for (int j = i; j < *numContacts - 1; j++)
                {
                    strcpy(contacts[j].name, contacts[j + 1].name);
                    strcpy(contacts[j].phone, contacts[j + 1].phone);
                    strcpy(contacts[j].email, contacts[j + 1].email);
                }

                (*numContacts)--;
                found = 1;
                printf("Contact deleted successfully!\n");
                break;
            }
        }

        if (!found)
        {
            printf("Contact not found.\n");
        }
    }
}