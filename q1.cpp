#include <iostream>
#include <omp.h>
#include <time.h>

using namespace std;
int main()
{
    long double f = 1;

    int i, num;

    printf("Input the number : ");
    cin >> num;

#pragma omp parallel reduction(* \
                               : f)
    {
#pragma omp for
        for (i = 1; i <= num; i++)
        {
            f = f * i;
        }
        printf("%d\n", omp_get_thread_num());
    }

    cout << "Threads Ends" << endl;
    cout << "The Factorial of " << num << " is " << f << endl;

    return 0;
}
