class Solution {
public:
    string intToRoman(int num) {
        string roman[4][9]={"M", "MM", "MMM", "MM", "M", "MM", "MMM", "MMMM", "MM",
                            "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                            "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                            "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        string retRoman = "";
        int scale = 1000;
        int flag = 0;
        while(scale){
            if (num/scale)
                retRoman.append(roman[flag][num/scale-1]);
            flag++;
            num%=scale;
            scale/=10;
        }
        return retRoman;
    }
};
