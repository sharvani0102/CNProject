#ifndef _GEN_NETWORK_H
#define _GEN_NETWORK_H
#include "string_util.h"
#include "suffix.h"
#include <time.h>
#include <math.h>


void generate_Subnet_IP(int mask_segments[],int network_segments[],char* db_name){

    FILE *fp;
    fp = fopen(db_name,"w+");

    srand(time(0));
    int a,b,c,d;
    int suffix_segments[4];
    int ip_segments[4];

    int upper = 255;
    int lower = 0;
    int l=1;

    for(int j=0; j < 10 ; ++j){

    ip_segments[0]= (rand() % (upper-l+1)) + l;
    ip_segments[1]= (rand() % (upper-lower+1)) + lower;
    ip_segments[2]= (rand() % (upper-lower+1)) + lower;
    ip_segments[3]= (rand() % (upper-lower+1)) + lower;

    for(int i=0 ; i<=3 ; ++i){
        suffix_segments[i] = ip_segments[i] & (~mask_segments[i]);
        ip_segments[i] = suffix_segments[i] + network_segments[i];
    }

    //printf("\n Random ip within the subnet is : ");
    //printf("%d.%d.%d.%d\n",ip_segments[0],ip_segments[1],ip_segments[2],ip_segments[3]);
    char buffer[256],temp[256];

    itoa(ip_segments[0],temp);
    //printf("%s\n",temp);
    strcpy(buffer,temp);
    strcat(buffer,".");
    //printf("%s\n",buffer);

    itoa(ip_segments[1],temp);
    strcat(buffer,temp);
    strcat(buffer,".");
    //printf("%s\n",buffer);

    itoa(ip_segments[2],temp);
    strcat(buffer,temp);
    strcat(buffer,".");
    //printf("%s\n",buffer);

    itoa(ip_segments[3],temp);
    strcat(buffer,temp);

    fprintf(fp,"%s\n",buffer);

   }

}

int calc_upper_limit(int prefix_length){

    int u=0;
    for(int i =0 ; i < prefix_length ; ++i){
        u = u + pow(2,8-prefix_length+i);
    }

    return u;

}

void generate_Network(int suffix_length,char*mask,char* db_name[]){

    int prefix_length = 32-suffix_length;
    int a,b,c,d;
    int upper = 255;
    int lower = 1;
    int l=1;
    srand(time(0));

    int mask_segments[4];
    char mask_temp[50];
    strcpy(mask_temp,mask);
    make_int_segments(mask_temp,mask_segments);

    int status = prefix_length/8;

    for(int i=0; i<3 ; ++i){
        
        switch(status){

            case 1 : a = (rand() % (upper-l+1)) + l;
                    b =0;
                    c=0;
                    d=0;
                    break;
            case 2 : a = (rand() % (upper-l+1)) + l;
                    b = (rand() % (upper-lower+1)) + lower;
                    c=0;
                    d=0;
                    break;
            case 3:  a = (rand() % (upper-l+1)) + l;
                    b =(rand() % (upper-lower+1)) + lower;
                    c=(rand() % (upper-lower+1)) + lower;
                    d=0;
                    break;
            case 0 : upper = calc_upper_limit(prefix_length);
                    lower = pow(2,8-prefix_length);
                    a = (rand() % (upper-lower+1)) + lower;
                    b=0;
                    c=0;
                    d=0;
                    break;
        }


        char buffer[size],temp[size];
        //printf("%d.%d.%d.%d\n",a,b,c,d);

        itoa(a,temp);
        //printf("%s\n",temp);
        strcpy(buffer,temp);
        strcat(buffer,".");
        //printf("%s\n",buffer);

        itoa(b,temp);
        strcat(buffer,temp);
        strcat(buffer,".");
        //printf("%s\n",buffer);

        itoa(c,temp);
        strcat(buffer,temp);
        strcat(buffer,".");
        //printf("%s\n",buffer);

        itoa(d,temp);
        strcat(buffer,temp);

        printf("%s\n",buffer);

        int ip_segments[] = {a,b,c,d};
        
        generate_Subnet_IP(mask_segments,ip_segments,db_name[i]);
    }

}

#endif
