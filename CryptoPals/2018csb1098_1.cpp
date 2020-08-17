#include <iostream>
using namespace std;

int max(int x, int y) {
  return (x>y) ? x : y;
}

void copyArray(char a[], char c[], int k, int j, int i) {
  while(k<=j) {
    c[i] = a[k];
    k++;
    i++;
  }
  return;
}

int hextoDec(char c) {
  if(c>='0' && c<='9') {
    return c - '0';
  }
  else {
    return c-'a'+10;
  }
}

char decto64(int v) {
  if(v<26) {
    return 'A' + v;
  }
  else if(v<52) {
    return 'a' + v - 26;
  }
  else if(v<62) {
    return v - 52 + '0';
  }
  else if(v==62) {
    return '+';
  }
  else {
    return '/';
  }
}

void hexto64(char c[], char d[]) {
  int val = hextoDec(c[0]);
  int i = 1;
  while(i<6){
    val = val*16 + hextoDec(c[i]);
    i++;
  }
  i = 3;
  while(i>=0) {
    d[i] = decto64(val%64);
    val = val/64;
    i--;
  }
}

void printArray(char b[], int l) {
  for(int i=1; i<l; i++) {
    cout<<b[i];
  }
  cout<<endl;
}

int main() {
  char a[10000];
  cin>>a;
  int len = 0;
  while(a[len] != '\0') {
    len++;
  }
  int lenb =(len)*(3.0/4.0);
  char b[lenb];
  int j = len-1;
  while(j>=0) {
    char c[6];
    for(int i=0; i<6; i++) {
      c[i] = '0';
    }
    copyArray(a, c, max(j-5, 0), j, 0);
    // printArray(c, 6);
    char d[4];
    hexto64(c, d);
    // printArray(d, 4);
    copyArray(d, b, 0, 3, (2.0/3.0)*(j-3));
    j = j - 6;
  }
  printArray(b, lenb);
}
