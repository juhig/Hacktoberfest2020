var one=document.getElementById('one');
var two=document.getElementById('two');
var three=document.getElementById('three');
one.addEventListener('click', function(){
    var  paraone=document.getElementById('paraone');
    var  paratwo=document.getElementById('paratwo');
    paraone.style.display="block";
    paratwo.style.display='none';

})
two.addEventListener('click', function(){
    var  paraone=document.getElementById('paraone');
    var  paratwo=document.getElementById('paratwo');
    var  parathree=document.getElementById('parathree');
    paraone.style.display="none";
    paratwo.style.display='block';
    parathree.style.display='none';
    


})
three.addEventListener('click', function(){
    var  paraone=document.getElementById('paraone');
    var  paratwo=document.getElementById('paratwo');
    var  parathree=document.getElementById('parathree');
    paraone.style.display="none";
    paratwo.style.display='none';
    parathree.style.display='block';

})