import java.util.Scanner;

class Main {

    static boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        double log = Math.log10(x);
        int totalDigits = (int) Math.floor(log) + 1;
        int mask = (int) Math.pow(10, totalDigits - 1);

        for (int i = 0; i < totalDigits / 2; i++) {
            int leftMostDigit = x / mask;
            int rightMostDigit = x % 10;

            if (leftMostDigit != rightMostDigit) {
                return false;
            }

            x %= mask;
            x /= 10;
            mask /= 100;
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner keyboardInput = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = keyboardInput.nextInt();

        System.out.println(isPalindrome(num));
    }
}