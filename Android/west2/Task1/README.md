# Task1 - 宠物店

使用纯 Java 完成 west2-online Java 第一轮考核中的“宠物店”任务。

## 实现内容

- `Animal` 抽象类及 `ChineseRuralDog`、`Cat`、`Rabbit` 三个子类
- `Customer` 顾客类，记录到店次数和最近到店日期
- `AnimalShop` 接口及 `MyAnimalShop` 实现
- `InsufficientBalanceException`、`AnimalNotFoundException` 自定义运行时异常
- 测试类 `PetStoreTest`
- Bonus：两个数组的多线程交替输出、邮箱格式校验

## 注释

- `Animal.price` 同时作为进货价和销售价。
- `buyAnimal(Animal animal)` 买入时扣除动物价格；余额不足时抛出 `InsufficientBalanceException`。
- 为了保持简单，利润直接按销售金额累计，没有单独记录进货成本。
- `closeShop()` 输出当天到店顾客和当天利润，并将店铺状态设为歇业。
- Bonus 的交替输出示例假设两个数组长度相同。

这份实现刻意保持初学者风格，部分边界条件没有处理，例如歇业后仍然可以调用买入和出售方法。

## 编译与运行

要求 JDK 17 或更高版本。

PowerShell：

```powershell
javac -encoding UTF-8 -d out (Get-ChildItem src/petstore/*.java).FullName
java -cp out petstore.PetStoreTest
```
Bash：

```bash
javac -encoding UTF-8 -d out src/petstore/*.java
java -cp out petstore.PetStoreTest
```

