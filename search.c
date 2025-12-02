#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int searchName(char tempName[], char storedName[])
{
    int t = strlen(tempName);
    int s = strlen(storedName);
    if (t != s)
    {
        return -1;
    }
    int j = 0;
    while (tempName[j] != '\0')
    {
        if (tempName[j] != storedName[j])
        {
            return -1;
        }
        j++;
    }
    return 1;
}

int searchNumber(char tempNum[], char storedNumber[])
{
    int j = 0;
    while (tempNum[j] != '\0')
    {
        if (tempNum[j] != storedNumber[j])
        {
            return -1;
        }
        j++;
    }
    return 1;
}

int searchEmail(char tempEmail[], char storedEmail[])
{
    int t = strlen(tempEmail);
    int s = strlen(storedEmail);
    if (t != s)
    {
        return -1;
    }
    int j = 0;
    while (tempEmail[j] != '\0')
    {
        if (tempEmail[j] != storedEmail[j])
        {
            return -1;
        }
        j++;
    }
    return 1;
}