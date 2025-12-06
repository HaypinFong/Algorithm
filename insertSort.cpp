#include <iostream>

/**
 * 插入排序，从第二个元素开始，前面序列视为有序
 */
template<typename T, typename Compare>
void insertSort(T arr[], int len, Compare compare)
{
    if(len <= 1)
        return;
    for(int i = 1; i<len;i++)
    {
        if(compare(arr[i-1],arr[i]))
            continue;
        T val = arr[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(!compare(arr[j],val))
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = val;
    }
}

int main(int argc, char* argv[])
{
    int arr[] = {3,1,4,1,5,9,2,6};
    insertSort(arr,8,[](const int& left, const int &right){return left<=right;});
    for(int i =0;i<8;i++)
        std::cout<<arr[i]<<' ';
}