#ifndef _NETWORK_H
#define _NETWORK_H
#include "string_util.h"
#include "ip_util.h"


void find_network_address(char* ip, char* mask){

    //printf("hello from find_nw_addr\n");
    int ip_segments[4];
    int mask_segments[4];
    int nw_segments[4];
    int i=0;


    char *ptr = strtok(ip, ".");
    if (ptr == NULL)
        strcpy(nw_addr,"error");// "error";
 
    printf("\n IP Segments\n ");
    while (ptr) {        
        if (valid_part(ptr))
        {   
            ip_segments[i] = atoi(ptr);
            printf("\t%d\n",ip_segments[i++]);
            /* parse remaining string */
            ptr = strtok(NULL, ".");           
        }
    }

    i=0;
    char mask_temp[50];
    strcpy(mask_temp,mask);
    char *mask_ptr = strtok(mask_temp, ".");
    if (mask_ptr == NULL)
        strcpy(nw_addr,"error");//return "error";

    printf("\n Mask Segments\n ");
 
    while (mask_ptr) {        
        if (valid_part(mask_ptr))
        {   
            mask_segments[i] = atoi(mask_ptr);
            printf("\t%d\n",mask_segments[i++]);
            /* parse remaining string */
            mask_ptr = strtok(NULL, ".");            
        }
    }

    printf("\n Network segments \n");
    for (int i = 0; i < 4; i++)
    {
        nw_segments[i] = mask_segments[i] & ip_segments[i];
        printf("\t%d\n",nw_segments[i]);
    }

    char nw_char_segments[4][len];
    

    for (int i = 0; i < 4; i++)
    {
         itoa(nw_segments[i],nw_char_segments[i]);
         //printf("%s\n",nw_char_segments[i]);
    }

    printf("\n");

    strcpy(nw_addr,nw_char_segments[0]);

    for (int i = 1; i < 4; i++)
    {
        strcat(nw_addr,".");
        strcat(nw_addr,nw_char_segments[i]);
        //printf("%s\n",nw_addr);
    }

    //return nw_addr;
    
}

#endif