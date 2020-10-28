function GetNum(num) {//gets the number assoicate with a roman character
    if (num == 'I' || num == 'i') {
        return 1;
    }
    if (num == 'V' || num == 'v') {
        return 5;
    }
    if (num == 'X' || num == 'x') {
        return 10;
    }
    if (num == 'L' || num == 'l') {
        return 50;
    }
    if (num == 'C' || num == 'c') {
        return 100;
    }
    if (num == 'D' || num == 'd') {
        return 500;
    }
    if (num == 'M' || num == 'm') {
        return 1000;
    }

    return -1;
}

function numberToRoman(number){//Converts a number into a roman numerial
    let roman = "";
    while(number != 0){//checks if the number is not equal to 0, if it is not equal then there is more processing to be done
        if(number >= 1000){//if the number is larger than 1000, then add an M to the roman string and subtract 1000 from number
            roman += "M";
            number -= 1000;
        }
        else if(number >= 900){//if the number is larger than 900, then add an CM to the roman string and subtract 900 from number
            roman += "CM";
            number -= 900;
        }
        else if(number >= 500){//if the number is larger than 500, then add an D to the roman string and subtract 500 from number
            roman += "D";
            number -= 500;
        }
        else if(number >= 400){//if the number is larger than 400, then add an CD to the roman string and subtract 400 from number
            roman += "CD";
            number -= 400;
        }
        else if(number >= 100){//if the number is larger than 100, then add an C to the roman string and subtract 100 from number
            roman += "C";
            number -= 100;
        }
        else if(number >= 90){//if the number is larger than 90, then add an XC to the roman string and subtract 90 from number
            roman += "XC";
            number -= 90;
        }
        else if(number >= 50){//if the number is larger than 50, then add an L to the roman string and subtract 50 from number
            roman += "L";
            number -= 50;
        }
        else if(number >= 40){//if the number is larger than 40, then add an XL to the roman string and subtract 40 from number
            roman += "XL";
            number -= 40;
        }
        else if(number >= 10){//if the number is larger than 10, then add an X to the roman string and subtract 10 from number
            roman += "X";
            number -= 10;
        }
        else if(number >= 9){//if the number is larger than 9, then add an IX to the roman string and subtract 9 from number
            roman += "IX";
            number -= 9;
        }
        else if(number >= 5){//if the number is larger than 5, then add an V to the roman string and subtract 5 from number
            roman += "V";
            number -= 5;
        }
        else if(number >= 4){//if the number is larger than 4, then add an IV to the roman string and subtract 4 from number
            roman += "IV";
            number -= 4;
        }
        else if(number >= 1){//if the number is larger than 1, then add an I to the roman string and subtract 1 from number
            roman += "I";
            number -= 1;
        }
    }
    return roman;
}

function romanToNumber(roman){//Converts a roman numerial into a number
    let results = 0;
    for (let i = 0; i < roman.length; i++) {//iterate through all the characters
        let cur = GetNum(roman[i]);//Gets the integer of the roman number
        if (cur == -1) {//checks if the cur num is -1, if it is -1, it means that it is an invalid character
            return -1;
        }
        if (i + 1 < roman.Length) {//checks if the next index is out of bounds
            let next = GetNum(roman[i + 1]);//gets the next character character
            if (next == -1) {//checks if the cur num is -1, if it is -1, it means that it is an invalid character
                return -1;
            }
            if (cur >= next) {//compares the current number to the next number
                results += cur;//if it is bigger, simply add the current number
            }
            else {//if the current number is smaller than the next number
                results += (next - cur);//subtract the next number by the current number
                i++;//increment the index, since the next number has already been used
            }
        }
        else {//only here to add the last number to the results
            results += cur;//adds the last character to the results
        }
    }
    return results;//returns the result
}

//Examples
console.log(numberToRoman(123));  //123 will return CXXIII
console.log(romanToNumber("VI")); //VI will return 6