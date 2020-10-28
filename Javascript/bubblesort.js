// Javascript: Bubblesort

// Basics:
// Compare every adjacent index, swap if needed
// Compare the next pair until end of arr
// Repeat for arr.length times

function bubbleSort(arr) {
  //iterate through every index
  for (let i = 0; i < arr.length; i++) {
    //iterate through every index
    for (let j = 0; j < arr.length; j++) {
      //if j > j + 1, swap
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

let arr = [2, 8, 1, 3, 9, 6, 7, 5, 4];
let sortArr = bubbleSort(arr);
console.log(sortArr);
