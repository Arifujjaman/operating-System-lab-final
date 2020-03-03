#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int ref[30],q[30],dis[30];
    int i,j,k;
    int s,e,pos,N,size,max,count=0;

    printf("Enter reference string length: ");
    scanf("%d",&N);
    printf("Number of frame:");
    scanf("%d",&size);

    printf("Enter reference string: ");

    for(i=0; i<N; i++)
        scanf("%d",&ref[i]);

    s=e=pos=0;
    for(i=0; i<N; i++) {
        printf("%d  =",ref[i]);

        int found=0;

        for(j=s; j<e; j++) {
            if(ref[i]==q[j])
                found=1;
        }


        if(found==1)
            printf("\n");
        else {
            if(e<size) {
                q[e++]=ref[i];
                count++;
            }
            else {
                for(j=0; j<size; j++) {
                    for(k=i; k>=0; k--) {
                        if(ref[k]==q[j])
                            break;
                    }
                    dis[j]=i-k;
                }
                max=0;
                for(j=1; j<size; j++) {
                    if(dis[j]>dis[max])
                        max=j;
                }

                q[max]=ref[i];
                count++;
            }

            for(j=s; j<e; j++)
                printf(" %3d",q[j]);
            printf("\n");
        }
    }

    printf("\nNumber of page fault: %d",count);

    return 0;
}
/*
20
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/


