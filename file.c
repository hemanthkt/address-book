#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp;
    // Open the file in write mode (overwrites old data)
    if ((fp = fopen("contacts.csv", "w")) == NULL)
    {
        printf("contacts.csv does not exist!");
        return;
    }

    // Save total number of contacts (first line in file)
    fprintf(fp, "#%d\n", addressBook->contactCount);

    // Write each contact into CSV format
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s", addressBook->contacts[i].name);
        fprintf(fp, "%c", ',');
        fprintf(fp, "%s", addressBook->contacts[i].phone);
        fprintf(fp, "%c", ',');
        fprintf(fp, "%s", addressBook->contacts[i].email);
        fprintf(fp, "\n");
    }
    fclose(fp); // Close file after writing
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;
    // Open the file in read mode
    if ((fp = fopen("contacts.csv", "r")) == NULL)
    {
        printf("contacts.csv does not exist");
        return;
    }

    rewind(fp); // Move file pointer to the beginning

    // Read total number of contacts stored
    fscanf(fp, "#%d\n", &addressBook->contactCount);

    // Read each stored contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {

        // Read name until a comma is found
        fscanf(fp, "%[^,],", addressBook->contacts[i].name);

        // Read phone until next comma
        fscanf(fp, "%[^,],", addressBook->contacts[i].phone);
        // Read email until end of line
        fscanf(fp, "%[^\n]\n", addressBook->contacts[i].email);
    }

    fclose(fp); // Close file after reading
}
