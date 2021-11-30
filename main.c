#include "generate_nw.h"
#include "network.h"
#include "suffix.h"
#define db1 "IPAddress.txt"
#define db2 "IPAddress2.txt"
#define db3 "IPAddress3.txt"


int main(){
    char ip[50],mask[50];
    printf("Enter your chosen ip address and mask\n");
    scanf("%s",ip);
    scanf("%s",mask);
    
    is_valid_ip(ip) ? printf("\n\nThe given ip address is valid!\n") : printf("\n\nThe given ip address is not valid!\n");
    printf("-------------------------------------------------------------------------------");
    printf("\n\nWe now move on to finding the Network Address for this ip address\n\n");
    find_network_address(ip,mask);
    printf("\nThe network address for the given ip and mask is %s\n\n",nw_addr);

    printf("-------------------------------------------------------------------------------");
    printf("\n\nCalculating the block size for the given network...\n\n");
    //printf("\n%s before suffix len()\n",mask);
    int suffix_length = find_suffix_length(mask);
    //printf("\n%s after suffix len()\n",mask);
    int block_size = find_block_size(mask);
    //printf("\n%s after block size()\n",mask);
    printf("\n\nThe block size of the network is %d\n\n ",block_size);
    printf("-------------------------------------------------------------------------------");
    
    printf("\n\nGenerating three random network addresses with the block size %d\n\n",block_size);
    char* filenames[] = {db1,db2,db3};
    generate_Network(suffix_length,mask,filenames);

    return 0;
}