#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

int checkName(char name[])
{
    int i = 0;
    int flag = 0;
    while (name[i] != '\0')
    {
        if (name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' ')
        {

            flag = 1;
            i++;
        }
        else
        {
            printf("Enter a valid name. Only use alphabets\n");
            return flag = 0;
        }
    }

    return flag;
}

int checkPhone(char phone[])
{
    int i = 0;
    int count = 0;
    while (phone[i] != '\0')
    {
        i++;
        count++;
    }

    if (count == 10)
    {
        int j = 0;
        int flag = 0;
        while (phone[j] != '\0')
        {
            if (phone[j] >= '0' && phone[j] <= '9')
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                printf("The phone number you have entered is invalid!\n");
                return flag;
            }
            j++;
        }

        return flag;
    }
    else
    {
        printf("Please enter 10 digits\n");
        return 0;
    }
}

int checkMail(char mail[])
{
    char domain[10] = "@gmail.com";
    int atIndex = -1;
    int bodyLength = 0;
    if (mail[0] == '@')
    {
        printf("Invalid email\n");
        return 0;
    }
    int i = 0;
    int flag = 0;
    while (mail[i] != '\0')
    {
        if (mail[i] >= 'A' && mail[i] <= 'Z')
        {
            printf("No capital letters are allowed!\n");
            return 0;
        }

        if (mail[i] == '@' && atIndex == -1)
        {
            atIndex = i;
        }
        i++;
    }
    bodyLength = atIndex;
    if (bodyLength <= 1)
    {
        printf("Too small, Invalid!");
        return 0;
    }

    for (int i = 0; i < bodyLength; i++)
    {
        if (isdigit(mail[i]))
        {
            continue;
        }
        if (isalpha(mail[i]) == 0)
        {
            printf("No symbols are allowed!\n");
            return 0;
        }
    }

    if (atIndex == -1)
    {
        printf("@ is missing");
        return 0;
    }
    i = 0;
    while (mail[atIndex] != '\0')
    {
        atIndex++;
        i++;
        if (mail[atIndex] != domain[i])
        {
            printf("Domain name is incorrect!\n");
            return 0;
        }
    }

    return 1;
}