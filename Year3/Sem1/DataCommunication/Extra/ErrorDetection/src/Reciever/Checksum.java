package Reciever;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Checksum {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String message = bufferedReader.readLine();
        String  checksum = getCheckSum(message);
        System.out.println("Check Sum for given data is :"+ checksum);
    }

    private static String  getCheckSum(String s) {
        String hex_value = new String();
        int x, i, checksum = 0;
        for (i = 0; i < s.length() - 2; i = i + 2)
        {
            x = (int) (s.charAt(i));
            hex_value = Integer.toHexString(x);
            x = (int) (s.charAt(i + 1));
            hex_value = hex_value + Integer.toHexString(x);
            x = Integer.parseInt(hex_value, 16);
            checksum += x;
        }
        if (s.length() % 2 == 0)
        {
            x = (int) (s.charAt(i));
            hex_value = Integer.toHexString(x);
            x = (int) (s.charAt(i + 1));
            hex_value = hex_value + Integer.toHexString(x);
            x = Integer.parseInt(hex_value, 16);
        }
        else
        {
            x = (int) (s.charAt(i));
            hex_value = "00" + Integer.toHexString(x);
            x = Integer.parseInt(hex_value, 16);
        }
        checksum += x;
        hex_value = Integer.toHexString(checksum);
        if (hex_value.length() > 4)
        {
            int carry = Integer.parseInt(("" + hex_value.charAt(0)), 16);
            hex_value = hex_value.substring(1, 5);
            checksum = Integer.parseInt(hex_value, 16);
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
