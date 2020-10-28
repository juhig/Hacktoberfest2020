import java.util.Scanner;

public class piglatin {
    public static void main(String Args[]) {
        int k = 0;
        int m = 0;
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter the string:");
        String a = kb.nextLine();
        int l = a.length();
        a = a.toUpperCase();
        for (int i = 0; i < l; i++) {
            if (a.charAt(i) == 'A' | a.charAt(i) == 'E' | a.charAt(i) == 'I' | a.charAt(i) == 'O'
                    | a.charAt(i) == 'U') {
                k++;
                m = i;
                break;
            }
        }
        if (k != 0) {
            System.out.println(a.substring(m, l) + a.substring(0, m) + "AY");
        } else {
            System.out.println(a + "AY");
        }
    }
}
