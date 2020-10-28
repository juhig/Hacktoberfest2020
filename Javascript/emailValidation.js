function validateEmail(params) {
    var re = /\S+@\S+\.\S+/;

    if(re.test(params) == true){
        return 'this is a valid email'
    } else{
        return 'this is not a email'
    }

}


console.log(validateEmail('mark@gmail.com'))


