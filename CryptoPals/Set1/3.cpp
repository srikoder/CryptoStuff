#include <iostream>

using namespace std;

int hextoDec(char c) {
  return (c>='0' && c<='9') ? c-'0' : c-'a'+10;
}

void dectoBin(int a, int arr[]) {
  int i = 7;
  while(a>0) {
    arr[i] = a%2;
    a = a/2;
    i--;
  }
}

void dectoBin4(int a, int arr[]) {
  int i = 7;
  while(a>0) {
    arr[i] = a%2;
    a = a/2;
    i--;
  }
}

void xorc(int a[], int b[], int c[]) {
  for(int i=0; i<8; i++) {
    c[i] = (a[i]==b[i]) ? 0 : 1;
  }
}

// char bintoHex(char a[]) {
//   int val = a[0]-'0';
//   int i = 1;
//   while(i<4) {
//     val = 2*val+a[i]-'0';
//     i++;
//   }
//   return (val<10) ? val+'0' : val+'a'-10;
// }

int bintoDec(int arr[]) {
  int val = arr[0];
  for(int i=1; i<8; i++) {
    val = val*2+arr[i];
  }
  return val;
}

int xorhex(int a, int b) {
  int arr1[8];
  int arr2[8];
  dectoBin(a, arr1);
  dectoBin(b, arr2);
  int arr[8];
  xorc(arr1, arr2, arr);
  return bintoDec(arr);
}

int main() {
  char a[10000];
  cin>>a;
  int len = 0;
  while(a[len] != '\0') {
    len++;
  }
  int asc[256];
  for(int i=0; i<256; i++) {
    asc[i] = 0;
  }
  for(int i=0; i<len; i=i+2) {
    int val = hextoDec(a[i]);
    val = 16*val + hextoDec(a[i+1]);
    asc[val]++;
  }
  int max = 0;
  for(int i=1; i<256; i++) {
    max = (asc[i]>asc[max]) ? i : max;
  }
  printf("%d  ", max);
  int v = xorhex(max, 'e');
  printf("%d  \n", v);
  for(int i=0; i<len; i=i+2) {
    int val = hextoDec(a[i]);
    val = 16*val + hextoDec(a[i+1]);
    printf("%d ", xorhex(val, v));
  }
  cout<<endl;
}
