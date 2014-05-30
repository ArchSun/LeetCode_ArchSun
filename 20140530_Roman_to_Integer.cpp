class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int inter = 0;
        while (i<s.size()){
            if (s[i]=='M')
                inter += 1000;
            else if (s[i]=='C'&&s[i+1]!='D'&&s[i+1]!='M')
                inter += 100;
            else if (s[i]=='C')
                inter -= 100;
            else if (s[i]=='D')
                inter += 500;
            else if (s[i]=='X'&&s[i+1]!='L'&&s[i+1]!='C')
                inter += 10;
            else if (s[i]=='X')
                inter -=10;
            else if (s[i]=='L')
                inter += 50;
            else if (s[i]=='I'&&s[i+1]!='V'&&s[i+1]!='X')
                inter += 1;
            else if (s[i]=='I')
                inter -= 1;
            else
                inter += 5;
            i++;
        }
        return inter;
    }
};
