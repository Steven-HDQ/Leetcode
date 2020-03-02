1.cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a(2,0);
        for (int m=0;m<(nums.size()-1);m++)
        {
            for (int n=m+1;n<nums.size();n++)
            {if(nums[m]+nums[n]==target)
            {
                a[0]=m;a[1]=n;
                return a;
            }
             }
            }
        return a;
    }
};

1.py
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        a=list()
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    a.append(i)
                    a.append(j)
        return a

7.cpp
class Solution {
public:
     int reverse(int x) {
        long int a=0;
        if((x>-10)&&(x<10)){return x;}
        else {
            do{
                a=a*10+x%10;
                x=x/10;
            }while(x/10!=0);
            a=a*10+x;
            if((a<-2147483648)||(a>2147483647)){return 0;} 
            else{return a;}            
        }    
   }
};

9.cpp
class Solution {
public:
    bool isPalindrome(int x) {     
        long int a=0,b=x;
        if(x<0){return false;}
        else if((x>=0)&&(x<10)){return true;}
        else {
            do{
                a=a*10+x%10;
                x=x/10;
            }while(x/10!=0);
            a=a*10+x;
            if(a==b){return true;} 
            else{return false;}            
        }    
    }
};

13.cpp
class Solution {
public:
    int convert(char c){
        int data;
        switch(c){
                case'I':data=1;break;
                case'V':data=5;break;
                case'X':data=10;break;
                case'L':data=50;break;
                case'C':data=100;break;
                case'D':data=500;break;
                case'M':data=1000;break;  
        }
        return data;
    }
    int romanToInt(string s) {
        int sum=convert(s[0]);
        for(int i=1;i<s.length();i++){
            sum+=convert(s[i]);
            if(convert(s[i-1])<convert(s[i])){
                sum-=2*convert(s[i-1]);
            }
        }
        return sum;
    }
};

14.cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string x;
        char z;
        if(strs.empty()){return x;}
        for(int j=0;j<strs[0].length();j++){
            z=strs[0][j];
            for(int i=1;i<strs.size();i++){
                if(z!=strs[i][j]){return x;}
            }
            x+=z;  
        }
        return x;
    }
};

20.cpp
class Solution {
public:
    bool isValid(string s) {
        if(s==""){return true;}
        if(s.length()%2!=0){return false;}
        string t;
        t=t+s[0];
        for(int i=1;i<s.length();i++){
            switch(s[i]){
                    case '(':t=t+s[i];break;
                    case '{':t=t+s[i];break;
                    case '[':t=t+s[i];break;
                    case ')':if(t[t.length()-1]!='('){return false;}
                             else {t.pop_back();}
                             break;
                    case '}':if(t[t.length()-1]!='{'){return false;}
                             else {t.pop_back();}
                             break;
                    case ']':if(t[t.length()-1]!='['){return false;}
                             else {t.pop_back();}
                             break;
            }
        }
        if(t==""){return true;}
        else {return false;}
    }
};

21.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* l;
        if(l1->val<l2->val){l=l1;l1=l1->next;}
        else {l=l2;l2=l2->next;}
        ListNode* p=l;
        while(l1&&l2){
            if(l1->val<l2->val){p->next=l1;l1=l1->next;}
            else{p->next=l2;l2=l2->next;}
            p=p->next;
        }
        if(l1) p->next=l1;
        else p->next=l2;
        return l;
    }
};

26.cpp.1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        if(nums.size()==0){return 0;}
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){l++;nums[l]=nums[i];}
        }
        return l+1;
    }
};

26.cpp.2(not so good at runtime)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){nums.erase(begin(nums)+i);i--;}
        }
        return nums.size();
    }
};

27.cpp.1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        if(nums.size()==0){return 0;}
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){nums[l]=nums[i];l++;}
        }
        return l;
    }
};

27.cpp.2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){return 0;}
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){nums.erase(begin(nums)+i);i--;}
        }
        return nums.size();
    }
};

28.cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){return 0;}
        if(haystack.length()<needle.length()){return -1;}
        for(int i=0;i<=haystack.length()-needle.length();i++){
            if(haystack[i]==needle[0]){
                if(needle.length()==1){return i;}
                int t=0;
                for(int j=1;j<needle.length();j++){
                    if(haystack[i+j]!=needle[j]){t=-1;break;}
                }
                if(t==0){return i;}
            }
        }
        return -1;
    }
};

