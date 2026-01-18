#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 16;
    string s = "I love you Vidhi";
    for(int i=2;i<=n;i++){
        cout<<s.substr(0, i)<<endl;
    }
    for(int i=n-1;i>1;i--){
        cout<<s.substr(0, i)<<endl;
    }
}
