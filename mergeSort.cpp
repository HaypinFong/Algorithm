#include <iostream>
#include <functional>

/**
 * 归并排序
 * 要实现稳定排序则compare(a,a)应该返回true
 * */
template<typename T
    //, typename Compare>
    >
void mergeSort(T arr[], size_t start, size_t end, 
    const std::function<bool(const T&,const T&)> &compare)
    //std::function<bool(const T&,const T&)> compare)
    //std::function<bool(const T&,const T&)> &&compare)
    //bool(*compare)(const T&, const T&))
    //Compare compare)
{
    if(start >= end)
        return;
    size_t mid = (start + end)*0.5;
    mergeSort(arr,start,mid,compare);
    mergeSort(arr,mid+1,end,compare);
    T *_arr = new T[end-start+1];
    size_t i = start, j = mid+1, k=0;
    while(i<=mid && j<=end)
    {
        if(compare(arr[i],arr[j]))
            _arr[k++] = arr[i++];
        else
            _arr[k++] = arr[j++];
    }
    while(i<=mid)
        _arr[k++] = arr[i++];
    while(j<=end)
        _arr[k++] = arr[j++];
    for(int m=0;m<k;m++)
        arr[start + m] = _arr[m];
    delete []_arr;
    return;
}

int main(int argv, char* args[])
{
    int arr[] = {3,1,4,1,5,9,2,6};
    mergeSort<int>(arr,(size_t)0,(size_t)7,[](const int& left, const int& right)->bool{return left<=right;});
    for(int i=0;i<=7;i++)
        std::cout<<arr[i]<<' ';
    return 0;
}