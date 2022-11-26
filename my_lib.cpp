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

void Bubble(vector<int>& nums){
    int len=nums.size();
    bool exchange=true;
    for(int i=0;i<len&&exchange;i++){
        exchange=false;
        for(int j=len-1;j>i;j--){
            if(nums[j-1]>nums[j]){
                swap1(nums[j-1],nums[j]);
                exchange=true;
            }
        }
    }
}

void Shell1(vector<int>& nums){
    int len=nums.size();
    int d=len;
    do{
        d=d/3+1;
        for(int i=d;i<len;i+=d){
            int sub=i;
            int min=nums[sub];
            for(int j=i-d;j>=0&&nums[j]>min;j-=d){
                nums[j+d]=nums[j];
                sub=j;
            }
            if(sub!=i) nums[sub]=min;
        }
    }while(d>1);
}

void Shell2(vector<int>& nums){
    int len=nums.size();
    int d=len;
    do{
        d=d/3+1;
        bool exchange=true;
        for(int i=d==1?0:d;i<len&&exchange;i+=d){
            exchange=false;
            for(int j=(len-1)/d*d;j>i;j-=d){
                if(nums[j-1]>nums[j]){
                    swap1(nums[j-1],nums[j]);
                    exchange=true;
                }
            }
        }
    }while(d>1);
}

void merge(vector<int>& nums,vector<int>& vec,int begin,int end){
    if(begin<end){
        int mid=begin+(end-begin)/2;
        merge(nums,vec,begin,mid);
        merge(nums,vec,mid+1,end);
        int numsa=begin;
        int numsb=mid+1;
        int i=begin;
        while((numsa<=mid)&&(numsb<=end)){
            if(nums[numsa]>nums[numsb]){
                vec[i++]=nums[numsb++];
            }else{
                vec[i++]=nums[numsa++];
            }
        }
        while(numsa<=mid){
            vec[i++]=nums[numsa++];
        }
        while(numsb<=end){
            vec[i++]=nums[numsb++];
        }
        for( i=begin;i<=end;i++){
            nums[i]=vec[i];
        }
    }
}

int partition(vector<int>& nums,int begin,int end){
    int piv=nums[begin];
    while(begin<end){
        while(nums[end]>piv&&begin<end){
            end--;
        }
        swap(nums[begin],nums[end]);
        while(nums[begin]<=piv&&begin<end){
            begin++;
        }
        for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<",";
        }
        cout<<endl;
        cout<<nums[begin]<<"->"<<nums[end]<<endl;
        swap1(nums[begin],nums[end]);
    }
    cout<<"-----end-----"<<endl;
    cout<<begin<<"-"<<end<<endl;
    return begin;
}
void Quick(vector<int>& nums,int begin,int end){
    if(begin<end){
        int pivot=partition(nums,begin,end);
        Quick(nums,begin,pivot-1);
        Quick(nums,pivot+1,end);
    }
}

int main(){
    vector<int> vec={1,8,3,2,3,2,0,8,0,1,9,10};
    vector < int >* vec1=new vector <int>{1,8,3,2,3,2,0,8,9,10};
    int array[10]={1,8,3,2,3,2,0,8,9,10};

    vector<int> m_vec(vec.size(),-1);
    //Shell2(vec);
    //merge(vec,m_vec,0,vec.size()-1);
    Quick(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
