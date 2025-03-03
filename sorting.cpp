#include <bits/stdc++.h>
using namespace std;

class sorting{
public:
    void bubble(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        
        
    }
    void selection(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
        
            int ind=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[ind]){
                    
                    ind=j;
                }
            }
            swap(nums[i],nums[ind]);
        }
    }
    void insertion(vector<int>&nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            int j=i-1;
            int ind=i;
            while(j>=0&&(nums[ind]<nums[j])){
                swap(nums[ind],nums[j]);
                ind--;
                j--;
            }
        }
    }
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid&&right<=high){
            if(arr[left]<arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
                temp.push_back(arr[left]);
                left++;        
            
        }
        while(right<=high){
                temp.push_back(arr[right]);
                right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergesort(vector<int>&nums,int low ,int high){
        if(low>=high)return;
        int mid=(low +high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    void print(vector<int>input){
        for(int x:input)
            cout<<x<<" ";
    }
    int partition(vector<int>&nums,int low,int high){
        int privot=nums[high];
        int i=low-1;
        for(int j=low;j<=high;j++){
            if(nums[j]<privot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
    void quicksort(vector<int>&nums,int low,int high){
        if(low>=high)
            return;
        int pi=partition(nums,low,high);
        quicksort(nums,low,pi-1);
        quicksort(nums,pi+1,high);
    }
};
int main()
{    
    vector<int>input={64, 34, 25, 12, 22, 11, 90};
    sorting obj;
   

  return 0;
}