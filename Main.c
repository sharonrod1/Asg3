#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StrList.h"
int main(void){
    int action;
    StrList* strList = NULL;
   while(1) {
        scanf("%d",&action);
        switch (action) {
            case 1:
                if (strList == NULL) {
                    strList = StrList_alloc();
                    int i;
                    scanf("%d",&i);
                    char temp[100];
                    for(int k=0;k<i;k++)
                    {
                       scanf("%s",temp);
                       StrList_insertLast(strList,temp);
                       
                    }
                }
                else {
                    printf("StrList is not allocated. Please allocate first.\n");
                } 
                break;
            case 2:
                if (strList != NULL) {
                    char data[100];
                    int index;
                    scanf("%d", &index);
                    scanf("%s", data);
                    StrList_insertAt(strList, data, index);
                } 
                break;
            case 3:
                if (strList != NULL) {
                    StrList_print(strList);
                }
                else{     
                    printf("\n");
                } 
                break;
            case 5:
                if (strList != NULL) {
                    int index;
                    scanf("%d", &index);
                    StrList_printAt(strList, index);
                } 
                break;
            case 4:
                if (strList != NULL) {
                    printf("%ld\n", StrList_size(strList));
                } 
                break;
            case 7:
                if (strList != NULL) {
                    char data[100];
                    scanf("%s", data);
                    printf("%d\n", StrList_count(strList, data));
                } 
                break;
            case 8:
                if (strList != NULL) {
                    char data[100];
                    scanf("%s", data);
                    StrList_remove(strList, data);
                } 
                break;
            case 9:
                if (strList != NULL) {
                    int index;
                    scanf("%d", &index);
                    StrList_removeAt(strList, index);
                } 
                break;
            case 6:
                printf("%d\n",StrList_printLen(strList));
                break;

            case 10:
                if (strList != NULL) {
                    StrList_reverse(strList);
                } 
                
                break;
            case 11:
                if (strList != NULL) {
                    StrList_free(strList);
                    strList = NULL; // Reset the pointer after freeing memory
                } 
                break;
            case 12:
                if (strList != NULL) {
                    StrList_sort(strList);
                } 
                break;
            case 13:
                if (strList != NULL) {
                    printf("%s\n", StrList_isSorted(strList) ? "true" : "false");
                } 
                break;
            case 0:
                printf("\n");
                StrList_free(strList);
                // free(action);
                exit(0);
            default:
                printf("Invalid action. Please try again.\n");
                StrList_free(strList);
        }
    }
    if (strList!= NULL)
    {
        StrList_free(strList);
    }
    
    StrList_free(strList);
    // free(action);
    return 0;
}