// ********First working day - Task 1 *********** //
#include <bits/stdc++.h>
using namespace std;


// find2Numbers function returns true if there is a pair numbers in the given vector vect with sum equal to 'sum'
//  Also, prints the pair numbers and multiplying them.
bool find2Numbers(vector<int> vect, int vect_size, int sum)
{
    int r,l;
    /* Sort the elements */
    sort(vect.begin(), vect.end());

    // To find the two elements, start an index from the two corners and move them
    l = 0; // index of the first element
    r = vect_size - 1; // index of the last element
    while (l < r)
    {
        if (vect[l] + vect[r] == sum)
        {
            printf("The two entries that sum to %d are %d and %d and the Answer is %d \n",sum, vect[l],vect[r],vect[l] * vect[r]);
            return true;
        }
        else if ( vect[l] + vect[r] < sum)
            l++;
        else // vect[l] +vect[r] > sum
            r--;
    }

    // If we reach here, then no pair was found
    return false;
}

// find3Numbers function returns true if there is is triplet in the given vector vect with sum equal to 'sum'
//  Also, prints the print the triplet and multiplying them.
bool find3Numbers(vector<int> vect, int vect_size, int sum)
{
    int l, r;
    /* Sort the elements */
    sort(vect.begin(), vect.end());
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < vect_size - 2; i++)
    {
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the remaining elements
        r = vect_size - 1; // index of the last element
        while (l < r)
        {
            if (vect[i] + vect[l] + vect[r] == sum)
            {
                printf("The triplet that sum to %d are  %d, %d, %d and The Answer is %d\n",sum, vect[i], vect[l],vect[r],vect[i] * vect[l] * vect[r]);
                return true;
            }
            else if (vect[i] + vect[l] + vect[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

/****** Main Function *******/
int main()
{
    ifstream File;
    File.open("data.txt");

    std::vector<int>numbers;
    int number;
    int n = 0; //n is the number of the integers in the file
    while(File >> number)
    {
        numbers.push_back(number);
        n++;
    }
    File.close();

    int sum = 2020;
    find3Numbers(numbers,n, sum);
    find2Numbers(numbers, n, sum);

    return 0;
}
