#ifndef _IPUTIL_H
#define _IPUTIL_H
#include "string_util.h"

int valid_part(char* s)
{
    int n = strlen(s);
     
    // if length of passed string is
    // more than 3 then it is not valid
    if (n > 3)
        return 0;
     
    // check if the string only contains digits
    // if not then return false
    for (int i = 0; i < n; i++)
        if (!(s[i] >= '0' && s[i] <= '9') )
            return 0;
    
     
    // if the string is "00" or "001" or
    // "05" etc then it is not valid
    if (s[0]=='0' && n > 1){
        //printf("\n I AM HERE ");
        return 0;
    }
    
    int x = atoi(s);
    //printf("%d\n",x);
    
    // the string is valid if the number
    // generated is between 0 to 255
    return (x >= 0 && x <= 255);
}

int is_valid_ip(char* ip)
{
    // if empty string then return false
    char ip_str[sz];
    strcpy(ip_str,ip);

    if (ip_str == NULL)
        return 0;
    int i, num, dots = 0;
    int temp = strlen(ip_str);
    int count = 0;
     
    // the number dots in the original
    // string should be 3
    // for it to be valid
    for (int i = 0; i < temp; i++)
        if (ip_str[i] == '.')
            count++;
    if (count != 3)
        return 0;
     
    // See following link for strtok()
   
    char *ptr = strtok(ip_str, ".");
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* after parsing string, it must be valid */
        if (valid_part(ptr))
        {
            /* parse remaining string */
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
 
    /* valid IP string must contain 3 dots */
    // this is for the cases such as 1...1 where
    // originally the no. of dots is three but
    // after iteration of the string we find
    // it is not valid
    if (dots != 3)
        return 0;
    return 1;
}


void make_int_segments(char* str, int segments[]){
    char *ptr = strtok(str, ".");
    if (ptr == NULL){
        printf("Error\n");
        exit(EXIT_FAILURE);        
    }
        
    int i=0;
    while (ptr) {        
        if (valid_part(ptr))
        {   
            segments[i] = atoi(ptr);
            //printf("%d\n",segments[i]);
            i++;
            
            /* parse remaining string */
            ptr = strtok(NULL, ".");           
        }
    }
    
}
#endif