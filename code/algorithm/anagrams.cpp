#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>

using namespace std;


vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > output;
    int length = strs.size();
    vector<bool> visited(length, false);
    
    for(int i=0; i<length; i++){
        if(visited[i])
            continue;

        vector<string> anagrams;
        visited[i] = true;
        anagrams.push_back(strs[i]);
        unordered_map<char, int> strMap;
        int strLen = strs[i].length();
        
        for(int stri=0; stri<strLen; stri++){
          char c = strs[i][stri];
            if(strMap[c] == 1){
                strMap[c] = strMap[c] + 1;
            }
            else{
                strMap[c] = 1;
            }
        }
        
        for(int j=i+1;j<length;j++){
            if(visited[j])
              continue;
            int tempLen = strs[j].length();
            unordered_map<char, int> compMap;

            if(tempLen == strLen){
                for(int stri=0; stri<strLen; stri++){
                  char c = strs[j][stri];
                    if(compMap[c] == 1){
                        compMap[c] = compMap[c] + 1;
                    }
                    else{
                        compMap[c] = 1;
                    }
                }
                
                unordered_map<char, int>::iterator it = strMap.begin();
                while(it != strMap.end() && compMap[it->first] == it->second)
                    it++;
                
                if(it == strMap.end()){
                    visited[j] = true;
                    anagrams.push_back(strs[j]);
                }
            }
        }
        
        output.push_back(anagrams);
    }

    return output;
}

vector<vector<string> > groupAnagrams2(vector<string>& strs) {
    vector<vector<string> > output;
    
    int length = strs.size();
    vector<bool> visited(length, false);
    
    for(int i=0;i<length;i++){
      if(visited[i])
        continue;
      
      vector<string> anagrams;
      visited[i] = true;

      string orgStr1 = strs[i];
      string str1 = orgStr1;
      sort(str1.begin(), str1.end());

      anagrams.push_back(orgStr1);

      for(int j=i+1; j<length; j++){
        if(visited[j])
          continue;
        
        string orgStr2 = strs[j];
        string str2 = orgStr2;

        sort(str2.begin(), str2.end());

        if(str1 == str2){
          anagrams.push_back(orgStr2);
          visited[j] = true;
        }

      }
      output.push_back(anagrams);

    }

    
    return output;
}


int main()
{
  vector<bool> v(5, false);
  for(int i=0;i<5;i++)
  {
    v[i + 5] = true;
    //std::cout << v[i+10] << "\n";
  }

  cout << "\n";
  
  vector<bool>::iterator it = v.begin();
  while(it != v.end())
  {
    cout << *it << "\n";
    it++;
  }
  vector<string> input;//{"eat","tea","tan","ate","nat","bat"};
  input.push_back("eat");
  input.push_back("tea");
  input.push_back("tan");
  input.push_back("ate");
  input.push_back("nat");
  input.push_back("bat");

  vector<vector<string> > test = groupAnagrams2(input);

  for(vector<string> x : test)
  {
    for(string s : x)
    {
      cout << "  "  << s << "  ";
    }
    cout << "\n";
  }

  string arr[] = {"1", "3", "8", "8"};

  std::multimap<char,int> mymultimap;

  mymultimap.insert (std::pair<char,int>('a',10));
  mymultimap.insert (std::pair<char,int>('b',20));
  mymultimap.insert (std::pair<char,int>('b',150));

  // show content:
  for (std::multimap<char,int>::iterator it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';


  return 1;
}