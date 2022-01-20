package ChannelDir;
public class Packet
{
    int length;
    byte[] data;

    public Packet() {
        this.data = new byte[100];
    }

}
