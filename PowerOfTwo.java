import java.util.Scanner;

class PowerOfTwo {

    static boolean isPowerOfTwo(int num) {
        if (num == 0) {
            return false;
        }
        if (num % 2 == 0 || num == 1) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int num = input.nextInt();

        System.out.println(isPowerOfTwo(num));
    }
}