35.cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(target<=nums[i]){return i;}
        }
        return nums.size();
    }
};

38.cpp
class Solution {
public:
    string countAndSay(int n) {
        string ss[31];
        ss[0]="1";
        for(int m=1;m<=n;m++){
          string s="";
          string sn=ss[m-1];
          int num=sn[0],c=1;
          for(int i=1;i<sn.length();i++){
              if(sn[i]==sn[i-1]){c++;}
              else{s=s+to_string(c)+sn[i-1];c=1;}
          }
          s=s+to_string(c)+sn[sn.length()-1];
          ss[m]=s;  
        }
        return ss[n-1];
    }
};

53.cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],t=0;
        for(int i=0;i<nums.size();i++){
            t=t+nums[i];
            if(t>maxsum){maxsum=t;}
            if(t<0){t=0;}
        }   
        return maxsum;
    }
};

58.cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int t=0;
        if(s.length()==0){return 0;}
        for(int i=0;i<s.length();i++){
            if(s[s.length()-1]==' '){s.pop_back();i--;continue;}
            if(s[s.length()-1-i]==' '){return t;}
            t++;
        }
        return t;
    }
};

66.cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if((digits.size()==1)&&(digits[0]==9)){
            digits[0]=0;
            digits.insert(begin(digits),1);
            return digits;
        }
        if(digits[digits.size()-1]!=9){digits[digits.size()-1]+=1;return digits;}
        else {
            digits.pop_back();
            digits=plusOne(digits);
            digits.insert(end(digits),0);
            return digits;
        }
    }
};

67.cpp
class Solution {
public:
    string addone(string s){
        if(s.length()==0){return "1";}
        if(s[s.length()-1]=='0'){s[s.length()-1]='1';return s;}
        else{
            s.pop_back();
            s=addone(s);
            s+='0';
            return s;
            }
    }
    int c=0;
    string addBinary(string a, string b) {
        string s;
        char k;
        if((a.length()==0)&&(b.length()==0)){
            if(c==0){return "";}
            else {return "1";}
        }
        if(a.length()==0){
            if(c==0){return b;}
            else {b=addone(b);return b;}
        }
        if(b.length()==0){
            if(c==0){return a;}
            else {a=addone(a);return a;}
        }
        int t;
        t=(int)a[a.length()-1]+(int)b[b.length()-1]+c-96;
        switch(t){
                case 0:t=0;c=0;break;
                case 1:t=1;c=0;break;
                case 2:t=0;c=1;break;
                case 3:t=1;c=1;break;
        }
        a.pop_back();b.pop_back();
        s=addBinary(a,b);
        k=t+'0';
        s+=k;
        return s;
    }
};

69.cpp
class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x;
        long int m;
        if(x==1){return 1;}
        while((low!=high)&&(low!=(high-1))){
            m=(low+high)/2;
            if(m*m>x){high=m;}
            else if(m*m<x){low=m;}
            else {return m;}
        }
        return low;
    }
};

70.cpp
class Solution {
public:
    int climbStairs(int n) {
        long int a=1,b=1;
        while(n--){
            a=(b+=a)-a;
        }
        return a;
    }
};

83.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* p=head;
        while(p->next){
            if(p->val==p->next->val)p->next=p->next->next;
            else p=p->next;
        }
        return head;
    }
};

88.cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t=0;
        if(m==0){nums1=nums2;}
        else{
            for(int i=0;i<n;i++){
            for(t;t<m+n;t++){
                if(nums2[i]<=nums1[t]){
                    nums1.insert(begin(nums1)+(t++),nums2[i]);
                    nums1.pop_back();
                    break;
                    }
                if(nums2[i]>nums1[t]&&(nums2[i]<=nums1[t+1]||t==m+i-1)){
                    nums1.insert(begin(nums1)+(++t),nums2[i]);
                    nums1.pop_back();
                    break;
                    }
                }
            }
        }
    }
};

100.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL) return p==q;
        return p->val==q->val&&isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};

118.cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        return r;
    }
};


119.cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        return r[rowIndex];
    }
};