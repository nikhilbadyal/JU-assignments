package util;

import sender.SenderDataLinkLayer;

import java.util.Arrays;
import java.util.zip.CRC32;

public class CRC {
    public static String getCrc(String message) {
        CRC32 crc32 = new CRC32();
        crc32.update(message.getBytes());
        String crc = Long.toString(crc32.getValue());
        int len = crc.length();
        if(len < SenderDataLinkLayer.CRC_LEN ){
            char pad = '0';
            char [] rep = new char[20-len];
            Arrays.fill(rep,pad);
            crc += new String(rep);
        }
        return crc;
    }
}
