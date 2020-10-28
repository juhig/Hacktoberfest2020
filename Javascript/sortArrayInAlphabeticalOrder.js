let array = [{item: 'apple'}, {item: 'zebra'}, {item: 'bed'}];

const alphabeticalSort = (array) => {
 return array.sort((a, b) => a.item.localeCompare(b.item));
};