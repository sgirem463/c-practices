#include "stdlib.h"
#include "stdio.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int fhandle;

/*
 * return a line upto a newline '\n'
 * by using read256()
 */

int read256(char *buf)
{
    int n;

    n = read(fhandle, buf, 256);
    return n;
}

int firstTime = 1;

char *readLine2(void)
{
    static char buf[1024];
    static int lineSize = 0;
    static int index = 0;

    char *p = malloc(1024);
    memset(p, 0, 1024);
    int i = 0;

    if (firstTime) {
        lineSize = read256(buf);
        index = 0;
        if (lineSize == 0) {
            return p; // return NULL string indeed
        }
        if (lineSize == -1) {
            printf("read file error!!\n");
            exit(1);
        }
        firstTime = 0;
    }
    while ((p[i++] = buf[index++]) != '\n') {
        if (index == lineSize) {
            memset(buf, 0, 1024);
            lineSize = read256(buf);
            index = 0;
            if (lineSize == 0) {
                break;
            }
            if (lineSize == -1) {
                printf("read file error!!\n");
                exit(1);
            }
        }
    }
    return p;
}


char *readLine(void)
{
    static char buf[1024];
    static int lineSize = 0;
    static int index = 0;

    char *p = malloc(1024);
    int i = 0;

    /*
     * read until '\n'
     */
    do {
        if (lineSize == 0 || index == lineSize) {
            lineSize = read256(buf);
            index = 0;
            if (lineSize == -1) {
                printf("error!! \n");
                exit(1);
            }
            if (lineSize == 0) {
                break;
            }
        }
    } while ((p[i++] = buf[index++]) != '\n');
    return p;
}


char *readLineNew()
{
    char *buffer = malloc(1024);
    static char p256[256];
    static int i;
    static int lineSize;
    char *q;

    if (lineSize == 0) {
        lineSize = read256(p256);
        if (lineSize == 0)
            return &buffer[0];
        i = 0;
    } 

    q = &buffer[0];
    while ((*q++ = p256[i++]) != '\n') {
        if (i == lineSize) {
            lineSize = read256(p256);
            if (lineSize == 0)
                break;
            i = 0;
        }
    } 
    return &buffer[0];
}

int main(void)
{
    fhandle = open("readlineData.txt", O_RDONLY);
    char *p;
    char buf[1024];
    int r;

    do {
        p = readLineNew();
        printf("%s", p);

    } while (p[0] != 0);
}
