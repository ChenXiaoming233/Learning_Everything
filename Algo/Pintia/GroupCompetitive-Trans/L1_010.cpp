#include <iostream>
 
using namespace std;
 
int main ()
{
   int a[3];
   int temp;
   cin >> a[0] >> a[1] >> a[2];
   for (int i=0; i<3-1; i++){
      for (int j=1; j<3; j++){
         if (a[j]<a[i]){
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
         }
      }
   }
   cout << a[0] << "->" << a[1] << "->" << a[2] << endl;
   

   
   return 0;
}