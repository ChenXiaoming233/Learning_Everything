package com.example.helloandroid

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.example.helloandroid.ui.theme.HelloAndroidTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            HelloAndroidTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    Greeting(
                        name = "Android",
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    HelloAndroidTheme {
        Greeting("Android")
    }
}

fun main() {
    val jack = Person("Jack", 19)
    jack.eat()
    val tom = Student("001", 10, "Tom", 20)
    tom.learn()
    val tim = Student("Cook", 70)
    tim.learn()
    tim.eat()

    val amy = Student("Amy", 19)
    doStudy(amy)

    val cellphone1 = Cellphone("Samsung",1999.0)
    val cellphone2 = Cellphone("Xiaomi",1999.0)
    println(cellphone1)
    println("cellphone1 equals cellphone2 " + (cellphone1 == cellphone2))

    Singleton.singletonTest()

}

fun doStudy(study: Study){
    study.readBooks()
    study.doHomework()
}