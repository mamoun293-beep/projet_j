#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<int> generate_sorted_vector(int min, int max, size_t size)
{
    std::vector<int> input_tab(size); //vector to initialize, used for research of couple

    /*********************** Generation of random number to initialize the vector*************/
    std::generate(input_tab.begin(),input_tab.end(),[=](){
        return random()%(max - min + 1) + min;
    });

    /************************sort int per croissant order ************************************/
    std::sort(input_tab.begin(),input_tab.end());

    return input_tab;
}

std::vector<std::pair<int,int>> two_sum(const std::vector<int>& research,int T)
{
/***************INIT******************************/
        if(research.empty() || research.size() < 2)
    {
        throw std::invalid_argument("the input vector is empty or have less than 2 elements");
    }
    
    std::vector<std::pair<int,int>> solutions;
    const int *x = research.data();
    const int *y = research.data() + research.size() - 1;

/***************RECHERCHE COUPLE*****************/
    while(x<y)
    {
        if(*x+*y == T)
        {
            solutions.push_back(std::pair(x - research.data(),y - research.data()));
            x++;
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