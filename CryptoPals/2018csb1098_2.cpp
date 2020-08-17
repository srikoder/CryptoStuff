#include <iostream>

using namespace std;

int hextoDec(char c) {
  return (c>='0' && c<='9') ? c-'0' : c-'a'+10;
}

void hextoBin(char a, char arr[]) {
  int val = hextoDec(a);
  int i = 3;
  while(i>=0) {
    arr[i] = val%2 + '0';
    val = val/2;
    i--;
  }
}

void xorc(char a[], char b[], char c[]) {
  for(int i=0; i<4; i++) {
    c[i] = (a[i]==b[i]) ? '0' : '1';
  }
}

char bintoHex(char a[]) {
  int val = a[0]-'0';
  int i = 1;
  while(i<4) {
    val = 2*val+a[i]-'0';
    i++;
  }
  return (val<10) ? val+'0' : val+'a'-10;
}

char xorchar(char a, char b) {
  char arr1[4];
  char arr2[4];
  char ans[4];
  hextoBin(a, arr1);
  hextoBin(b, arr2);
  xorc(arr1, arr2, ans);
  char c = bintoHex(ans);
  return c;
}

int main() {
  char str1[1000];
  char str2[1000];
  char ans[1000];
  cin>>str1;
  cin>>str2;
  int len = 0;
  while(str2[len] != '\0') {
    len++;
  }
  // cout<<len<<endl;
  ans[len] = '\0';
  cout<<ans[len];
  for(int i=0; i<len; i++) {
    ans[i] = xorchar(str1[i], str2[i]);
  }
  cout<<ans;
  cout<<endl;
}
