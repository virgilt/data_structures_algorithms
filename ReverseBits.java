import java.util.Scanner;

class ReverseBits {

    static int reverseBits(int input) {
        int output = 0;
        while (input != 0) {
            output = output << 1;

            if ((input & 1) == 1) {
                output |= 1;
            }

            input = input >> 1;
        }

        return output;
    }

    public static void main(String[] args) {
        Scanner keyboardInput = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int num = keyboardInput.nextInt();

        System.out.println(reverseBits(num));
    }
}