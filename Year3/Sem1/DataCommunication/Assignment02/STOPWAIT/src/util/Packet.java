package util;


public class Packet {
    private final int seqNum;
    String  data;

    public Packet(String data, int seqNum){
        /*if (length > MAX_SIZE) {
            throw new Exception("too large packet (max size 512)");
        }*/
        this.seqNum = seqNum;
        this.data = data;
    }

    public int getSeqNum() {
        return seqNum;
    }
}
