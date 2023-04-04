#include <string>
#include <vector>

using namespace std;
string fillDummy(string x){
  int len = x.length();
  int k = 1;
  while(len - k > 0){
    len -= k;
    k = k*2;
  }
  for(int i=0; i<k-len; i++)
    x += "0";
  return x;
}
int check_binary(string x){
  int len = x.length();
  if(len < 3)
    return 1;
  if(x.find("1") == string::npos){
    return 1;
  }
  if(x[len/2] == '1'){
    return check_binary(x.substr(0,len/2)) && check_binary(x.substr(len/2 + 1)); 
  }
  else{
    return 0;
  }
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;
  for(auto number: numbers){
    string bn ="";
    while(number >0){
      if(number % 2 == 1)
        bn += "1";
      else
        bn += "0";
      number /= 2;
    }
    bn = fillDummy(bn);
    answer.push_back(check_binary(bn));
  }
  return answer;
}