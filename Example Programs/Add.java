import java.util.*;

public class Add {
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
        int x = 10;
        int y = 20;
        System.out.print(("Sum = " + (x+y) + ""));
    }

}
