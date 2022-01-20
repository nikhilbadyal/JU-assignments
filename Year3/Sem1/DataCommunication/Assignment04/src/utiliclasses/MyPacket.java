package utiliclasses;

import java.nio.ByteBuffer;
import java.util.Arrays;

public class MyPacket {
    private final int length;
    private final byte[] data;
    private static final int HEADER_SIZE = 4;

    public byte[] getData() {
        System.out.println(Arrays.toString(data));
        return data;
    }

    public MyPacket(int length, byte[] data) throws Exception {
        this.length = length;
        this.data = data;
    }

    public static MyPacket getPacket(byte[] bytes) throws Exception {
        ByteBuffer buffer = ByteBuffer.wrap(bytes);
        int length = buffer.getInt();
        System.out.println("Length is "+length);
        byte[] data = new byte[length-HEADER_SIZE];
        buffer.get(data, 0, length-HEADER_SIZE);
        System.out.println(Arrays.toString(data));
        return new MyPacket(length, data);

    }

    public byte[] getBytes() {
        ByteBuffer buffer = ByteBuffer.allocate(length);
        buffer.putInt(length);
        buffer.put(data, 0, length-HEADER_SIZE);
        System.out.println(Arrays.toString(buffer.array()));
        return buffer.array();
    }
}
