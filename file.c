#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp;
    if ((fp = fopen("contacts.csv", "w")) == NULL)
    {
        printf("contacts.csv does not exist!");
        return;
    }

    fprintf(fp, "#%d\n", addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s", addressBook->contacts[i].name);
        fprintf(fp, "%c", ',');
        fprintf(fp, "%s", addressBook->contacts[i].phone);
        fprintf(fp, "%c", ',');
        fprintf(fp, "%s", addressBook->contacts[i].email);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;

    if ((fp = fopen("contacts.csv", "r")) == NULL)
    {
        printf("contacts.csv does not exist");
        return;
    }

    rewind(fp);
    fscanf(fp, "#%d\n", &addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, "%[^,],", addressBook->contacts[i].name);
        fscanf(fp, "%[^,],", addressBook->contacts[i].phone);
        fscanf(fp, "%[^\n]\n", addressBook->contacts[i].email);
    }

    fclose(fp);
}
