#include <iostream>
#include <vector>
#include <utility>


std::vector<std::pair<int,int>> two_sum(int A[6])
{
/***************INIT******************************/

    std::vector<std::pair<int,int>> solutions;

    int T  = 12;
    int *x = &A[0];
    int *y = &A[5];

/***************RECHERCHE COUPLE*****************/
    while(x<y)
    {
        if(*x+*y == T)
        {
            std::cout << "couple trouvé indice : " << *x <<" ; "<< *y << "\n";
            solutions.insert(solutions.begin(),std::pair(*x,*y));
        }
        else if (*x+*y < T)
        {
            x=x+1;
        }
        else if (*x+*y > T)
        {
            y=y-1;
        }
    }
    return solutions;
}

int main() {
    int A[6] {1,2,4,6,10,11};

    two_sum(A);

    return 0;
}