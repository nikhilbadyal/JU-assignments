package Assignment2.question7;

import java.sql.SQLOutput;
import java.util.StringTokenizer;

public class StringClass {
    public int stringAppears(String str,String word){
        int n = 0,space=0,noOfWords,flag = 0;

        str = str.trim();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i) == ' '){
                space++;
            }
        }

        noOfWords = space + 1;
        System.out.println(noOfWords);
        String[] s = str.split(" ");
        for(String x : s){
            System.out.println(x);
        }
        for(int i=0;i<noOfWords;i++){
            for(int j=0;j<s[i].length();j++){
                if(s[i].charAt(j) == word.charAt(j)){
                    flag++;
                }
            }
            if(flag == word.length()){
                n++;
            }
            flag=0;
        }
        return n;

    }

    public int characterAppears(String str,char ch){
        int n=0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i) == ch){
                n++;
            }
        }
        return n;
    }

    public boolean TheChecker(String str){
        str=str.trim();
        System.out.println(str.substring(0,3));
        if("The ".equalsIgnoreCase(str.substring(0,3))){
            return true;
        }
        return false;
    }

    public void TokenizeString(String str){
        StringTokenizer st = new StringTokenizer(str,".@ ");
        while(st.hasMoreTokens()){
            System.out.println(st.nextToken());
        }
    }


    public static void main(String[] args){
        String str = "the @aman is a go.od boy aman";



        StringClass s = new StringClass();
       // System.out.println(s.stringAppears(str,"aman"));
       // System.out.println((s.characterAppears(str,'a')));
        System.out.println(s.TheChecker(str));
        System.out.println();
        System.out.println();
        s.TokenizeString(str);

        /*String str2 = "raman";
        System.out.println(str.indexOf('a',1));
        System.out.println(str.indexOf("aan" ));
        System.out.println(str.indexOf("good",3));
        System.out.println(str2.compareTo(str));*/


    }
}
