#include <vector>
#include <cassert>
#include <iostream>

int solution_1(std::vector<int> & vect)
{
    assert(vect.size() != 0);

    int max_sum = vect[0];
    int curr_sum = vect[0];
    for(size_t i=1;i<vect.size();++i)
    {
        curr_sum = std::max(curr_sum+vect[i],vect[i]);
        max_sum = std::max(curr_sum,max_sum);
    }
    return max_sum;
}

int main(void)
{
    std::vector<int> v{-1,2,5,0,-3,3,5,56,7,-4,-4};
    std::cout<<"largest sum = "<<solution_1(v)<<std::endl;
    std::vector<int> v1{-1,-2,-5,0};
    std::cout<<"largest sum = "<<solution_1(v1)<<std::endl;

    return 0;
}