#include <iostream>

/**
 * 快速排序
 * 若要保持稳定排序则compare(leftA,rightA)返回true
 */
template<typename T,typename Compare>
void fastSort(T arr[], int start, int end, const Compare &compare)
{
    if(start >= end)
        return;
    T val = arr[start];
    int left = start, right = end;
    while(left < right)
    {
        while(left < right)
        {
            if(!compare(val,arr[right]))
            {
                arr[left++] = arr[right];
                break;
            }
            else
                right--;
        }
        while(left < right)
        {
            if(!compare(arr[left],val))
            {
                arr[right--] = arr[left];
                break;
            }
            else
                left++;
        }
    }
    arr[left] = val;
    fastSort(arr,start,left-1,compare);
    fastSort(arr,left+1,end,compare);
    return;
}

int main(int args, char* argv[])
{
    int arr[] = {3,1,4,1,5,9,2,6};
    fastSort(arr,0,7,[](const int &left, const int &right){return left<=right;});
    for(int i = 0; i<=7;i++)
        std::cout<<arr[i]<<' ';
    
}