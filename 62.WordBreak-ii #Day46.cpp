  void fun(string s,vector<vector<string>>& v,int i,vector<string>& ans,string temp)
    {
        if(i==s.size()){ // if indeex reaces to size of string, it means we have covered all string and finally reached at final point. So we can simply remove last space and store it in to answer vector;
            int n = temp.size();
            temp = temp.substr(0,n-1);
            ans.push_back(temp);
            return ;
        }
        vector<string> start = v[s[i]-'a'];
       
        for(int ind=0;ind<start.size();ind++){
           
            int n = start[ind].size(); // size of a string.
            string part = s.substr(i,n);// just taking out part of that specific lenngth substring  for compaaring that it is equal or not.
            if(part==start[ind]){ // if substring and string of start equal then we will proceed by adding string to temp. 
                fun(s,v,i+n,ans,temp+part+" ");
            }
        }
        return ;
        
    }
    
     public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> ans; // answer vector will contain all resultant string
        vector<vector<string>> array(26); // a vector to store  strings starting with  same alphabet 
        for(int i=0;i<wordDict.size();i++){
            array[wordDict[i][0]-'a'].push_back(wordDict[i]);
        }
        int ind=0;// starting index
        string temp=""; // temporary string to store current result
      fun(s,array,ind,ans,temp);

        return ans;
    }
