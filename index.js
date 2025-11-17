const str = "welcme welcme to the jungle";
let counter = 0;

const splitted = str.split(" ").filter((elem) => {
  if (elem === "welcme") {
    counter++;
  }
  return true;
});
console.log(counter);
