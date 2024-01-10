 /*
Functions
---------
acc_strlen
acc_low2up
acc_strcat
acc_strcmp
acc_strrev

// finds the length of a string

int acc_strlen(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

char acc_low2up(const char string[], string2[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if ('a' <= string[i] <= 'z')
        {
            string2[i] = string[i] - ('a' - 'A');
        }
    }
}

char acc_strcat(char initial[], char append[])
{
    char output_string[128] = "";
    for (int i = 0; initial[i] != '\0'; i++)
    {
        output_string[i] = initial[i];
    }
    for (int c = 0; append[c] != '\0'; c++)
    {
        output_string[c + acc_strlen(initial)] = append[c];
    }

    return output_string;
}

int acc_strcmp(char string_one[], char string_two[])
{
    int i = 0;
    while ((string_one[i] != '\0') || (string_two[i] != '\0'))
    {
        if (string_one[i] != string_two[i])
        {
            if (string_one[i] - string_two[i] > 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}

char acc_strrev(char input_string[])
{
    int array_length = sizeof(input_string) / sizeof(input_string[0]);
    char output_string[64] = "";
    int i = 0;
    while (i < array_length - 1)
    {
        output_string[array_length - i] = input_string[i];
    }
    return output_string;
}
