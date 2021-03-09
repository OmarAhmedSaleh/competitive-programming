class MyHashSet {
    private final int maxKey = (int)1e6;
    private boolean[] mySet;
    /** Initialize your data structure here. */
    public MyHashSet() {
        mySet = new boolean[maxKey + 1];
    }
    
    public void add(int key) {
        mySet[key] = true;
    }
    
    public void remove(int key) {
        mySet[key] = false;        
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return mySet[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
