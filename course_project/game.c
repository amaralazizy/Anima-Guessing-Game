#include <stdio.h>
#include "database.h"



int main() {
    //TODO: to be removed from this file
	FILE* fp;

    errno_t err;

    if ((err = fopen_s(&fp ,"database.txt", "w+")) != 0) {
        // This indicates that the file can not be opened 
        // will print the error message
        fprintf(stderr, "cannot open file '%s': %s\n",
            "database.txt", strerror(err));
    }
    else {
		fprintf(fp, "(\"does it live in water ?\"whale\" (\"Does it have four legs ? \" \"cat\" \"elephant\")) ");
        // whale
        // does it live in water
		fclose(fp);
    }
}