import java.util.Scanner

fun main() {
    println("Enter the length of array")
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    
    println("Enter elements of the array")
    var array = arrayOfNulls<Int>(n);
    for(index in 0..n-1){
        array[index] = sc.nextInt()
    }
    
    println("Enter a value to search in the array")
    linearSearch(array, sc.nextInt())
    
}

fun linearSearch(searchArray: Array<Int?>, searchNumber: Int){
    for(value in searchArray){
        if(value==searchNumber){
            println("$searchNumber is present in the array")
            return;
        }
    }
    println("$searchNumber is not present in the array")
}
