package hackotober;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MinIntOfAList {
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		List<Integer> list = takeInput();

		display(list);

		System.out.println("The minimum is: " + getMinIntoList(list));
	}

	public static List<Integer> takeInput() {
		System.out.println("What is the size of the list?");
		int n = scn.nextInt();

		List<Integer> arr = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			System.out.println("enter the value for " + (i + 1) + " index");
			arr.add(scn.nextInt());
		}
		return arr;
	}

	public static void display(List<Integer> list) {
		System.out.println("The list contains: ");
		list.stream().forEach(x -> System.out.print(x + " "));
		System.out.println("");
	}

	public static int getMinIntoList(List<Integer> list) {
		int min = list.stream().mapToInt(x -> x).min().orElse(Integer.MIN_VALUE);
		return min;
	}
}