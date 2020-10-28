package strings;

public class AnagramOptimised {

	public static void main(String[] args) {
		String a="aab#123";
		String b="aba#321";
		boolean isAnagram = true;
		
		int al[]=new int[256];
		int bl[]=new int[256];//remove the array for more optimisation
		
		for(char c:a.toCharArray()) { //for each loop
			int index=(int) c;
			al[index]++;
		}
		
		for(char c:b.toCharArray()) { //for each loop
			int index=(int) c;
			bl[index]++; //al[index]--
		}
		
		for(int i=0; i<256; i++) {
			if(al[i]!=bl[i]) {
				isAnagram= false;
				break;
			}
		}
		

		if(isAnagram) {
			System.out.println("anagram");
		}
		else {
			System.out.println("not an anagram");
		}


	}

}
