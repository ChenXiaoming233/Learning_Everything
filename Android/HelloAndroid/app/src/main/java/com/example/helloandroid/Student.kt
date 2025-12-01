package com.example.helloandroid

class Student (val sno: String, val grade: Int, name: String, age: Int): Person(name, age), Study{
    constructor(name: String, age: Int): this("", 0, name,age)
    fun learn() {
        println("$name is learning. He is in $age grade.")
    }
    override fun readBooks(){
        println("$name is reading.")
    }
    override fun doHomework(){
        println("$name is doing homework.")
    }
}