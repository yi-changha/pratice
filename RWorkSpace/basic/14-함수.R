rm(list=ls())
number = 1:5
alphabet = c('a', 'b', 'c')

paste(number,alphabet)
# 입력 받은 객체들의 같은 위치 요소를 하나의 문자열로 붙임.

fruit = c('apple', 'banana', 'orange')
substr(fruit, 2, 4)
# 주어진 문자열에서 특정 문자열 추출
# substr(대상, 시작위치, 끝위치)

split(iris, iris$Species)
r1 = split(iris, iris$Species)
# 데이터를 분리할 때 사용, split(데이터, 분리조건)


subset(iris, subset=Species=='setosa' & Sepal.Length > 5.5)
# 특정 부분만 추출하는 용도

#select
subset(iris, select= c(Sepal.Length, Species))
# subset에 select 인자를 지정하면 특정 열을 선택하거나 제외 용도로 사용

#subset select 동시에 가능. - : 제외외
subset(iris, subset=Species=='setosa' & Sepal.Length > 5.5, 
       select = -c(Sepal.Length, Species))