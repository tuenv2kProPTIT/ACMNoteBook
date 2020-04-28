#include<bits/stdc++.h>
using namespace std;

vector<long long > fakePrime;

void fakeUp(long long fakeNumber){
    if(fakeNumber==1)return;

    for(int i=0;i<fakePrime.size();i++){
        
        long long tmp=__gcd(fakePrime[i],fakeNumber);

        if(tmp!=1){

            long long new_z=fakePrime[i];

            fakePrime[i]=tmp;

            while(new_z%tmp==0)new_z/=tmp;

            fakeUp(new_z);

            while(fakeNumber%tmp==0)fakeNumber/=tmp;

            fakeUp(fakeNumber);

            return;
        }
    }
    fakePrime.push_back(fakeNumber);
}
int main(){
    int n;
    cin>>n;
    vector<long long>pos;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        fakeUp(x);
        pos.push_back(x);
    }
    int cnt=1;
    for(int i=0;i<fakePrime.size();i++){
        int m=0;
        for(int k=0;k<n;k++){
            if(pos[k]%fakePrime[i]==0)m+=1;
        }
        cnt=max(cnt,m);
    }
    cout<<cnt;
    
}