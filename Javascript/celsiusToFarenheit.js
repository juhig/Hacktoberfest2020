const celsiusToFarenheit = celsius => {
    if(isNaN(celsius)){
        return "The providede value is not a number.";
    }
    return celsius*9/5+32;
}
