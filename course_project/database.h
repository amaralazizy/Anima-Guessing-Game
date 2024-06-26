#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

void initDatabase() {
    FILE* ptr;
    fopen_s(&ptr, "database.txt", "a+");
    //TODO: check if the file does not exist or if it is empty
    if (NULL != ptr) {
        fseek(ptr, 0, SEEK_END);
        long size = ftell(ptr);

        if (0 == size) {
            fprintf(ptr, "Does it live in water? \nwhale\n\ncat\n\n");
        }
    }
    fclose(ptr);
    //TODO: if yes then write the first question:
    //Does it live under water? 
    //whale
    //
    //cat
    //
    //TODO: if no then return
}

line *filetext()
{
    FILE *ptr;
    line *head = (line *)malloc(sizeof(line));
    head->next = NULL;
    char str[300];
    fopen_s(&ptr, "database.txt", "a+");

    if (ptr == NULL)
    {
        printf("file can't be opened \n");
    }

    fgets(str, 300, ptr);
    strcpy_s(head->text, 300, str);

    int i = 1;
    while (fgets(str, 300, ptr) != NULL)
    {
        insertLine(i, str, &head);
        i++;
    }
    fclose(ptr);
    return head;
}

void writeData(line *lines)
{
    FILE *fp;

    errno_t err;

    if ((err = fopen_s(&fp, "database.txt", "w")) != 0)
    {
        // This indicates that the file can not be opened
        // will print the error message
        fprintf(stderr, "cannot open file '%s': %s\n",
                "database.txt");
    }
    else
    {
        line *temp = lines;
        while (temp) {
            fprintf(fp, temp->text);
            temp = temp->next;
        }
        fclose(fp);
    }
}