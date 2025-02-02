#include<iostream>
#include<vector>
using namespace std;
int main()
{   vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    vector<int> ans;
        int left = 0;
        int right = 0;
        while(left < nums1.size() && right < nums2.size() )
        {
            if(nums1[left] <= nums2[right])
            {
                ans.push_back(nums1[left]);
                left++;
            }
            else
            {
                ans.push_back(nums2[right]);
                right++;
            }
        }

        while(left < nums1.size())
        {
            ans.push_back(nums1[left]);
            left++;
        }

        while(right < nums2.size())
        {
            ans.push_back(nums2[right]);
            right++;
        }
       
       for (int i = 0; i < ans.size(); i++)
       {
         cout<<ans[i];
       }
       cout<<endl;

        int length = ans.size();

        double median;
        if(length % 2 == 0)
        {
            int mid = length /2;
            cout<<endl<<mid;
            median = (ans[mid] + ans[mid-1]) / 2.00;
    
        }
        else
        {
            int mid = length/2;
            median = ans[mid];
        }
       cout<<median;
}
