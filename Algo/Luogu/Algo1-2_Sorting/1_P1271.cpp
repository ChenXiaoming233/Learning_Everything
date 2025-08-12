#include <iostream>
 
using namespace std;
 
int main ()
{
   int a[1000]={0};
   int n,m,tmp;
   cin >> n >> m;
   for(int i=0; i<m; i++){
      cin >> tmp;
      a[tmp]++;
   }
   for(int i=0; i<=n; i++){
      for (int j=0; j<a[i]; j++){
         cout << i << " ";
      }
   } 
   cout << endl;
   return 0;
}