public String lastChars(String a, String b) {
    char bb = (b.length()<1)?'@':b.charAt(b.length()-1);
    char aa = (a.length()<1)?'@':a.charAt(0);
    return ""+aa+bb;
}
