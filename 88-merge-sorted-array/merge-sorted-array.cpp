class Solution {
public:
    void merge(vector<int>& arr,int low,int mid,int high){
        int ls=mid-low+1;
        int rs=high-mid;
        vector<int>lr(ls);
        vector<int>rr(rs);
        for(int i=0;i<ls;i++){
            lr[i]=arr[low+i];
        }
        for(int i=0;i<rs;i++){
            rr[i]=arr[mid+i+1];//+1
        }
        int i=0,j=0,k=low;
        while(i<ls && j<rs){
            if(lr[i]<=rr[j]){
                arr[k++]=lr[i++];
            }
            else{
                arr[k++]=rr[j++];
            }
        }
        while(i<ls){
            arr[k++]=lr[i++];
        }
        while(j<rs){
            arr[k++]=rr[j++];
        }
    
    }
    void mergesort(vector<int>& arr,int low,int high){
        if(low<high){
            int mid=low+(high-low)/2;
            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        mergesort(nums1,0,n+m-1);
    }
};