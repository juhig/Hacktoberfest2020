import java.util.*;

public class TicTacToeDriver {
    public static void main(String[] args) {
        TicTacToe game = new TicTacToe(3);

        Scanner input = new Scanner(System.in);
        System.out.println("Please Enter Row/Column on separate lines");
        int row = input.nextInt();
        int column = input.nextInt();

        int currentPlayer = 1;
        int move = game.move(row, column, 1);
        while(move == 0) {
            if(currentPlayer == 1) currentPlayer = 2;
            else currentPlayer = 1;

            System.out.println("Please Enter Row/Column on separate lines");
            row = input.nextInt();
            column = input.nextInt();
            move = game.move(row, column, currentPlayer);
        }

        if(move == 1) System.out.println("Player 1 Won!");
        else System.out.println("Player 2 Won!");
    }
}
