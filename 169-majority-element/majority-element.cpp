class Solution {
public:
    int majorityElement(vector<int>& arr) {
    
    int n=arr.size();
    int temp;
    int count=0;
    for(int i=0;i<n;i++){
        if(count==0){
            temp=arr[i];
            count=1;
        }
        else if(arr[i]==temp){
            count++;
        }
        else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==temp){
            count++;
        }
    }
    if(count>n/2){
        return temp;
    }
    return -1;
    }
};