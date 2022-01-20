package Util;

public class PasswordChecker {
    public static boolean isStrong(String password){
        return password.matches("^(?=.*[A-Z].*[A-Z])(?=.*[!@#$&*])(?=.*[0-9].*[0-9])(?=.*[a-z].*[a-z].*[a-z]).{8}$");
    }
}
