function CheckDataInArray(array, data) {
    let splitData = []
    for (let a = 0; a < array.length; a++) {
        if (array[a] == data) {
            //do what your command here etc replace with other data , or remove it
            splitData.push(array[a])
        }
    }
    return splitData;
}