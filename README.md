# software_and_data_security
Software and Data Security course

## Задача
### Реализовать программу на языке C\C++, которая должна включать следующую последовательность действий:
1. Запрос какой-либо информации от пользователя (логин, номер телефона, номер какого-либо документа, ключ любого вида и т.д. )
2. Произведение манипуляций по разработанному алгоритму с введенной пользователем информацией для генерации ответа на ключевой вопрос
3. Запрос ключа от пользователя и сравнение его со сгенерированным ключом на этапе 2.
4. Выдача результата по принципу:
сгенерированный и алгоритмом и введенный пользователем ключи совпадают – TRUE->поздравление или доступ к какой
либо информации
Не совпадают – ошибка
В приложении к программе должен быть описан алгоритм работы.
### Далее переписать программу с учетом следующих условий:
1. Внутри программы должен быть какой-либо алгоритм преобразования данных для
генерации ключевой информации. Например, сложение по модулю кодов букв из таблицы ASCII, Подсчет количества букв в логине пользователя и умножение его на текущий год, запросы системного времени или к каким-либо заранее определённым файлам.
2. Должны быть реализованы меры защиты от отладки: специальные функции языка, искусственное усложнение кода, директивы препроцессора, условия сборки компилятора, упаковщики и т. д. (см. лекция)
3. В приложении должны быть описаны механизмы, применяющиеся для защиты от анализа
Далее провести сравнительный анализ двух реализаций в дизассемблерах и описать в чём наблюдается усложнение во второй программе с точки зрения анализа ПО.
Описать в отчете с привидением сравнительных скриншотов с объяснениями
Результатом выполнения задания должны быть две разработанные программы в виде исполняемых файлов и исходных кодов, make/cmake
файла сборки (или инструкции по сборке в случае применения дополнительных средств или специальных скриптов.). Документация к программе с описанием алгоритма работы, описанием входных и выходных данных и применяемых в программе мер защиты, а также отчёта о сравнительном анализе в дизассемблере двух реализаций.
