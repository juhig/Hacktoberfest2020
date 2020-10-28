import Foundation

func oddOrEven(num: Int) -> String {
    var result = ""

    if(num % 2 == 0){
        result = "even"
    }else{
        result = "odd"
    }

    return result
}
