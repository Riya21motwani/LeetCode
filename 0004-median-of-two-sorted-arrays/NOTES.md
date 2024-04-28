cnt++;
j++;
}
if( newn%2==1){
return indexel2;
}
return   (double) ( (double)(indexel2)+ (double)(indexel1))/2;
}
//optimal approach
//based on symmetry
// b.s in shorter array
in case of even number of array
we will see the symmetry
if  total 10 number then 5 on left ,5 on right
if we take 2 numbers from array1 then we will take 3  number from array2
7  12 (l1) | 14(r1)  15
1  2  3 (l2) |  4 (r2)   9  11
l1>r2 then h=mid-1
|    7 (r1)  14 15
1  2  3 (l2) |  4 (r2)   9  11
l2>r1 then l=mid+1
l1=arr1[mid1-1]
l2=arr2[mid2-1]
r1=arr[mid1]
r2=arr[mid2]
median=max(l1,l2)+min(r1,r2)/2;
}