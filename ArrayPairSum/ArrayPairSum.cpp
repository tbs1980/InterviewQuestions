#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

void solution_1(std::vector<int>  & arr,int const k)
{
    // order of N^2 solution
    std::cout<<"solution 1: complexity O(N^2)"<<std::endl;
    if( arr.size() < 2 )
    {
        return;
    }

    for(size_t i=0;i<arr.size()-1;++i)
    {
        for(size_t j=i+1;j<arr.size();++j)
        {
            if(arr[i]+arr[j]==k)
            {
                std::cout<<"pair found ("<<arr[i]<<","<<arr[j]<<")"<<std::endl;
            }
        }
    }
}


void solution_2(std::vector<int>  & arr,int const k)
{
    // order of NlogN solution
    std::cout<<"solution 2: complexity O(logN)"<<std::endl;
    if( arr.size() < 2 )
    {
        return;
    }

    std::sort( arr.begin(),arr.end() );
    size_t low=0;
    size_t high=arr.size()-1;
    while(low < high)
    {
        int sum = arr[low] + arr[high];
        if(sum == k)
        {
            std::cout<<"pair found ("<<arr[low]<<","<<arr[high]<<")"<<std::endl;
            ++low;
        }
        else if(sum < k)
        {
            ++low;
        }
        else
        {
            --high;
        }
    }
}

void solution_3(std::vector<int>  & arr,int const k)
{
    // order of N solution
    std::cout<<"solution 3: complexity O(N)"<<std::endl;

    if( arr.size() < 2 )
    {
        return;
    }

    std::unordered_set<int> seen;

    for(size_t i=0;i<arr.size();++i)
    {
        int target = k - arr[i];
        auto res = seen.find(target);
        if(res == seen.end())
        {
            seen.insert(arr[i]);
        }
        else
        {
            std::cout<<"pair found ("<<std::min(arr[i],target)<<","<<std::max(arr[i],target)<<")"<<std::endl;
        }
    }
}

int main(void)
{
    std::vector<int> x{1,1,2,3,4};
    solution_1(x,4);
    solution_2(x,4);
    solution_3(x,4);
    return 0;
}