class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi=INT_MIN;
        int n=energy.size();
        for(int i=0;i<k;i++){
            int tmp=energy[i],j=i;
            j+=k;
            while(j<n){
                if(tmp<=0)tmp=energy[j];
                else tmp+=energy[j];
                j+=k;
            }
            maxi=max(maxi,tmp);
        }
        return maxi;
    }
};