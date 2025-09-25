#include <iostream>

int main() {

/***************INIT******************************/
    int A[6] {1,2,4,6,10,11};
    int T = 12;
    int *x = &A[0];
    int *y = &A[5];

/***************RECHERHCE COUPLE*****************/
    while(x<y)
    {
        if(*x+*y == T)
        {
            std::cout << "couple trouvé indice : " << *x <<" ; "<< *y << "\n";
            return 0;
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
    std::cout << "couple non trouvé \n";
    return 0;
}