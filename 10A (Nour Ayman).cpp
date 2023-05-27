#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int count, changesCount, indexResult, indexA, indexB, indexC, minChanges;
string line, dataset[110][5];

int recycling() {
    indexResult = 0, minChanges = 0xffffff, changesCount;

    for (indexA = 0; indexA < count; indexA++) {
        changesCount = 0;
        for (indexB = 0; indexB < count; indexB++) {
            for (indexC = 0; indexC < 5; indexC++) {
                if (dataset[indexA][indexC] != dataset[indexB][indexC])
                    changesCount++;
            }
        }

        if (changesCount < minChanges) {
            minChanges = changesCount;
            indexResult = indexA;
        }
    }

    return indexResult + 1;
}


int main() {

    // freopen("input.txt", "r", stdin);

    count = 0;

    int k, i;
    char c;

    while (getline(cin, line)) {
        if (line.compare("#") == 0)
            break;

        if (line.at(0) == 'e') {
            printf("%d\n", recycling());
            count = 0;
        } else {
            for (k = 0; k < 5; k++) {
                c = line.at(k * 4);
                i = 0;

                if (c == 'r')
                    i = 0;
                else if (c == 'o')
                    i = 1;
                else if (c == 'y')
                    i = 2;
                else if (c == 'g')
                    i = 3;
                else if (c == 'b')
                    i = 4;

                dataset[count][i] = line.at(k * 4 + 2);
            }
            count++;
        }


    }

    return 0;
}
