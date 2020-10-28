class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;



    static void init(InputStream input) {
        reader = new BufferedReader(
                     new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }


    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {


            tokenizer = new StringTokenizer(
                   reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {

    	return Integer.parseInt( next() );
    }
	
    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}



Class Fibonacci {
    public static long fib(int x) {
          if (x <= 1) 
            return x; 
        return fib(x - 1) + fib(x - 2); 
    }

    public static void main(String args[]) {
        Reader.init(System.in);
        int n = Reader.nextInt();
        System.out.println("The "+n+"th Fibonacci number is: "+fib(n));
        
    }
}
