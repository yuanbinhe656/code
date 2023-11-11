/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        bool result;
        class bp {
            public :
            bool xiaoshu(string s)
            {
                if(s[0] =='.')
                {
                    return true;
                }
                else return false;
            }
             bool fuhao(string x)
            {
                if( x[0]=='.'||x[0] == '.')
                {
                    return true;
                }
                else return false;
            }
            bool shuzi( string &x) {
                for (int i = 0; i < x.size();i++)
                {
                    if(x[i]>=0 && x[i]<=9)
                    {
                        x = x.erase(0,i);
                    }
                    else if (i != x.size() - 1)
                    {

                        return false;
                    }
                    else return true;
                        
                }
                if(x == "")
                {
                 return false;   
                }
                return  true;
            
            }
            bool ex(string x)
            {
                if(x[0] == 'e'|| x[0] == 'e')
                {
                    return true;
                }
                else return false;
            }

        };
       
        
        string ::iterator iter1 = s.begin(),iter2;
        bp ba;
       
            iter2 = s.begin() +1;
            if( ba.ex(s)) //判断e
            {
                
                if(ba.shuzi(new string(iter2,s.end()))){
                    return true;
                }
                else if(ba.fuhao(new string(iter2,s.end()))){
                    iter2++;
                     if(ba.shuzi(new string(iter2,s.end()))){
                    return true;
                      
                }
                  else return false;
                }
                else return false;
                
            }
            else  if(ba.shuzi( new string(iter1,s.end()) )){   //纯数字
                    return true;
                }
                else if(ba.fuhao(new string(iter1,s.end()))){ //带符号
                    
                     
                if( ba.xiaoshu(new string(iter1+1,s.end())))  //
                {
                    if(ba.shuzi(new string(iter1+2,s.end())))
                    {
                        return true;

                    }
                    
                    else return false;
                }
                else if(ba.shuzi(new string(iter2,s.end()))){
                    return true;
                      }
                    else if(ba.xiaoshu(s))
                    {
                        if (ba.shuzi(new string(s.beging()+1,s.end())))
                        {
                            return true;
                        }
                        else return false;
                    }
                else return false;
                }
                else if( ba.xiaoshu(s))  //小数
                {
                    if(ba.shuzi(new string(s.begin()+1,s.end())))
                    {
                        return true;

                    }
                    else return false;
                }
                else return false;
        
        return result;
    }
};
// @lc code=end

