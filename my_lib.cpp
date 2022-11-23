#undef __STRICT_ANSI__
#include <iostream>
#include <vector>
#include "Sort.h"

using namespace mylib;
using namespace std;

template<typename T>
void swap1(T& a,T& b ){
    T c(a);
    a=b;
    b=c;
}

void insert(vector<int>& dp){
    for(int i=1;i<dp.size();i++){
        int min=i;
        int num=dp[min];
        for(int j=i-1;j>=0&&dp[j]>num;j--){
            dp[j+1]=dp[j];
            min=j;
        }
        if(min!=i) dp[min]=num;
    }
}



int main()
{
    vector<int> vec={1,8,3,2,0,8,9,10};
    insert(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
	return 0;
}
