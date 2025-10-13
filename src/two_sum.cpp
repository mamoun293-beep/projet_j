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

std::vector<std::pair<int,int>> two_sum(const std::vector<int>& research,int T, int& count)
{
/***************INIT******************************/

    std::vector<std::pair<int,int>> solutions;
    const int *x = research.data();
    const int *y = research.data() + research.size() - 1;

/***************RECHERCHE COUPLE*****************/
    while(x<y)
    {
        if(*x+*y == T)
        {
            std::cout << "couple trouvé indice : " << x - research.data() <<" ; "<< y - research.data() << "\n";
            solutions.insert(solutions.begin(),std::pair(x - research.data(),y - research.data()));
            count++;
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

int main() {
    int min = 0;
    int max = 12;
    int size = 12;
    int T = 12;
    std::vector<int> research;
    int count = 0;

    research = generate_sorted_vector(min,max,size);
    auto couples = two_sum(research,T,count);

    std::cout << "couples trouvé : " << count << "\n";
    return 0;
}