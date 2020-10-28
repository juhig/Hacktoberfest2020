<!DOCTYPE HTML>
<?xml version="1.0" encoding="utf-8"?>
<html xmlns="http://www.w3.org/1999/xhtml">
 
<head>
<title> Square.html </title>
<script type="text/javascript">
function square()
{
var n=prompt ("Enter the limit 'n' to generate the table of numbers from 1 to n:","");
var msg="";
var res= "0";
 
for(var x= 1; x<=n;x++)
{
res = x * x;
msg = msg + " " + x + " * "+ x + " = " + res + "\n";
}
 
alert(msg);
} 
</script>

</head>
 
<body style = "background-color:lightblue" onload = "square();">
<h2 style="text-align:center;color:black"> Javascript to generate squares of 1 to 'N' numbers</h2>
</body>
</html>
