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
    for (int i = 1; i < m; i++)
        if ((a * i) % m == 1)
            return i;
    return -1;
}


string encrypt(string message, int key1, int key2)
{
    string cipher = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (isupper(message[i]))
            cipher += char((key1 * (message[i] - 'A') + key2) % 26 + 'A');
        else if (islower(message[i]))
            cipher += char((key1 * (message[i] - 'a') + key2) % 26 + 'a');
        else
            cipher += message[i];
    }
    return cipher;
}


string decrypt(string cipher, int key1, int key2)
{
    string message = "";
    int inv_key1 = modInverse(key1, 26);
    for (int i = 0; i < cipher.length(); i++)
    {
        if (isupper(cipher[i]))
            message += char((inv_key1 * ((cipher[i] - 'A' - key2 + 26) % 26)) % 26 + 'A');
        else if (islower(cipher[i]))
            message += char((inv_key1 * ((cipher[i] - 'a' - key2 + 26) % 26)) % 26 + 'a');
        else
            message += cipher[i];
    }
    return message;
}

int main()
{
    string message;
    int key1, key2;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the first key (should be co-prime with 26): ";
    cin >> key1;

    if (gcd(key1, 26) != 1)
    {
        cout << "Invalid key! Please enter a co-prime number." << endl;
        return 0;
    }

    cout << "Enter the second key: ";
    cin >> key2;

    string cipher = encrypt(message, key1, key2);
    cout << "Encrypted Message: " << cipher << endl;

    string decrypted_message = decrypt(cipher, key1, key2);
    cout << "Decrypted Message: " << decrypted_message << endl;

    return 0;
}
