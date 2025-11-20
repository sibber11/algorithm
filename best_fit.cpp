#include <iostream>
// #include <limits.h>

using namespace std;

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int assigned[5] = {-1, -1, -1, -1, -1};
    int processes[4] = {-1, -1, -1, -1};

    for (int i = 0; i < 4; i++)
    {
        int process = processSize[i];
        int minimum = -1;
        for (int j = 0; j < 5; j++)
        {
            if (assigned[j] == -1 && blockSize[j] > process)
            {
                if (minimum == -1)
                    minimum = j;
                else if (blockSize[minimum] > blockSize[j])
                    minimum = j;
            }
        }
        if (minimum != -1)
        {
            assigned[minimum] = i;
            processes[i] = minimum;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (processes[i] == -1)
        {
            continue;
        }
        cout << "Process: " << i + 1 << " " << processes[i] + 1 << endl;
    }
}