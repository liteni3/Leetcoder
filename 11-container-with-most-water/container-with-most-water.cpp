class Solution {
public:
    int maxArea(vector<int>& h) { 
        int ans = 0 ;
        int left = 0 ;
        int right = h.size()-1 ;
        while( left < right){

            if( h[left] < h[right])
            ans = max( ans , h[left] * (right-left) ) ;
            else 
             ans = max( ans, h[right] * (right-left) ) ;


            if( h[left] < h[right] ) 
               left++ ;
            else if(  h[left] > h[right]  ) 
               right--;
            else{
                left++ ;
                right--;
            }

        }
        return ans ;
        
    }
};