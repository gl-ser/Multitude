# Multitude
Библиотека логических манипуляций над множествами

Используется функционал кватернионно-векторно-матричной библиотеки [QuatVectMatr](https://github.com/gl-ser/QuatVectMatr)

Построена на библиотеке Clipper автора Angus Johnson

Множества интерпретируются как контуры на поверхности Земли (в геодезических координатах)

---

#### Публичные методы
1. _AMinusB_ из множества A вычитает несколько множеств B (A\B)

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AMinusB(TSpot A, TArraySpot B)
```

2. _APlusB_ к множеству A прибавляет несколько множеств B (AuB)

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot APlusB(TSpot A, TArraySpot B)
```

3. _AIntersectionB_ возвращает пересечение множества A с хотя бы одним множеством из B (AпB)

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AIntersectionB(TSpot A, TArraySpot B)
```

4. _AXorB_ объединяет множества A и B, затем из результата вычитает пересечение множества A с хотя бы одним множеством из B ((AuB) \ (AпB))

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AXorB(TSpot A, TArraySpot B)
```

5. _AHoldB_ отвечает на вопрос: "Множество B полностью входит во множество A?"

Ограничение по использованию метода: каждое из множеств A и B не должно иметь самопересечений (песочные часы не допускаются).

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Возвращаемые значения:

  - 0 - B целиком лежит вне множества A;
  - 1 - B входит в A целиком;
  - 2 - B пересекает множество A (часть B лежит внутри A, часть B лежит вне множества A).

Синтаксис:

```cpp
int AHoldB(TSpot A, TSpot B)
```

6. _MiddleL_ виртуально "делит" множество A по долготе пополам и возвращает эту долготу

Само множество A не меняется.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
double MiddleL(TSpot A)
```

7. _DivideA_ делит множество A по указанной пользователем долготе на части (производит разрезание множества)

Если долгота разреза указана неверно, тогда разрезания не производится, а возвращается исходное множество.

В результате успешного разрезания могут получиться два и более множеств.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot DivideA(double L, TSpot A)
```

8. _AMinusBSimpleResult_ из множества A вычитает множество B, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AMinusBSimpleResult(TSpot A, TSpot B)
```

9. _AMinusBSimpleResult_ из нескольких никак не связанных друг с другом множеств A вычитает множество B, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AMinusBSimpleResult(TArraySpot A, TSpot B)
```

10. _AMinusBSimpleResult_ из множества A вычитает несколько множеств B, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AMinusBSimpleResult(TSpot A, TArraySpot B)
```

11. _AMinusBSimpleResult_ из нескольких никак не связанных друг с другом множеств A вычитает несколько множеств B, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot AMinusBSimpleResult(TArraySpot A, TArraySpot B)
```

12. _APlusBSimpleResult_ к множеству A прибавляет множество B, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot APlusBSimpleResult(TSpot A, TSpot B)
```

13. _APlusASimpleResult_ складывает (прибавляет одно к другому) множества A, при этом результирующие множества являются простыми полигонами (не имеют дырок и каждый состоит из одного контура)

Задача применяется для изменения площадного объекта наблюдения в процессе покрытия его сканами.

Широта и долгота подаются на вход в радианах.

Диапазон изменения подаваемой на вход широты [-pi/2; +pi/2].

Диапазон изменения подаваемой на вход долготы может быть либо [0; +2pi), либо [-pi; +pi].

Результат возвращается также в радианах, но долгота возвращается только в пределах [0; +2pi).

Синтаксис:

```cpp
TArraySpot APlusASimpleResult(TArraySpot A)
```
