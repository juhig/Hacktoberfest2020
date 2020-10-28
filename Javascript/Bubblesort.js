let bubbleSort = (unordered) => {
  let flag;
  do {
    flag = false;
    for (let i = 0; i < unordered.length; i++) {
      if (unordered[i] > unordered[i + 1]) {
        let aux = unordered[i];
        unordered[i] = unordered[i + 1];
        unordered[i + 1] = aux;
        flag = true;
      }
    }
  } while (flag);
  return unordered;
};

const unsorted = [9, 5, 1, 2, 7, 10, 0, -1];
const sorted = bubbleSort(unsorted);
console.log(sorted);
