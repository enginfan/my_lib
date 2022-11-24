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



void shell(vector<int>& nums){
    int d=nums.size();
    int len=nums.size();
    do{
        d=d/3+1;
        bool exchange=true;
        for(int i=(d==1)?0:d;i<len&&exchange;i+=d){
            cout<<"i="<<i<<endl;
            for(int j=((len-1)/d)*d;j>i;j-=d){
                cout<<"j="<<j<<endl;
                exchange=false;
                if(nums[j-d]>nums[j]){
                    cout<<nums[j-d]<<"->"<<nums[j]<<endl;
                    swap1(nums[j-d],nums[j]);
                    exchange=true;
                }
            }
        }
    }while(d>1);

}


int main(){
    vector<int> vec={1,8,3,2,3,2,0,8,9,10};
    vector < int >* vec1=new vector <int>{1,8,3,2,3,2,0,8,9,10};
    int array[10]={1,8,3,2,3,2,0,8,9,10};
    //Sort::Shell(array,10);
    shell(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
