import java.util.*;

public class BubbleSort {
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
        int n = readInt("Enter number of elements: ");
        int[] a = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i <= (n - 1); i += 1) {
            int v = readInt("  element: ");
            a[i] = v;
        }
        System.out.println("Original array:");
        for (int i = 0; i <= (n - 1); i += 1) {
            System.out.print(a[i]);
            if ((i < (n - 1))) {
                System.out.print(" ");
            }
        }
        System.out.println("");
        for (int i = 0; i <= (n - 2); i += 1) {
            for (int j = 0; j <= ((n - i) - 2); j += 1) {
                if ((a[j] > a[(j + 1)])) {
                    int temp = a[j];
                    a[j] = a[(j + 1)];
                    a[(j + 1)] = temp;
                }
            }
        }
        System.out.println("Sorted array:");
        for (int i = 0; i <= (n - 1); i += 1) {
            System.out.print(a[i]);
            if ((i < (n - 1))) {
                System.out.print(" ");
            }
        }
        System.out.println("");
    }

}
