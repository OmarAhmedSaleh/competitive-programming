class Solution {
    public int handleSubtraction(StringBuilder rNum, int num){
        if(num >= 900){
            rNum.append("CM");
            num -= 900;
        }else{
            if(num >= 400 && num < 500){
                rNum.append("CD");
                num -= 400;
            }else{
                while(num >= 500){num -= 500; rNum.append("D");}
                while(num >= 100){num -= 100; rNum.append("C");}
            }
        }
        
        if(num >= 90 && num < 100){
            rNum.append("XC");
            num -= 90;
        }else{
            if(num >= 40 && num < 50){
                rNum.append("XL");
                num -= 40;
            }else{
                while(num >= 50){num -= 50; rNum.append("L");}
                while(num >= 10){num -= 10; rNum.append("X");}
            }            
        }

        if(num >= 9 && num < 10){
            rNum.append("IX");
            num -= 9;
        }else{
           if(num >= 4 && num < 5){
            rNum.append("IV");
            num -= 4;
           }else{
               while(num >= 5){num -= 5; rNum.append("V");}
               while(num >= 1){num -= 1; rNum.append("I");}
           } 
        }
        
        return num;
    }
    public String intToRoman(int num) {
        StringBuilder rNum = new StringBuilder("");
        while(num >= 1000){
            num -= 1000;
            rNum.append("M");
        }
        handleSubtraction(rNum, num);
        return rNum.toString();
    }
}
