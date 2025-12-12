#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validation.h"
#include "search.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("Name: %s\n", addressBook->contacts[i].name);
        printf("Phone: %s\n", addressBook->contacts[i].phone);
        printf("Email: %s\n", addressBook->contacts[i].email);
        printf("\n");
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0; // start with empty count
    // populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook); // load saved contacts from file
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{

    /* Define the logic to create a Contacts */
    char tempName[50];

    int valid = 0;
    do
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", tempName);
        valid = checkName(tempName); // Validate name format
    } while (valid == 0);
    char tempNumber[15];

    // Get valid phone number

    do
    {
        int addressIndex;
        printf("Enter Phone Number: ");
        scanf("%s", tempNumber);
        valid = checkPhone(tempNumber); // Validate number format
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (searchName(tempNumber, addressBook->contacts[i].phone) != -1)
            {
                printf("This phone number already exists.\n");
                valid = 0;
                break;
            }
        }
    } while (valid == 0);

    char tempEmail[20];
    // Get valid email
    do
    {
        printf("Enter Email ID: ");
        scanf("%s", tempEmail);
        valid = checkMail(tempEmail); // Validate email format

        // Check duplicate email
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // searchname
            if (searchName(tempEmail, addressBook->contacts[i].email) != -1)
            {
                printf("This Email already exists.\n");
                valid = 0;
                break;
            }
        }
    } while (valid == 0);
    // Store new contact
    strcpy(addressBook->contacts[addressBook->contactCount].name, tempName);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, tempNumber);
    strcpy(addressBook->contacts[addressBook->contactCount].email, tempEmail);
    addressBook->contactCount++; // Increase count
    printf("Contact succesfully created");
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int valid = 0;
    int choice;
    char tempName[50];
    char tempNumber[15];
    char tempEmail[20];
    do
    {
        // Menu options
        printf("\nSearch By:\n");
        printf("1. Name\n");
        printf("2. Phone Number\n");
        printf("3. Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Search by Name
            printf("Enter Name: ");
            scanf(" %[^\n]", tempName);
            valid = checkName(tempName);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                // Loop through all contacts
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (searchName(tempName, addressBook->contacts[i].name) != -1)
                    {
                        addressIndex = i; // Found contact
                        printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                        printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                        printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                        printf("\n");
                    }
                }

                if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }

            break;
        case 2: // Search by Phone
            printf("Enter Number: ");
            scanf("%s", tempNumber);
            valid = checkPhone(tempNumber);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    // search number returns the index of the retirved contact
                    if (searchNumber(tempNumber, addressBook->contacts[i].phone) != -1)
                    {
                        addressIndex = i;
                        break;
                    }
                }

                if (addressIndex != -1)
                {
                    // displays the contac t which have searhced
                    printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                    printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                    printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                    printf("\n");
                }
                else if (addressIndex == -1)
                {

                    printf("Contact not found");
                }
            }
            break;
        case 3: // Search by Email
            printf("Enter Email: ");
            scanf("%s", tempEmail);
            // validating if the email is correclty formatted
            valid = checkMail(tempEmail);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    // searchEmail function looks for a match in email in the contact
                    if (searchEmail(tempEmail, addressBook->contacts[i].email) != -1)
                    {
                        addressIndex = i;
                        break;
                    }
                }

                if (addressIndex != -1)
                {
                    printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                    printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                    printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                    printf("\n");
                }
                else if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (valid == 0);
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int valid = 0;
    int choice;
    char tempName[50];
    char tempNewName[50];

    char tempNumber[15];
    char tempNewNumber[15];

    char tempEmail[20];
    char tempNewEmail[20];

    int check = 0;

    do
    {
        // Menu
        printf("\nEdit By:\n");
        printf("1. Name\n");
        printf("2. Phone Number\n");
        printf("3. Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Edit Name
            printf("Enter Name: ");
            scanf(" %[^\n]", tempName);
            // validates the given number is valid or not
            valid = checkName(tempName);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                // Find name match
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (searchName(tempName, addressBook->contacts[i].name) != -1)
                    {
                        addressIndex = i;
                        break;
                    }
                }

                if (addressIndex != -1)
                {

                    printf("Contact Found!\n");
                    printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                    printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                    printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                    printf("\n");

                    // Get new name
                    do
                    {
                        printf("Enter new Name: ");
                        scanf(" %[^\n]", tempNewName);
                        // checks if the newly enterd name is valid
                        check = checkName(tempNewName);
                        // checkname returns 0 if the newly enterd name is invalid
                        if (check == 0)
                        {
                            continue;
                        }
                        // update new contact name in place of old ones
                        strcpy(addressBook->contacts[addressIndex].name, tempNewName);
                        printf("\n");
                        printf("Contact Name succesfully changed!\n");

                    } while (check == 0);
                }
                else if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }
            break;

        case 2: // edit phone number
            printf("Enter Number: ");
            scanf(" %[^\n]", tempNumber);
            valid = checkPhone(tempNumber);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                // searches for the number which needs to be replaced or edited
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (searchNumber(tempNumber, addressBook->contacts[i].phone) != -1)
                    {
                        addressIndex = i;
                        break;
                    }
                }

                if (addressIndex != -1)
                {

                    printf("Contact Found!\n");
                    printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                    printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                    printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                    printf("\n");

                    // editing the number with new number
                    do
                    {
                        printf("Enter new Number: ");
                        scanf(" %[^\n]", tempNewNumber);
                        check = checkPhone(tempNewNumber);
                        if (check == 0)
                        {
                            continue;
                        }
                        strcpy(addressBook->contacts[addressIndex].phone, tempNewNumber);
                        printf("\n");
                        printf("Contact Number succesfully changed!\n");
                    } while (check == 0);
                }
                else if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }
            break;
        case 3: // edit email
            printf("Enter Email ID: ");
            scanf(" %[^\n]", tempEmail);
            valid = checkMail(tempEmail);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (searchEmail(tempEmail, addressBook->contacts[i].email) != -1)
                    {
                        addressIndex = i;
                        break;
                    }
                }

                if (addressIndex != -1)
                {
                    // edit email

                    printf("Contact Found!\n");
                    printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                    printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                    printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                    printf("\n");
                    do
                    {
                        printf("Enter new Email ID: ");
                        scanf(" %[^\n]", tempNewEmail);
                        check = checkMail(tempNewEmail);
                        if (check == 0)
                        {
                            continue;
                        }
                        strcpy(addressBook->contacts[addressIndex].email, tempNewEmail);
                        printf("\n");
                        printf("Contact Email ID succesfully changed!\n");

                    } while (check == 0);
                }
                else if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (valid == 0);
}

