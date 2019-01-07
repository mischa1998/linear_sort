# linear_sort
Разработана программа, осуществляющая ввод пар «ключ-значение», их упорядочивание
по возрастанию ключа сортировкой подсчетом (за линейное время) 
и вывод отсортированной последовательности.

Программа принимает на вход телефонные номера, с кодами стран и городов в формате
+<код страны>-<код города>-телефон.

На каждой непустой строке входного файла располагается пара «ключ-значение», 
в которой ключ является телефонным номером, затем следует знак табуляции и указано значение - строка, соответствующая владельцу
данного номера. (Строки переменной длины).


Пример:

+7-499-1582977 Moscow Aviation Institute

+7-495-6063602 Presidential Executive Office

+7-495-2242222 Federal Security Service

+375-225-449732 Babruisk hot line

+7-495-9631102 P. B. Gannushkin Moscow City Clinical Psychiatric Hospital

+7-903-5388412 "Pray to God" service 

Вывод программы:

+7-495-2242222 Federal Security Service

+7-495-6063602 Presidential Executive Office

+7-495-9631102 P. B. Gannushkin Moscow City Clinical Psychiatric Hospital

+7-499-1582977 Moscow Aviation Institute

+7-903-5388412 "Pray to God" service

+375-225-449732 Babruisk hot line 

