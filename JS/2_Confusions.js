//10 + "20"
//9  - "5"
//" " + " "
//" " + 0
//"shahil" + "gupta"
//"shahil" - "gupta" 
//true + true
//true + false
//false + true
//flase - true

var a1 = 10 + 20;
console.log("a1 = ", a1);
var a2 = 10 + "20";
console.log("a2 = ", a2);

var b = 9 - "5";
console.log("b = ", b);
var c = "9" - "5";
console.log("c = ", c);
var d1 = "9" - 5;
console.log("d1 = ", d1);
var d2 = "19" - "5";
console.log("d2 = ", d2);


var e = "shahil" - "gupta";
console.log("e = ", e);// NaN = not a number
//NaN is a property of the global object.
//In other words, it is a variable in global scope.
//The initial value of NaN is Not-a-Number

var e2 = "Shahil" + "Gupta"; 
console.log(isNaN(e2)); //true
console.log(isNaN(b)); //false

var f1 = " " + " ";
console.log("f1 = ",f1);

var g1 = true + true;
var g2 = true + false;
var g3 = false + true;
var g4 = false - true;
var g5 = false + false;

console.log("g1,g2,g3,g4,g5 = ",g1,g2,g3,g4,g5);