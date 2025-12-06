#include <iostream>

template<typename T, typename Compare>
void bubbleSort(T arr[],int len,Compare compare)
{
    for(int j = len;j>=1;j--)
    {
        for(int i = 0;i<j-1;i++)
        {
            if(!compare(arr[i],arr[i+1]))
                std::swap(arr[i],arr[i+1]);
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[] = {3,1,4,1,5,9,2,6};
    bubbleSort(arr,8,[](const int &left, const int &right){return left<=right;});
    for(int i=0;i<8;i++)
        std::cout<<arr[i]<<' ';
}