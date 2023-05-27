#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

string xqs[7] = {"SUN,", "MON,", "TUE,", "WED,", "THU,", "FRI,", "SAT,"};
string yues[13] = {" ", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int Shi;
int Fen;
int Miao;
int ris[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getXq(string xq){
 for(int i = 0; i < 7; i++){
  if(strcmp(xq.c_str(), xqs[i].c_str()) == 0){
   return i;
  }
 }
 return -1;
}

int getYue(string yue){
 for(int i = 1; i <= 12; i++){
  if(strcmp(yue.c_str(), yues[i].c_str()) == 0){
   return i;
  }
 }
 return 0;
}

int getNian(string nian){
 int Nian = atoi(nian.c_str());
 if(nian.length() == 2) return Nian + 1900;
 return Nian;
}

void getSj(string sj){
 stringstream ss(sj);
 char fei;
 ss >> Shi >> fei >> Fen >> fei >> Miao;
}

int getSqOfs(string sq){
 if(sq.length() == 5){
  int pureOffset = (sq[1]-'0') * 600 + (sq[2]-'0') * 60 + (sq[3]-'0') * 10 + sq[4]-'0';
  if(sq[0] == '+') return 180 - pureOffset;
  else return 180 + pureOffset;
 }
 switch(sq[0]){
  case 'U': case 'u': case 'G': case 'g': return 180;
  case 'E': case 'e': return 420;
  case 'C': case 'c': return 480;
  case 'M': case 'm': return 540;
  case 'P': case 'p': return 600;
  default: return 2147483647;
 }
}

bool isRun(int &N){
 if(N%4!=0 || (N%100==0 && N%400!= 0)) return 0;
 return 1;
}

int RiofYue(int &Y, int &N){
 if(!isRun(N) || Y!=2) return ris[Y];
 return 29;
}

bool overflow(int &R, int &Y, int &N){
 return R > RiofYue(Y, N);
}

void getNextRi(int &Ri, int &Yue, int &Nian){
 //cout << 1 << endl;
 Ri++;
 if(overflow(Ri, Yue, Nian)){
  Ri = 1;
  Yue++;
  if(Yue > 12){
   //cout << 1 << endl;
   Yue = 1;
   Nian++;
  }
 }
}

void getLastRi(int &Ri, int &Yue, int &Nian){
 Ri--;
 if(Ri == 0){
  Yue--;
  if(Yue == 0){
   Yue = 12;
   Nian--;
  }
  Ri = RiofYue(Yue, Nian);
 }
}

void getNewRi(int offsetRi, int &Ri, int &Yue, int &Nian){
 if(offsetRi > 0){
  for(int i = 0; i < offsetRi; i++){
   getNextRi(Ri, Yue, Nian);
  }
 }
 else{
  for(int i = 0; i < -offsetRi; i++){
   getLastRi(Ri, Yue, Nian);
  }
 }
}

void getNewXq(int offsetRi, int &Xq){
 int ofs = (offsetRi + 14)%7;
 Xq = (Xq + ofs)%7;
}
//SUN, 03 DEC 1996 12:10:35 +0300
void printMoscow(int Xq, int Ri, int Yue, int Nian, int Shi, int Fen, int Miao){
 cout << xqs[Xq] << " ";
 if(Ri < 10) cout << 0;
 cout << Ri << " ";
 cout << yues[Yue] << " ";
 if(Nian < 10) cout << "000";
 else if(Nian < 100) cout << "00";
 else if(Nian < 1000) cout << "0";
 cout << Nian << " ";
 if(Shi < 10) cout << 0;
 cout << Shi << ":";
 if(Fen < 10) cout << 0;
 cout << Fen << ":";
 if(Miao < 10) cout << 0;
 cout << Miao << " +0300";
}

int main() {
 string xq, yue, nian, sj, sq;
 int Ri;
 cin >> xq >> Ri >> yue >> nian >> sj >> sq;
 int Xq = getXq(xq);
 int Yue = getYue(yue);
 int Nian = getNian(nian);
 getSj(sj);
 int offsetFz = getSqOfs(sq);// in fz
 //cout << offsetFz << endl;
 Fen += offsetFz;
 int offsetXs = 0;
 if(Fen >= 60){
  offsetXs = Fen / 60;
  Fen %= 60;
 }
 else if(Fen < 0){
  offsetXs = -((-Fen)/60+1);
  Fen = 60 - (-Fen)%60;
  if(Fen == 60){
   Fen = 0;
   offsetXs++;
  }
 }
 if(offsetXs != 0){
  Shi += offsetXs;
  int offsetRi = 0;
  if(Shi >= 24){
   offsetRi = Shi / 24;
   Shi %= 24;
  }
  else if(Shi < 0){
   offsetRi = -((-Shi)/24+1);
   Shi = 24 - (-Shi)%24;
   if(Shi == 24){
    Shi = 0;
    offsetRi++;
   }
  }
  if(offsetRi != 0){
   getNewRi(offsetRi, Ri, Yue, Nian);
   getNewXq(offsetRi, Xq);
  }
 }
 //cout << Xq << endl;
 printMoscow(Xq, Ri, Yue, Nian, Shi, Fen, Miao);
 return 0;
}
