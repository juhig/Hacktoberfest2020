import kotlin.system.exitProcess

fun main() {
    print("Number of rows: ")
    val rows = readLine()?.toIntOrNull()

    if (rows == null || rows < 1) {
        println("The value for 'rows' must be a number higher than 0")
        exitProcess(0)
    }

    print("Number of columns: ")

    val columns = readLine()?.toIntOrNull()

    if (columns == null || columns < 1) {
        println("The value for 'columns' must be a number higher than 0")
        exitProcess(0)
    }

    print("Power: ")
    val power = readLine()?.toIntOrNull()

    if (power == null || power < 2) {
        println("Power must be a number higher or equal to 2")
        exitProcess(0)
    }

    val matrix = Array(rows) { IntArray(columns) }

    println("Type yor $rows x $columns matrix (the value of each column on it's own line)")
    var zeros = 0

    for (i in 0 until rows) {
        println("# Row ${i + 1}")

        for (j in 0 until columns) {
            val number = readLine()?.toIntOrNull() ?: 0

            if (number == 0) {
                zeros++
            }

            matrix[i][j] = number
        }
    }

    println("Your matrix: ")
    matrix.print()

    println("Sparse matrix: ${zeros > rows * columns - zeros}")

    matrix.pow(power)
}

fun Array<IntArray>.print() {
    val columns = this[0].size
    val rows = this.size

    for (i in 0 until rows) {
        for (j in 0 until columns) {
            print("${this[i][j]} ")
        }

        println()
    }
}

fun Array<IntArray>.pow(pow: Int) {
    val columns = this[0].size
    val rows = this.size
    val out = Array(rows) { IntArray(columns) }

    for (i in 0 until rows) {
        for (j in 0 until columns) {
            out[i][j] = (i == j).toInt()
        }
    }

    val temp = Array(rows) { IntArray(columns) }

    for (p in 0 until pow) {
        for (i in 0 until rows) {
            for (j in 0 until columns) {
                temp[i][j] = 0

                for (k in 0 until rows) {
                    temp[i][j] += out[i][k] * this[k][j]
                }
            }
        }

        for (i in 0 until rows) {
            for (j in 0 until columns) {
                out[i][j] = temp[i][j]
            }
        }
    }

    out.print()
}

fun Boolean.toInt(): Int {
    return if (this) 1 else 0
}
