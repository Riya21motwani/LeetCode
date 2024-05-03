stringstream ss (version) are used to break the string acc to '.' or ','
or anything into string of array
exp
1.02.02
{'1','2','2'}
vector< string >gettoken(string version){
stringstream ss(version);
vector<string>tokens;
string token="";
while(getline(ss,token,'.')){
tokens.push_back(token);
}
return tokens;
}