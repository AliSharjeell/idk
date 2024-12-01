#include <iostream>
#include <string>
using namespace std;

// Function to implement Rabin-Karp
void rabinKarpSearch(string text, string pattern, int prime)
{
    int n = text.length();
    int m = pattern.length();
    int base = 256; // Base for hash function (number of characters in the input alphabet)
    int patternHash = 0; // Hash value for the pattern
    int textHash = 0;    // Hash value for the current window of the text
    int h = 1;           // Multiplier for the highest digit (used in rolling hash)

    // Precompute h = (base^(m-1)) % prime
    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;

    // Calculate the initial hash values for the pattern and the first window of text
    for (int i = 0; i < m; i++)
    {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        // If the hash values match, verify the characters
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate the hash value for the next window of text
        if (i < n - m)
        {
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;

            // If the hash value is negative, convert it to positive
            if (textHash < 0)
                textHash += prime;
        }
    }
}

int main()
{
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";
    int prime = 101; // A prime number for hashing
    rabinKarpSearch(text, pattern, prime);
    return 0;
}
