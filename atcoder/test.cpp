#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
   int Q,N;
   cin>>N>>Q;
   dsu ds(N);
   for(int i=0;i<Q;i++){
       int t,u,v;
       cin>>t>>u>>v;
       if(t==0){
           ds.merge(u,v);
       }
       else{
           cout<<ds.same(u,v)<<endl;
       }
   }
}
