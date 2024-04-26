with the help of index and arr[index] we can find the number that are missing exp{11-4-1 =6} therefore 6 number are missing in index 4;
similarly {7-3-1} therfore 3 number are missing in index 3
and we need to find missing number at  position  k=5;
therefore  5 lie in between 3 and 6 so we need to apply bs;
now,ans=arr[high]+moreneeded
moreneeded=k-(arr[high]-high-1);
ans=k+high+1;