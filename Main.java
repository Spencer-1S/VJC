import java.util.*;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);

    private static int readInt(String prompt) {
        System.out.print(prompt);
        String s = scanner.nextLine();
        return Integer.parseInt(s.trim());
    }

    private static double readDouble(String prompt) {
        System.out.print(prompt);
        String s = scanner.nextLine();
        return Double.parseDouble(s.trim());
    }

    private static boolean readBool(String prompt) {
        System.out.print(prompt);
        String s = scanner.nextLine();
        return Boolean.parseBoolean(s.trim());
    }

    private static String readLine(String prompt) {
        System.out.print(prompt);
        return scanner.nextLine();
    }

    public static void main(String[] args) {
        System.out.println("=== Array & Prime Analyzer ===");
        int n = readInt("Enter the size of the array: ");
        if (((n <= 0) || (n > 100))) {
            System.out.println("Invalid size! Defaulting to 5.");
            n = 5;
        }
        int[] arr = new int[n];
        System.out.println("Let's fill the array. Enter -1 to stop early.");
        int count = 0;
        while ((count < arr.length)) {
            int val = readInt(("Enter element " + (count) + ": "));
            if ((val == (-1))) {
                System.out.println("Stopping input early.");
                break;
            }
            arr[count] = val;
            count = (count + 1);
        }
        int primeCount = 0;
        double sum = 0;
        for (int i = 0; i <= (count - 1); i += 1) {
            int current = arr[i];
            if ((current <= 0)) {
                continue;
            }
            sum = (sum + ((double)(current)));
            boolean isP = checkPrime(current);
            if (((isP == true) && (current != 1))) {
                primeCount = (primeCount + 1);
                System.out.println(("" + (current) + " is a prime number!"));
            }
        }
        int remainder = (count % 2);
        double average = (sum / ((double)(count)));
        System.out.println(("\nTotal Primes Found: " + (primeCount) + ""));
        System.out.println(("Average of elements: " + (average) + ""));
        if ((remainder == 0)) {
            System.out.println("You processed an even number of elements.");
        } else {
            System.out.println("You processed an odd number of elements.");
        }
    }

    public static boolean checkPrime(int x) {
        if ((x < 2)) {
            return false;
        }
        for (int i = 2; i <= (x - 1); i += 1) {
            if (((x % i) == 0)) {
                return false;
            }
        }
        return true;
    }

}
