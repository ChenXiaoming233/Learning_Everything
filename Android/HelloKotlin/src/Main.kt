import java.util.Locale
import java.util.Locale.getDefault
import kotlin.math.max

// TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。

/*fun main() {
    val a = 10
    val b: Double = 2.0
    println("Hello World!")
}*/

fun largerNumber(
    num1: Int,
    num2: Int,
): Int = max(num1, num2)

fun largerNumberShorter(
    num1: Int,
    num2: Int,
) = max(num1, num2)

fun largerNumberIfElse(
    num1: Int,
    num2: Int,
) = if (num1 > num2) num1 else num2

fun getScore(name: String) =
    when (name) {
        "Tom" -> 75
        "Lily" -> 100
        else -> "None"
    }

fun getScore2(name: String) =
    when {
        name == "Tom" -> 75
        else -> 0
    }

// [主构造函数]
class Person3(
    var name: String,
    var age: Int,
) { // 主构造函数中将参数声明为 var/val 将成为该类的属性（成员变量），不声明则仅用于构造函数本身
}

// [继承]
open class Person { // open 关键字令对象可继承
    // 属性初始化器
    var name = ""
    var age = 0

    fun eat() {
        println(name + " is eating. He is " + age + " years old")
    }
}

class Student(
    val sno: String,
    val grade: Int,
) : Person() { // 继承 Perosn 类，空括号表示 Student 类的主构造函数初始化时调用 Perosn 类的无参构造函数
    // init-结构体，用于在主构造函数中编写逻辑，执行顺序：主构造函数参数（属性初始化器） -> init 结构体 -> 次构造函数
    init {
        println("sno is $sno")
        println("grade is $grade")
    }
}

val student = Student("a12345", 5)

// 若被继承类的主构造函数有参
open class Person2(
    var name: String,
    var age: Int,
) {
    fun eat() {
        println(name + " is eating. He is " + age + " years old")
    }
}

class Student2(
    val sno: String,
    val grade: Int,
    name: String,
    age: Int,
) : Person2(name, age) { // 增加 name 与 age 且不能声明为 val/var，否则属性冲突
    init {
        println("name is $name")
        println("age is $age")
        println("sno is $sno")
        println("grade is $grade")
    }
}

val student1 = Student2("a12345", 5, "John", 18)

// [次构造函数]
class Student3(
    val sno: String,
    val grade: Int,
    name: String,
    age: Int,
) : Person2(name, age) {
    // constructor-次构造函数，所有的次构造函数都必须直接或间接委托给主构造函数
    constructor(name: String, age: Int) : // 接受 name 与 age 参数
        this("", 0, name, age) { // this 调用主构造函数并对 sno 与 grade 赋初始值
    }
    constructor() :
        this("", 0) { // 调用第一个次构造函数并对 name 与 age 赋初始值
    }
}

val student2 = Student3()
val student3 = Student3("Jack", 19)
val student4 = Student3("a123", 5, "Jack", 19)

// 只有次构造函数，没有主构造函数（但一定有一个构造函数）
class Student4 : Person2 { // 由于 Student4 类没有主构造函数，因而继承 Person2 类时也不用加括号
    constructor(name: String, age: Int) :
        super(name, age) { // Student4 类没有主构造函数，通过 super 关键字调用父类的构造函数
    }
}

// [接口 / 多态]
class Student5(
    name: String,
    age: Int,
) : Person2(name, age),
    Study {
    override fun readBooks() { // override 关键字重写父类或实现接口函数
        println(name + " is reading.")
    }

    override fun doHomework() {
        println(name + " is doing homework.")
    }
}

fun doStudy(student: Study) { // 接受任何 Study 接口的实现类对象
    student.readBooks()
    student.doHomework()
}

// [集合的创建与遍历]
fun fruit() {
    val fruitList = listOf("Apple", "Banana") // listOf() 创建的集合不可变
    for (fruit in fruitList) {
        println(fruit)
    }
    val fruiList2 = mutableListOf("Apple") // mutableListOf() 创建的集合可变
    fruiList2.add("Banana")

    val fruitSet = setOf("Apple", "Banana")
    val fruitSet2 = mutableSetOf("Apple", "Banana")

    val map = mapOf("Apple" to 1, "Banana" to 2)
    for ((fruit, number) in map) {
        println("fruit " + fruit + "is " + number)
    }
}

// [集合的函数式 API]
// 函数式 api 类似 c++ 中的 stl
fun fruit2() {
    val list = listOf("Apple", "Banana", "Orange", "Pear", "Grape", "Watermelon")
    val maxLengthFruit = list.maxBy { it.length }
    val maxLengthFruit1 = list.maxBy({ fruit: String -> fruit.length }) // 完整 Lambda
    println("max length fruit is " + maxLengthFruit)

    // map 函数式 api, 将集合中的每个元素都映射成另一个值，映射规则在 Lambda 中指定
    val newList = list.map { it.uppercase(getDefault()) }
    // filter 函数式 api, 过滤集合中的数据
    val newList1 =
        list
            .filter { it.length < 5 }
            .map { it.uppercase(getDefault()) }
    // any 函数式 api, 判断集合中是否存在至少一个元素满足条件
    val newList2 = list.any { it.length <= 5 }
    // all 函数式 api, 判断集合中是否所有元素都满足条件
    val newList3 = list.all { it.length <= 5 }
}

// 可空类型系统
fun doStudy2(student: Student5?) { // 类型后接 ? 允许类型可空
    if (student != null) { // 须处理可能的空指针异常
        student.readBooks()
        student.eat()
    }
}

fun doStudy3(student: Student5?) {
    student?.eat() // ?. 为安全调用操作符，对象为空时整个表达式返回 null，不会继续调用后面的方法
}

fun getTextLengtht(text: String?) = text?.length ?: 0

var content: String? = "hello"

fun toUpperCase() {
    var upperCase = content!!.uppercase(getDefault()) // 此时函数内部无法检出外部的判空操作，需使用非空断言工具绕过空指针检查
    println(upperCase)
}

fun printUpperCase() {
    if (content != null) {
        toUpperCase()
    }
}

fun doStudy4(student: Study?) {
    student?.let {
        // let 函数式 api, 将原始调用对象作为参数传递到 Lambda 表达式中
        it.readBooks()
        it.doHomework()
    }
}

fun main() {
    val p = Person()
    p.name = "Jack"
    p.age = 19
    p.eat()
    val student = Student5("Jack", 19)
    doStudy(student)
    Singleton.singletonTest() // 调用单例
}
