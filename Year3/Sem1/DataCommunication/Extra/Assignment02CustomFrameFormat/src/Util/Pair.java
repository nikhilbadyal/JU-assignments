package Util;

public class Pair {
    boolean hasNext ;
    String status ;
    public Pair(boolean hasNext, String status) {
        this.hasNext = hasNext;
        this.status = status;

    }

    public String getKey() {
        return  status;
    }

    public boolean getValue() {
        return  hasNext;
    }
}
