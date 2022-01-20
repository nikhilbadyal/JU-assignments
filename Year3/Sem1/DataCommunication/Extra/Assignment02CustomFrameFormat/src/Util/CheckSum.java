package Util;

public class CheckSum {
    public static String getChecksum(String segment) {
        String hexValue ;
        int x ;
        int checksum = 0;
        int i ;
        for ( i = 0; i < segment.length() - 2; i = i + 2)
        {
            x = (int) (segment.charAt(i));
            hexValue = Integer.toHexString(x);
            x = (int) (segment.charAt(i + 1));
            hexValue = hexValue + Integer.toHexString(x);
            x = Integer.parseInt(hexValue, 16);
            checksum += x;
        }
        if (segment.length() % 2 == 0)
        {
            x = (int) (segment.charAt(i));
            hexValue = Integer.toHexString(x);
            x = (int) (segment.charAt(i + 1));
            hexValue = hexValue + Integer.toHexString(x);
            x = Integer.parseInt(hexValue, 16);
        }
        else
        {
            x = (int) (segment.charAt(i));
            hexValue = "00" + Integer.toHexString(x);
            x = Integer.parseInt(hexValue, 16);
        }
        checksum += x;
        hexValue = Integer.toHexString(checksum);
        if (hexValue.length() > 4)
        {
            int carry = Integer.parseInt(("" + hexValue.charAt(0)), 16);
            hexValue = hexValue.substring(1, 5);
            checksum = Integer.parseInt(hexValue, 16);
            checksum += carry;
        }
        checksum = generateComplement(checksum);
        return Integer.toHexString(checksum);
    }
    static int generateComplement(int checksum)
    {
        checksum = Integer.parseInt("FFFF", 16) - checksum;
        return checksum;
    }
}
