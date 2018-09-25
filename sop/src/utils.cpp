#include "includes/utils.hpp"

bool getFiles(vector<string>& files, const char * name, const char * nthr, unsigned int ithr){
  string tname = name;
  string tnthr = nthr;
  files.push_back(tname);
  FILE * a;
  for(unsigned int i=1; i<=ithr; i++){
    string temp = tname+"-"+to_string(i);
    if(temp.size() <= tname.size()){
      return false;
    }else if((a = fopen(temp.c_str(), "r")) == NULL){
      return false;
    }
    fclose(a);
    files.push_back(temp);
  }
  return true;
}

bool isNumber(string str){
  for(auto c : str){
    if(c < '0' or c > '9'){
      return false;
    }
  }
  return true;
}
