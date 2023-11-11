#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std; 
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int size1=nums1.size();
            int size2=nums2.size();
            int flag;
            int med1,med2;

            if((size1+size2)%2==0)
            {
                flag=1;
            }
            else 
                flag=0;
                int med=(size1+size2)/2;
            int r1=size1-1,r2=size2-1,l1=0,l2=0;
          
            while(r1+r2-l1-l2>5)
            {
                 med1=(r1+l1)/2;
                med2=(r2+l2)/2;
                if(nums1[med1]>nums2[med2])
                {
                   l2=med2;
                   r1=med1;

                }
                else
                {
                    
                    l1=med1;
                    r2=med2;
                }
                       
            }

            
            int f=1;
            while(f)
            {
                while(l1+l2<med-1)
                {
                    if(nums1[l1]<nums2[l2])
                    {
                        l1++;
                              
                    }
                    else
                    {
                    	                    
					}
                    l2++;
                }
               if(nums1[l1+1]>nums2[l2+1])
               {
                   if(nums1[l1]<nums2[l2+1]||l1<0||l2<0||l1==size1-1||l2==size2-1)
                    f=0;
                    else 
                    {
                        l1--;
                        l2++;
       
                    }
               }
               else
               {
                    if(nums1[l1+1]>nums2[l2]||l1<0||l2<0||l1==size1-1||l2==size2-1)
                    f=0;
                    else 
                    {
                        l1++;
                        l2--;

                    }                  
               }
            }

            if(flag==1)
            {
            	 if(l1<0)
            	 {
            	 	return double(nums2[l2-1]+nums2[l2])/2;
				 }
				 else if(l2<0)
				 {
				 return double(nums1[l1-1]+nums1[l1])/2;	
				 }
				 else if(nums1[l1]<nums2[l2])
                {
                	
                	if(l2-1<0||nums1[l1]>nums2[l2-1])
                	{
                		return double(nums1[l1]+nums2[l2])/2;	
					}
					else 
					{
						return double(nums2[l2-1]+nums2[l2])/2;
					}
				}
				else if(nums1[l1]>nums2[l2])
				{
					if(l1-1<0||nums2[l2]>nums1[l1-1])
                	{
                		return double(nums1[l1]+nums2[l2])/2;	
					}
					else 
					{
						return double(nums2[l1-1]+nums2[l1])/2;
					}
				}
            }
            else
            {
                if(l1<0||nums1[l1]<nums2[l2])
                {
                    return double(nums2[l2]);
                }
                else
                {
                    return double(nums1[l1]);
                }
            }
    }
    int main()
    {
    	vector<int> nums1={1,2,3,5,7};
		vector<int> nums2={6,8,9,10};
		vector<int> n1={1,3,6,7,8,9,11,34,67};
		vector<int> n2={2,4,5,12,56,78,97,112,445,667,889,991};
    	
    	double s=findMedianSortedArrays(n1,n2);
    	cout<<"result"<<s<<endl;
    	return 0;
	}
