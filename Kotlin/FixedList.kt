enum class FixedListLocation {
    /**
     * Remove from the start
     * AKA 0
     */
    START,

    /**
     * Remove from the end
     * AKA [List.lastIndex]
     */
    END
}

open class FixedList<T> : ArrayList<T> {

    /**
     * set the max size this list can hold
     */
    var fixedSize: Int
        set(value) {
            require(value > 0) { "FixedSize must be greater than 0" }
            field = value
            multipleSizeCheck()
        }

    /**
     * choose where to remove items from
     * Default is [FixedListLocation.END]
     */
    var removeFrom: FixedListLocation = FixedListLocation.END

    constructor(fixedSize: Int, location: FixedListLocation = FixedListLocation.END) : super() {
        this.fixedSize = fixedSize
        this.removeFrom = location
    }

    constructor(fixedSize: Int, location: FixedListLocation = FixedListLocation.END, c: Collection<T>) : super(c.toMutableList()) {
        this.fixedSize = fixedSize
        this.removeFrom = location
    }

    constructor(fixedSize: Int, location: FixedListLocation = FixedListLocation.END, initialCapacity: Int) : super(initialCapacity) {
        this.fixedSize = fixedSize
        this.removeFrom = location
    }

    private val removeIndex
        get() = when (removeFrom) {
            FixedListLocation.START -> 0
            FixedListLocation.END -> lastIndex
        }

    protected fun singleSizeCheck() {
        if (size > fixedSize) removeAt(removeIndex)
    }

    override fun add(element: T): Boolean {
        val addition = super.add(element)
        singleSizeCheck()
        return addition
    }

    override fun add(index: Int, element: T) {
        val addition = super.add(index, element)
        singleSizeCheck()
        return addition
    }

    protected fun multipleSizeCheck() {
        while (size > fixedSize) removeAt(removeIndex)
    }

    override fun addAll(elements: Collection<T>): Boolean {
        val addition = super.addAll(elements)
        multipleSizeCheck()
        return addition
    }

    override fun addAll(index: Int, elements: Collection<T>): Boolean {
        val addition = super.addAll(index, elements)
        multipleSizeCheck()
        return addition
    }

    override fun toString(): String = "FixedSize=$fixedSize, RemoveFrom=$removeFrom, ${super.toString()}"

}
