/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int searchi(int i,int j,MountainArray &mountainArr){
        if(i+1==j){
            int xi=mountainArr.get(i),xj=mountainArr.get(j);
            if(xi>xj)
                return i;
            else
                return j;
        }
        int mid=i+(j-i)/2;
        int _xm=mountainArr.get(mid-1),xm=mountainArr.get(mid),xm_=mountainArr.get(mid+1);
        if(_xm<xm && xm>xm_)
            return mid;
        else if(_xm>xm)
            return searchi(i,mid-1,mountainArr);
        else
            return searchi(mid+1,j,mountainArr);
    }
    int searchasc(int i,int j,int target,MountainArray &mountainArr){
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=mountainArr.get(mid);
            if(target==x)
                return mid;
            if(target>x)
                i=mid+1;
            else
                j=mid-1;
        }
        return -1;
    }
    int searchdes(int i,int j,int target,MountainArray &mountainArr){
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=mountainArr.get(mid);
            if(target==x)
                return mid;
            if(target<x)
                i=mid+1;
            else
                j=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i=0,j=mountainArr.length()-1;
        int index=searchi(i,j,mountainArr);
        cout<<index;
        if(mountainArr.get(index)==target)
            return index;
        int ans=searchasc(i,index-1,target,mountainArr);
        if(ans!=-1)
            return ans;
        ans=searchdes(index+1,j,target,mountainArr);
        return ans;
    }
};
