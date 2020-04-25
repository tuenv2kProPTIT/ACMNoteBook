#include<bits/stdc++.h>

using namespace std;

template<class T> struct BIT
{
    vector<T>Tree;
    int maxVal;
    // int offset=1
    BIT(int maxValue=1000006){

        maxVal=maxValue+5;
        Tree.assign(maxVal,0);
    }
    void update(int i,T val){
        for(;i<maxVal;i|=(i+1)){
            Tree[i]+=val;
        }
    }
    T query(int i){
        T ans=0;
        while(i>=0){
            ans+=Tree[i];
            i&=(i+1);
            i--;
        }
        return ans;
    }
};

int main(){
    // test runtime o(log(n)) update and o(log(n)) query 
    BIT<int> fenwicktre;
    fenwicktre.update(2,3); // update val[2]+=3
    fenwicktre.update(1,3);
    fenwicktre.update(5,3); // -> [0,3,3,0,3] 
    cout<<fenwicktre.query(4)<<endl; // query_sum(0->4)=6

}

