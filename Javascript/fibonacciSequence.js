// Fibonacci sequence using recursion method


function fibonacci(num) 
    {    
        if(num==1) 
            return 0; 
        if (num == 2) 
            return 1; 
        return fibonacci(num - 1) + fibonacci(num - 2); 
    } 
    
    // Use the line below to get the output
// document.write("Fibonacci(5): "+fibonacci(5)+"<br>"); 
