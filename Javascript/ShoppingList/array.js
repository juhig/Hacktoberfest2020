let shoppingList = ["milk", "bread", "butter", "chocolate", "cream"];
shoppingList.forEach(function (items) {
  console.log(items);
});

shoppingList.push("wheat", "rice", "juice", "cashews");
console.log("updated list of items");
shoppingList.forEach(function (shoppingBasket) {
  console.log(shoppingBasket);
});
