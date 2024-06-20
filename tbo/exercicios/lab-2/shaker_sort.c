#include "item.h"

//shaker sort
void sort(Item *a, int lo, int hi){
    int i, j, k;
    for (i=lo, j=hi; i<j; i++, j--){
        for (k=i; k<j; k++){
            if (less(a[k+1], a[k])){
                exch(a[k], a[k+1]);
            }
        }
        for (k=j; k>i; k--){
            if (less(a[k], a[k-1])){
                exch(a[k], a[k-1]);
            }
        }
    }
}