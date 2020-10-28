
public class BeginArrayAtIndex {

	public static int[] intArrayAtIndex(int[] array, int size, int startingIndex) {
		int[] newArray = new int[size];
		for (int i = 0; i < array.length; i++) {
			int pointer = (i + startingIndex) % array.length;
			newArray[i] = array[pointer];
		}
		newArray[12] = newArray[0];
		return newArray;
	}
	
	public static String[] stringArrayAtIndex(String[] array, int size, int startingIndex) {
		String[] newArray = new String[size];
		for (int i = 0; i < array.length; i++) {
			int pointer = (i + startingIndex) % array.length;
			newArray[i] = array[pointer];
		}
		newArray[12] = newArray[0];
		return newArray;
	}
}
