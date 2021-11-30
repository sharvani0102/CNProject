#ifndef _SUFFIX_H
#define _SUFFIX_H
#include "string_util.h"
#include "ip_util.h"

int find_suffix_length(char mask[]){
    int mask_segments[4];
    int i,count=0;
    char mask_temp[50];
    strcpy(mask_temp,mask);
    make_int_segments(mask_temp,mask_segments);

    // for (i=0 ; i < 4; i++)
    // {
    //     //printf("\nhello yaar\n");
    //     printf("%d\t",mask_segments[i]);
    //     //printf("\nhi yaar\n");

    // }
    //printf("\n\n");
    
    i = 3;
    while(i>=0){
        if(mask_segments[i]==0){
            count+=8;
            i--;
        }
        else break;
    }
    int curr_seg = i;
    i = 1;

    while((mask_segments[curr_seg] & i) == 0){
        count++;
        i=i<<1;
    }

    return count;
}

int find_block_size(char mask[]){
    char mask_temp[50];
    strcpy(mask_temp,mask);
    int suffix_len = find_suffix_length(mask_temp);
    return pow(2,suffix_len);
}

#endif