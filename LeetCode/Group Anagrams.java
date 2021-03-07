class Solution {
    public String sortString(String s){
        char[] charArray = s.toCharArray();
        Arrays.sort(charArray);
        return new String(charArray);
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,Integer> stringToGroupIndex = new HashMap<String, Integer>();
        List<List<String>> groups = new ArrayList<List<String>> (); 
        for(String str: strs){
            String sortedString = sortString(str);
            int groupIdx = groups.size();
            if(stringToGroupIndex.containsKey(sortedString)){
                groupIdx = stringToGroupIndex.get(sortedString);
            }else{
                groups.add(new ArrayList<String>());
                stringToGroupIndex.put(sortedString, groupIdx);
            }
            groups.get(groupIdx).add(str);
        }
        return groups;
    }
}
