#include <bits/stdc++.h>
using namespace std;
unordered_map <string ,int> mp;
bool solve(string a,string b){
    string p = a+"_"+b;
    if(mp.find(p)!=mp.end()) return mp[p];
    if(a.compare(b) == 0) return true;
    if(a.length()<1) return false;
    if(a.length()==1){
        if(a[0]!=b[0]) return 0;
        else return true;
    }
    int n = a.length();
    bool ans = false;
    for(int i=1;i<n;i++){
        ans = (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)) ) ||( solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) );
        if(ans== true) return mp[p] =  true;
    }
    return mp[p] =  ans;
}
int main(){
    mp.clear();
    string a;
    string b;
    cin>>a;
    cin>>b;
    bool x = false;
    if(a.length()==b.length()){
       x =  solve(a,b);
    }
    cout<<x<<endl;
    return 0;
}