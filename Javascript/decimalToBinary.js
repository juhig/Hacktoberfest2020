// function for the decimal to binary

function decimalToBinary(n) {
// Declaration of array for storing binary number
    let binaryDigits = [];
// Looping through the values
    while (n > 0) {
        binaryDigits.unshift(n % 2);
        n = Math.floor(n / 2);
    }
// Array joining as binary number
    return binaryDigits.join("");
}
