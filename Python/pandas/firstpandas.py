#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pandas

f1 = pandas.read_csv("f1.csv")
f2 = pandas.read_csv("f2.csv",";")

print("Исходные данные")
print(f1)
print(f2)

print("Добавление столбцов")
country = [u'Украина',u'РФ',u'Беларусь',u'РФ',u'РФ']
f2.insert(0, 'country', country)

print("Выборка")
dset = f2[f2.country == u'РФ']
print(dset)

print("Добавление строк")
news = pandas.DataFrame([["Name", "444","Gomel"], ["N2","43","Brest"]], columns=["country","shop","name"])
print(news)
f3 = f2.append(news)
print(f3)

print("Объединение")
res = f2.merge(f1, 'left', on='shop')
#res = f2.merge(f1, 'right', on='shop')
#res = f2.merge(f1, 'inner', on='shop')
print(res)

print("Сводная таблица:")
res = res.pivot_table(['qty'],['country'], aggfunc='sum', fill_value = 0)
print(res)