void deleteContact(AddressBook *addressBook)
{
    char tempName[50];
    char tempNumber[15];
    char tempEmail[20];
    int choice;
    int valid;
    do
    {
        printf("\nDelete By:\n");
        printf("1. Name\n");
        printf("2. Phone Number\n");
        printf("3. Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // delete by name

            printf("Enter Name: ");
            scanf(" %[^\n]", tempName);
            int j = 0;
            valid = checkName(tempName);
            if (valid == 0)
            {
                break;
            }
            else
            {
                int addressIndex = -1;
                // find a match for name
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (searchName(tempName, addressBook->contacts[i].name) != -1)
                    {
                        // displays all the contact ith the same name with the
                        // index of the contact
                        addressIndex = i;
                        printf("\n----Contact Index: %d----\n", i);

                        printf("Name: %s\n", addressBook->contacts[addressIndex].name);
                        printf("Phone: %s\n", addressBook->contacts[addressIndex].phone);
                        printf("Email: %s\n", addressBook->contacts[addressIndex].email);
                        printf("\n");
                    }
                }

                if (addressIndex != -1)
                {

                    printf("\n----> Please enter the contact index correctly <----\n");
                    printf("Contact Index: ");
                    int indexChoice;
                    // inputs the index number from the user
                    scanf("%d", &indexChoice);
                    printf("\n");
                    int delChoice;
                    printf("To delete press 1, to revoke press 0: ");
                    scanf("%d", &delChoice);
                    // deltes the contact which the user enterd
                    if (delChoice == 1)
                    {
                        for (int i = indexChoice; i < addressBook->contactCount - 1; i++)
                        {
                            strcpy(addressBook->contacts[i].name, addressBook->contacts[i + 1].name);
                            strcpy(addressBook->contacts[i].phone, addressBook->contacts[i + 1].phone);
                            strcpy(addressBook->contacts[i].email, addressBook->contacts[i + 1].email);
                        }
                        // after deleting contactcount is decreased by one
                        addressBook->contactCount--;
                        saveContactsToFile(addressBook);
                        printf("\nContact Successfully deleted!!\n");
                    }
                    else
                    {
                        printf("Action revoked !");
                        break;
                    }
                }
                else if (addressIndex == -1)
                {
                    printf("Contact not found");
                }
            }
            break;

        default:
            break;
        }
    } while (valid == 0);
}
