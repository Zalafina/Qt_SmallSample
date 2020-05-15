#include <iostream>

using namespace std;

extern int testfunction_a();
extern int testfunction_b();

int main()
{
    testfunction_a();
    testfunction_b();
    return 0;
}
