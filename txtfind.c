#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

int getLine(char s[])
{
    if(s == NULL) return 0;
    int counter = 0;
    char c=' ';
    for(int i = 0 ; i < LINE ; i++){
        scanf("%c", &c);
        if(c == '\n' || c == '\r')
        {
            counter++;
            s[i] = 0;
            return counter;
        }
        s[i] = c;
        counter++;
    }
    return counter;
}

int getWord(char w[])
{
    if(w == NULL) return 0;
    int counter = 0;
    char c=' ';
    for(int i = 0 ; i < WORD ; i++){
        scanf("%c", &c);
        if(c == '\n' || c == '\t' || c == ' ' || c == '\r')
        {
            counter++;
            w[i] = 0;
            return counter;
        }
        w[i] = c;
        counter++;
    }
    return counter;
}

int substring( char * str1, char * str2)
{
    if(str1 == NULL || str2 == NULL) return 0;
    char *found_string = strstr(str1, str2);
    if(found_string == NULL) return 0;
    else return 1;
}

int similar (char *s, char *t, int n)
{
    if(s == NULL || t == NULL) return 0;
    int len1 = strlen(s);
    int len2 = strlen(t);
    int c = 0;
    int i = 0, j = 0;
    while(i < len1)
    {
        if(s[i] != t[j]){
            i++;
            c++;
        }
        else{
            i++;
            j++;
        }
    }
    if(j < len2) return 0;
    if(c > n) return 0;
    return 1;
}

void print_lines(char * str)
{
    if(str == NULL) return;
    char string[LINE];
    int contains = 0;
    int numc = 0;
    for(int i = 0 ; i< 250 ;i++)
    {
        numc = getLine(string);
        if(numc == 0) return; //if string is empty line
        contains = substring(string, str);
        if(contains)
        {
            printf("%s\n", string);
        }
    }
    
}

void print_similar_words(char * str)
{
    if(str == NULL) return;
    char word[WORD];
    int contains = 0;
    int numc = 0;
    for(int i = 0 ; i< 250*LINE ;i++)
    {
        numc = getWord(word);
        if(numc == 0) return; //if word is empty
        contains = similar(word, str, 1);
        if(contains)
        {
            printf("%s\n", word);
        }
    }
}

int main(){

    char func = ' ';
    char word[WORD];
    getWord(word);
    scanf("%c", &func);

    if(func == 'a')
    {
        print_lines(word);
    }
    else if(func == 'b')
    {
        print_similar_words(word);
    }
    else printf("change");


    return 0;
}