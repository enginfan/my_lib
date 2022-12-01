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

int partition(vector<int>& nums,int begin,int end){
    if(begin<end){
        int pivot=nums[begin];
        while(begin<end){
            while(nums[end]>pivot&&begin<end) end--;
            swap(nums[begin],nums[end]);
            while(nums[begin]<=pivot&&begin<end) begin++;
            swap(nums[begin],nums[end]);
        }
        return begin;
    }
}
void quick(vector<int>& nums,int begin,int end){
    if(begin<end){
        int pivot=partition(nums,begin,end);
        quick(nums,begin,pivot-1);
        quick(nums,pivot+1,end);
    }
}

int main(){
    vector<int> vec={1,8,3,2,3,2,0,8,0,1,9,10};
    int array[10]={1,8,3,2,3,2,0,8,9,10};

    vector<int> m_vec(vec.size(),-1);
    //shell(vec);
    //merge(vec,m_vec,0,vec.size()-1);
    quick(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
        cout<<",";
    }
    cout<<endl;
    return 0;
}
