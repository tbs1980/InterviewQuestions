#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>

int solution_1(std::vector<int>   v1,std::vector<int>   v2)
{
    // complexity O(N)
    assert(v1.size() == v2.size()+1);

    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());

    for(size_t i=0;i<v2.size();++i)
    {
        if(v2[i] != v1[i])
        {
            return v1[i];
        }
    }

    return v1[v1.size()-1];
}

int solution_2(std::vector<int>  v1,std::vector<int>  v2)
{
    // O(N) solution
    std::map<int,int> dict;

    for(size_t i=0;i<v2.size();++i)
    {
        dict[v2[i]] += 1;
    }

    for(size_t i=0;i<v1.size();++i)
    {
        if(dict[v1[i]] == 0)
        {
            return v1[i];
        }
        else
        {
            dict[v1[i]] -= 1;
        }
    }
}

int main(void)
{
    std::vector<int> x1{4,1,0,2,9,6,8,7,5,3};
    std::vector<int> x2{6,4,7,2,1,0,8,3,9};

    std::cout<<"missing elemet is "<<solution_1(x1,x2)<<std::endl;
    std::cout<<"missing elemet is "<<solution_2(x1,x2)<<std::endl;

    return 0;
}