#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int searchName(char tempName[], char storedName[])
{
    int t = strlen(tempName);   // Length of the name entered by user
    int s = strlen(storedName); // Length of stored name from contacts

    // If lengths don't match, names cannot be equal
    if (t != s)
    {
        return -1; // Name not found
    }
    int j = 0;

    // Compare both strings character-by-character
    while (tempName[j] != '\0')
    {

        // If any character differs, names do not match
        if (tempName[j] != storedName[j])
        {
            return -1; // Not a match
        }
        j++;
    }
    return 1; // Perfect match found
}

int searchNumber(char tempNum[], char storedNumber[])
{
    int j = 0;
    // Compare digits until null terminator
    while (tempNum[j] != '\0')
    {
        // If any digit does not match, numbers are different
        if (tempNum[j] != storedNumber[j])
        {
            return -1; // Not a match
        }
        j++;
    }
    return 1; // Phone number matches
}

int searchEmail(char tempEmail[], char storedEmail[])
{
    int t = strlen(tempEmail);   // Length of email entered by user
    int s = strlen(storedEmail); // Length of stored email

    // Emails must be same length to match
    if (t != s)
    {
        return -1; // Not a match
    }
    int j = 0;

    // Compare character-by-character

    while (tempEmail[j] != '\0')
    {
        if (tempEmail[j] != storedEmail[j])
        {
            return -1; // Email does not match
        }
        j++;
    }
    return 1; // Exact match found
}