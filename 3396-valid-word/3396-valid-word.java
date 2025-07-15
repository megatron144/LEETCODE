class Solution {
     private boolean isVowel(char c){
        return (c=='a'|| c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U');
    }
    public boolean isValid(String word) {
        int l=word.length();
        boolean vow=false,cons=false;
        if(l<3)return false;
        for(char c: word.toCharArray()){
            if(Character.isDigit(c))continue;
            if(isVowel(c))vow=true;
            else if(Character.isLetter(c))cons=true;
            else return false;
        }
        return vow && cons;
    }
}