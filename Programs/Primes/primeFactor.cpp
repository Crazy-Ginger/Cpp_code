#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;
int depth = 0;

vector<int> primeSieve(vector <int> initial)
{
    vector<int>::iterator start = initial.begin();
    vector<int>::iterator end = initial.end();
    if (start == end)
    {
        cout << "No numbers\n";
    }
    else
    {
        //clear the container with 0
        fill(start, end, 0);
        //mark composites with 1
        for (vector<int>::iterator prime_it = start + 1; prime_it != end; ++prime_it)
        {
            if (*prime_it == 1)
                continue;
            //determine the prime number represented by this iterator location
            int stride = (prime_it - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator mark_it = prime_it;
            while ((end - mark_it) > stride)
            {
                advance(mark_it, stride);
                *mark_it = 1;
            }
        }

        //copy marked primes into container
        vector<int>::iterator out_it = start;
        for (vector<int>::iterator it = start + 1; it != end; ++it)
        {
            if (*it == 0)
            {
                *out_it = (it - start) + 1;
                ++out_it;
            }
        }
    }
    //removes the elements of the vector that doesn't contain primes
    vector<int>::iterator mark;
    for (mark = initial.begin(); mark != initial.end(); ++mark)
    {
            if (*mark == 1)
            {
                    initial.erase(mark, initial.end());
                    break;
            }
    }

    //checks for an error that allows 0 to be the last element in the array of vectors
    if (*(--initial.end()) == 0)
    {
            initial.erase(--initial.end());
    }

    return initial;
}


vector <int> primeFactorer(int numb)
{
    vector <int> factors;
    //iterates through the prime list to find prime factors 
    for (vector<int>::iterator i = primes.begin(); i!=primes.end(); i++)
    { 
        float remain = fmod(((float)numb),((float)*i));
        if (*i == numb)
        {
            factors.push_back(*i);
            break;
        }
        
        else if (remain == 0)
        {
            factors.push_back(*i);

            if (*i != numb)
            {
                vector <int> deeper = primeFactorer(numb/(*i));
                factors.insert(factors.begin(), deeper.begin(), deeper.end());
            }
            //break ensures that for loop stops after its found one primefacter at each level
            break;
        }
    }
    return factors;
}

int main(int argc, char* argv[])
{
    int numb = atoi(argv[1]);
    primes.resize(numb);
    primes = primeSieve(primes);

    vector<int> factors(1);
    factors = primeFactorer(numb);
    cout << "numbers of factors: " << factors.size() << endl;

    for (unsigned int i = 0; i < factors.size(); i++)
    {
        if (i == factors.size()-1)
        {
            cout << factors.at(i);
        }
        else
        {
            cout << factors.at(i) << ", ";
        }

    }
    cout << endl;
    return 0;
}
