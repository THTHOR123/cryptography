#include <iostream>
using namespace std;


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
      
        int q = a / m;
        int t = m;

      
        m = a % m, a = t;
        t = y;

      
        y = x - q * y;
        x = t;
    }


    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    int a, m;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of m: ";
    cin >> m;

    if (gcd(a, m) != 1)
    {
        cout << "Modular multiplicative inverse does not exist." << endl;
        return 0;
    }

    int inv_a = modInverse(a, m);
    
    cout << "Modular multiplicative inverse of " << a << " modulo " << m << " is: " << inv_a << endl;

    return 0;
}
