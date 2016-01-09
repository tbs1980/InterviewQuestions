#include <random>
#include <iostream>

// A B
// C D

int solution_1(std::vector< std::vector<int> > & mat, std::vector<size_t> const & A, std::vector<size_t> const & D)
{
    // complexity of this solution is O(MN)
    int sum=0;
    for(size_t i=A[0];i<D[0]+1;++i)
    {
        for(size_t j=A[1];j<D[1]+1;++j)
        {
            sum += mat[i][j];
        }
    }
    return sum;
}

std::vector< std::vector<int> > precompute_sums(std::vector< std::vector<int> > & mat)
{
    size_t top_row = 0;
    size_t bottom_row = mat.size()-1;
    size_t left_col = 0;
    size_t right_col = mat[0].size()-1;

    std::vector< std::vector<int> > sums(mat.size(),std::vector<int>(mat[top_row].size()) );

    sums[top_row][top_row] = mat[top_row][top_row];

    // get the top row
    for(size_t j=left_col+1;j<right_col+1;++j)
    {
        sums[top_row][j]  = sums[top_row][j-1] + mat[top_row][j];
    }
    // get the left col
    for(size_t i=top_row+1;i<bottom_row+1;++i)
    {
        sums[i][left_col] = sums[i-1][left_col] + mat[i][left_col];
    }

    for(size_t j=left_col+1;j<right_col+1;++j)
    {
        int column_sum = mat[top_row][j];
        for(size_t i=top_row+1;i<bottom_row+1;++i)
        {
            sums[i][j] = sums[i][j-1] + mat[i][j] + column_sum;
            column_sum += mat[i][j];
        }
    }

    return sums;

}

int solution_2(std::vector< std::vector<int> > & mat,std::vector<size_t> const & A, 
    std::vector<size_t> const & D,std::vector< std::vector<int> > & sums)
{
    int OA,OB,OC,OD;
    if(A[0]==0 or A[1]==0)
    {
        OA=0;
    }
    else
    {
        OA = sums[A[0]-1][A[1]-1];
    }

    if(A[1] == 0)
    {
        OC = 0;
    }
    else
    {
        OC = sums[D[0]][A[1]-1];
    }

    if(A[0] == 0)
    {
        OB = 0;
    }
    else
    {
        OB = sums[A[0]-1][D[1]];
    }

    OD  =  sums[D[0]][D[1]];

    return OD - OB - OC + OA;
}
int main(void)
{
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    size_t const rows=4;
    size_t const cols=4;
    std::vector< std::vector<int> > mat(rows,std::vector<int>(cols));

    for(size_t i=0;i<rows;++i)
    {
        for(size_t j=0;j<cols;++j)
        {
            mat[i][j] = uniform_dist(e1);
            std::cout<<mat[i][j]<<",";
        }
        std::cout<<std::endl;
    }

    std::vector<size_t> A{0,0};
    std::vector<size_t> D{3,3};

    std::cout<<"sub matrix sum 1 = "<<solution_1(mat,A,D)<<std::endl;

    std::vector< std::vector<int> > prec_sums = precompute_sums(mat);

    std::cout<<"sub matrix sum 2 = "<<solution_2(mat,A,D,prec_sums)<<std::endl;

    return 0;
}