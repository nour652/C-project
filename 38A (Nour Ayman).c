//Here's the equivalent C code for the given C++ code:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* xqs[7] = {"SUN,", "MON,", "TUE,", "WED,", "THU,", "FRI,", "SAT,"};
char* yues[13] = {" ", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int Shi;
int Fen;
int Miao;
int ris[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getXq(char* xq) {
    for(int i = 0; i < 7; i++) {
        if(strcmp(xq, xqs[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int getYue(char* yue) {
    for(int i = 1; i <= 12; i++) {
        if(strcmp(yue, yues[i]) == 0) {
            return i;
        }
    }
    return 0;
}

int getNian(char* nian) {
    //int NianHere's the continuation of the C code for the given C++ code:

    int Nian = atoi(nian);
    if(strlen(nian) == 2) {
        return Nian + 1900;
    }
    return Nian;
}

void getSj(char* sj) {
    sscanf(sj, "%d:%d:%d", &Shi, &Fen, &Miao);
}

int getSqOfs(char* sq) {
    if(strlen(sq) == 5) {
        int pureOffset = (sq[1]-'0') * 600 + (sq[2]-'0') * 60 + (sq[3]-'0') * 10 + sq[4]-'0';
        if(sq[0] == '+') {
            return 180 - pureOffset;
        }
        else {
            return 180 + pureOffset;
        }
    }
    switch(tolower(sq[0])) {
        case 'u': case 'g': return 180;
        case 'e': return 420;
        case 'c': return 480;
        case 'm': return 540;
        case 'p': return 600;
        default: return 2147483647;
    }
}

int isRun(int N) {
    if(N%4 != 0 || (N%100 == 0 && N%400 != 0)) {
        return 0;
    }
    return 1;
}

//Continuation of the C code for the given C++ code:

int RiofYue(int Y, int N) {
    if(!isRun(N) || Y != 2) {
        return ris[Y];
    }
    return 29;
}

int overflow(int R, int Y, int N) {
    return R > RiofYue(Y, N);
}

void getNextRi(int* Ri, int* Yue, int* Nian) {
    (*Ri)++;
    if(overflow(*Ri, *Yue, *Nian)) {
        *Ri = 1;
        (*Yue)++;
        if(*Yue > 12) {
            *Yue = 1;
            (*Nian)++;
        }
    }
}

void getLastRi(int* Ri, int* Yue, int* Nian) {
    (*Ri)--;
    if(*Ri == 0) {
        (*Yue)--;
        if(*Yue == 0) {
            *Yue = 12;
            (*Nian)--;
        }
        *Ri = RiofYue(*Yue, *Nian);
    }
}

void getNewRi(int offsetRi, int* Ri, int* Yue, int* Nian) {
    if(offsetRi > 0) {
        for(int i = 0; i < offsetRi; i++) {
            getNextRi(Ri, Yue, Nian);
        }
    }
    else {
        for(int i = 0; i < -offsetRi; i++) {
            getLastRi(Ri, Yue, Nian);
        }
    }
}

void getNewXq(int offsetRi, int* Xq) {
    int ofs = (offsetRi + 14) % 7;
    *Xq = (*Xq + ofs) % 7;
}

void printMoscow(int Xq, int Ri, int Yue, int Nian, int Shi, int Fen, int Miao) {
    printf("%s ", xqs[Xq]);
    if(Ri < 10) printf("0");
    printf("%d ", Ri);
    printf("%s ", yues[Yue]);
    if(Nian < 10) printf("000");
    else if(Nian < 100) printf("00");
    else if(Nian < 1000) printf("0");
    printf("%d ", Nian);
    if(Shi < 10) printf("0");
    printf("%d:", Shi);
    if(Fen < 10) printf("0");
    printf("%d:", Fen);
    if(Miao < 10) printf("0");
    printf("%d +0300", Miao);
}

int main() {
    char xq[5], yue[5], nian[10], sj[10],sq[10];//Here's the continuation of the C code for the given C++ code:


    int Ri;
    scanf("%s %d %s %s %s %s", xq, &Ri, yue, nian, sj, sq);
    int Xq = getXq(xq);
    int Yue = getYue(yue);
    int Nian = getNian(nian);
    getSj(sj);
    int offsetFz = getSqOfs(sq); // in fz
    Fen += offsetFz;
    int offsetXs = 0;
    if(Fen >= 60) {
        offsetXs = Fen / 60;
        Fen %= 60;
    }
    else if(Fen < 0) {
        offsetXs = -((-Fen)/60+1);
        Fen = 60 - (-Fen)%60;
        if(Fen == 60) {
            Fen = 0;
            offsetXs++;
        }
    }
    if(offsetXs != 0) {
        Shi += offsetXs;
        int offsetRi = 0;
        if(Shi >= 24) {
            offsetRi = Shi / 24;
            Shi %= 24;
        }
        else if(Shi < 0) {
            offsetRi = -((-Shi)/24+1);
            Shi = 24 - (-Shi)%24;
            if(Shi == 24) {//Continuation of the C code for the given C++ code:

                Shi = 0;
                offsetRi++;
            }
        }
        if(offsetRi != 0) {
            getNewRi(offsetRi, &Ri, &Yue, &Nian);
            getNewXq(offsetRi, &Xq);
        }
    }
    printMoscow(Xq, Ri, Yue, Nian, Shi, Fen, Miao);
    return 0;
}
