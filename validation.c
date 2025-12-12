#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

int checkName(char name[])
{
    int i = 0;
    int flag = 0;
    // Loop through each character in the name
    while (name[i] != '\0')
    {
        // Allow only alphabets (A–Z, a–z) and spaces
        if (name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' ')
        {

            flag = 1; // valid charecter found
            i++;      // continue checking
        }
        else
        {
            // if any invalid charecter is found, show error
            printf("Enter a valid name. Only use alphabets\n");
            return flag = 0;
        }
    }

    return flag; // Returns 1 if valid, 0 if invalid
}

int checkPhone(char phone[])
{
    int i = 0;
    int count = 0;

    // Count number of digits in phone number
    while (phone[i] != '\0')
    {
        i++;
        count++;
    }

    // Phone number must be exactly 10 digits
    if (count == 10)
    {
        int j = 0;
        int flag = 0;

        // Check if every character is a digit
        while (phone[j] != '\0')
        {
            if (phone[j] >= '0' && phone[j] <= '9')
            {
                flag = 1; // Valid digit
            }
            else
            {
                // If a non-digit character is found, reject
                flag = 0;
                printf("The phone number you have entered is invalid!\n");
                return flag;
            }
            j++;
        }

        return flag; // Valid 10-digit number
    }
    else
    {
        // If digits are not exactly 10
        printf("Please enter 10 digits\n");
        return 0;
    }
}

int checkMail(char mail[])
{
    char domain[10] = "@gmail.com"; // Expected email domain
    int atIndex = -1;               // Position of '@' in email
    int bodyLength = 0;

    // Email cannot start with '@'
    if (mail[0] == '@')
    {
        printf("Invalid email\n");
        return 0;
    }
    int i = 0;
    int flag = 0;

    // Scan through the email to find '@' and check uppercase letters
    while (mail[i] != '\0')
    {
        // Reject uppercase letters (email must be lowercase)
        if (mail[i] >= 'A' && mail[i] <= 'Z')
        {
            printf("No capital letters are allowed!\n");
            return 0;
        }

        // Record the first '@' symbol position
        if (mail[i] == '@' && atIndex == -1)
        {
            atIndex = i;
        }
        i++;
    }

    // Body = part before '@'
    bodyLength = atIndex;

    // Body cannot be too short (single character not allowed)
    if (bodyLength <= 1)
    {
        printf("Too small, Invalid!");
        return 0;
    }

    // Validate characters in the body (before '@')
    for (int i = 0; i < bodyLength; i++)
    {
        // Numbers allowed
        if (isdigit(mail[i]))
        {
            continue;
        }
        // Letters allowed only (no symbols)
        if (isalpha(mail[i]) == 0)
        {
            printf("No symbols are allowed!\n");
            return 0;
        }
    }
    // If '@' never appeared, email is invalid
    if (atIndex == -1)
    {
        printf("@ is missing");
        return 0;
    }
    // Check if the domain matches "@gmail.com"
    i = 0;
    while (mail[atIndex] != '\0')
    {
        atIndex++;
        i++;
        // Compare each character with expected domain
        if (mail[atIndex] != domain[i])
        {
            printf("Domain name is incorrect!\n");
            return 0;
        }
    }

    return 1; // Email is valid
}