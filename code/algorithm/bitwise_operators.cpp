#include<iostream>

using namespace std;

void toggleCase(char* str){
  unsigned length = strlen(str);
  cout << " " << length << " ";
  for(unsigned i=0;i<length;i++){
    if(str[i] >= 'A' && str[i] <= 'z')
      str[i] ^= 32;
  }
}

int main(){
  char str[] = "Testing Case Toogle.";
  toggleCase(str);
  cout << str;
  cout << endl;

  int test1 = 0x0FF;
  int test2 = 0x100;
  cout << " test hex => " << (test1 ^ test2);

  return 0;
}