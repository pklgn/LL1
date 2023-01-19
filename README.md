﻿# Парсер LL(1).

## 1. Правила
```
<EXP> -> <EXP> + <T> | <T>
<T>   -> <T> * <F> | <F>
<F>   -> -<F> | (<EXP>) | a | b | 8 | 3
```

## 2. Правила без левой рекурсии

```
<EXP>  -> <T><EXP'>
<EXP'> -> E | + <T><EXP'>
<T>    -> <F><T'>
<T'>   -> E | * <F><T'>
<F>    -> -<F> | (<EXP>) | a | b | 8 | 3
```

## 3. Задания

- убрать левую рекурсию
- определить направляющее множество для каждого нетерминала
- составить _таблицу_
- написать _бегунок_
- составить тесты **положительные** и **отрицательные**
- добавить диагностику ошибок
- протестировать на _чистых_ и _грязных_ тестах

## Meta информация
Как собирать: выполнить команду в корне проекта

```
cmake -S . -B build -G "Visual Studio 17 2022"
```
