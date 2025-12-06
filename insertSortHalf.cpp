#include <iostream>

/**
 * 若要稳定排序，compare(a,a)需返回true
 * 二分插入排序，插入排序的进化版，从第二个元素开始，前面的元素视为有序
 */

template<typename T, typename Compare>
void insertSortHalf(T arr[], size_t len, Compare compare)
{
    if(len <= 1)
        return;
    int left,right,mid;
    for(size_t i = 1; i<len;i++)
    {
        left = 0, right = i-1;
        if(compare(arr[right],arr[i]))
            continue;
        //compare(arr[i],arr[right]) need insert
        while(right - left > 1) // need half
        {
            mid = (left+right)*0.5;
            if(compare(arr[mid],arr[i]))
                left = mid;
            else
                right = mid;
        }
        size_t sizeT = sizeof(T);
        if(compare(arr[i],arr[left]))
        {
            T val = arr[i];
            //memcpy(arr+sizeT*(left+1),arr+sizeT*left,sizeT*(i-left));
            for(int j = i-1; j >=left;j--)
                arr[j+1] = arr[j];
            arr[left] = val;
        }
        if(compare(arr[left],arr[i]) && compare(arr[i],arr[right]))
        {
            T val = arr[i];
            //memcpy(arr+sizeT*(right+1),arr+sizeT*right,sizeT*(i-right));
            for(int j = i-1; j>=right;j--)
                arr[j+1] = arr[j];
            arr[right] = val;
        }
    }
}

int main(int args, char* argv[])
{
    int arr[] = {3,1,4,1,5,9,2,6};
    insertSortHalf(arr,8,[](const int& left, const int& right){return left<=right;});
    for(int i = 0 ;i<8;i++)
        std::cout<<arr[i]<<' ';
}