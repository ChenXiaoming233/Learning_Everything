interface Study {
    fun readBooks()

    fun doHomework() { // 接口函数的默认实现，允许类在实现时不进行重写
        println("do homework default implementation")
    }
}
