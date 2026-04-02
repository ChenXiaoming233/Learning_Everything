import kotlin.math.max

//TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
fun main() {
    val a = 10
    val b: Double = 2.0
    println("Hello World!")
}


fun largerNumber(num1: Int, num2: Int): Int {
    return max(num1, num2)
}
fun largerNumberShorter(num1: Int, num2: Int)= max(num1, num2)


fun largerNumberIfElse(num1: Int, num2: Int) = if(num1 > num2) num1 else num2


fun getScore(name: String) = when (name){
    "Tom" -> 75
    "Lily" -> 100
    else -> "None"
}

fun getScore2(name: String) = when{
    name == "Tom" -> 75
    else -> 0
}