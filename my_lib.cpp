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

int Partition(vector<int>& nums,int begin,int end){
    if(begin<end){
        int pivot=nums[begin];
        while(begin<end){
            while(begin<end&&nums[end]>pivot){
                end--;
            }
            swap(nums[end],nums[begin]);
            while(begin<end&&nums[begin]<=pivot){
                begin++;
            }
            swap(nums[begin],nums[end]);
        }
        return begin;
    }
}

void Quick(vector<int>& nums,int begin,int end){
    if(begin<end){
        int pivot=Partition(nums,begin,end);
        Quick(nums,begin,pivot-1);
        Quick(nums,pivot+1,end);
    }
}



int main(){
    vector<int> vec={1,8,3,2,3,2,0,8,9,10};
    vector < int >* vec1=new vector <int>{1,8,3,2,3,2,0,8,9,10};
    int array[10]={1,8,3,2,3,2,0,8,9,10};
    //Sort::Shell(array,10);
    vector<int> m_vec(vec.size(),-1);
    Quick(vec,0,vec.size()-1);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
